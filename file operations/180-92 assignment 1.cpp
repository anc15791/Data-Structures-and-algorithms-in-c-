/**
 * 180-92 Assignment 1, president.cpp
 * Purpose: Output the president.in file in specified format.
 *
 * @author Anurag Chowdhary(011550201)
 * @version 1.0 2/2/2017
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string INPUT_FILE_NAME = "presidents.in";

/**
 * The main: Read the input file and print the report.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

     // store positing of start of last name

    double ageAverage=0;
    int averageCount=0;

    string line;

    cout<<"First name   Middle name   Last name   Born   Died   Age   Start   End    Party"<<'\n';
    cout<<"----------   -----------   ---------   ----   ----   ---   -----   ----   -----"<<'\n';

    while( getline (input,line) && line[0]!='.') // for parsing the input file
    	  {
    		bool flagFirstNameFound=false;

    		bool flagLastNameFound = false;
    		int startOfLastName = -1;
    		int outputPrintPosition=0;
			string birthYear;
			string deathYear;
			int age=0;
			//bool startYear=false;

			bool flagClosingBraceFound=false;
			int partyEndPosition=-1;


    		for ( int i=0; i!=line.length(); i++) // for parsing character by character of each line
    		  {

    			  //print first name
    			  if(line[i]!=' ' && !flagFirstNameFound)
    			  {
    				  cout<<line[i];
    				  outputPrintPosition++;
    			  }

    			  // give spacing between first and middle name
    			  if(line[i]==' ' && !flagFirstNameFound)
    				  {

						  for(int j=0;j<12-i;j++)// 12 is start of Middle Name column
						  {
							  cout<<" ";
							  outputPrintPosition++;
						  }
						  flagFirstNameFound=true;
    				  }

    			  //Compute starting positing of last name.
    			  if(flagFirstNameFound && !flagLastNameFound)
    				  {
						  int j=i;

						  while(line[j]!='(' && !flagLastNameFound)
						  {

							  if(line[j]==' ' && line[j+1]!='(')
							  {
								  startOfLastName=j;

							  }
							  if(line[j]==' ' && isalpha(line[j+1]) && islower(line[j+1]))
							  {
								  startOfLastName=j;
								  flagLastNameFound=true;
								  break;
							  }
							  j++;
						  }
						  flagLastNameFound=true;
    				  }

    			  //If middle name isn't there, print last name
    			 if(i==startOfLastName)
    			 	 {
    				 	cout<<"              ";
    				 	outputPrintPosition+=14;
    			      	int k=i;
    			      	while(line[k]!='(')
    					 {
   	      					 cout<<line[k];
   	      					 k++;
   	      					 outputPrintPosition++;
    			   		 }
    			      	cout<<" ";
    			      	outputPrintPosition+=1;
    			      	i=k; // move the main for loop for reading input forward.
    			 	 }


    			 //If middle Name is there, print middle name, give space, print last name.
    			 if(startOfLastName>i)
    			 {
    				 int k=i;

    				 for(k=i;k<startOfLastName;k++)
    				 {
    					 cout<<line[k];
    					 outputPrintPosition++;
    				 }

    				 for(int j=outputPrintPosition;j<26;j++)// 26 is start of Last Name column
    				 {
    					 cout<<" ";
    					 outputPrintPosition++;
    				 }

    				 while(line[k]!='(')
    				    {
    					 cout<<line[k];
    					 k++;
    					 outputPrintPosition++;
    				    }

    				 cout<<" ";
    				 outputPrintPosition+=1;
    				 i=k; // move the main for loop for reading input forward.
       			 }

    			 //Extract Birth Year, Death Year, Calculate Age and Average Age, print birth, death year and age.
    			 if(line[i]=='(' && !flagClosingBraceFound)
    			 {
    				 birthYear = birthYear.append(line,i+2,4);
    				 i=i+5; // move the main for loop for reading input forward.

    				 //If president is alive
    				 if(line[i+2]!='-')
    				 {
    					 age=0;
    					 deathYear="0";
    				 }

    				 else
    				 {
    					 deathYear = deathYear.append(line,i+4,4);
    					 averageCount++;
    					 age=stoi(deathYear)-stoi(birthYear);
    					 ageAverage=(double)(ageAverage+age);
    				 }


    				 if(deathYear=="0")
    				 {
    					 for(int j=outputPrintPosition;j<39;j++)// 39 is start of Born column
    					 {
    						 cout<<" ";
    						 outputPrintPosition++;
    					 }
    					 cout<<birthYear;
    					 i+=2; // move the main for loop for reading input forward.
    					 cout<<"             ";
    					 outputPrintPosition+=17;
    				 }
    				 else
    				 {
    					 for(int j=outputPrintPosition;j<39;j++)
    					 {
    					     cout<<" ";
    					     outputPrintPosition++;
    					 }
    					 cout<<birthYear<<"   "<<deathYear<<"   "<<age<<" ";
    					 outputPrintPosition+=15;
    					 i=i+8;
    				 }




    			 }
    			 if(line[i]==')')
    			 {
    				 flagClosingBraceFound=true;
    			 }


    			 //Print Start and End year, print Party.
    			 if(flagClosingBraceFound && partyEndPosition<0)
    			 {
    				 cout<<"  ";
    				 outputPrintPosition+=2;
    				 string startYear;

    				 //Find position of end of party name
    				 for(int j=i;j<line.length() && partyEndPosition<0;j++)
    				 {
    					 if(isdigit(line[j]) && line[j-1]==' ')
    					 {
    						 partyEndPosition=j-1;
    					 }
    				 }

    				 if(partyEndPosition>0)
    				 {
    					 startYear=startYear.append(line,partyEndPosition,5);

    					 //To print start and End Year whose term was greater than 1 year
    					 for(int j=partyEndPosition;j<line.length();j++)
    					 {
    						 if(line[j]=='-')
    							 cout<<"  ";
    						 else
    							 cout<<line[j];
    						 outputPrintPosition++;
    					 }

    					 //To print End Year for those whose Term was only 1 year.(start year = end year)
    					 if(line[partyEndPosition+6]!='-')
    					 {
    						 cout<<"   "<<startYear;

    					 }
    					 cout<<"   ";
    					 outputPrintPosition+=10;

    					 //Print party
    					 for(int j=i+1;j<partyEndPosition;j++)
    					 {
    						 cout<<line[j];
    						 outputPrintPosition++;
    					 }
    				 }
    			 }
    		  }
    		cout<<'\n';
    	  }

    cout<<'\n'<<"Average age at death = ";
    cout<<setprecision(3)<<ageAverage/averageCount;
    input.close();
    return 0;
}

