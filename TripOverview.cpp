#define _GLIBCXX_USE_CXX11_ABI 0
#include "TripOverview.h"
#include <ctime>


TripOverview::TripOverview(Trip userTrip, std::vector< Trip > data): userTrip(userTrip), dataArray(data){}

TravelTime TripOverview::calcCheapestTime(std::vector< Trip > data){

  //Array of arrays
  const int NUM_PIECES = 5;
  std::vector<Trip> timeIncArray[24];

  for(int i = 0; i < data.size(); i++){
    Trip currentTrip = data.at(i);

    //Set new time
    std::string time = convertTime(
      FilterData::GetTimeStampNumber(
        currentTrip.getTimeStamp()
      )
    );

    std::string timePieces[NUM_PIECES];

    for(int j = 0; j < NUM_PIECES; j++){
      size_t pos = time.find(" ");
      timePieces[j] = time.substr(0, pos);
      time.erase(0, pos + 1);
    }

    int hour = stoi(timePieces[3].substr(0, timePieces[3].find(":")));
    timeIncArray[hour].push_back(currentTrip);

  }

  //Get averages of each hour
  double* avgs = computeAvgs(timeIncArray);

  //Determine cheapest hour
  int cheapestHour = 0;

  for(int i = 1; i < 24; i++){
      if(avgs[i] < avgs[cheapestHour])
          cheapestHour = i;              
  }

  TravelTime t = TravelTime(cheapestHour, cheapestHour + 1, "Mon");

  return t;
  
}

double* TripOverview::computeAvgs(const std::vector<Trip>* tripVecArr){
  double* avgs = new double[24];

  //For every 1 element in the averages array
  for(int i = 0; i < 24; i++){
    std::vector<Trip> tripVec = tripVecArr[i];

    //If vector at current hour is not empty
    if(!tripVec.empty()){
      //Get sum of the vector
      double sum = 0.0;
      for(int j  = 0; j < tripVec.size(); j++){
        sum += tripVec.at(j).getPrice();
      }

      avgs[i] = sum/tripVec.size();
    }
    else{
      avgs[i] = 10000.0; //If empty avg cost is -1
    }
  }

  return avgs;
}

std::string TripOverview::convertTime(long long int epochTimeInMS){
  //Convert milliseconds to seconds and subtract 18000 to convert from GMT to EST
  long long int timeInSeconds = (epochTimeInMS * 0.001) - 18000;
  time_t t = timeInSeconds;
  std::string test = asctime(gmtime(&t));
  return test;
}