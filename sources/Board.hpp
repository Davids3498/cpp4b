#pragma once
#include <iostream>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>

namespace pandemic
{
    class Board
    {
    private:
        std::map<City, int> CityDisease;
        std::set<City> Station;
        std::set<Color> Cures;
        std::map<Color, std::set<City>> ColorCity;
        std::map<City, Color> CityColor;
        std::map<City, std::set<City>> RoadMap;
        void initBoard(); //

    public:
        Board();               //
        bool is_clean();       //
        int &operator[](City); //
        friend std::ostream &operator<<(std::ostream &, const Board &);
        void remove_cures();       //
        void remove_stations();    //
        bool isBuilt(City);        //
        void destroyStation(City); //
        void BuildStation(City);   //
        bool isCureCity(City);     //
        bool isCureColor(Color);   //
        bool getRoad(City, City);  //
        Color getCityColor(City);  //
        void addCure(Color);       //
    };
}