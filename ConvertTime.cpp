#include "ConvertTime.h"


int judgeMonth(int currentYear,  long long int& daysInSeconds) {

	int month = 1;

	int days = daysInSeconds / 86400;

	if (currentYear % 4 == 0) {

	if ( (31 < days ) && (days<= 60) ) {

		month = 2;
		daysInSeconds -= (31 * 86400);
	}

	else if ( (60 < days) && (days <= 91)) {

		month = 3;
		daysInSeconds -= (60 * 86400);
	}

	else if ( (91 < days) && (days<= 121)) {

		month = 4;
		daysInSeconds -= (91 * 86400);
	}

	else if ( (121 < days) && (days <= 152)) {

		month = 5;
		daysInSeconds -= (121 * 86400);
	}

	else if ( (152 < days) && (days <= 182) ){

		month = 6;
		daysInSeconds -= (152 * 86400);
	}

	else if ( (182 < days) && (days <= 213)) {

		month = 7;
		daysInSeconds -= (182 * 86400);
	}

	else if ( (213 < days) && (days <= 244)) {

		month = 8;
		daysInSeconds -= (213 * 86400);
	}

	else if ( (244 < days ) && (days<= 274)) {

		month = 9;
		daysInSeconds -= (244 * 86400);
	}

	else if ( (274 < days) && (days <= 305)) {

		month = 10;
		daysInSeconds -= (274 * 86400);
	}

	else if ( (305 < days)&& (days <= 335)) {

		month = 11;
		daysInSeconds -= (305 * 86400);
	}

	else if ( (335 < days) && (days <= 366)) {

		month = 12;
		daysInSeconds -= (335 * 86400);
	}


}

	else {

			if (  (31 < days) && (days <= 59)) {

				month = 2;
				daysInSeconds -= (31 * 86400);
			}

			else if ( (59 < days)&& ( days<= 90) ){

				month = 3;
				daysInSeconds -= (59 * 86400);
			}

			else if ( (90 < days) && (days <= 120)) {

				month = 4;
				daysInSeconds -= (90 * 86400);
			}

			else if (  (120 < days) && (days<= 151)) {

				month = 5;
				daysInSeconds -= (120 * 86400);
			}

			else if ( (151 < days) && (days <= 181)) {

				month = 6;
				daysInSeconds -= (151 * 86400);
			}

			else if (  (181 < days) && (days <= 212)) {

				month = 7;
				daysInSeconds -= (181 * 86400);
			}

			else if (  (212 < days) && (days <= 243)) {

				month = 8;
				daysInSeconds -= (212 * 86400);
			}

			else if ( (243 < days) && (days <= 273)) {

				month = 9;
				daysInSeconds -= (243 * 86400);
			}

			else if ( (273 < days) && (days <= 303)) {

				month = 10;
				daysInSeconds -= (273 * 86400);
			}

			else if ( (303 < days) &&(days <= 333) ){

				month = 11;
				daysInSeconds -= (304 * 86400);
			}

			else if ( (333 < days) && (days <= 364)) {       //since the element day already has a value of 1

				month = 12;
				daysInSeconds -= (334 * 86400);
			}


	}

	return month;
}

humanDate convertTimeStamp(long long int sample) {

	humanDate sampleDate;

	sample /= 1000;             //remove last 3 digits for miliseconds

	int a = sample / 31536000;   //divide by a year in seconds

	int currentYear = 1970 + a;

	int leap = 86400 * a / 4;      //subtract for extra days for leap years in past

	sample -= leap;

	sample = sample % 31536000;

	int b = judgeMonth(currentYear, sample);

	int c = sample / 86400;  //divide by a day in seconds

	sample = sample % 86400;

	int d = sample / 3600;  //divide by an hour in seconds

	sample = sample % 3600;

	int e = sample / 60;  //divide by a minute in seconds



	sampleDate.year += a;
	sampleDate.month = b;
	sampleDate.day += c;
	sampleDate.hour += d;
	sampleDate.minute += e;


	return sampleDate;

}
