#pragma once

#include "Core/Layer.h"
#include "Core/Timestep.h"
#include "Card.h"
#include "Hand.h"

class GameLayer : public FS::Layer {
public:
    GameLayer();
    ~GameLayer() = default;
    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(FS::Timestep ts) override;
    void OnImGuiRender() override;

private:
    Image image;
    Texture2D cubicmap;
    Mesh mesh;
    Model model;
    Texture2D texture;
    Deck deck;
    Stack DrawDeck;
    Hand PlayerHand;
    Table table;
};