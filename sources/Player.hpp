#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic
{
    class Player
    {
    protected:
        std::string Role;
        City CurrentCity;
        std::set<City> Cards;
        Board *GameBoard;
        bool hasCard(City);

    public:
        Player(Board &, City, const std::string &); //
        virtual Player &build();                    //
        virtual Player &take_card(City);            //
        virtual Player &fly_direct(City);           //
        virtual Player &treat(City);                //
        virtual Player &drive(City);                //
        virtual Player &fly_charter(City);          //
        virtual Player &fly_shuttle(City);          //
        virtual Player &discover_cure(Color);       //
        virtual void remove_cards();                //
        std::string role();                         //
    };
}