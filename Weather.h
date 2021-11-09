#ifndef WEATHER_H
#define WEATHER_H

#include <string>

class Weather{
    private:
    std::string location;
    double rainInches;
    std::string Timestamp;
    public:
    Weather(std::string location,double rainInches,std::string Timestamp);
    ~Weather();
    std::string GetLocation();
    double GetRainInches(); 
    std::string GetTimestamp();

};

#endif