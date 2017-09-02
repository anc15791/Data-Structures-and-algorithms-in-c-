#include "City.h"


City::City() : name(""), state(""){}

City::~City(){}

//getters
string City::get_name() const { return name; }
string City::get_state() const { return state; }
Coordinate City::get_coordinate() const { return coordinate; }

//setters
void City::set_name(string s){name=s;}
void City::set_state(string s){state=s;}
void City::set_coordinate(Coordinate &c){coordinate=c;}

ostream& operator <<(ostream& outs, const City& city)
{
    outs << "*" << city.name << " " << city.state;
    return outs;
}


istream& operator >>(istream& ins, City& city)
{
    string input;
    Coordinate c;
    getline(ins, input,  ',');
    city.set_name(input);
    getline(ins, input, ',');
    city.set_state(input);
    ins >> c;
    city.set_coordinate(c);

    return ins;
}
