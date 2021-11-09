#include "FilterData.h"
const std::string WHITESPACE = " \n\r\t\f\v";

std::vector<Trip> FilterTrips(const std::string sourceLocation,const std::string DestinationLocation,std::vector<Trip> Trips)
{
    std::vector<Trip> resultData;
    std:: string trimmedSourceLocation = trimString(sourceLocation);
    std::string resultSourceLocation = ConvertToLower(trimmedSourceLocation);
    std::string trimmedDestinationLocation = trimString(DestinationLocation);
    std::string resultDestinationLocation = ConvertToLower(trimmedDestinationLocation); 
    for(int i=0;i<Trips.size();i++)
    {
        if(Trips[i].getSourceLoc()==resultSourceLocation && Trips[i].getDestination()==resultDestinationLocation)
        {
            resultData.push_back(Trips[i]);
        }
    }
    return resultData;
}

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trimString(const std::string &s) {
    return rtrim(ltrim(s));
}

std::string ConvertToLower(std::string &s)
{
    std::string resultString ="";
    for (int i = 0; i < s.length(); i++)
  	{
  		resultString+=tolower(s[i]);
  	}
    return resultString;
}

std::vector<Weather> FilterWeatherData(const std::string sourceLocation,const std::string DestinationLocation,const double lowerRange,const double higherRange,std::vector<Weather> WeatherData)
{
    std::vector<Weather> resultData;
    std:: string trimmedSourceLocation = trimString(sourceLocation);
    std::string resultSourceLocation = ConvertToLower(trimmedSourceLocation);
    std::string trimmedDestinationLocation = trimString(DestinationLocation);
    std::string resultDestinationLocation = ConvertToLower(trimmedDestinationLocation); 
    for(int i=0;i<WeatherData.size();i++)
    {
        if((WeatherData[i].GetLocation()==resultSourceLocation || WeatherData[i].GetLocation()==resultDestinationLocation) && (WeatherData[i].GetRainInches()>=lowerRange || WeatherData[i].GetRainInches()<higherRange))
        {
            resultData.push_back(WeatherData[i]);
        }
    }
    return resultData;
}