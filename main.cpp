
#include "TripOverview.cpp"
#include <string>
#include <iostream>
#include "fileread.cpp"
#include "FilterData.h"

int main() {
   Trip a = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1544952607890", 5.0, false);
   Trip b = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1543805278271", 15.0, false);
   Trip c = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1545098110455", 10.0, false);
   Trip d = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1545098110455", 25.0, false);
   Trip e = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1545098110455", 20.0, false);
   Trip f = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1544952607890", 10.0, false);

   std::vector<Trip> data;
   data.push_back(a);
   data.push_back(b);
   data.push_back(c);
   data.push_back(d);
   data.push_back(e);
   data.push_back(f);

   TripOverview overview = TripOverview(a, data);

   overview.calcCheapestTravelTime(data);

   std::cout<<"Start Program Execution"<<"\n";

   std::vector<Trip> TripData = read_file_into_trip("cab_rides.csv");
   std::vector<Weather> WeatherData = read_file_into_weather("weather.csv");

   /*for(int i=0;i<TripData.size();i++)
   {
      std::cout<<TripData[i].getCompany()<<" "<<TripData[i].getDestination()<<" "<<TripData[i].getIsRaining()<<" "<<TripData[i].getPrice()<<" "<<TripData[i].getSourceLoc()<<" "<<TripData[i].getTimeStamp()<<" "<<TripData[i].getTripId()<<"\n";
   }

   for(int i=0;i<WeatherData.size();i++)
   {
      std::cout<<WeatherData[i].GetLocation()<<" "<<WeatherData[i].GetRainInches()<<" "<<WeatherData[i].GetTimestamp()<<"\n";
   }*/

   std::vector<Trip> FilteredTrips = FilterData::FilterTrips("  West end   ","   North End    ",TripData);
   /*for(int i=0;i<FilteredTrips.size();i++)
   {
      std::cout<<FilteredTrips[i].getCompany()<<" "<<FilteredTrips[i].getDestination()<<" "<<FilteredTrips[i].getIsRaining()<<" "<<FilteredTrips[i].getPrice()<<" "<<FilteredTrips[i].getSourceLoc()<<" "<<FilteredTrips[i].getTimeStamp()<<" "<<FilteredTrips[i].getTripId()<<"\n";  
   }*/
   std::vector<Weather> FillteredWeather = FilterData::FilterWeatherData("west end","North end",0,0,WeatherData);
   /*for(int i=0;i<FillteredWeather.size();i++)
   {
      std::cout<<FillteredWeather[i].GetLocation()<<" "<<FillteredWeather[i].GetRainInches()<<" "<<FillteredWeather[i].GetTimestamp()<<"\n";
   }*/

   std::vector<Trip> ResultTrips = FilterData::MatchTripsWithWeather(FilteredTrips,FillteredWeather);
   for(int i=0;i<ResultTrips.size();i++)
   {
      std::cout<<ResultTrips[i].getCompany()<<" "<<ResultTrips[i].getDestination()<<" "<<ResultTrips[i].getIsRaining()<<" "<<ResultTrips[i].getPrice()<<" "<<ResultTrips[i].getSourceLoc()<<" "<<ResultTrips[i].getTimeStamp()<<" "<<ResultTrips[i].getTripId()<<"\n";  
   }
}
