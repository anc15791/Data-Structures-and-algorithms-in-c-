/*
 * DataSorted.h
 *
 *  Created on: Apr 26, 2017
 *      Author: Anurag Chowdhary
 */

#ifndef DATASORTED_H_
#define DATASORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for already sorted data.
 */
class DataSorted: public DataGenerator
{
public:
    DataSorted();
    virtual ~DataSorted();

    virtual void generate_data(vector<Element>& data, int size);
};

#endif /* DATASORTED_H_ */
