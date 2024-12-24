#pragma once

#include "raymath.h"
#include "external/glad.h"

namespace FS
{
    static TextureCubemap GenTextureCubemap(Shader shader, Texture2D panorama, int size, int format);
    // define the AssetID type as a 64-bit unsigned integer
    using AssetID = uint64_t;
    const AssetID EMPTY_ASSET = 0u;

    typedef enum {

        FISRT = 0,
        SECOND
    } HDR;

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
        Texture2D Data;
    };

    struct SkyboxAsset : Asset
    {
        int32_t Size = 2048;
        bool IsHDR = true;
        bool FlipV = true;
        Texture2D EnvMap;
        Model Data;
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
        // bool HasJoints = false;
        Model Data;
    };
   
    // define an unordered map to store assets based on their type and UID
    using SharedAsset = std::shared_ptr<Asset>;
    using AssetMap = std::unordered_map<AssetID, SharedAsset>;

    // asset registry to manage the addition and retrieval of assets
    struct AssetRegistry
    {
        inline AssetRegistry()
        {
            // add default asset for each type
            AddEmpty<MaterialAsset>();
            AddEmpty<TextureAsset>();
            AddEmpty<SkyboxAsset>();
            AddEmpty<ScriptAsset>();
            AddEmpty<ModelAsset>();
            AddEmpty<SceneAsset>();
        }

        inline auto AddSkybox(AssetID uid, const std::string& source, int32_t size = 1024, bool isHDR = false, bool flipV = true)
        {
            auto asset = std::make_shared<SkyboxAsset>();
            // Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);
            // Shader shdrCubemap = LoadShader("Resources/Shaders/cubemap.vs", "Resources/Shaders/cubemap.fs");

            // bool usingHDR = isHDR ? 1 : 0;

            // asset->Data = LoadModelFromMesh(cube);
            // asset->Data.materials[0].shader = LoadShader("Resources/Shaders/skybox.vs", "Resources/Shaders/skybox.fs");
            // rlEnableShader(asset->Data.materials[0].shader.id);
            // SetShaderValue(asset->Data.materials[0].shader, GetShaderLocation(asset->Data.materials[0].shader, "doGamma"), &usingHDR, SHADER_UNIFORM_INT);
            // // SetShaderValue(asset->Data.materials[0].shader, GetShaderLocation(asset->Data.materials[0].shader, "vflipped"), &usingHDR, SHADER_UNIFORM_INT);

            // // SetShaderValue(asset->Data.materials[0].shader, GetShaderLocation(asset->Data.materials[0].shader, "environmentMap"),  &use2 , SHADER_UNIFORM_INT);
            // // SetShaderValue(asset->Data.materials[0].shader, GetShaderLocation(asset->Data.materials[0].shader, "environmentMap"),  (void*)MATERIAL_MAP_CUBEMAP , SHADER_UNIFORM_INT);

            // glUniform1i(GetShaderLocation(asset->Data.materials[0].shader, "environmentMap"), 0);
            // glUniform1i(GetShaderLocation(asset->Data.materials[0].shader, "doGamma"), usingHDR);
            // glUniform1i(GetShaderLocation(asset->Data.materials[0].shader, "vflipped"), usingHDR);

            // rlEnableShader(shdrCubemap.id);
            // // SetShaderValue(shdrCubemap, GetShaderLocation(shdrCubemap, "equirectangularMap"), &use , SHADER_UNIFORM_INT);
            // glUniform1i(GetShaderLocation(shdrCubemap, "equirectangularMap"), 0);
            // char skyboxFileName[256] = { 0 };
            // if(isHDR){

            //     TextCopy(skyboxFileName, source.c_str());
            //     asset->EnvMap = LoadTexture(skyboxFileName);
            //     asset->Data.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = GenTextureCubemap(shdrCubemap, asset->EnvMap, 1024, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
            //     // asset->Data.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = GenTextureCubemap(shdrCubemap, asset->EnvMap, size, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);

            //     UnloadTexture(asset->EnvMap);
            // }
            // else{
            //     Image img = LoadImage("Resources/Textures/HDRs/skybox.png");// error cheching to do
            //     Texture2D tex = LoadTexture("Resources/Textures/HDRs/Sky.png");
            //     // asset->Data.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);    // CUBEMAP_LAYOUT_PANORAMA
            //     asset->Data.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = tex;    // CUBEMAP_LAYOUT_PANORAMA
            //     UnloadImage(img);
            // }
            Mesh cube = GenMeshCube(10.0f, 10.0f, 10.0f);
            asset->Data = LoadModelFromMesh(cube);

            Image img = LoadImage(source.c_str());
            // ImageFlipHorizontal(&img);

            // asset->EnvMap = LoadTexture(source.c_str());
            asset->EnvMap = LoadTextureFromImage(img);

            asset->Data.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = asset->EnvMap;

            asset->Type = AssetType::SKYBOX;
            asset->IsHDR = isHDR;
            asset->FlipV = flipV;
            asset->Size = size;
            Add(uid, source, asset);
            return asset;
        }
       
        inline auto AddTexture(AssetID uid, const std::string& source)
        {
            auto asset = std::make_shared<TextureAsset>();
            asset->Data = LoadTexture(source.c_str());
            asset->Type = AssetType::TEXTURE;
            Add(uid, source, asset);
            return asset;
        }

        inline auto AddModel(AssetID uid, const std::string& source, bool hasJoints = false)
        {
            auto asset = std::make_shared<ModelAsset>();            
            asset->Type = AssetType::MODEL;
            asset->Data = LoadModel(source.c_str());
            Add(uid, source, asset);
            return asset;
        }

        inline auto AddMaterial(AssetID uid, const std::string& name)
        {
            auto asset = std::make_shared<MaterialAsset>();
            asset->Type = AssetType::MATERIAL;
            Add(uid, name, asset);
            return asset;
        }
        
        inline auto AddScript(AssetID uid, const std::string& source)
        {
            auto asset = std::make_shared<ScriptAsset>();
            asset->Type = AssetType::SCRIPT;
            Add(uid, source, asset);
            return asset;
        }

        inline auto AddScene(AssetID uid, const std::string& source)
        {
            auto asset = std::make_shared<SceneAsset>();
            asset->Type = AssetType::SCENE;
            Add(uid, source, asset);
            return asset;
        }
     
        // retrieve asset based on its uid
        template <typename T>
        inline T& Get(AssetID uid)
        {
            const uint32_t type = TypeID<T>();
            if (m_Registry[type].count(uid))
                return (T&)(*m_Registry[type][uid]);            
            return (T&)(*m_Registry[type][EMPTY_ASSET]);
        }

        // helps loop through all assets
        template <typename F>
        inline void View(F&& func)
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
        inline auto& GetMap()
        {
            return m_Registry[TypeID<T>()];
        }

        inline void Clear()
        {
            m_Registry.clear();
        }

    private:
        // adds a new asset to the registry
        template <typename T>
        inline void Add(
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
        inline void AddEmpty()
        {
            m_Registry[TypeID<T>()][EMPTY_ASSET] = std::make_shared<T>();
        }

    private:
        std::unordered_map<uint32_t, AssetMap> m_Registry;  
    };


    TextureCubemap GenTextureCubemap(Shader shader, Texture2D panorama, int size, int format)
    {
        TextureCubemap cubemap = { 0 };

        rlDisableBackfaceCulling();     // Disable backface culling to render inside the cube

        // STEP 1: Setup framebuffer
        //------------------------------------------------------------------------------------------
        unsigned int rbo = rlLoadTextureDepth(size, size, true);
        cubemap.id = rlLoadTextureCubemap(0, size, format, 1);

        unsigned int fbo = rlLoadFramebuffer();
        rlFramebufferAttach(fbo, rbo, RL_ATTACHMENT_DEPTH, RL_ATTACHMENT_RENDERBUFFER, 0);
        rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X, 0);

        // Check if framebuffer is complete with attachments (valid)
        if (rlFramebufferComplete(fbo)) TraceLog(LOG_INFO, "FBO: [ID %i] Framebuffer object created successfully", fbo);
        //------------------------------------------------------------------------------------------

        // STEP 2: Draw to framebuffer
        //------------------------------------------------------------------------------------------
        // NOTE: Shader is used to convert HDR equirectangular environment map to cubemap equivalent (6 faces)
        rlEnableShader(shader.id);

        // Define projection matrix and send it to shader
        Matrix matFboProjection = MatrixPerspective(90.0*DEG2RAD, 1.0, rlGetCullDistanceNear(), rlGetCullDistanceFar());
        rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_PROJECTION], matFboProjection);

        // Define view matrix for every side of the cubemap
        Matrix fboViews[6] = {
            MatrixLookAt(Vector3{ 0.0f, 0.0f, 0.0f }, Vector3{  1.0f,  0.0f,  0.0f }, Vector3{ 0.0f, -1.0f,  0.0f }),
            MatrixLookAt(Vector3{ 0.0f, 0.0f, 0.0f }, Vector3{ -1.0f,  0.0f,  0.0f }, Vector3{ 0.0f, -1.0f,  0.0f }),
            MatrixLookAt(Vector3{ 0.0f, 0.0f, 0.0f }, Vector3{  0.0f,  1.0f,  0.0f }, Vector3{ 0.0f,  0.0f,  1.0f }),
            MatrixLookAt(Vector3{ 0.0f, 0.0f, 0.0f }, Vector3{  0.0f, -1.0f,  0.0f }, Vector3{ 0.0f,  0.0f, -1.0f }),
            MatrixLookAt(Vector3{ 0.0f, 0.0f, 0.0f }, Vector3{  0.0f,  0.0f,  1.0f }, Vector3{ 0.0f, -1.0f,  0.0f }),
            MatrixLookAt(Vector3{ 0.0f, 0.0f, 0.0f }, Vector3{  0.0f,  0.0f, -1.0f }, Vector3{ 0.0f, -1.0f,  0.0f })
        };

        rlViewport(0, 0, size, size);   // Set viewport to current fbo dimensions

        // Activate and enable texture for drawing to cubemap faces
        rlActiveTextureSlot(0);
        rlEnableTexture(panorama.id);

        for (int i = 0; i < 6; i++)
        {
            // Set the view matrix for the current cube face
            rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_VIEW], fboViews[i]);
            
            // Select the current cubemap face attachment for the fbo
            // WARNING: This function by default enables->attach->disables fbo!!!
            rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X + i, 0);
            rlEnableFramebuffer(fbo);

            // Load and draw a cube, it uses the current enabled texture
            rlClearScreenBuffers();
            rlLoadDrawCube();

            // ALTERNATIVE: Try to use internal batch system to draw the cube instead of rlLoadDrawCube
            // for some reason this method does not work, maybe due to cube triangles definition? normals pointing out?
            // TODO: Investigate this issue...
            //rlSetTexture(panorama.id); // WARNING: It must be called after enabling current framebuffer if using internal batch system!
            //rlClearScreenBuffers();
            //DrawCubeV(Vector3Zero(), Vector3One(), WHITE);
            //rlDrawRenderBatchActive();
        }
        //------------------------------------------------------------------------------------------

        // STEP 3: Unload framebuffer and reset state
        //------------------------------------------------------------------------------------------
        rlDisableShader();          // Unbind shader
        rlDisableTexture();         // Unbind texture
        rlDisableFramebuffer();     // Unbind framebuffer
        rlUnloadFramebuffer(fbo);   // Unload framebuffer (and automatically attached depth texture/renderbuffer)

        // Reset viewport dimensions to default
        rlViewport(0, 0, rlGetFramebufferWidth(), rlGetFramebufferHeight());
        rlEnableBackfaceCulling();
        //------------------------------------------------------------------------------------------

        cubemap.width = size;
        cubemap.height = size;
        cubemap.mipmaps = 1;
        cubemap.format = format;

        return cubemap;
    }
}