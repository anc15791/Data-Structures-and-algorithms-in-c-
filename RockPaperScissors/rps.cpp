/*
 * File Name: rps.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:2
 * Description: Program that plays the game of Rock Paper Scissors with a human player.
 * Created on: Feb 7, 2017
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX_ROUNDS = 20;  // max rounds per game

enum Player { HUMAN, COMPUTER, TIE };   // players and winners
enum Thing  { ROCK, PAPER, SCISSORS };  // what each player chooses

void record_win(Player,int&,int&,int&);
char get_human_choice();
int get_computer_choice(int);
Thing choice_to_enum(char);
Thing choice_to_enum(int);
Player compare_choices(Thing,Thing);
Thing game_rule(Thing,Thing);
string enum_to_string(Thing);

/**
 * The main. Play a game consisting of MAX_ROUNDS.
 * Print the number of human player wins, computer wins, and ties.
 */
int main()
{
    int human_wins = 0;
    int computer_wins = 0;
    int ties = 0;
    int round_no=1;

    srand(time(NULL));  // seed the random number generator

    //Play 20 rounds
    for(round_no=1; round_no<MAX_ROUNDS+1;round_no++)
    {
    	char human_choice;
    	int computer_choice;
    	Player winner;
    	cout << "\n Round "<< round_no <<"\n   Your Choice? ";
    	human_choice=get_human_choice();
    	if(choice_to_enum(human_choice)!=ROCK && choice_to_enum(human_choice)!=PAPER && choice_to_enum(human_choice)!=SCISSORS)
    	{
    		cout<<"Wrong input, try again, enter r,R -> Rock , p,P->Paper, s,S->Scissor\n";
    		round_no--;
    		continue;
    	}
    	computer_choice = get_computer_choice(rand());
    	winner = compare_choices(choice_to_enum(human_choice),choice_to_enum(computer_choice));
    	record_win(winner,human_wins,computer_wins,ties);
    	cout<< "   You chose "<<enum_to_string(choice_to_enum(human_choice))<<'\n';
    	cout<< "   The computer chose "<<enum_to_string(choice_to_enum(computer_choice))<< '\n';
    	if(winner==HUMAN)
    		cout<<"   The winner is you \n";
    	if(winner==COMPUTER)
    		cout<<"   The winner is the computer \n";
		if(winner==TIE)
			cout<<"   Game is a tie \n";

    }

    cout<<"\n Summary \n _______ \n\n";
    cout<<"    Human wins: "<< human_wins<<'\n';
    cout<<" Computer wins: "<< computer_wins<<'\n';
    cout<<"          Ties: "<< ties<<'\n';


    return 0;
}

/*
 * Depending upon the winner of the current round record the current game as Human or Computer win OR tie.
 * */

void record_win(Player winner, int& human_wins, int& computer_wins, int& ties)
{
	if(winner==HUMAN)
		human_wins++;
	if(winner==COMPUTER)
		computer_wins++;
	if(winner==TIE)
		ties++;
}

/*
 * Get Human choice
 * r,R -> Rock , p,P->Paper, s,S->Scissor
 * give error message for wrong input (return x)
 * Return r,c,p or R,C,P for right inout and x for wrong input.
 * */
char get_human_choice()
{
	char input;
	cin >> input;
	if (input == 'r' || input == 'R' || input == 'p' || input == 'P' || input == 's' || input == 'S')
		return input;
	else
		return 'x';
}

/*
 * Get Computer Choice
 * Return 1 or 2 or 3;
 * */
int get_computer_choice(int random_number)
{
	int input;
	input = random_number%3;
	return input;

}

/*
 * Convert character input (rR,pP,sS) to ENUM of Thing(ROCK,PAPER,SCISSORS).
 * */

Thing choice_to_enum(char input)
{
	if(input == 'r' || input == 'R')
		return ROCK;
	if(input == 's' || input == 'S')
		return SCISSORS;
	if(input == 'p' || input == 'P')
		return PAPER;
}

/*
 * Convert integer input (1,2,3) to ENUM of Thing(ROCK,PAPER,SCISSORS).
 * */
Thing choice_to_enum(int input)
{
	switch(input)
	{
	case 0: return ROCK;
	case 1: return PAPER;
	case 2: return SCISSORS;
	}

}

/*
 * Compare User and Computer choices and return the Winning Player according to rules of rock,paper, scissor game
 * */
Player compare_choices(Thing user_choice, Thing computer_choice)
{
	if(user_choice==computer_choice)
		{
			return TIE;
		}
	Thing winning_choice;
	winning_choice = game_rule(user_choice,computer_choice);
	if(user_choice==winning_choice)
		return HUMAN;
	else if(computer_choice==winning_choice)
		return COMPUTER;

}


/*
 * Defining rules of the game rock paper scissor.
 * Rock wins over Scissors
 * Paper wins over Rock
 * Scissors wins over Paper
 * */
Thing game_rule(Thing input1, Thing input2)
{
	if((input1==ROCK && input2==SCISSORS) || (input1==SCISSORS && input2 == ROCK))
		return ROCK;
	if((input1==PAPER && input2==ROCK) || (input1==ROCK && input2 == PAPER))
		return PAPER;
	if((input1==SCISSORS && input2==PAPER) || (input1==PAPER && input2 == SCISSORS))
		return SCISSORS;
}


/*
 * Convert Thing ENUM values to corresponding string values for printing.
 * */
string enum_to_string(Thing input)
{
	if(input==ROCK)
		return "ROCK";
	if(input==SCISSORS)
		return "SCISSORS";
	if(input==PAPER)
		return "PAPER";
}
