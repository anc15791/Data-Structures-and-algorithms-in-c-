/*
 * Constitution.cpp
 * Program to compare STL vector and Map data structures by creating concordance tables for US Constitution.
 *
 *  Created on: Apr 19, 2017
 *      Author: Anurag Chowdhary
 */

#include <iostream>
#include <utility>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <stdlib.h>
#include "Word.h"
#include "WordVector.h"
#include "WordMap.h"

using namespace std;

const string INPUT_FILE_NAME = "USConstitution.txt";
const int    MAX_SEARCHES    = 100000;

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m);
void make_spot_checks(WordVector& v, WordMap& m) throw(string);
void check_concordances(WordVector& v, WordMap& m) throw(string);
void time_word_searches(WordVector& v, WordMap& m) throw(string);
bool is_word(string text);
bool is_word(char text);
string commafy(const long n);
string trim(string token);
void print(WordVector& v, WordMap& m);

int main()
{
    ifstream in;
    in.open(INPUT_FILE_NAME);
    if (in.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    WordVector v;
    WordMap    m;

    try {
        time_word_insertions(in, v, m);
        make_spot_checks(v, m);
        check_concordances(v, m);
        time_word_searches(v, m);
        print(v,m);
    }
    catch (string& msg)
    {
        cout << endl << endl << "***** " << msg << endl;
    }

    return 0;
}

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m)
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;

    cout << "Timed insertions ..." << endl;

    // Loop once per line of the input file.
    while (getline(in, line))
    {
    	line_count++;
    	std::istringstream iss(line);
    	std::string token;
    	while (std::getline(iss, token, ' '))
    		{
    			transform(token.begin(),token.end(),token.begin(),::tolower); // convert the line into lowercase.
    			if(is_word(token)){

    				token = trim(token); // Remove leading and trailing special characters in a word.
    				token = trim(token);

    				character_count+=token.length();

    				word_count++;
    				v.insert(token);
    				m.insert(token);

    			}
    	    }
    }

    cout << "          Lines: " << setw(6) << commafy(line_count) << endl;
    cout << "     Characters: " << setw(6) << commafy(character_count) << endl;
    cout << "          Words: " << setw(6) << commafy(word_count) << endl;
    cout << endl;
    cout << "    Vector size: " << commafy(v.get_data().size()) << endl;
    cout << "       Map size: " << commafy(m.get_data().size()) << endl;
    cout << endl;
    cout << "    Vector total insertion time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total insertion time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;


}

void make_spot_checks(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Spot checks of word counts ..." << endl;

    vector<Word>&      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    vector<string> texts = {
        "amendment", "article", "ballot", "citizens", "congress",
        "constitution", "democracy", "electors", "government", "law",
        "legislature", "people", "president", "representatives",
        "right", "trust", "united", "vice", "vote"
    };

    for (string text : texts)
    {
        cout << "    " << text << ": ";

        vector<Word>::iterator      itv = v.search(text);
        map<string, Word>::iterator itm = m.search(text);

        /***** Complete this function. *****/
        if(itv < vdata.begin())
        	cout<<"vector:"<<" (not found) ";
        else
        	cout<<"vector:"<<itv->get_count()<<" ";
        if(itm ==mdata.end() )
        	cout<<"map:"<<" (not found) ";
        else
        	cout<<"map:"<<itm->second.get_count();
        cout<<"\n";
    }
}

void check_concordances(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Checking concordances ... ";  cout.flush();

    vector<Word>&      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    int vsize = vdata.size();
    int msize = mdata.size();

    if (vsize == 0) throw("Empty vector.");
    if (msize == 0) throw("Empty map.");

    if (vsize != msize ) throw(string("Size mismatch: ") + to_string(vsize) +
                                                 " and " + to_string(msize));

    vector<Word>::iterator      itv = vdata.begin();
    map<string, Word>::iterator itm = mdata.begin();

    while (itv != vdata.end())
    {
        if (*itv != itm->second)
        {
            throw string(string("Data mismatch: ")
                    + itv->get_text() + ":" + to_string(itv->get_count())
                    + " and " + itm->second.get_text() + ":"
                    + to_string(itm->second.get_count()));
        }

        ++itv;
        ++itm;
    }

    cout << "both match!" << endl;
}

void time_word_searches(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Timed searches (" << commafy(MAX_SEARCHES)
                 << " searches) ..." << endl;

    v.reset_elapsed_time();
    m.reset_elapsed_time();

    for (int i = 1; i <= MAX_SEARCHES; i++)
    {
        int index = rand()%v.get_data().size();
        string text = v.get_data()[index].get_text();
        v.search(text);
        m.search(text);

    }

    cout << endl;
    cout << "    Vector total search time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total search time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}

/**
 * Check if the word is any special character or a number
 * @param text the string word to check..
 */
bool is_word(string text){
	bool result =true;
	if(text=="." || text=="?" || text=="_" || text=="-" || text=="/" || text=="," ||
			text=="!" || text=="\'" || text==";" || text=="\"" || text==":" || isdigit(text[0]) || text=="(" || text==")" ){
		result=false;
	}

	return result;
}

/**
 * Check if the char is any special character or a number
 * @param text the char to check..
 */
bool is_word(char text){
	bool result =true;
	if(text=='.' || text=='?' || text=='_' || text=='-' || text=='/' || text==',' || text==' ' ||
			text=='!' || text=='\'' || text==';' || text=='\"' || text==':' || isdigit(text) || text=='(' || text==')' ){
		result=false;
	}

	return result;
}

/**
 * Trim a word frim its prevailing and trailing special characters.
 * @param token the string to trim..
 */
string trim(string token){

	if(!is_word(token[0])){
		token = token.substr(1);
	}
	if(!is_word(token.back())){
		token.pop_back();
	}

	return token;
}

/**
 * Output the vector and map dump
 * @param WordVector and MapVector to print
 */
void print(WordVector& v, WordMap& m){
	cout << endl;
	int word_count=0;
    vector<Word>::iterator      itv = v.get_data().begin();
    map<string, Word>::iterator itm = m.get_data().begin();
    cout<<"vector"<<setw(20)<<"map"<<endl;
    while (itv != v.get_data().end())
    {

    	cout<<itv->get_text()<<":"<<itv->get_count()<<setw(20)<<itm->second.get_text()<<":"<<itm->second.get_count()<<endl;
    	word_count+=itv->get_count();
        ++itv;
        ++itm;
    }

}


