
#include "TripOverview.cpp"
#include <string>
#include <iostream>
#include "fileread.cpp"
#include "FilterData.h"

int main() {
   //Variables
   std::string sourceLoc, destinationLoc;
   double lowerRange, higherRange;
   char selection;

   //Get user input
   std::cout << "Enter your starting location: ";
   getline(std::cin, sourceLoc);
   std::cout << "Enter your destination: ";
   getline(std::cin, destinationLoc);
   std::cout << "Choose weather option from below:\na. no rain\nb. light rain\nc. moderate rain\nd. heavy rain\n";

   //Assign rain values based on user's selection
   std::cin >> selection;
   switch(selection){
      case 'a':
         lowerRange = 0;
         higherRange = 0;
         break;
      case 'b':
         lowerRange = 0.000;
         higherRange = 0.1000;
         break;
      case 'c':
         lowerRange = 0.1000;
         higherRange = 0.3000;
         break;
      case 'd':
         lowerRange = 0.3000;
         higherRange = 1.000;
         break;
      default:
         break;
   }

   //Build user's Trip
   Trip userTrip = Trip("NULL", sourceLoc, destinationLoc, "NULL", "NULL", 0.00, higherRange != 0.000);

   //Read in data from files
   std::cout << "Reading in data from files..." << std::endl;
   std::vector<Trip> TripData = read_file_into_trip("cab_rides.csv");
   std::vector<Weather> WeatherData = read_file_into_weather("weather.csv");
   
   //Filter the data based on user inputs
   std::vector<Weather> filteredWeather = FilterData::FilterWeatherData(sourceLoc, destinationLoc, lowerRange, higherRange, WeatherData);
   std::vector<Trip> filteredTrips = FilterData::FilterTrips(sourceLoc, destinationLoc, TripData);
   std::vector<Trip> filteredData = FilterData::MatchTripsWithWeather(filteredTrips, filteredWeather);
   std::cout << filteredData.size() << " data points found..." << std::endl;

   //Calculate Trip overview
   std::cout << "Calculating your trip overview..." << std::endl;
   TripOverview overview = TripOverview(userTrip, filteredData);
   TravelTime cheapTime = overview.calcCheapestTravelTime();

   //outputting results of trip overview 
   std::cout << "\n\nOverall Trip Analysis:" << std::endl
             << "Least expensive travel time:" << std::endl
             << cheapTime.getWeekDay() << " ";

   if(cheapTime.getStartingHour() > 12 ){
      cheapTime.setStartingHour(cheapTime.getStartingHour() - 12);
      std::cout << cheapTime.getStartingHour() << "PM";
   }
   else{
      if(cheapTime.getStartingHour() == 0){
         cheapTime.setStartingHour(12);
      }
      std::cout << cheapTime.getStartingHour() << "AM";
   }

   std::cout << "-";

   if(cheapTime.getEndingHour() > 12 ){
      cheapTime.setEndingHour(cheapTime.getEndingHour() - 12);
      std::cout << cheapTime.getEndingHour() << "PM";
   }
   else{
      if(cheapTime.getEndingHour() == 0){
         cheapTime.setEndingHour(12);
      }
      std::cout << cheapTime.getEndingHour() << "AM";
   }

   std::cout << std::endl;

}
