#ifndef convertTime_h
#define convertTime_h


#include <iostream>


struct humanDate {

    int year=1970;      // since timestamp started to be used

    int month=1;

    int day=1;

    int hour=0;

    int minute=0;
};

int judgeMonth(int currentYear, long long int& daysInSeconds);

humanDate convertTimeStamp(long long int sample);


#endif
