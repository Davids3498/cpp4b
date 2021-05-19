#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Scientist.hpp"
using namespace std;

namespace pandemic
{
    Scientist::Scientist(Board &b, City c, int i) : Player(b, c, "Scientist"), VaccineDiscovery(i) {}

    Scientist &Scientist::discover_cure(Color c)
    {
        if (!GameBoard->isBuilt(CurrentCity)) // must have a station
        {
            throw std::out_of_range{"Can't discover cure if theres no research station"};
        }

        if (GameBoard->isCureColor(c)) // cure already discoverd do nothing
        {
            return *this;
        }

        int CardCount = 0; //we need at least 4 (VaccineDiscovery) cards to cure
        set<City> CardsToDiscard;
        for (const auto &card : Cards)
        {
            if (GameBoard->getCityColor(card) == c && CardCount <= VaccineDiscovery)
            {
                CardCount++;
                CardsToDiscard.insert(card);
            }
        }

        if (CardCount < VaccineDiscovery)
        {
            throw std::out_of_range{"scientist cant discover cure"};
        }

        for (const auto &card : CardsToDiscard)
        {
            Cards.erase(card);
        }

        GameBoard->addCure(c);

        return *this;
    }
}