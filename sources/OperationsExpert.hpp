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
    class OperationsExpert : public Player
    {
    private:
    public:
        OperationsExpert(Board &, City);
        OperationsExpert &build();
    };
}