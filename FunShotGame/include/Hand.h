#pragma once

#include "Card.h"

// a stack of card pointers, used for things like draw decks and things that draw as card stack.
class Stack
{
public:
	// where the stack origin is on screen
	Vector2 Pos = { 0 };

	std::vector<Card*> Cards;

	void FromDeck(Deck& deck)
	{
		Cards.clear();
		for (auto& card : deck.Cards)
			Cards.push_back(&card);
	}

	// swaps the location of two cards
	void Swap(size_t a, size_t b)
	{
		Card* t = Cards[a];
		Cards[a] = Cards[b];
		Cards[b] = t;
	}

    void Update(){
        for(auto& card : Cards)
            card->Update();
    }

	// swaps random cards for factor * card count to try and shuffle the stack.
	void Shuffle( size_t factor = 4)
	{
		size_t count = Cards.size() * factor;

		for (size_t i = 0; i < count; i++)
		{
			size_t a = (size_t)GetRandomValue(0, (int)Cards.size() - 1);
			size_t b = (size_t)GetRandomValue(0, (int)Cards.size() - 1);

			Swap(a, b);
		}
	}

	Card* Top()
	{
		Card* topCard = nullptr;
		if (!Cards.empty())
			topCard = Cards[Cards.size() - 1];

		return topCard;
	}

	Card* PopTop()
	{
		if (Cards.empty())
			return nullptr;

		Card* topCard = Cards[Cards.size() - 1];
		Cards.erase(Cards.begin() + (Cards.size()-1));

		return topCard;
	}

	void Draw()
	{
		Rectangle baseRect = Rectangle{ Pos.x,Pos.y, (float)100, (float)144 };

		// draw a gray rectangle where this stack is
		DrawRectangleRec(baseRect, DARKGRAY);


		// draw a fake 'card' for every 10 cards in the stack
		int stackHeight = (int)Cards.size() / 10;
		stackHeight *= 3;

		for (int i = 3; i < stackHeight; i += 3)
		{
			baseRect.x -= 3;
			baseRect.y -= 3;
			DrawRectangleRec(baseRect, (i % 6) == 0 ? DARKGRAY : GRAY );
		}

		// draw the top card
		Card* topCard = Top();

		if (topCard != nullptr)
		{
			topCard->Position.x = baseRect.x - 3;
			topCard->Position.y = baseRect.y - 3;
			topCard->Update();
		}
	}
};

class Hand : public Stack
{
public:
    Hand(){
        m_ID = FS::Application::Get().CreateEntt<FS::Entity>();
        m_ID.Attach<FS::InfoComponent>().Name = "Hand";
    }

    void Update(){
        auto& ts = m_ID.Attach<FS::TransformComponent>().Transforms.translation;
        ts.x = Pos.x;
        ts.y = Pos.y;
    }
	std::list<Card*> Cards;

	Card* SelectedCard = nullptr;

	void AddCard(Card* card, bool selected = true)
	{
		Cards.emplace_back(card);
		if (selected)
			Select(card);
	}

	void Select(Card* card)
	{
		Deselect();
		if (card == nullptr)
			return;

		SelectedCard = card;
        card->Update();

		auto itr = std::find(Cards.begin(), Cards.end(), SelectedCard);
		if (itr != Cards.end())
			Cards.erase(itr);

		Cards.push_back(SelectedCard);

		// make it look like we picked up the card
		SelectedCard->Position.x -= 5;
		SelectedCard->Position.y -= 5;
	}

	void Deselect()
	{
		if (SelectedCard != nullptr)
		{
			// make it look like we dropped the card
			SelectedCard->Position.x += 10;
			SelectedCard->Position.y += 10;
		}
		SelectedCard = nullptr;
	}

	void Draw()
	{
		for (Card* card : Cards)
		{
			if (card == SelectedCard)
			{
				// draw a shadow below the card
				Rectangle shadow = SelectedCard->GetScreenRect();
				shadow.x += 10;
				shadow.y += 10;

				DrawRectangleRec(shadow, ColorAlpha(BLACK, 0.5f));

			}

			card->Update();
			
		}
	}
private:
    FS::Entity m_ID;
};


class Table : public Stack{
public:
    Table(){
        m_ID = FS::Application::Get().CreateEntt<FS::Entity>();
        m_ID.Attach<FS::InfoComponent>().Name = "Table";
    }
    std::list<Card*> Cards;

	Card* SelectedCard = nullptr;

    void Update(){
        auto& ts = m_ID.Attach<FS::TransformComponent>().Transforms.translation;
        ts.x = Pos.x;
        ts.y = Pos.y;
    }

    void AddCard(Card* card, bool selected = true)
	{
		Cards.emplace_back(card);
		if (selected)
			Select(card);
	}

	void Select(Card* card)
	{
		Deselect();
		if (card == nullptr)
			return;

		SelectedCard = card;
        card->Update();

		auto itr = std::find(Cards.begin(), Cards.end(), SelectedCard);
		if (itr != Cards.end())
			Cards.erase(itr);

		Cards.push_back(SelectedCard);

		// make it look like we picked up the card
		SelectedCard->Position.x -= 5;
		SelectedCard->Position.y -= 5;
	}

	void Deselect()
	{
		if (SelectedCard != nullptr)
		{
			// make it look like we dropped the card
			SelectedCard->Position.x += 10;
			SelectedCard->Position.y += 10;
		}
		SelectedCard = nullptr;
	}

	void Draw()
	{
		for (Card* card : Cards)
		{
			if (card == SelectedCard)
			{
				// draw a shadow below the card
				Rectangle shadow = SelectedCard->GetScreenRect();
				shadow.x += 10;
				shadow.y += 10;

				DrawRectangleRec(shadow, ColorAlpha(BLACK, 0.5f));

			}

			card->Update();
			
		}

        DrawRectangleV(Pos, {500,144}, WHITE);
	}

private:
    FS::Entity m_ID;
};