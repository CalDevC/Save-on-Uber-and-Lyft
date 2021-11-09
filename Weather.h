#ifndef WEATHER_H
#define WEATHER_H

#include <string>

class Weather{
    private:
    std::string location;
    double rainInches;
    public:
    Weather();
    ~Weather();
    std::string GetLocation();
    double GetRainInches(); 
};

#endif