/*
 * Word.cpp
 * Store Word text and count.
 *
 *  Created on: Apr 19, 2017
 *      Author: Anurag Chowdhary
 */

#include <string>
#include "Word.h"
using namespace std;


Word::Word() : text(""), count(0)
{
}

Word::Word(string text) : text(text), count(1)
{

}

Word::~Word()
{
}

string Word::get_text()  const { return text; }
int    Word::get_count() const { return count; }

void   Word::increment_count() { count++; }


/**
 * Overloading the != operator
 * @param other word to compare and MapVector to print
 */
bool Word::operator!=(const Word &other)const{
    return !(text==other.get_text() && count==other.get_count());
  }

bool Word::operator<(const Word &other)const{
    return (text<other.get_text() );
  }
