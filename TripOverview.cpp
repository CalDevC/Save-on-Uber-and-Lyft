#define _GLIBCXX_USE_CXX11_ABI 0
#include "TripOverview.h"
#include <ctime>


TripOverview::TripOverview(Trip userTrip, std::vector< Trip > data): userTrip(userTrip), dataArray(data){}

TravelTime TripOverview::calcCheapestTime(std::vector< Trip > data){
  /*
  For each trip in the trip vector:
    Group trips by 1 hour increments
  
  Take the average cost from each time group

  Return the 1 hour time period with the highest average
  */

 //Array of arrays
 std::vector<Trip> TimeIncArray[24];

  for(int i = 0; i < data.size(); i++){
    Trip currentTrip = data.at(i);

    //Set new time
    currentTrip.setTimeStamp(
      convertTime(
        FilterData::GetTimeStampNumber(
          currentTrip.getTimeStamp()
        )
      )
    );


  }

  TravelTime t = TravelTime(1, 2, "Mon");
  return t;
  
}

std::string TripOverview::convertTime(long long int epochTimeInMS){
  //Convert milliseconds to seconds and subtract 18000 to convert from GMT to EST
  long long int timeInSeconds = (epochTimeInMS * 0.001) - 18000;
  time_t t = timeInSeconds;
  std::string test = asctime(gmtime(&t));
  return test;
}