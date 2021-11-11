#include "TripOverview.h"
#include <ctime>


TripOverview::TripOverview(Trip userTrip, std::vector< Trip > data): userTrip(userTrip), dataArray(data){}

TravelTime TripOverview::calcCheapestTime(std::vector< Trip >){
  /*
  For each trip in the trip vector:
    Group trips by 1 hour increments
  
  Take the average cost from each time group

  Return the 1 hour time period with the highest average
  */

  
}

std::string convertTime(long long int epochTimeInMS){
  //Convert milliseconds to seconds and subtract 18000 to convert from GMT to EST
  long long int timeInSeconds = (epochTimeInMS * 0.001) - 18000;
  time_t t = timeInSeconds;
  return asctime(gmtime(&t));
}