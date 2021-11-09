#ifndef FILTERDATA_H
#define FILTERDATA_H

#include<string.h>
#include<Trip.h>
#include <vector>
#include <algorithm>
#include <cctype>

namespace FilterData
{
    std::vector<Trip> FilterTrips(const std::string sourceLocation,const std::string DestinationLocation,std::vector<Trip> Trips);
    std::string ltrim(const std::string &s);
    std::string rtrim(const std::string &s);
    std::string trimString(const std::string &s);
    std::string ConvertToLower(std::string &s);
}

#endif