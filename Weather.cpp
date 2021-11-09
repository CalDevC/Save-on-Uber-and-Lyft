#include "Weather.h"

Weather::Weather(std::string location,double rainInches,std::string Timestamp)
{
    this->location=location;
    this->rainInches=rainInches;
    this->Timestamp=Timestamp;
}

std::string Weather::GetLocation()
{
    return location;
}

double Weather::GetRainInches()
{
    return rainInches;
}

std::string Weather::GetTimestamp()
{
    return Timestamp;
}