/*
 * Node.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: sparta
 */

#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;

/***** Complete this file. *****/

Node::Node(const long the_value):value(the_value){
	Node::constructor_count++;
}

Node::Node(const Node& other):value(other.get_value()){
	Node::copy_count++;
}
Node::~Node(){
 	Node::destructor_count++;
}

long Node::get_value() const{return value;}
// Access and reset the values of the static member variables.
long Node::get_constructor_count(){return Node::constructor_count;}
long Node::get_copy_count(){return Node::copy_count;}
long Node::get_destructor_count(){return Node::destructor_count;}
void Node::reset(){
 Node::constructor_count=0;
 Node::copy_count=0;
 Node::destructor_count=0;
}

bool Node::operator >(const Node &other) const{
	return (value>other.get_value());
}

// Overloaded stream output insertion operator.
ostream& operator <<(ostream& outs, const Node& node){
	outs<<node.get_value();
	return outs;
}
