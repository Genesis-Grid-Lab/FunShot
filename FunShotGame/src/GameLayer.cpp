#include "GameLayer.h"
#include "Core/Application.h"
#include "Auxiliaries/ECS.h"

using namespace FS;

GameLayer::GameLayer()
    :Layer("Game"){
}

void GameLayer::OnAttach()
{
    DrawDeck.Pos = {50, 50};
    DrawDeck.FromDeck(deck);
    DrawDeck.Shuffle();
    table.Pos = { GetScreenWidth() / (float)2, (float)(GetScreenHeight() / 2 - 144)};
    PlayerHand.Pos = { 0, GetScreenHeight() - (float)144};

    
    DrawDeck.Cards[0]->Position.x = table.Pos.x;
    DrawDeck.Cards[0]->Position.y = table.Pos.y;

    DrawDeck.Cards[1]->Position.x = table.Pos.x + 105;
    DrawDeck.Cards[1]->Position.y = table.Pos.y;

    DrawDeck.Cards[2]->Position.x = table.Pos.x + 210;
    DrawDeck.Cards[2]->Position.y = table.Pos.y;

    DrawDeck.Cards[3]->Position.x = table.Pos.x + 315;
    DrawDeck.Cards[3]->Position.y = table.Pos.y;

    DrawDeck.Cards[4]->Position.x = PlayerHand.Pos.x;
    DrawDeck.Cards[4]->Position.y = PlayerHand.Pos.y;

    DrawDeck.Cards[5]->Position.x = PlayerHand.Pos.x + 105;
    DrawDeck.Cards[5]->Position.y = PlayerHand.Pos.y;

    DrawDeck.Cards[6]->Position.x = PlayerHand.Pos.x + 210;
    DrawDeck.Cards[6]->Position.y = PlayerHand.Pos.y;

    DrawDeck.Cards[7]->Position.x = PlayerHand.Pos.x + 315;
    DrawDeck.Cards[7]->Position.y = PlayerHand.Pos.y;

    table.AddCard(DrawDeck.Cards[0], false);
    table.AddCard(DrawDeck.Cards[1], false);
    table.AddCard(DrawDeck.Cards[2], false);
    table.AddCard(DrawDeck.Cards[3], false);
    PlayerHand.AddCard(DrawDeck.Cards[4], false);
    PlayerHand.AddCard(DrawDeck.Cards[5], false);
    PlayerHand.AddCard(DrawDeck.Cards[6], false);
    PlayerHand.AddCard(DrawDeck.Cards[7], false);

}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(FS::Timestep ts)
{
   bool handled = false;
   for(auto& card : deck.Cards)
        card.Update();

    table.Update();
    PlayerHand.Update();

    // check to see if we are dragging a card
    if (PlayerHand.SelectedCard != nullptr)
    {
        if (PlayerHand.SelectedCard->PointIn(GetMousePosition()))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                PlayerHand.SelectedCard->Position = Vector2Add(PlayerHand.SelectedCard->Position, GetMouseDelta());
            else
                PlayerHand.Deselect();
            handled = true;
        }
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) // check to see if we are selecting a card from the hand
    { 
        for (auto itr = PlayerHand.Cards.rbegin(); itr != PlayerHand.Cards.rend(); itr++ )
        {
            auto* card = *itr;
            if (card->PointIn(GetMousePosition()))
            {
                // activate this card so we can start dragging it.
                PlayerHand.Select(card);
                break;
            }
        }
    }

    if (table.SelectedCard != nullptr)
    {
        if (table.SelectedCard->PointIn(GetMousePosition()))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                table.SelectedCard->Position = Vector2Add(table.SelectedCard->Position, GetMouseDelta());
            else
                table.Deselect();
            handled = true;
        }
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) // check to see if we are selecting a card from the hand
    { 
        for (auto itr = table.Cards.rbegin(); itr != table.Cards.rend(); itr++ )
        {
            auto* card = *itr;
            if (card->PointIn(GetMousePosition()))
            {
                // activate this card so we can start dragging it.
                table.Select(card);
                break;
            }
        }
    }

    // check to see if we are interacting with the draw deck
    if (!handled)
    {
        Card* deckTop = DrawDeck.Top();
        if (deckTop != nullptr)
        {
            if (deckTop->PointIn(GetMousePosition()))
            {
                if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
                {
                    // show the top card
                    // deckTop->FaceUp = true;
                }
                else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && PlayerHand.SelectedCard == nullptr)
                {
                    // take the card into a hand and start dragging it.
                    PlayerHand.AddCard(DrawDeck.PopTop());

                    // always show the face of drawn cards
                    // PlayerHand.SelectedCard->FaceUp = true;
                }
            }
        }
    }

    DrawText("DECK", int(DrawDeck.Pos.x), int(DrawDeck.Pos.y - 40), 20, PINK);
    // DrawRectangleV({0,0}, {10,10}, WHITE);
    table.Draw();
    DrawDeck.Draw();
    PlayerHand.Draw();
}

void GameLayer::OnImGuiRender()
{
}
