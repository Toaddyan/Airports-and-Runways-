/*
 distance.cpp
    -prints distance between 2 airports(read from command line)
    - nautical miles
 */
#include "Facility.h"
#include "Runway.h"
#include "Code.h"
#include "SiteNumber.h"
#include "gcdistance.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
    string line;
    string air_code1 = argv[1];
    string air_code2 = argv[2];
    
    
    if(air_code1.length() > 4)
        cout << "Airport code must be at most 4 characters" << endl;
    if(air_code2.length() > 4)
        cout << "Airport code must be at most 4 characters" << endl;
    
    while(air_code1.length() < 4)
        air_code1.append(" ");
    while(air_code2.length() < 4)
        air_code2.append(" ");
    
    vector<Facility*> Fac;
    vector<Runway*> Run;
    ifstream fac_file("Facilities.txt");
    ifstream run_file("Runways.txt");
    
    if(!fac_file)
    {
        cout << "Error opening File" << endl;
        return 1;
    }
    while(getline(fac_file,line))
    {
        Facility* f = new Facility(line);
        Fac.push_back(f);
    }
    
    // reading Runway file
    if(!run_file){
        cout<<"Error opening File" << endl;
        return 1;
    }
    while(getline(run_file,line)){
        Runway* r = new Runway(line);
        Run.push_back(r);
    }
    vector<Facility*>::iterator obj1 = find_if(Fac.begin(), Fac.end(), Code(air_code1));
    vector<Facility*>::iterator obj2 = find_if(Fac.begin(), Fac.end(), Code(air_code2));
    if ((*obj1) == NULL)
    {
        cout<< setw(4) << air_code1 << " not found" << endl;
        return 1;
    }
    if ((*obj2) == NULL)
    {
        cout<< setw(4) << air_code2 << " not found" << endl;
        return 1;
    }
    cout <<
    (*obj1)->code() << " - " << (*obj2)->code() << " " <<
    floor((*obj1)->distance((*obj2)->latitude(), (*obj2)->longitude())) <<
    " NM"
    << endl;
}

 
