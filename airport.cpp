/* Todd Yan 914224875
airport.cpp Prompt
 -prints description of Airport
 -read two textfiles-> Facilities.txt&Runways.txt
 -site#-> 10 char String-> etc(Facility type/name/code/position)
 -read code of airport as command line argument.
*/

/* Helpful tips
 -To Iterate through Facility.txt and create Facility Vector
    Lecture14-> getline.cpp
    Lecture15-> copy1.cpp
 -To search through text files when only given code
    Put everything as Facility/Runway object in vector
    use Stable_partition/find_if
 -Code is used in Find_if
    if 'a' is a pointer to Facility
    -> with code "SFO" -> Code("SFO")(a) shoul be true
 -Read Information from .txt
    Lecture14-> file1.cpp
 */

#include "Facility.h"
#include "Runway.h"
#include "Code.h"
#include "SiteNumber.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(int argc, char **argv){
    string line;
    string air_code = argv[1];
    
    if(air_code.length() > 4)
        cout << "Airport code must be at most 4 characters" << endl;
    
    while(air_code.length() < 4)
        air_code.append(" ");
    
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

    vector<Facility*>::iterator iS = find_if(Fac.begin(), Fac.end(), Code(air_code));

    if ((*iS) == NULL)
    {
        cout<< setw(4) << air_code << " not found" << endl;
        return 1;
    }
    // Fac is a vector of full of text that contains random information.
    // Code(air_code) will return true when the air_code appears in Fac
    // find_if will return first thing that is true
    // Facility is a class
    
    cout <<
    setw(9)<< (*iS)->site_number() << " " <<
    setw(3) << (*iS)->code() << " " <<
    (*iS)->name() <<
    endl;
    
    string air_number = (*iS)->site_number();
    
    vector<Runway*>::iterator iP = stable_partition(Run.begin(), Run.end(), SiteNumber<Runway>(air_number));
    
    vector<Runway*>::iterator temp_iP = iP;
    iP = Run.begin();
    while(iP != temp_iP){
        cout<<
        setw(0) << (*iP)->site_number() << " " <<
        setw(0) << (*iP)->name() << " " <<
        setw(0) << (*iP)->length() <<
        endl;
        *iP++;
    }
}
