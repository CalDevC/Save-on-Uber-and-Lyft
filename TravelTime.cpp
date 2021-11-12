#include "TravelTime.h"

//Constructor
TravelTime::TravelTime(int startingHour, int endingHour, std::string weekDay): startingHour(startingHour), endingHour(endingHour), weekDay(weekDay){}

//Accessors
int TravelTime::getStartingHour(){
  return startingHour;
}

int TravelTime::getEndingHour(){
  return endingHour;
}

std::string TravelTime::getWeekDay(){
  return weekDay;
}


//Mutators
void TravelTime::setStartingHour(int startingHour){
  this->startingHour = startingHour;
}

void TravelTime::setEndingHour(int endingHour){
  this->endingHour = endingHour;
}

void TravelTime::setWeekDay(std::string weekDay){
  this->weekDay = weekDay;
}

