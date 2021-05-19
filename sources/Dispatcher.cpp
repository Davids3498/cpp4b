#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Dispatcher::Dispatcher(Board &b, City c) : Player(b, c, "Dispatcher") {}
    Dispatcher &Dispatcher::fly_direct(City c)
    {
        if (c == CurrentCity) // make sure we dont move to the same city
        {
            throw std::out_of_range{"Can't fly direct."};
        }

        if (GameBoard->isBuilt(CurrentCity)) // if in current city has a station FLY
        {
            CurrentCity = c;
            return *this;
        }

        if (!hasCard(c)) //make sure we have the card | COULD ALSO CALL PLAYER FLY DIRECT
        {
            throw std::out_of_range{"Don't have a card."};
        }
        Cards.erase(c); //normal fly direct 
        CurrentCity = c;
        return *this;
    }

}