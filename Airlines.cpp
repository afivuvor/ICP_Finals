//
// Created by Sena Vuvor on 26/11/2022.
//

#include <string>
#include <list>
#include <map>
#include <iostream>
#include "Airlines.h"

using namespace std;

Airlines::Airlines(string airlineId, string airline, string alias, string airlineIATA, string airlineICAO, string callSign, string country, string active) {
    this->airlineId = airlineId;
    this->airline = airline;
    this->alias = alias;
    this->airlineIATA = airlineIATA;
    this->airlineICAO = airlineICAO;
    this->callSign = callSign;
    this->country = country;
    this->active = active;
}


void Airlines::airlineReader() {

    ifstream airlineFile;
    airlineFile.open("cmake-build-debug/airlines.csv");
    string row = "";
    int count = 0;
    string key;
    vector<Airlines> airlines;

    if (airlineFile.is_open()) {
        while (getline(airlineFile, row)) {
            if (count == 0) {
                count++;
                continue;
            }
            string airlineId, airline, alias, airlineIATA, airlineICAO, callSign, temp, country, active;
            stringstream inputString(row);

            getline(inputString, airlineId, ',');
            getline(inputString, airline, ',');
            getline(inputString, alias, ',');
            getline(inputString, airlineIATA, ',');
            getline(inputString, airlineICAO, ',');
            getline(inputString, callSign, ',');
            getline(inputString, country, ',');
            getline(inputString, active, ',');


            key = airlineIATA;
            Airlines airlineObj = *new Airlines(airlineId, airline, alias, airlineIATA, airlineICAO, callSign, country, active);

            /**this section checks if there is already a key in the map with the same name.
            * if it does, it adds the new object to the vector belonging to the particular key already in the map
            */
            if (airlinesMap.find(key) == airlinesMap.end()){
                airlines.push_back(airlineObj);
                airlinesMap.insert({ key, airlines});}
            else{
                airlinesMap[key].push_back(airlineObj);
            }
        }
    }
    else {
        cout << "Sorry cannot open";
    }
    airlineFile.close();
}