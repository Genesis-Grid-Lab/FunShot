#pragma once
#include "Core.h"

class Mesh {
public:
    Mesh();
    ~Mesh();

    //load/unload mesh
    bool Load(const std::string& fileName, class Renderer* renderer);
    void Unload();
    //Get the vertex array associated with this mesh
    class VertexArray* GetVertexArray(){ return mVertexArray;}
    // Get a texture from specified index
    class Texture2D* GetTexture(size_t index);
    //Get name of shader
    const std::string& GetShaderName() const { return mShaderName;}
    //Get object space bounding sphere radius
    float GetRadius() const { return mRadius;}
    //Get specular power of mesh
    float GetSpecPower() const { return mSpecPower;}

private:
    //Texture associated with this mesh
    std::vector<class Texture2D*> mTextures;
    //Vertex array associated with this mesh
    class VertexArray* mVertexArray;
    //Name of shader specified by mesh
    std::string mShaderName;
    //store object space bounding radius
    float mRadius;
    //Specular power of surface
    float mSpecPower;
};