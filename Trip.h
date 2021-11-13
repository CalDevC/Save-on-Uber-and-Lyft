#ifndef TRIP_H
#define TRIP_H

#include <string>

class Trip {
private:
   std::string tripId;
   std::string sourceLoc;
   std::string destination;
   std::string company;
   std::string timeStamp;
   double price;
   bool isRaining;

public:
   //Constructor and Destructor
   Trip(std::string id, std::string source, std::string destination, std::string company, std::string timeStamp, double price, bool isRaining);
   ~Trip();

   //Member functions
   std::string translateTime(std::string);

   //Accessors
   std::string getTripId();
   std::string getSourceLoc();
   std::string getDestination();
   std::string getCompany();
   std::string getTimeStamp();
   double getPrice();
   bool getIsRaining();

   //Mutators
   void setTripId(std::string);
   void setSourceLoc(std::string);
   void setDestination(std::string);
   void setCompany(std::string);
   void setTimeStamp(std::string);
   void setPrice(double);
   void setIsRaining(bool);
};

#endif