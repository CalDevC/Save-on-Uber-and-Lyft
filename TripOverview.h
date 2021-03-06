#ifndef TRIP_OVERVIEW_H
#define TRIP_OVERVIEW_H

#include <vector>
#include "TravelTime.cpp"
#include "FilterData.cpp"

class TripOverview {
private:
   Trip userTrip;
   std::vector< Trip > dataArray;

public:

   TripOverview(Trip userTrip, std::vector< Trip > data);

   std::vector<double> computeAvgs(const std::vector< std::vector<Trip> > allTripVecs, int avgVecSize);

   TravelTime calcCheapestTravelTime();

   std::string convertTime(long long int);
   
   void TripOutput(); 

};

#endif
