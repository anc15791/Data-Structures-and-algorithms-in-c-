#include <math.h>
#include "Node.h"

	//constructor and destructors
	Node::Node():next(nullptr),name(""),state(""),row(0),col(0){}
	Node::Node(Coordinate c):next(nullptr), name(""),state(""){
		convert_coordinate(c);
	}
	Node::Node(City c): next(nullptr), name(c.get_name()), state(c.get_state())
	{
	    convert_coordinate(c.get_coordinate());
	}

	Node::~Node(){}

    //getters
	string Node::get_name() const{return name;}
	string Node::get_state() const{return state;}
	int Node::get_row() const {return row;}
	int Node::get_col() const {return col;}


	//setters
	void Node::set_name(string n){name=n;}
	void Node::set_state(string s){state=s;}
	void Node::set_row(int r){row=r;}
	void Node::set_col(int c){col=c;}

    // Overloaded stream output insertion operator.
    ostream& operator <<(ostream& outs, const Node& node){
    	if(node.name.length()>0)
    		outs<<"*"<<node.name<<" "<<node.state;
    	else
    		cout<<"#";

    	return outs;
    }


/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */
void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}


//compares node on lhs with rhs of > operator. compare with row and then with column.
bool Node::operator >(const Node &other)
{
    bool is_greater=false;

    if(row>other.get_row()){
    	is_greater=true;
    }

    if(row<other.get_row()){
    	is_greater=false;
    }

    if(row==other.get_row()){
    	if(col>other.get_col()){
    		is_greater = true;
    	}
    	else{
    		is_greater = false;
    	}

    }

    return is_greater;
}
