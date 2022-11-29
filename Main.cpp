//
// Created by Sena Vuvor on 26/11/2022.
//

#include "Airlines.h"
#include "Routes.h"
#include "Airports.h"
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

map<string,vector<Airlines>> airlinesMap = *new map<string, vector<Airlines>>;
map<string,vector<Routes>> routesMap = *new map<string, vector<Routes>>;
map<string,Routes> airlineMap = *new map<string, Routes>;
map<string,vector<Airports>> airportsMap = *new map<string, vector<Airports>>;
map<string, string> sol_path;
deque<string> frontier;
vector<string> mylist;
vector<string> answer;
vector<string> airlines;
string line1, line2,child, removed_code, iata,iata2, file_name, air;


// method declarations
void outputFile();
vector<string> correctpath(string endpoint);
void csvReader(string file);
void findCode(string start_iata);

int main() {
    Airlines::airlineReader();
    Routes::routeReader();
    Airports::airportReader();

    cout<<"Please enter the file name"<<endl;
    cin>>file_name;
    csvReader(file_name);


    return 0;
}
/**
 *This method reads the user input file and determines the start and end destination
 * It calls the 'findcode' method to provide a route that links the start location
 * to the end destination
 * @Precondition
 * the file must exist
 * @param myFile
 * @return none
 */

void csvReader(string myFile) {
    ifstream file;
    file.open(myFile);
    string line = "";
    string key;
    if (file.is_open()) {

        while (getline(file, line)) {

            string city, country;

            stringstream inputString(line);
            getline(inputString, city, ',');
            getline(inputString, country, ',');

            mylist.push_back(city);
            mylist.push_back(country);
        }

        line1 = mylist[0] + "," +mylist[1];
        line2 = mylist[2] + ","+ mylist[3];

        if(airportsMap.find(line2)!= airportsMap.end()) {
            for (int i = 0; i<airportsMap[line2].size(); i++) {
                iata2 = airportsMap[line2].at(i).IATA;
                if (iata2 == "\\N") {
                    continue;}
            }}
        else{
            cout<<"sorry could not find it"<< endl;
        }
        if(airportsMap.find(line1)!= airportsMap.end()) {

            for (int i = 0; i<airportsMap[line1].size(); i++){
                iata = airportsMap[line1].at(i).IATA;
                if(iata == "\\N"){

                    continue;}
                else{
                    findCode(iata);
                }
            }}
        else{
            cout<<"sorry could not find it"<< endl;
        }
    }
    else{
        cout<< "Sorry could not find the file specified"  << endl;
    }
    file.close();
}

/**
 * This method uses the breadth-first search algorithm to find the optimal path from the
 * start location to end destination
 *
 * @param start_iata
 * This resource was obtained from Doctor Ayorkor Korsah's Implementation of BFS algorithm
 * This method automatically finds the optimal solution
 */
void findCode(string start_iata){
    vector<string> explored;
    /*Check if the AITA code passed as a parameter can be found as a key in the Routes hashmap  */

    if (routesMap.find(start_iata)!= routesMap.end()){
        if(start_iata==iata2){
            cout<<"You have reached your destination"<<endl;
        }else{
            frontier.push_back(start_iata);
        }

        /* This loop will run until the frontier is empty */
        while(frontier.size() >0){
            removed_code=frontier.front();
            frontier.pop_front();
            explored.push_back(removed_code);
            if (routesMap.find(removed_code)!= routesMap.end()){


                int number2 = routesMap[removed_code].size();

                for(int j =0; j<number2; j++){
                    child = routesMap[removed_code].at(j).destAirportCode;

                    if((find(explored.begin(), explored.end(), child) == explored.end()) && \
                     (find(frontier.begin(), frontier.end(), child) == frontier.end())){
                        sol_path.insert({child, removed_code});

                        if (child== iata2){
                            correctpath(iata2);
                            outputFile();
                            exit(0);
                        }

                        else{
                            frontier.push_back(child);}
                    }
                }
            }else{ continue;}
        }
    }
    else{cout<<"Sorry, could not find yous start destination";}
}


/**
 *This method  returns a series of flights and their respective airports from the start location to the end
 * @Precontion:
 * variable' sol_path' should not be empty
 * @param endpoint the end destination of the user
 * @return answer
 */
vector<string> correctpath(string endpoint){
    answer.push_back((endpoint));
    string ending = endpoint;
    while(sol_path.find(ending) != sol_path.end()){
        ending = sol_path[ending];
        answer.push_back(ending);
    }

    reverse(answer.begin(), answer.end());

    for (int i = 0; i< answer.size()-1; i++){
        string mykey = answer.at(i) + ", "+ answer.at(i+1);
        if (airlineMap.find(mykey)!= airlineMap.end()){

            air = airlineMap.at(mykey).airlineCode;
            airlines.push_back(air);
        }
    }
    return answer;
}

/**
 * This method writes out the path to a file
 * @Precondition:
 * variable 'answer' must not be null
 *
 */
void outputFile(){
    int pos = file_name.find(".txt");
    string sub = file_name.substr(0,pos);
    ofstream output(sub+"_output.txt");
    int start = 0;
    while(start<answer.size()-1){
        for (int i = 0; i < answer.size()-1; i++){
            output<< i+1 <<". "<<airlines.at(i)<<" from "<< answer.at(start)<<" to " << answer.at(start+1)<< ", stops = 0"<<endl;
            start ++;
        }
    }
    output<< "Total flights: "<< answer.size()-1<<endl;
    output<< "Total additional stops: 0"<<endl;
    output<<"Optimality criteria: flights"<< endl;
    output.close();}
