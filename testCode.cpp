//
// testCode.cpp
//
// test the Code predicate

#include "Facility.h"
#include "Code.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string testcode("DFW");
    string testcode1("SFO");
  ifstream facilities_file("testFacility1.in");
  string line;
  getline(facilities_file,line);
  Facility *f = new Facility(line);
  cout << f->code() << " " << f->name() << endl;
  cout << "test if DFW: " << boolalpha << Code(testcode)(f) << endl;
  cout << "test if SFO: " << boolalpha << Code(testcode1)(f) << endl;
  delete f;
}
