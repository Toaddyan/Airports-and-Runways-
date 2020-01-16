/* Todd Yan 914224875
 Facility.cpp
 testFacility.cpp
 int main()
 {
 string line;
 getline(cin,line);
 Facility f(line);
 cout << f.site_number() << " " << f.type() << " " << f.code() << " "
 << f.name() << " ";
 cout << setw(12) << setprecision(4) << fixed << f.latitude() << " "
 << setw(12) << setprecision(4) << fixed << f.longitude() << " ";
 cout << f.distance(40,-100) << endl;
 }
 */
#include<iostream>
#include<sstream>
#include<string>
#include "Facility.h"
#include "gcdistance.h"
using namespace std;

Facility::Facility(string s):
site_number_(s.substr(0,10)),
type_(s.substr(11,13)),
code_(s.substr(24,4)),
name_(s.substr(130,50)),
latitude_(convert_latitude(s.substr(535,12))),
longitude_(convert_longitude(s.substr(562,12)))
{
    
}

string Facility::site_number(void) const{
    // return Facility's site number
    return site_number_;
}

string Facility::type(void) const{
    // return facility's type
    return type_;
}


string Facility::code(void) const{
    // return facility's code
    return code_;
}

string Facility::name(void) const{
// return facility's name
    return name_;
}

double Facility::latitude(void) const{
// return latitude of facility in degrees decimal

    return latitude_;
}

double Facility::longitude(void) const{
// return longitude of facility in degrees decimal

    return longitude_;
}

double Facility::distance(double lat, double lon) const{
// return distance in nautical miles between facility and position defined
// by (lat,lon)
    return gcdistance(latitude_, longitude_, lat, lon);
}
double Facility::convert_latitude(string s)const {
    string lat = s.substr(0,11);
    istringstream is(lat);
    double latitude;
    is >> latitude;
    if ( s.substr(11,1) == "S")
    {
        // negative result
        latitude = latitude / 3600;
        latitude *= -1;
    }
    else{
        //positive result
        latitude = latitude / 3600;
    }
    
    return latitude;
    
}
double Facility::convert_longitude(string s)const {
    
    string lon = s.substr(0,11);
    istringstream is(lon);
    double longitude;
    is >> longitude;

    if (s.substr(11,1) == "W")
    {
        // negative result
        longitude = longitude / 3600;
        longitude *= -1;
    }
    else{
        //positive result
        longitude = longitude / 3600;
    }
    
    return longitude;
}

