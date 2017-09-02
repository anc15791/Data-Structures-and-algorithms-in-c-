/*
 * DataReverseSorted.h
 *
 *  Created on: Apr 26, 2017
 *      Author: Anurag Chowdhary
 */

#ifndef DATAREVERSESORTED_H_
#define DATAREVERSESORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for reverse-sorted data.
 */
class DataReverseSorted: public DataGenerator
{
public:
    DataReverseSorted();
    virtual ~DataReverseSorted();

    virtual void generate_data(vector<Element>& data, int size);
};

#endif /* DATAREVERSESORTED_H_ */
