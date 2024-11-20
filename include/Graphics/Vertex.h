#pragma once
#include "Core.h"

class VertexArray{
public:
    VertexArray(const float* verts, unsigned int numVerts,
                const unsigned int* indices, unsigned int numIndices);
    ~VertexArray();

    //Activate this vertex array (so we can draw it)
    void SetActive();

    unsigned int GetNumIndices() const { return mNumIndices;}
    unsigned int GetNumVertices() const { return mNumVertices;}

private:
    //How many vertices in the vertex buffer?
    unsigned int mNumVertices;
    //how many indices in the index buffer
    unsigned int mNumIndices;
    //OpenGL ID of the vertex buffer
    unsigned int mVertexBuffer;
    //OpenGL ID if the index buffer
    unsigned int mIndexBuffer;
    //OpenGL ID of the vertex array object
    unsigned int mVertexArray;
};