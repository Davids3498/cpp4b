#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic
{
    Player::Player(Board &b, City c, const string &PRole) : GameBoard(&b), CurrentCity(c), Role(PRole) {}

    bool Player::hasCard(City c)
    {
        bool b = false;
        if (Cards.find(c) != Cards.end()) // if finds city
        {
            b = true;
        }
        return b;
    }

    //      moving through the cities       //
    Player &Player::drive(City c)
    {
        if (GameBoard->getRoad(CurrentCity, c)) // if the citys are connected move
        {
            CurrentCity = c; //move
            return *this;
        }
        throw std::out_of_range{"Cities arn't connected"};
    }

    Player &Player::fly_direct(City c) // moivng to c and need to discard c
    {
        if (c == CurrentCity || !hasCard(c)) // make sure we can move cities
        {
            throw std::out_of_range{"Can't fly direct."};
        }
        Cards.erase(c);
        CurrentCity = c;
        return *this;
    }

    Player &Player::fly_charter(City c) // moivng to c and need to discard the City you are in
    {
        if (hasCard(CurrentCity))
        {
            Cards.erase(CurrentCity);
            CurrentCity = c;
            return *this;
        }
        throw std::out_of_range{"Can't fly charter"};
    }

    Player &Player::fly_shuttle(City c)
    {
        if (GameBoard->isBuilt(c) && GameBoard->isBuilt(CurrentCity) && c != CurrentCity) // if in current city and c have a station we can move between them
        {
            CurrentCity = c;
            return *this;
        }
        throw std::out_of_range{"Can't fly if no research station"};
    }

    ///******************************///

    Player &Player::build() // check if there is a research station | build one station | discard card if built
    {
        if (GameBoard->isBuilt(CurrentCity))
        {
            return *this;
        }

        if (hasCard(CurrentCity)) // checks if exist or not |builds only if not exist
        {
            GameBoard->BuildStation(CurrentCity);
            Cards.erase(CurrentCity);
            return *this;
        }
        throw std::out_of_range{"Can't build."};
    }

    Player &Player::take_card(City c) // only one card for each city | THIS METHOD ALLWAYS WORKS
    {
        Cards.insert(c);
        return *this;
    }

    Player &Player::treat(City c)
    {
        if (GameBoard->operator[](c) == 0) // make sure that there is a disease
        {
            throw std::out_of_range{"Can't cure what is already healed."};
        }
        if (CurrentCity == c)
        {
            if (GameBoard->isCureCity(c))
            {
                GameBoard->operator[](c) = 0; //WE SAVED THE CIYT!!
            }
            else
            {
                GameBoard->operator[](c)--; //cure disease by one
            }
        }
        return *this;
    }

    Player &Player::discover_cure(Color c)
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

    void Player::remove_cards() // removes all cards in hand
    {
        Cards.clear();
    }

    string Player::role()
    {
        return Role;
    }
}