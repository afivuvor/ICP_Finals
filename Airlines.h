//
// Created by Sena Vuvor on 26/11/2022.
//

#ifndef ICP_FINALPROJECT_AIRLINES_H
#define ICP_FINALPROJECT_AIRLINES_H
#endif //ICP_FINALPROJECT_AIRLINES_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

class Airlines {
private:
    /* Instance variables/Fields*/
    string airlineId;
    string airline;
    string alias;
    string airlineIATA;
    string airlineICAO;
    string callSign;
    string country;
    string active;

public:
    /**
     * Constructor declaration
     * @param id  the unique OpenFlights identifier for the airline.
     * @param name the name of airline.
     * @param aka the also known as of the airline.
     * @param iata  the 2-letter IATA code
     * @param icao  the 3-letter ICAO code
     * @param calsign  the Airline callsign.
     * @param country   the airline origin country
     * @param active   determines if the airline is in use or not
     */

    Airlines(string airlineId, string airline, string alias, string airlineIATA, string airlineICAO, string callSign, string country, string active);


    /**
     * @returns none
     * This method reads the airlines file, splits the lines in the file, and stores the values in a map
     * The keys of the map are strings and the values are vectors of Airline objects
     */
    static void airlineReader();
    static map<string, vector<Airlines>> airlinesMap;
};
