#ifndef TRIP_OVERVIEW_H
#define TRIP_OVERVIEW_H

#include <vector>
#include "TravelTime.cpp"
#include "FilterData.cpp"

class TripOverview{
private:
  Trip userTrip;
  std::vector< Trip > dataArray;

public:

  TripOverview(Trip userTrip, std::vector< Trip > data);

  double* computeAvgs(const std::vector<Trip>*);

  TravelTime calcCheapestTime(std::vector<Trip>);

  std::string convertTime(long long int);

};

#endif