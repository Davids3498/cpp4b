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
    class Researcher : public Player
    {
    private:
    public:
        Researcher(Board &, City);
        Researcher &discover_cure(Color c);
    };
}