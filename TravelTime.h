#ifndef TRAVEL_TIME_H
#define TRAVEL_TIME_H

#include <string>

class TravelTime{
private:
  int startingHour;
  int endingHour;
  std::string weekDay;

public:
  TravelTime(int, int, std::string);

  //Accessors
  int getStartingHour();
  int getEndingHour();
  std::string getWeekDay();

  //Mutators
  void setStartingHour(int);
  void setEndingHour(int);
  void setWeekDay(std::string);

};

#endif