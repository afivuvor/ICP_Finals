//
// Created by Sena Vuvor on 26/11/2022.
//

#ifndef ICP_FINALPROJECT_AIRPORTS_H
#define ICP_FINALPROJECT_AIRPORTS_H
#endif //ICP_FINALPROJECT_AIRPORTS_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

class Airports {

public:
    string airportId;
    string airlineName;
    string city;
    string country;
    string IATA;
    string ICAO;

    Airports(string airportId, string airlineName, string city, string country, string IATA, string ICAO);

    static void airportReader();
    static map<string, vector<Airports>> airportsMap;

};

