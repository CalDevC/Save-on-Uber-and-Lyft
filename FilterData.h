#ifndef FILTERDATA_H
#define FILTERDATA_H

#include <string>
#include "Trip.cpp"
#include "Weather.cpp"
#include <vector>
#include <algorithm>
#include <cctype>
#include <math.h>
#include "iostream"
#include "map"

namespace FilterData {
   std::vector<Trip> FilterTrips(const std::string sourceLocation, const std::string DestinationLocation, std::vector<Trip> Trips);
   std::string ltrim(const std::string& s);
   std::string rtrim(const std::string& s);
   std::string trimString(const std::string& s);
   std::string ConvertToLower(std::string& s);
   std::vector<Weather> FilterWeatherData(const std::string sourceLocation, const std::string DestinationLocation, const double lowerRange, const double higherRange, std::vector<Weather> WeatherData);
   std::vector<Trip> MatchTripsWithWeather(std::vector<Trip> FilteredTrips, std::vector<Weather> FilteredWeather);
   long long int GetTimeStampNumber(std::string StringTimeStamp);
}

#endif