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
    class Dispatcher : public Player
    {
    private:
    public:
        Dispatcher(Board &, City);
        Dispatcher &fly_direct(City);
    };
}