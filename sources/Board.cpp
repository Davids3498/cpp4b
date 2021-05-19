#include <iostream>
#include <string>
#include "City.hpp"
#include "Board.hpp"
#include <map>
#include <set>
#include <stdexcept>

using namespace std;

namespace pandemic
{
    Board::Board()
    {
        initBoard();
    }

    bool Board::is_clean()
    {
        for (const auto &NumOfDiseases : CityDisease)
        {
            if (NumOfDiseases.second != 0)
            {
                return false;
            }
        }
        return true;
    }

    bool Board::isBuilt(City c) //checks if a station is allready built
    {
        bool b = false;
        if (Station.find(c) != Station.end()) //if not end then there is a station
        {
            b = true;
        }
        return b;
    }

    void Board::BuildStation(City c)
    {
        Station.insert(c);
    }

    void Board::destroyStation(City c)
    {
        if (Station.find(c) != Station.end()) // if not end then there is a station that we need to destroy
        {
            Station.erase(c); //destroy the station
        }
    }

    int &Board::operator[](City c)
    {
        return CityDisease[c];
    }

    void Board::remove_cures()
    {
        Cures.clear();
    }

    void Board::remove_stations()
    {
        Station.clear();
    }

    bool Board::isCureCity(City c)
    {
        bool b = false;
        if (Cures.find(CityColor[c]) != Cures.end()) // there is a cure
        {
            b = true;
        }
        return b; // no cure
    }

    bool Board::isCureColor(Color c)
    {
        bool b = false;
        if (Cures.find(c) != Cures.end())
        {
            b = true;
        }
        return b;
    }

    bool Board::getRoad(City src, City dst)
    {
        if (RoadMap[src].find(dst) != RoadMap[src].end())
        {
            return true; // can move to the dst
        }
        throw std::out_of_range("To drive the cities need to be connected");
        return false; // cant move to the dst
    }

    Color Board::getCityColor(City c)
    {
        return CityColor[c];
    }

    void Board::addCure(Color c)
    {
        Cures.insert(c);
    }

    ostream &operator<<(ostream &out, const Board &b)
    {
        out << "Research centers built: " << b.Station.size() << endl;
         
        out << "Cures discovers: " << b.Cures.size() << endl;

        out << "Number of cities infectef: " << b.CityDisease.size() << endl;

        return out;
    }



