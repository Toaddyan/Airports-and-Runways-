/* Todd Yan 914224875
 Runway.cpp
    -takes single string argument.
    - S is a full line read from Runways.txt file
 */
#include<iostream>
#include<string>
#include<sstream>
#include"Runway.h"
using namespace std;

Runway::Runway(string s):
site_number_(s.substr(0,10)),
name_(s.substr(13,7)),
length_(convert_length(s.substr(20,5)))
{}
// contains a full line read from Runways.txt
// select appropriate substrings from argument

string Runway::site_number(void) const{
// return site number of facility
    return site_number_;
}

string Runway::name(void) const{
// return name of runway
    return name_;
}

int Runway::length(void) const{
    // return length of runway in ft
    return length_;
}

int Runway::convert_length(string s) const
{
    istringstream is(s);
    int length;
    is >> length;
    return length;
}





