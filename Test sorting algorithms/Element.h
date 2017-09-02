/*
 * Element.h
 *
 *  Created on: Apr 26, 2017
 *      Author: Anurag Chowdhary
 */

#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();
    static void reset();
    static long get_copy_count();
    static long get_destructor_count();

    long get_value() const;
    bool operator<(const Element& other)const;
    bool operator>(const Element& other)const;
    bool operator<=(const Element& other)const;
    bool operator>=(const Element& other)const;
    friend ostream& operator<<(ostream& o, const Element& other);

    /***** Complete this class. *****/

private:
    long value;
    static long copy_count;
    static long destructor_count;
};

#endif /* DATA_H_ */
