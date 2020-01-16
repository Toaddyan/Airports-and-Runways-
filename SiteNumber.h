/*
SiteNumber.h
STL stable_partition algorithm and function object SiteNumber.
 print description of all runways of airport(site#/name/length)
*/
#ifndef SITENUMBER_H
#define SITENUMBER_H
#include <string>
using namespace std;

template <class T>
class SiteNumber
{
public:
    SiteNumber(string s): s_num(s) {}
    bool operator() (T* object) {
        if(object->site_number().compare(s_num) == 0)
            return true;
        else{
            return false;
        }
        
    }
private:
    const string s_num;
};
#endif
