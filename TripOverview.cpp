#define _GLIBCXX_USE_CXX11_ABI 0
#include "TripOverview.h"
#include <ctime>
#include <map>


TripOverview::TripOverview(Trip userTrip, std::vector< Trip > data) : userTrip(userTrip), dataArray(data) {}

TravelTime TripOverview::calcCheapestTravelTime() {
   std::vector< Trip > data = dataArray;
   const int NUM_PIECES = 5;
   std::vector< std::vector<Trip> > timeIncArray(24);

   for (int i = 0; i < data.size(); i++) {
      Trip currentTrip = data.at(i);

      //Set new time
      std::string time = convertTime(
         FilterData::GetTimeStampNumber(
            currentTrip.getTimeStamp()
         )
      );

      std::string timePieces[NUM_PIECES];

      for (int j = 0; j < NUM_PIECES; j++) {
         size_t pos = time.find(" ");
         timePieces[j] = time.substr(0, pos);
         time.erase(0, pos + 1);
      }

      int hour = stoi(timePieces[3].substr(0, timePieces[3].find(":")));
      timeIncArray[hour].push_back(currentTrip);

   }

   //Get averages of each hour
   std::vector<double> avgs = computeAvgs(timeIncArray, 24);

   //Determine cheapest hour
   int cheapestHour = 0;

   for (int i = 1; i < 24; i++) {
      if (avgs[i] < avgs[cheapestHour])
         cheapestHour = i;
   }

   //Determine which day of the week is cheapest
   std::cout << "Determining best day..." << std::endl;
   std::map<std::string, int> dayMap;
   dayMap["Mon"] = 0;
   dayMap["Tue"] = 1;
   dayMap["Wed"] = 2;
   dayMap["Thu"] = 3;
   dayMap["Fri"] = 4;
   dayMap["Sat"] = 5;
   dayMap["Sun"] = 6;

   std::vector<Trip> bestTimeVec = timeIncArray.at(cheapestHour);
   std::vector< std::vector<Trip> > daysVec(7);

   // for (int i = 0; i < bestTimeVec.size(); i++) {
   //    Trip currentTrip = bestTimeVec.at(i);

   //    //adjust time
   //    std::string time = convertTime(
   //       FilterData::GetTimeStampNumber(
   //          currentTrip.getTimeStamp()
   //       )
   //    );

   //    std::string day = time.substr(0, time.find(" "));
   //    daysVec.at(dayMap[day]).push_back(currentTrip);

   // }

   // std::vector<double> dayAvgs = computeAvgs(daysVec, 7);

   // //Determine cheapest day
   // int cheapestDayNum = 0;

   // for (int i = 1; i < daysVec.size(); i++) {
   //    if (dayAvgs.at(i) < dayAvgs.at(cheapestHour)) {
   //       cheapestDayNum = i;
   //    }
   // }

   // std::string cheapestDay;

   // // Traverse the map to find the string associated with the day number
   // for (std::map<std::string, int>::iterator iter = dayMap.begin(); iter != dayMap.end(); iter++) {
   //    if (iter->second == cheapestDayNum) {
   //       cheapestDay = iter->first;
   //       break;
   //    }
   // }

   TravelTime t = TravelTime(cheapestHour, cheapestHour + 1, "Mon");
   return t;

}

std::vector<double> TripOverview::computeAvgs(const std::vector< std::vector<Trip> > allTripVecs, int avgVecSize) {
   std::vector<double> avgs(avgVecSize);

   //For every 1 element in the averages array
   for (int i = 0; i < allTripVecs.size(); i++) {
      std::vector<Trip> tripVec = allTripVecs.at(i);

      //If vector at current hour is not empty
      if (!tripVec.empty()) {
         //Get sum of the vector
         double sum = 0.0;
         for (int j = 0; j < tripVec.size(); j++) {
            sum += tripVec.at(j).getPrice();
         }

         avgs[i] = sum / tripVec.size();
      }
      else {
         avgs[i] = 10000.0; //If empty avg cost is -1
      }
   }

   return avgs;
}

void TripOverview::TripOutput(){
   std::cout << "Overall Trip Analysis:" << std::endl; 
   /*std::cout << "Least expensive hour: " << cheapestHour << std::endl;
   std::cout << "Least expensive day: " << cheapestDay << endl; 
   std::cout << "Best time to travel: " << cheapestDay << " at " cheapestHour << ":00" << endl; 
   std::cout << "Averages for each hour: " << endl; 
   for(int i = 0; i < avgVecSize; i++){
    std::cout << avgs[i] << endl;   
   }
   std::cout << "Most cost effective trip: " << currentTrip << endl; */
}

std::string TripOverview::convertTime(long long int epochTimeInMS) {
   //Convert milliseconds to seconds and subtract 18000 to convert from GMT to EST
   long long int timeInSeconds = (epochTimeInMS * 0.001) - 18000;
   time_t t = timeInSeconds;
   std::string test = asctime(gmtime(&t));
   return test;
}
