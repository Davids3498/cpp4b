#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic
{
    OperationsExpert::OperationsExpert(Board &b, City c) : Player(b, c, "OperationsExpert") {}

    OperationsExpert &OperationsExpert::build()
    {
        if (!GameBoard->isBuilt(CurrentCity)) // checks if exist or not
        {
            GameBoard->BuildStation(CurrentCity); //builds 
        }
        return *this;
    }
}