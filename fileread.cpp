//
//  fileread.cpp
//  Fileread
#include "fileread.h"



 std::vector<Trip> read_file_into_trip(std::string fileName) {
     //create fstream objects and open the cab rides file
     std::fstream cabfile;
     cabfile.open("cab_rides.csv");
     //variables
     std::vector<Trip> data;
     std::vector<std::string> row;
     std::string line, word;
     int startIndex=0;
     //read the data from cabfile into line and go by each line to read the row
         while(getline(cabfile,line)){
                std::stringstream str(line);
     
         while (getline(str, word, ',')) {
         row.push_back(word);
     
     }
     //put the data into Trip object
     if(startIndex>0)
     {
         Trip A = Trip(row[7], row[4], row[3], row[1], row[2], stod(row[5] == "" ? "0" : row[5]), "");
         data.push_back(A);
     }
     row.clear();
     startIndex+=1;
     }
     
     cabfile.close();
     return data;
     
     
 }
std::vector<Weather> read_file_into_weather(std::string fileName) {
    //create fstream objects and open the weather file
    std::fstream weatherfile;
    weatherfile.open("weather.csv");
    std::vector<Weather> data;
    std::vector<std::string> row;
    std::string line, word;
    //read data from weather file into line and go by each line to read the row
    int startIndex = 0;
    while (getline(weatherfile, line)) {
        std::stringstream str(line);
        
        while (getline(str, word, ',')) {
            row.push_back(word);
        }
        //put the data into Weather object
        if(startIndex>0)
        {
        Weather A = Weather(row[1], stod(row[4] == "" ? "0" : row[4]), row[5]);
        data.push_back(A);
        }
        row.clear();
        startIndex+=1;
    }
    weatherfile.close();
    return data;
}

