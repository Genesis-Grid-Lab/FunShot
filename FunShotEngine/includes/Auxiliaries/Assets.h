#pragma once
#include "../Scripts/Utilities.h"
#include "../Physics/Utilities.h"
#include "../Graphics/Models/Model.h"
#include "../Graphics/Textures/Texture.h"

namespace Gen
{
    // define the AssetID type as a 64-bit unsigned integer
    using AssetID = uint64_t;
    const AssetID EMPTY_ASSET = 0u;

    // asset type
    enum class AssetType : uint8_t
    {   
        UNKNOWN = 0,
        MATERIAL,
        TEXTURE,
        SKYBOX,
        SCRIPT,        
        SCENE,        
        MODEL,
    };

    // define the base Asset structure
    struct Asset
    {        
        // generate unique asset id
        AssetID UID = EMPTY_ASSET; 

        // file path of asset
        std::string Source;       

        // name of the asset
        std::string Name; 
        
        // asset type
        AssetType Type;
    };

    struct MaterialAsset : Asset
    {
        AssetID RoughnessMap = EMPTY_ASSET;
        AssetID OcclusionMap = EMPTY_ASSET;
        AssetID MetallicMap = EMPTY_ASSET;
        AssetID EmissiveMap = EMPTY_ASSET;
        AssetID AlbedoMap = EMPTY_ASSET;
        AssetID NormalMap = EMPTY_ASSET;

        Material Data;
    };

    struct TextureAsset : Asset
    {
        bool IsHDR = false;
        bool FlipV = true;
        Texture2D Data;
    };

    struct SkyboxAsset : Asset
    {
        int32_t Size = 2048;
        bool IsHDR = true;
        bool FlipV = true;
        Texture2D EnvMap;
        Skybox Data;
    };

    struct ScriptAsset : Asset 
    { 
        /* ... */ 
    };

    struct SceneAsset : Asset 
    { 
        /* ... */ 
    };

    struct ModelAsset : Asset
    {
        bool HasJoints = false;
        Model3D Data;
    };
   
    // define an unordered map to store assets based on their type and UID
    using SharedAsset = std::shared_ptr<Asset>;
    using AssetMap = std::unordered_map<AssetID, SharedAsset>;

    // asset registry to manage the addition and retrieval of assets
    struct AssetRegistry
    {
        GEN_INLINE AssetRegistry()
        {
            // add default asset for each type
            AddEmpty<MaterialAsset>();
            AddEmpty<TextureAsset>();
            AddEmpty<SkyboxAsset>();
            AddEmpty<ScriptAsset>();
            AddEmpty<ModelAsset>();
            AddEmpty<SceneAsset>();
        }

        GEN_INLINE auto AddSkybox(AssetID uid, const std::string& source, int32_t size, bool isHDR = true, bool flipV = true)
        {
            auto asset = std::make_shared<SkyboxAsset>();
            asset->EnvMap.Load(source, isHDR, flipV);
            asset->Type = AssetType::SKYBOX;
            asset->IsHDR = isHDR;
            asset->FlipV = flipV;
            asset->Size = size;
            Add(uid, source, asset);
            return asset;
        }
       
        GEN_INLINE auto AddTexture(AssetID uid, const std::string& source, bool isHDR = false, bool flipV = true)
        {
            auto asset = std::make_shared<TextureAsset>();
            asset->Data.Load(source, isHDR, flipV);
            asset->Type = AssetType::TEXTURE;
            asset->FlipV = flipV;
            asset->IsHDR = isHDR;
            Add(uid, source, asset);
            return asset;
        }

        GEN_INLINE auto AddModel(AssetID uid, const std::string& source, bool hasJoints = false)
        {
            auto asset = std::make_shared<ModelAsset>();
            asset->HasJoints = hasJoints;
            asset->Type = AssetType::MODEL;

            // load model
            if(hasJoints)
                asset->Data = std::make_shared<SkeletalModel>(source);
            else
                asset->Data = std::make_shared<StaticModel>(source);

            Add(uid, source, asset);
            return asset;
        }

        GEN_INLINE auto AddMaterial(AssetID uid, const std::string& name)
        {
            auto asset = std::make_shared<MaterialAsset>();
            asset->Type = AssetType::MATERIAL;
            Add(uid, name, asset);
            return asset;
        }
        
        GEN_INLINE auto AddScript(AssetID uid, const std::string& source)
        {
            auto asset = std::make_shared<ScriptAsset>();
            asset->Type = AssetType::SCRIPT;
            Add(uid, source, asset);
            return asset;
        }

        GEN_INLINE auto AddScene(AssetID uid, const std::string& source)
        {
            auto asset = std::make_shared<SceneAsset>();
            asset->Type = AssetType::SCENE;
            Add(uid, source, asset);
            return asset;
        }
     
        // retrieve asset based on its uid
        template <typename T>
        GEN_INLINE T& Get(AssetID uid)
        {
            const uint32_t type = TypeID<T>();
            if (m_Registry[type].count(uid))
                return (T&)(*m_Registry[type][uid]);            
            return (T&)(*m_Registry[type][EMPTY_ASSET]);
        }

        // helps loop through all assets
        template <typename F>
        GEN_INLINE void View(F&& func)
        {
            for(auto& [_, assetMap] : m_Registry)
            {                
                for(auto& [uid, asset] : assetMap)
                {
                    if(uid != EMPTY_ASSET)
                    {
                        func(asset.get());                                        
                    }
                }
            }
        }

        // return collection of asset
        template <typename T>
        GEN_INLINE auto& GetMap()
        {
            return m_Registry[TypeID<T>()];
        }

        GEN_INLINE void Clear()
        {
            m_Registry.clear();
        }

    private:
        // adds a new asset to the registry
        template <typename T>
        GEN_INLINE void Add(
            AssetID uid, 
            const std::string& source, 
            std::shared_ptr<T>& asset
        )
        {            
            asset->UID = uid;
            asset->Source = source;
            std::filesystem::path path(source);
            asset->Name = path.stem().string();
            m_Registry[TypeID<T>()][asset->UID] = asset;
        }

        template <typename T>        
        GEN_INLINE void AddEmpty()
        {
            m_Registry[TypeID<T>()][EMPTY_ASSET] = std::make_shared<T>();
        }

    private:
        std::unordered_map<uint32_t, AssetMap> m_Registry;  
    };
}
