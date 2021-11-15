#include "calculateLeastTime.h"


void sortVector(std::vector<humanDate> listOfDates) {

	if (listOfDates.size() != 0) {

		dateAndFreq testFreq;

		std::vector<dateAndFreq> listOfFreq;

		for (unsigned int i = 0; i < listOfDates.size(); ++i) {           //put each element of listOfDates into new vector listOfFreq with new parameter, freq

			if (listOfFreq.size() != 0) {
				for (unsigned int j = 0; j < listOfFreq.size(); ++j) {

					if (listOfDates.at(i).hour == listOfFreq.at(j).testDate.hour) {

						listOfFreq.at(j).freq += 1;
					}

					else {

						testFreq.testDate = listOfDates.at(i);
						listOfFreq.push_back(testFreq);
					}

				}
			}

			else {

				testFreq.testDate = listOfDates.at(i);
				listOfFreq.push_back(testFreq);
			}

		}


		unsigned int i, j, minIndex;          //sort listOfFreq in ascending order

		dateAndFreq tmp;

		for (i = 0; i < listOfFreq.size() - 1; ++i) {

			minIndex = i;

			for (j = i + 1; j < listOfFreq.size(); ++j) {

				if (!(listOfFreq.at(minIndex).freq <= listOfFreq.at(j).freq)) {

					minIndex = j;                   //swap index

				}

				if (minIndex != i) {

					tmp = listOfFreq.at(i);                             //swap elements
					listOfFreq.at(i) = listOfFreq.at(minIndex);
					listOfFreq.at(minIndex) = tmp;

				}
			}
		}



		std::cout << "The hour with the least rides in  " << listOfFreq.at(0).testDate.year << " " << listOfFreq.at(0).testDate.month << "/" << listOfFreq.at(0).testDate.day << "  is  " << listOfFreq.at(0).testDate.hour << ":00  to  " << listOfFreq.at(0).testDate.hour + 1 << ":00" << std::endl;
	   }

	else {

		std::cout << "no data in the day" << std::endl;
	}

}

void calculateLeastTime() {

	std::ifstream inFS;

	long long int timeStamp;

	//inFS.open("timestamp.txt");

	//inFS.open("sample.txt");

	inFS.open("TimestampCompact.txt");

	if (!inFS.is_open()) {

		std::cout << "Could not open file." << std::endl;		
	}


	std::vector<humanDate> listOfDates26;               // Days of survey ranged from 11/26 ~ 12/18
	std::vector<humanDate> listOfDates27;
	std::vector<humanDate> listOfDates28;
	std::vector<humanDate> listOfDates29;
	std::vector<humanDate> listOfDates30;
	std::vector<humanDate> listOfDates1;
	std::vector<humanDate> listOfDates2;
	std::vector<humanDate> listOfDates3;
	std::vector<humanDate> listOfDates4;
	std::vector<humanDate> listOfDates5;
	std::vector<humanDate> listOfDates6;
	std::vector<humanDate> listOfDates7;
	std::vector<humanDate> listOfDates8;
	std::vector<humanDate> listOfDates9;
	std::vector<humanDate> listOfDates10;
	std::vector<humanDate> listOfDates11;
	std::vector<humanDate> listOfDates12;
	std::vector<humanDate> listOfDates13;
	std::vector<humanDate> listOfDates14;
	std::vector<humanDate> listOfDates15;
	std::vector<humanDate> listOfDates16;
	std::vector<humanDate> listOfDates17;
	std::vector<humanDate> listOfDates18;  

	inFS >> timeStamp;

	while (!inFS.fail()) {

		

		humanDate testDates;

		testDates = convertTimeStamp(timeStamp);

		

		//listOfDates26.push_back(testDates);

		
     	if (testDates.day == 26) {

			listOfDates26.push_back(testDates);
		}

		else if (testDates.day == 27) {

			listOfDates27.push_back(testDates);
		}

		else if (testDates.day == 28) {

			listOfDates28.push_back(testDates);
		}

		else if (testDates.day == 29) {

			listOfDates29.push_back(testDates);
		}

		else if (testDates.day == 30) {

			listOfDates30.push_back(testDates);
		}

		else if (testDates.day == 1) {

			listOfDates1.push_back(testDates);
		}

		else if (testDates.day == 2) {

			listOfDates2.push_back(testDates);
		}

		else if (testDates.day == 3) {

			listOfDates3.push_back(testDates);
		}

		else if (testDates.day == 4) {

			listOfDates4.push_back(testDates);
		}

		else if (testDates.day == 5) {

			listOfDates5.push_back(testDates);
		}

		else if (testDates.day == 6) {

			listOfDates6.push_back(testDates);
		}

		else if (testDates.day == 7) {

			listOfDates7.push_back(testDates);
		}


		else if (testDates.day == 8) {

			listOfDates8.push_back(testDates);
		}

		else if (testDates.day == 9) {

			listOfDates9.push_back(testDates);
		}

		else if (testDates.day == 10) {

			listOfDates10.push_back(testDates);
		}

		else if (testDates.day == 11) {

			listOfDates11.push_back(testDates);
		}

		else if (testDates.day == 12) {

			listOfDates12.push_back(testDates);
		}

		else if (testDates.day == 13) {

			listOfDates13.push_back(testDates);
		}

		else if (testDates.day == 14) {

			listOfDates14.push_back(testDates);
		}

		else if (testDates.day == 15) {

			listOfDates15.push_back(testDates);
		}

		else if (testDates.day == 16) {

		listOfDates16.push_back(testDates);
		}

		else if (testDates.day == 17) {

		listOfDates17.push_back(testDates);
		}

		else {

		listOfDates18.push_back(testDates);
		}
		 
		inFS >> timeStamp;  

	}  

	/*for (unsigned int i = 0; i < listOfDates1.size(); ++i) {

		std::cout << listOfDates1.at(i).year << " " << listOfDates1.at(i).month << "/" << listOfDates1.at(i).day << " " << listOfDates1.at(i).hour << ":" << listOfDates1.at(i).minute << std::endl;
	}

	std::cout << std::endl;
	*/

	

	sortVector(listOfDates26);
	sortVector(listOfDates27);
	sortVector(listOfDates28);
	sortVector(listOfDates29);
	sortVector(listOfDates30);  
	sortVector(listOfDates1);
	sortVector(listOfDates2);
	sortVector(listOfDates3);
	sortVector(listOfDates4);
	sortVector(listOfDates5);
	sortVector(listOfDates6);
	sortVector(listOfDates7);
	sortVector(listOfDates8);
	sortVector(listOfDates9);
	sortVector(listOfDates10);
	sortVector(listOfDates11);
	sortVector(listOfDates12);
	sortVector(listOfDates13);
	sortVector(listOfDates14);
	sortVector(listOfDates15);
	sortVector(listOfDates16);
	sortVector(listOfDates17);
	sortVector(listOfDates18);   


	inFS.close();

	
}
