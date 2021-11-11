#ifndef TRIP_OVERVIEW_H
#define TRIP_OVERVIEW_H

#include <vector>
#include "Trip.cpp"
#include "TravelTime.cpp"

class TripOverview{
private:
  Trip userTrip;
  std::vector< Trip > dataArray;

public:
  TripOverview(Trip userTrip, std::vector< Trip > data);

  TravelTime calcCheapestTime(std::vector<Trip>);

};

#endif