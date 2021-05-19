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
    class FieldDoctor : public Player
    {
    private:
    public:
        FieldDoctor(Board &, City);
        FieldDoctor &treat(City);
    };
}