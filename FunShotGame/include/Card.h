#pragma once

#include "Auxiliaries/ECS.h"
#include "Core/Application.h"

// represents a single unique card
class Card
{
public:
    Card(const char* file);
    ~Card();

    void Update();

    Rectangle GetScreenRect();

    bool PointIn(const Vector2& pos){ return CheckCollisionPointRec(pos, GetScreenRect());}
	
    Vector2 Position;
private:
    FS::Entity m_ID;
    Vector3& m_Trans = Vector3{100};
    FS::Ref<FS::TextureAsset> m_Asset;
};


// owns a set of unique cards
class Deck
{
public:
	std::vector<Card> Cards;
    enum ESuit : int{
        BACK = 0,
        CLUB,
        DIAMOND,
        HEART,
        SPADE
    };

	Deck()
	{
        std::string begin = "Resources/Textures/Game/";
        std::string end = ".png";
		// build up 20 cards of each suit
		for (int Suit = 1; Suit < 4; Suit++)
		{
            for(int value = 1; value < 13; value++){
                
                std::string folder = ESuitToString((ESuit)Suit); 
                std::string number = std::to_string(value);
                std::string inter = number + "_";
                std::string file = begin + folder + "/" + inter + folder + end;                
                Cards.emplace_back(Card(file.c_str()));               
            }
		}

	}

    std::string ESuitToString(ESuit suit){
        switch(suit){
            case BACK:
                return "card_back";
                break;
            case CLUB:
                return "club";
                break;
            case DIAMOND:
                return "diamond";
                break;
            case HEART:
                return "heart";
                break;
            case SPADE:
                return "spade";
                break;
        }

        return "null";
    }

    void Update(){
        for(auto& card : Cards)
            card.Update();
    }
};