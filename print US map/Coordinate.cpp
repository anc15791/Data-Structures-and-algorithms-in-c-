#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

Coordinate::Coordinate():latitude(0),longitude(0){}
Coordinate::~Coordinate(){}

double Coordinate::get_latitude() const{return latitude;}
double Coordinate::get_longitude()const{return longitude;}
double Coordinate::get_max_latitude()const{return MAX_LATITUDE;}
double Coordinate::get_max_longitude()const{return MIN_LONGITUDE;}

void Coordinate::set_latitude(double la){latitude = la;}
void Coordinate::set_longitude(double lo){longitude=lo;}

istream& operator >>(istream& ins, Coordinate& coordinate){
	string input;
	getline(ins,input,',');
	coordinate.set_latitude(stod(input));
	getline(ins,input);
	coordinate.set_longitude(stod(input));
	return ins;
}
