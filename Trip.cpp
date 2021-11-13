#include "Trip.h"

Trip::Trip(std::string id, std::string source, std::string destination, std::string company, std::string time, double price, bool isRaining) :
   tripId(id), sourceLoc(source), destination(destination), company(company), timeStamp(time), price(price), isRaining(isRaining) {
}

Trip::~Trip() {
   //Any needed clean up
}

//Member functions
std::string translateTime(std::string) {
   return "";
}

//Accessors
std::string Trip::getTripId() {
   return tripId;
}

std::string Trip::getSourceLoc() {
   return sourceLoc;
}

std::string Trip::getDestination() {
   return destination;
}

std::string Trip::getCompany() {
   return company;
}

std::string Trip::getTimeStamp() {
   return timeStamp;
}

double Trip::getPrice() {
   return price;
}

bool Trip::getIsRaining() {
   return isRaining;
}


//Mutators
void Trip::setTripId(std::string tripId) {
   this->tripId = tripId;
}

void Trip::setSourceLoc(std::string sourceLoc) {
   this->sourceLoc = sourceLoc;
}

void Trip::setDestination(std::string destination) {
   this->destination = destination;
}

void Trip::setCompany(std::string company) {
   this->company = company;
}

void Trip::setTimeStamp(std::string timeStamp) {
   this->timeStamp = timeStamp;
}

void Trip::setPrice(double price) {
   this->price = price;
}

void Trip::setIsRaining(bool isRaining) {
   this->isRaining = isRaining;
}