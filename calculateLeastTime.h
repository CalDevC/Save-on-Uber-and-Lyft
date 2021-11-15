#ifndef calculateLeastTime_h
#define calculateLeastTime_h


#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "ConvertTime.h"

void sortVector(std::vector<humanDate> listOfDates);

void calculateLeastTime();

struct dateAndFreq {

	humanDate testDate;

	int freq = 1;

};

