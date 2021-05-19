#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"

using namespace std;

namespace pandemic
{
    Researcher::Researcher(Board &b, City c) : Player(b, c, "Researcher") {}
    Researcher &Researcher::discover_cure(Color c)
    {
        if (GameBoard->isCureColor(c)) // cure already discoverd do nothing
        {
            return *this;
        }

        const int CardsNeeded = 5;
        int CardCount = 0;
        set<City> CardsToDiscard;
        for (const auto &card : Cards)
        {
            if (GameBoard->getCityColor(card) == c && CardCount < CardsNeeded)
            {
                CardCount++;
                CardsToDiscard.insert(card);
            }
        }

        if (CardCount < CardsNeeded)
        {
            throw std::out_of_range{"Need at least 5 cards to discover a cure"};
        }

        for (const auto &card : CardsToDiscard)
        {
            Cards.erase(card);
        }

        GameBoard->addCure(c);

        return *this;
    }
}