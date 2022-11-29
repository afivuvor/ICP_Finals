//
// Created by Sena Vuvor on 26/11/2022.
//

#include "Routes.h"

Routes::Routes(string airlineCode, string airlineId, string srcAirport,
               string srcAirportID, string destAirportCode, string destAirportID, string stop) {
    this->airlineCode = airlineCode;
    this->airlineId = airlineId;
    this->srcAirport = srcAirport;
    this->srcAirportID = srcAirportID;
    this->destAirportCode = destAirportCode;
    this->destAirportID = destAirportID;
    this->stop = stop;
}

void Routes::routeReader() {
    ifstream routeFile;
    routeFile.open("C:/Users/HP/CLionProjects/Air_Routes_cpp/cmake-build-debug/routes.csv");
    string row = "";
    int count = 0;
    string key, airlineMapkey;
    if (routeFile.is_open()) {

        while (getline(routeFile, row)) {
            if (count == 0) {
                count++;
                continue;
            }
            string airlineCode, airlineId, srcAirport, srcAirportID, destAirportCode, destAirportID, ignore, stop;

            stringstream inputString(row);

            getline(inputString, airlineCode, ',');
            getline(inputString, airlineId, ',');
            getline(inputString, srcAirport, ',');
            getline(inputString, srcAirportID, ',');
            getline(inputString, destAirportCode, ',');
            getline(inputString, destAirportID, ',');
            getline(inputString, ignore, ',');
            getline(inputString, stop, ',');


            key = srcAirport;

            airlineMapkey = srcAirport + ", "+ destAirportCode;


            Routes route = *new Routes(airlineCode, airlineId, srcAirport, srcAirportID, destAirportCode, destAirportID, stop);
            airlineMap.insert({key, route});

            /**this section checks if there is already a key in the map with the same name.
            * if it does, it adds the new object to the vector belonging to the particular key already in the map
            */

            if (routesMap.find(key) == routesMap.end()){
                vector<Routes> lists;
                lists.push_back(route);
                routesMap.insert({ key, lists });}

            else{
                routesMap[key].push_back(route);
            }
        }
    }
    else {
        cout << "Sorry cannot open";
    }
    routeFile.close();

}