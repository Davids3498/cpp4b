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
    class GeneSplicer : public Player
    {
    private:
    public:
        GeneSplicer(Board &, City);
        GeneSplicer &discover_cure(Color c);
    };
}