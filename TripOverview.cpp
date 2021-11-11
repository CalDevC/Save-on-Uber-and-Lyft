#include "TripOverview.h"


TripOverview::TripOverview(Trip userTrip, std::vector< Trip > data): userTrip(userTrip), dataArray(data){}

TravelTime TripOverview::calcCheapestTime(std::vector< Trip >){
  /*
  For each trip in the trip vector:
    Group trips by 1 hour increments
  
  Take the average cost from each time group

  Return the 1 hour time period with the highest average
  */

  

  
}