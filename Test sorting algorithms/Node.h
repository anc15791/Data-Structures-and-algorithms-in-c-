/*
 * Node.h
 *
 *  Created on: Apr 26, 2017
 *      Author: sparta
 */

#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    /***** Complete this class. *****/
	Node *next;
	Node(Element elmt);

	Element element;
};

#endif /* NODE_H_ */