    void Board::initBoard()
    {
        //ColorCity
        //Yellow
        set<City> YellowSet{City::Bogota, City::BuenosAires, City::Johannesburg, City::Khartoum, City::Kinshasa, City::Lagos, City::Lima, City::LosAngeles, City::MexicoCity, City::Miami, City::Santiago, City::SaoPaulo};
        ColorCity[Color::Yellow] = YellowSet;
        //Black
        set<City> BlackSet{City::Algiers, City::Baghdad, City::Cairo, City::Chennai, City::Delhi, City::Istanbul, City::Karachi, City::Kolkata, City::Moscow, City::Mumbai, City::Riyadh, City::Tehran};
        ColorCity[Color::Black] = BlackSet;
        //Blue
        set<City> BlueSet{City::Atlanta, City::Chicago, City::Essen, City::London, City::Madrid, City::Milan, City::Montreal, City::NewYork, City::Paris, City::SanFrancisco, City::StPetersburg, City::Washington};
        ColorCity[Color::Blue] = BlueSet;
        //Red
        set<City> RedSet{City::Bangkok, City::Beijing, City::HoChiMinhCity, City::HongKong, City::Jakarta, City::Manila, City::Osaka, City::Seoul, City::Shanghai, City::Sydney, City::Taipei, City::Tokyo};
        ColorCity[Color::Red] = RedSet;

        //CityColor
        CityColor[City::Algiers] = Color::Black;
        CityColor[City::Atlanta] = Color::Blue;
        CityColor[City::Baghdad] = Color::Black;
        CityColor[City::Bangkok] = Color::Red;
        CityColor[City::Beijing] = Color::Red;
        CityColor[City::Bogota] = Color::Yellow;
        CityColor[City::BuenosAires] = Color::Yellow;
        CityColor[City::Cairo] = Color::Black;
        CityColor[City::Chennai] = Color::Black;
        CityColor[City::Chicago] = Color::Blue;
        CityColor[City::Delhi] = Color::Black;
        CityColor[City::Essen] = Color::Blue;
        CityColor[City::HoChiMinhCity] = Color::Red;
        CityColor[City::HongKong] = Color::Red;
        CityColor[City::Istanbul] = Color::Black;
        CityColor[City::Jakarta] = Color::Red;
        CityColor[City::Johannesburg] = Color::Yellow;
        CityColor[City::Karachi] = Color::Black;
        CityColor[City::Khartoum] = Color::Yellow;
        CityColor[City::Kinshasa] = Color::Yellow;
        CityColor[City::Kolkata] = Color::Black;
        CityColor[City::Lagos] = Color::Yellow;
        CityColor[City::Lima] = Color::Yellow;
        CityColor[City::London] = Color::Blue;
        CityColor[City::LosAngeles] = Color::Yellow;
        CityColor[City::Madrid] = Color::Blue;
        CityColor[City::Manila] = Color::Red;
        CityColor[City::MexicoCity] = Color::Yellow;
        CityColor[City::Miami] = Color::Yellow;
        CityColor[City::Milan] = Color::Blue;
        CityColor[City::Montreal] = Color::Blue;
        CityColor[City::Moscow] = Color::Black;
        CityColor[City::Mumbai] = Color::Black;
        CityColor[City::NewYork] = Color::Blue;
        CityColor[City::Osaka] = Color::Red;
        CityColor[City::Paris] = Color::Blue;
        CityColor[City::Riyadh] = Color::Black;
        CityColor[City::SanFrancisco] = Color::Blue;
        CityColor[City::Santiago] = Color::Yellow;
        CityColor[City::SaoPaulo] = Color::Yellow;
        CityColor[City::Seoul] = Color::Red;
        CityColor[City::Shanghai] = Color::Red;
        CityColor[City::StPetersburg] = Color::Blue;
        CityColor[City::Sydney] = Color::Red;
        CityColor[City::Taipei] = Color::Red;
        CityColor[City::Tehran] = Color::Black;
        CityColor[City::Tokyo] = Color::Red;
        CityColor[City::Washington] = Color::Blue;

        //RoadMap
        RoadMap[City::Algiers] = {City::Madrid, City::Paris, City::Istanbul, City::Cairo};
        RoadMap[City::Atlanta] = {City::Chicago, City::Miami, City::Washington};
        RoadMap[City::Baghdad] = {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi};
        RoadMap[City::Bangkok] = {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong};
        RoadMap[City::Beijing] = {City::Shanghai, City::Seoul};
        RoadMap[City::Bogota] = {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires};
        RoadMap[City::BuenosAires] = {City::Bogota, City::SaoPaulo};
        RoadMap[City::Cairo] = {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh};
        RoadMap[City::Chennai] = {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta};
        RoadMap[City::Chicago] = {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal};
        RoadMap[City::Delhi] = {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata};
        RoadMap[City::Essen] = {City::London, City::Paris, City::Milan, City::StPetersburg};
        RoadMap[City::HoChiMinhCity] = {City::Jakarta, City::Bangkok, City::HongKong, City::Manila};
        RoadMap[City::HongKong] = {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei};
        RoadMap[City::Istanbul] = {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow};
        RoadMap[City::Jakarta] = {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney};
        RoadMap[City::Johannesburg] = {City::Kinshasa, City::Khartoum};
        RoadMap[City::Karachi] = {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi};
        RoadMap[City::Khartoum] = {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg};
        RoadMap[City::Kinshasa] = {City::Lagos, City::Khartoum, City::Johannesburg};
        RoadMap[City::Kolkata] = {City::Delhi, City::Chennai, City::Bangkok, City::HongKong};
        RoadMap[City::Lagos] = {City::SaoPaulo, City::Khartoum, City::Kinshasa};
        RoadMap[City::Lima] = {City::MexicoCity, City::Bogota, City::Santiago};
        RoadMap[City::London] = {City::NewYork, City::Madrid, City::Essen, City::Paris};
        RoadMap[City::LosAngeles] = {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney};
        RoadMap[City::Madrid] = {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers};
        RoadMap[City::Manila] = {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong};
        RoadMap[City::MexicoCity] = {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota};
        RoadMap[City::Miami] = {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota};
        RoadMap[City::Milan] = {City::Essen, City::Paris, City::Istanbul};
        RoadMap[City::Montreal] = {City::Chicago, City::Washington, City::NewYork};
        RoadMap[City::Moscow] = {City::StPetersburg, City::Istanbul, City::Tehran};
        RoadMap[City::Mumbai] = {City::Karachi, City::Delhi, City::Chennai};
        RoadMap[City::NewYork] = {City::Montreal, City::Washington, City::London, City::Madrid};
        RoadMap[City::Osaka] = {City::Taipei, City::Tokyo};
        RoadMap[City::Paris] = {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London};
        RoadMap[City::Riyadh] = {City::Baghdad, City::Cairo, City::Karachi};
        RoadMap[City::SanFrancisco] = {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila};
        RoadMap[City::Santiago] = {City::Lima};
        RoadMap[City::SaoPaulo] = {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid};
        RoadMap[City::Seoul] = {City::Beijing, City::Shanghai, City::Tokyo};
        RoadMap[City::Shanghai] = {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo};
        RoadMap[City::StPetersburg] = {City::Essen, City::Istanbul, City::Moscow};
        RoadMap[City::Sydney] = {City::Jakarta, City::Manila, City::LosAngeles};
        RoadMap[City::Taipei] = {City::Shanghai, City::HongKong, City::Osaka, City::Manila};
        RoadMap[City::Tehran] = {City::Baghdad, City::Moscow, City::Karachi, City::Delhi};
        RoadMap[City::Tokyo] = {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco};
        RoadMap[City::Washington] = {City::Atlanta, City::NewYork, City::Montreal, City::Miami};
    }

}