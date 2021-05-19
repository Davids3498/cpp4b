#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{
    GeneSplicer::GeneSplicer(Board &b, City c) : Player(b, c, "GeneSplicer") {}
    GeneSplicer &GeneSplicer::discover_cure(Color c)
    {
        if (!GameBoard->isBuilt(CurrentCity)) // must have a station
        {
            throw std::out_of_range{"Can't discover cure if theres no research station"};
        }

        if (GameBoard->isCureColor(c)) // cure already discoverd do nothing
        {
            return *this;
        }

        const int CardsNeeded = 5;

        if (Cards.size() < CardsNeeded)
        {
            throw std::out_of_range{"GeneSplicer needs at least 5 cards to use discover_cure"};
        }

        int CardCount = 0;
        set<City> CardsToDiscard;
        for (const auto &card : Cards)
        {
            if (CardCount < CardsNeeded)
            {
                CardCount++;
                CardsToDiscard.insert(card);
            }
            else
            {
                break;
            }
        }
        for (const auto &card : CardsToDiscard)
        {
            Cards.erase(card);
        }

        GameBoard->addCure(c);

        return *this;
    }
}