//
// Created by Sena Vuvor on 26/11/2022.
//

#ifndef ICP_FINALPROJECT_ROUTES_H
#define ICP_FINALPROJECT_ROUTES_H
#endif //ICP_FINALPROJECT_ROUTES_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class Routes {
public:
    string airlineCode;
    string airlineId;
    string srcAirport;
    string srcAirportID;
    string destAirportCode;
    string destAirportID;
    string stop;

    Routes(string airlineCode, string airlineId, string srcAirport,
           string srcAirportID, string destAirportCode, string destAirportID, string stop);


    static void routeReader();
    static map<string, vector<Routes>> routesMap;
    static map<string, Routes> airlineMap;
};

