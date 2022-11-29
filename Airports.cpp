//
// Created by Sena Vuvor on 26/11/2022.
//

#include "Airports.h"

Airports::Airports(string airportId, string airlineName, string city, string country, string IATA, string ICAO) {
    this->airportId = airportId;
    this->airlineName = airlineName;
    this->city = city;
    this->country = country;
    this->IATA = IATA;
    this->ICAO = ICAO;
}

void Airports::airportReader() {
    ifstream airportsFile;
    airportsFile.open("cmake-build-debug/airports.csv");
    string line = "";
    int count = 0;
    string key;
    if (airportsFile.is_open()) {

        while (getline(airportsFile, line)) {
            if (count == 0) {
                count++;
                continue;
            }
            string airport_id,  name, city, country, iata_code, icao_code;

            stringstream inputString(line);

            getline(inputString, airport_id, ',');
            getline(inputString, name, ',');
            getline(inputString, city, ',');
            getline(inputString, country, ',');
            getline(inputString, iata_code, ',');
            getline(inputString, icao_code, ',');


            key = city + ", "+ country;


            Airports airportObj = *new Airports(airport_id,  name, city, country, iata_code, icao_code);
            /**this section checks if there is already a key in the map with the same name.
             * if it does, it adds the new object to the vector belonging to the particular key already in the map
             */
            if (airportsMap.find(key) == airportsMap.end()){
                vector<Airports> airports;
                airports.push_back(airportObj);
                airportsMap.insert({ key, airports});}
            else{
                airportsMap[key].push_back(airportObj);
            }
        }
    }
    else {
        cout << "Sorry cannot open";
    }
    airportsFile.close();
}




