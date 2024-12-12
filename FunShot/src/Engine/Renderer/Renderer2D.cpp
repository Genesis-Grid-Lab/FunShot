#include "fspch.h"
#include "Renderer2D.h"

#include "Engine/Renderer/VertexArray.h"
#include "Engine/Renderer/Shader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Engine/Renderer/RenderCommand.h"

namespace FS {

    struct Renderer2DStorage{
        Ref<VertexArray> QuadVertexArray;        
        Ref<Shader> TextureShader;
        Ref<Texture2D> WhiteTexture;
    };

    static Renderer2DStorage* s_Data;

    void Renderer2D::Init(){
        FS_PROFILE_FUNCTION();
        s_Data = new Renderer2DStorage();
        Ref<VertexBuffer> VB; 
        Ref<IndexBuffer> IB; 
        s_Data->QuadVertexArray = VertexArray::Create();

        float vertices2[5*4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
            0.5f, 0.5f, 0.0f,   1.0f, 1.0f,
            -0.5f, 0.5f, 0.0f,  0.0f, 1.0f
        };

        VB = VertexBuffer::Create(vertices2, sizeof(vertices2));

        VB->SetLayout({
            {ShaderDataType::Vec3, "a_Position"},
            {ShaderDataType::Vec2, "a_TexCoord"}
        });
        
        s_Data->QuadVertexArray->AddVertexBuffer(VB);

        uint32_t indices2[6] = { 0,1,2, 2, 3, 0};

        IB = IndexBuffer::Create(indices2, 6);

        s_Data->QuadVertexArray->SetIndexBuffer(IB);

        s_Data->WhiteTexture = Texture2D::Create(1,1);
        uint32_t whiteTextureData = 0xffffffff;
        s_Data->WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

        s_Data->TextureShader = Shader::Create("Resources/Shaders/Texture.glsl");
        s_Data->TextureShader->Bind();
        s_Data->TextureShader->SetInt("u_Texture", 0);
        
    }

    void Renderer2D::Shutdown(){
        FS_PROFILE_FUNCTION();
        delete s_Data;
    }

    void Renderer2D::BeginScene(const OrthographicCamera &camera){
        FS_PROFILE_FUNCTION();
        s_Data->TextureShader->Bind();
        s_Data->TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
    }

    void Renderer2D::EndScene(){
        FS_PROFILE_FUNCTION();
    }

    void Renderer2D::DrawQuad(const glm::vec3 &position, const glm::vec2 &size, const glm::vec4 &color){
        FS_PROFILE_FUNCTION();

        s_Data->TextureShader->SetFloat4("u_Color", color);
        s_Data->WhiteTexture->Bind();

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position);
        transform = glm::scale(transform, {size.x, size.y, 1.0f});
        s_Data->TextureShader->SetMat4("u_Transform", transform);

        s_Data->QuadVertexArray->Bind();
        RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
    }

    void Renderer2D::DrawQuad(const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color){

        DrawQuad({position.x, position.y, 0.0f}, size, color);
    }

    void Renderer2D::DrawQuad(const glm::vec2 &position, const glm::vec2 &size, const Ref<Texture2D> &texture){
        DrawQuad({position.x, position.y, 0.0f}, size, texture);
    }

    void Renderer2D::DrawQuad(const glm::vec3 &position, const glm::vec2 &size, const Ref<Texture2D> &texture){
        FS_PROFILE_FUNCTION();

        s_Data->TextureShader->SetFloat4("u_Color", glm::vec4(1.0f));
        texture->Bind();

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position);
        transform = glm::scale(transform, {size.x, size.y, 1.0f});
        s_Data->TextureShader->SetMat4("u_Transform", transform);

        s_Data->QuadVertexArray->Bind();
        RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
    }
}