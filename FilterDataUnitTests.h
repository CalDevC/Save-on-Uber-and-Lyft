#ifndef FILTERDATAUNITTESTS
#define FILTERDATAUNITTESTS

#include "vector"
#include "Trip.h"
#include "Weather.h"
#include "FilterData.h"

namespace FilterDataUnitTests{
    bool FilterTripsTest1(const std::string sourceLocation, const std::string DestinationLocation, std::vector<Trip> Trips);
    bool FilterTripsTest2(const std::string sourceLocation, const std::string DestinationLocation, std::vector<Trip> Trips);
    bool FilterTripsTest3(const std::string sourceLocation, const std::string DestinationLocation, std::vector<Trip> Trips);
    bool FilterWeatherTest1(const std::string sourceLocation, const std::string DestinationLocation, const double lowerRange, const double higherRange, std::vector<Weather> WeatherData);
    bool FilterWeatherTest2(const std::string sourceLocation, const std::string DestinationLocation, const double lowerRange, const double higherRange, std::vector<Weather> WeatherData);
    bool FilterWeatherTest3(const std::string sourceLocation, const std::string DestinationLocation, const double lowerRange, const double higherRange, std::vector<Weather> WeatherData);
}

#endif