/*
 Code.h
    - find airport having the given code
    - use STL find_if algorithm with object-> Code
 */

//#include <Facility.h>
#ifndef CODE_H
#define CODE_H
#include <string>
#include <iostream>
using namespace std;

class Code
{
public:
    Code(string s): c_name(s) {}
    bool operator() (Facility* object) {

        if(object->code().compare(c_name) == 0)
            return true;
        else{
            return false;
        }

    }
private:
    const string c_name;
};

#endif
