#include "Mesh.h"
#include "rapidjson/document.h"
#include "Vertex.h"
#include "Renderer.h"

Mesh::Mesh()
    :mVertexArray(nullptr),mRadius(0),mSpecPower(100){
}

Mesh::~Mesh(){}

bool Mesh::Load(const std::string& fileName, Renderer* renderer){

    std::ifstream file(fileName);
    if(!file.is_open()){
        FN_ERROR("File not found: Mesh {}", fileName.c_str());
        return false;
    }

    std::stringstream fileStream;
    fileStream << file.rdbuf();
    std::string contents = fileStream.str();
    rapidjson::StringStream jsonStr(contents.c_str());
    rapidjson::Document doc;

    doc.ParseStream(jsonStr);

    if(!doc.IsObject()){
        FN_ERROR("Mesh {} is not valid json", fileName.c_str());
        return false;
    }

    int ver = doc["version"].GetInt();

    //check the version
    if(ver != 1){
        FN_ERROR("Mesh %s not version 1", fileName.c_str());
        return false;
    }

    mShaderName = doc["shader"].GetString();

    size_t vertSize = 8;

    //load textures
    const rapidjson::Value& textures = doc["textures"];
    if(!textures.IsArray() || textures.Size() < 1){
        FN_ERROR("Mesh {} has no textures, there should be at least one", fileName.c_str());
        return false;
    }

    mSpecPower = static_cast<float>(doc["specularPower"].GetDouble());

    for(rapidjson::SizeType i = 0; i < textures.Size(); i++){
        //Is this texture already loaded?
        std::string texName = textures[i].GetString();

        Texture2D* t = renderer->GetTexture(texName);
        if(t == nullptr){
            //try loading the texture
            t = renderer->GetTexture(texName);
            if(t == nullptr){
                //if it's still null use default texture
                t = renderer->GetTexture("");
            }
        }

        mTextures.emplace_back(t);
    }

    //load in the vertices
    const rapidjson::Value& vertsJson = doc["vertices"];
    if(!vertsJson.IsArray() || vertsJson.Size() < 1){
        FN_ERROR("Mesh {} has no vertices", fileName.c_str());
        return false;
    }

    std::vector<float> vertices;
    vertices.reserve(vertsJson.Size() * vertSize);
    mRadius = 0;
    for(rapidjson::SizeType i = 0; i < vertsJson.Size(); i++){
        //for now we have 8 elements
        const rapidjson::Value& vert = vertsJson[i];
        if(!vert.IsArray() || vert.Size() != 8){
            FN_ERROR("Unexpected vertex format for {}", fileName.c_str());
            return false;
        }

        glm::vec3 tets = glm::vec3(0);

        glm::vec3 pos(vert[0].GetDouble(), vert[1].GetDouble(), vert[2].GetDouble());
        // mRadius =  glm::max(pos.length,mRadius);
        mRadius = glm::max(glm::length2(pos), mRadius);

        //add the floats
        for(rapidjson::SizeType i = 0; i < vert.Size(); i++){
            vertices.emplace_back(static_cast<float>(vert[i].GetDouble()));
        }
    }

    //we were computing lentg squared earlier
    mRadius = glm::sqrt(mRadius);

    //Load in the indices
    const rapidjson::Value& indJson = doc["indices"];
    if(!indJson.IsArray() || indJson.Size() < 1){
        FN_ERROR("Mesh {} had no indices", fileName.c_str());
        return false;
    }

    std::vector<unsigned int> indices;
    indices.reserve(indJson.Size() * 3);
    for(rapidjson::SizeType i = 0; i < indJson.Size(); i++){
        const rapidjson::Value& ind = indJson[i];
        if(!ind.IsArray() || ind.Size() != 3){
            FN_ERROR("Invalid indices for {}", fileName.c_str());
            return false;
        }

        indices.emplace_back(ind[0].GetUint());
        indices.emplace_back(ind[1].GetUint());
        indices.emplace_back(ind[2].GetUint());
    }

    //Now create a vertex array
    mVertexArray = new VertexArray(vertices.data(), static_cast<unsigned>(vertices.size()) / vertSize,
        indices.data(), static_cast<unsigned>(indices.size()));

    return true;
}

void Mesh::Unload(){
    delete mVertexArray;
    mVertexArray = nullptr;
}

Texture2D *Mesh::GetTexture(size_t index){
    if(index < mTextures.size()){
        return mTextures[index];
    }
    else{
        return nullptr;
    }
}
