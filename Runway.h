//
// Runway.h
//

#ifndef RUNWAY_H
#define RUNWAY_H
#include<string>
class Runway
{
  public:
    Runway(std::string s);
    std::string site_number(void) const;
    std::string name(void) const;
    int length(void) const;
  private:
    int convert_length(std::string s) const;
    // converts string s representing runway length to int value
    //  x = atoi(argv[1]);
    const std::string site_number_;
    const std::string name_;
    const int length_;
};
#endif
