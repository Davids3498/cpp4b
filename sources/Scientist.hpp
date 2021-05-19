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
    class Scientist : public Player
    {
    private:
        int VaccineDiscovery;

    public:
        Scientist(Board &, City, int);
        Scientist &discover_cure(Color);
    };
}