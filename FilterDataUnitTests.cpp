#include "FilterDataUnitTests.h"

namespace FilterDataUnitTests
{
    bool FilterTripsTest1(const std::string sourceLocation, const std::string DestinationLocation, std::vector<Trip> Trips)
    {
        std::vector<Trip> resultData= FilterData::FilterTrips(sourceLocation,DestinationLocation,Trips);
        for(int i=0;i<resultData.size();i++)
        {
            if(!(resultData[i].getSourceLoc()=="Haymarket Square" && resultData[i].getDestination()=="North Station"))
            {
                return false;
            }
        }
        return true;
    }

    bool FilterTripsTest2(const std::string sourceLocation, const std::string DestinationLocation, std::vector<Trip> Trips)
    {
        std::vector<Trip> resultData= FilterData::FilterTrips(sourceLocation,DestinationLocation,Trips);
        for(int i=0;i<resultData.size();i++)
        {
            if(!(resultData[i].getSourceLoc()=="Back Bay" && resultData[i].getDestination()=="Northeastern University"))
            {
                return false;
            }
        }
        return true;
    }

    bool FilterTripsTest3(const std::string sourceLocation, const std::string DestinationLocation, std::vector<Trip> Trips)
    {
        std::vector<Trip> resultData= FilterData::FilterTrips(sourceLocation,DestinationLocation,Trips);
        for(int i=0;i<resultData.size();i++)
        {
            if(!(resultData[i].getSourceLoc()=="North End" && resultData[i].getDestination()=="West End"))
            {
                return false;
            }
        }
        return true;
    }

    bool FilterWeatherTest1(const std::string sourceLocation, const std::string DestinationLocation, const double lowerRange, const double higherRange, std::vector<Weather> WeatherData)
    {
        std::vector<Weather> resultData = FilterData::FilterWeatherData(sourceLocation,DestinationLocation,lowerRange,higherRange,WeatherData);
        for(int i=0;i<resultData.size();i++)
        {
            if(!((resultData[i].GetLocation()=="North End" || resultData[i].GetLocation()=="West End") && (resultData[i].GetRainInches()>=lowerRange && resultData[i].GetRainInches()<higherRange)))
            {
                return false;
            }
        }
        return true;
    }

    bool FilterWeatherTest2(const std::string sourceLocation, const std::string DestinationLocation, const double lowerRange, const double higherRange, std::vector<Weather> WeatherData)
    {
        std::vector<Weather> resultData = FilterData::FilterWeatherData(sourceLocation,DestinationLocation,lowerRange,higherRange,WeatherData);
        for(int i=0;i<resultData.size();i++)
        {
            if(!((resultData[i].GetLocation()=="Haymarket Square" || resultData[i].GetLocation()=="North Station") && (resultData[i].GetRainInches()>=lowerRange && resultData[i].GetRainInches()<higherRange)))
            {
                return false;
            }
        }
        return true;
    }

    bool FilterWeatherTest3(const std::string sourceLocation, const std::string DestinationLocation, const double lowerRange, const double higherRange, std::vector<Weather> WeatherData)
    {
        std::vector<Weather> resultData = FilterData::FilterWeatherData(sourceLocation,DestinationLocation,lowerRange,higherRange,WeatherData);
        for(int i=0;i<resultData.size();i++)
        {
            if(!((resultData[i].GetLocation()=="Back Bay" || resultData[i].GetLocation()=="Northeastern University") && (resultData[i].GetRainInches()>=lowerRange && resultData[i].GetRainInches()<higherRange)))
            {
                return false;
            }
        }
        return true;
    }
}