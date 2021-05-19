#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    Medic::Medic(Board &b, City c) : Player(b, c, "Medic") {}

    Medic &Medic::treat(City c)
    {
        if (GameBoard->operator[](c) == 0) // make sure that there is a disease
        {
            throw std::out_of_range{"Can't cure what is already healed."};
        }

        if (c == CurrentCity)
        {
            GameBoard->operator[](c) = 0; //cure disease
        }

        return *this;
    }

    Medic &Medic::drive(City c)
    {
        if (GameBoard->getRoad(CurrentCity, c)) // if the cities are connected
        {
            CurrentCity = c; //move
        }
        if (GameBoard->isCureCity(c)) // also checks if a cure discovered
        {
            GameBoard->operator[](c) = 0;
        }

        return *this;
    }

    Medic &Medic::fly_direct(City c) // moivng to c and need to discard c
    {
        if (c == CurrentCity || !hasCard(c)) // make sure we can move cities
        {
            throw std::out_of_range{"Can't fly direct."};
        }
        //now we know we can moce to the city
        if (GameBoard->isCureCity(c)) //checking if theres a cure
        {
            GameBoard->operator[](c) = 0;
            CurrentCity = c;
            Cards.erase(c);
            return *this;
        }
        CurrentCity = c;
        Cards.erase(c);
        return *this;
    }

    Medic &Medic::fly_charter(City c) // moivng to c and need to discard the City you are in
    {
        if (!hasCard(CurrentCity)) // make sure we have the card of the current city
        {
            throw std::out_of_range{"Can't fly charter."};
        }
        if (GameBoard->isCureCity(c)) //checking if theres a cure
        {
            GameBoard->operator[](c) = 0;
            Cards.erase(CurrentCity);
            CurrentCity = c;
        }
        else
        {
            Cards.erase(CurrentCity);
            CurrentCity = c;
        }

        return *this;
    }

    Medic &Medic::fly_shuttle(City c)
    {
        if (GameBoard->isBuilt(c) && GameBoard->isBuilt(CurrentCity) && c != CurrentCity) // if in current city and c have a station we can move between them
        {
            CurrentCity = c;
            GameBoard->operator[](c) = 0;
            return *this;
        }
        throw std::out_of_range{"Can't fly if no research station"};
    }
}