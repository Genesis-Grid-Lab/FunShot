#include "Card.h"

Card::Card(const char* file)
    {
    // Position = {10,120};
    m_Asset = FS::Application::Get().m_Assets->AddTexture(FS::RandomU64(), file); 
    m_ID = FS::Application::Get().CreateEntt<FS::Entity>();
    m_ID.Attach<FS::InfoComponent>().Name = "Card";
    m_ID.Attach<FS::SpriteComponent>().Texture = m_Asset->UID;   
}

Card::~Card()
{
}

void Card::Update()
{
    auto& ts = m_ID.Attach<FS::TransformComponent>().Transforms.translation;
    ts.x = Position.x;
    ts.y = Position.y;
}

Rectangle Card::GetScreenRect()
{
    return Rectangle{Position.x, Position.y, (float)m_Asset->Data.width, (float)m_Asset->Data.height};
}
