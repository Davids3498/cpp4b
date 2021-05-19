#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
    private:
    public:
        Virologist(Board &, City);
        Virologist &treat(City c);
    };
}