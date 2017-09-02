#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

class Coordinate
{
public:

	//Constructor & destructor
    Coordinate();
    virtual ~Coordinate();

	double get_latitude() const;
	double get_longitude() const;
	double get_max_latitude() const;
	double get_max_longitude() const;

	void set_latitude(double la);
	void set_longitude(double lo);

    // Overloaded input stream extraction operator.
    friend istream& operator >>(istream& ins, Coordinate& coordinate);

    // Constants for this app's input data.
    static const double MAX_LATITUDE;
    static const double MIN_LONGITUDE;

private:
    double latitude;
    double longitude;
};

#endif /* COORDINATE_H_ */
