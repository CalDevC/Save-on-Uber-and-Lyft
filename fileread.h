

#ifndef fileread_h
#define fileread_h

#include <stdio.h>
#include "Trip.h"
#include "Weather.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
std::vector<Trip> read_file_into_trip(std::string fileName);
std::vector<Weather> read_file_into_weather(std::string fileName);
#endif 