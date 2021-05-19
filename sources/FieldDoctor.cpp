#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    FieldDoctor::FieldDoctor(Board &b, City c) : Player(b, c, "FieldDoctor") {}

    FieldDoctor &FieldDoctor::treat(City c)
    {
        if (GameBoard->operator[](c) == 0) // make sure that there is a disease
        {
            throw std::out_of_range{"Can't cure what is already healed."};
        }
        if (CurrentCity == c || GameBoard->getRoad(CurrentCity, c))
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
}