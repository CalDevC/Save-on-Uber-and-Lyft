
#include "TripOverview.cpp"
#include <string>
#include <iostream>
#include "fileread.cpp"
#include "FilterData.h"

int main() {

   std::string sourceLoc, destinationLoc;
   double lowerRange, higherRange;
   char selection;

   std::cout << "Start Program Execution" << "\n";
   std::cout << "Enter your location: ";
   getline(std::cin, sourceLoc);
   std::cout << "Enter your destination: ";
   getline(std::cin, destinationLoc);
   std::cout << "Choose weather option from below:\na. no rain\nb. light rain\nc. moderate rain\nd. heavy rain\n";

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

   /*
   ///////////?REMOVE//////////////////////
   sourceLoc = "Haymarket Square";
   destinationLoc = "North Station";
   lowerRange = 0.000;
   higherRange = 0.000;
   ///////////?REMOVE//////////////////////
   */



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

   std::cout << "Calculating your trip overview..." << std::endl;
   //Calculate Trip overview
   TripOverview overview = TripOverview(userTrip, filteredData);
   TravelTime cheapTime = overview.calcCheapestTravelTime();

   //outputting results of trip overview 
   std::cout << "\n\nOverall Trip Analysis:" << std::endl
             << filteredData.size() << " data points found..." << std::endl
             << "Least expensive travel time:" << std::endl
             << cheapTime.getStartingHour() << "-"
             << cheapTime.getEndingHour() << "EST" << std::endl;

}
