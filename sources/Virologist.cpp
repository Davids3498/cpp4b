#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Virologist::Virologist(Board &b, City c) : Player(b, c, "Virologist") {}

    Virologist &Virologist::treat(City c)
    {
        if (GameBoard->operator[](c) == 0) // make sure that there is a disease
        {
            throw std::out_of_range{"Can't cure what is already healed."};
        }
        if (hasCard(c) || c == CurrentCity)
        {
            if (GameBoard->isCureCity(c))
            {
                GameBoard->operator[](c) = 0; //WE SAVED THE CIYT!!
                Cards.erase(c);
            }
            else
            {
                GameBoard->operator[](c)--; //cure disease by one
                Cards.erase(c);
            }
        }
        else
        {
            throw std::out_of_range{"Can't cure if you don't have the card."};
        }

        return *this;
    }
}