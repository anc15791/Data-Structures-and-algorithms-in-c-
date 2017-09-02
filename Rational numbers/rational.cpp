/*
 * File Name: rational.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:4
 * Description: Program to implement a Rational class, perform arithmetic operations on class objects
 * 				and print the objects by using operator overloading.
 * Created on: Mar 1, 2017
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;


class Rational
{
public:

    friend Rational operator +(const Rational& r1, const Rational& r2);
    friend Rational operator -(const Rational& r1, const Rational& r2);
    friend Rational operator *(const Rational& r1, const Rational& r2);
    friend Rational operator /(const Rational& r1, const Rational& r2);

    friend ostream& operator <<(ostream& outs, const Rational& r);
    friend istream& operator >>(istream& ins, Rational& r);

    Rational();
    Rational(int num);
    Rational(int num, int den);

    int get_numerator() const;
    int get_denominator() const;

    void set_numerator(int num);
    void set_denominator(int den);

    Rational reduce() const;

private:
    int a, b;  // numerator and denominator
    int get_gcd(int num, int den) const;
};

// Rational class Constructors
Rational::Rational() :a(0),b(0){}
Rational::Rational(int num) :a(num),b(1){}
Rational::Rational(int num, int den) :a(num),b(den){}

//Rational class getters
int Rational::get_numerator() const {return a;}
int Rational::get_denominator() const {return b;}

//Rational class setters
void Rational::set_numerator(int num) {a=num;}
void Rational::set_denominator(int den) {b=den;}


//Other functions declarations
void do_problem(const Rational r1, const Rational r2, const char op);
bool is_operator(const char op);
Rational evaluate(const Rational r1, const Rational r2, const char op);

const string INPUT_FILE_NAME = "rational.in";


/*
 * Main method to read inputs from file and coll appropriate functions to compute and print.
 * */
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

    Rational r1, r2;
    char op;

    while (true)
    {
        input >> r1 >> op >> r2;
        if( input.eof() ) break;
        do_problem(r1, r2, op);
    }

    cout << endl << "Done!" << endl;
    return 0;
}


void do_problem(const Rational r1, const Rational r2, const char op)
{
    Rational result = evaluate(r1, r2, op);
    cout << r1 << " " << op << " " << r2 << " = " << result << endl;
}


//Perform the arithmetic operation on r1 and r2 according to the operator op.
Rational evaluate(const Rational r1, const Rational r2, const char op)
{
	Rational result;
	Rational reduced_r1 = r1; // r1 & r2 are const, we cannot change values of a&b in r1 and r2, hence copy into temp variables for computation.
	Rational reduced_r2 = r2;

	reduced_r1=reduced_r1.reduce();
	reduced_r2=reduced_r2.reduce();

	if(op == '+')
		result = reduced_r1 + reduced_r2;
	if(op == '-')
		result = reduced_r1 - reduced_r2 ;
	if(op == '*')
		result = reduced_r1 * reduced_r2;
	if(op == '/')
		result = reduced_r1 / reduced_r2;

return result;

}

/*
 * Reduce the rational number
 * return : reduced rational number
 * call an helper gcd function of class rational to provide gcd of the rational number.
 * */
Rational Rational::reduce() const
{
	Rational result(a,b); // copy a and b values of the calling object into a result Rational object.
	int gcd=1;
	gcd = get_gcd(result.get_numerator(), result.get_denominator());
	result.set_numerator((int)(result.get_numerator()/(int)gcd));
	result.set_denominator((int)(result.get_denominator()/(int)gcd));

	return result;
}


/*
 * Compute gcd of two numbers using Euclidean algorithm
 * Param 1 & 2 : Non negative integer
 * return :Non negative integer gcd of the two number
 * */
int Rational::get_gcd(int num, int den) const
{

	if(num==0 || den==0)
		return 1;

	int r=-1; // to store remainder

	//swap if num < den
	if(num<den)
	{
		r=num; // temporary storage
		num=den;
		den=r;
	}

	do
	{
		r= num % den;
		if(r==0) // stopping condition since r will always converge to 0
			return den;
		else
		{
			num=den;
			den=r;
		}

	}while(true);
	return den;
}


/*
 * Check if a character is an operator or not
 * Param 1: character value to check
 * Return : true of a valid operator else false.
 * */
bool is_operator(char op)
{
	bool is_op = false;

	if(op == '-' || op == '+' ||op == '*' ||op == '/')
		is_op = true;

	return is_op;
}

/*
 * Overloaded insertion operator << to print Rational class objects in format a or (a/b) or c(a/b).
 * */
ostream& operator <<(ostream& outs, const Rational& r)
{
	int remainder=0;
	int quotient =0;

	Rational result(r.get_numerator(),r.get_denominator());
	result = result.reduce();

	// to print (a/1)
	if(result.get_denominator() == 1)
	{
		outs <<result.get_numerator() ;
		return outs;
	}

	// to print (0/b)
	if(result.get_numerator() == 0)
	{
		outs <<0 ;
		return outs;
	}

	// to print mixed fraction n(a/b) when numerator > denominator
	if(result.get_numerator()>result.get_denominator())
	{
		remainder = (int)(result.get_numerator() % result.get_denominator());
		quotient = (int)(result.get_numerator() / result.get_denominator());
		outs <<quotient <<"(" <<remainder << "/" << result.get_denominator() << ")";
		return outs;
	}

	// to print proper rational number (a/b)
	outs << "(" <<result.get_numerator() << "/" << result.get_denominator() << ")";
    return outs;
}


/*
 * Overloaded extraction operator >> to read inputs from file into rational class object.
 * */

istream& operator >>(istream& ins, Rational& r)
{

	ins >> std::ws; // bypass white spaces
	char input;
	int num=-1;
	int den = -1;
	int n=0;


	input=ins.peek();
	input = (char)(input);


	// to read c in c(a/b) from file
	if(isdigit(input))
	{
		ins >> n;
		ins >> std::ws;
		input=static_cast<char>(ins.peek());

		// for inputs of format c+d= or c + d =
		if(is_operator(input) || input == ' ' || input == '=')
		{
			r.set_numerator(n);
			r.set_denominator(1);
			if(input == '=')
				ins >> input;
			return ins;
		}
	}

	input=static_cast<char>(ins.peek());
	if(input == '(')
	{
		ins >> input; // bypass (
		ins >> std::ws;
		ins >> num;
		ins >> std::ws;
		ins >> input; // bypass /
		ins >> std::ws;
		ins >>den;
		ins >> std::ws;
		ins >> input; // bypass )
		ins >> std::ws;
	}

	r.set_numerator(n*den + num);
	r.set_denominator(den);
	input=static_cast<char>(ins.peek());
	if(input == '=')
		ins >> input;

	return ins;
}


/*Overloading + operator to perform rational addition
 * (a/b)+(c/d) = (ad+bc)/bd
 * Param 1: First rational number (a/b)
 * Param 2: Second rational number (c/d)
 *
 * Return : Resulting rational number.
 * */
Rational operator +(const Rational& r1, const Rational& r2)
{
	Rational result;
	result.set_numerator((int)((r1.get_numerator() * r2.get_denominator())+(r1.get_denominator() * r2.get_numerator())));
	result.set_denominator((int)(r1.get_denominator() * r2.get_denominator()));
	return result;

}

/*
 * Overloading - operator to perform rational subtraction
 * (a/b)-(c/d) = (ad-bc)/bd
 * Param 1: First rational number (a/b)
 * Param 2: Second rational number (c/d)
 *
 * Return : Resulting rational number.
 * */
Rational operator -(const Rational& r1, const Rational& r2)
{
	Rational result;
	result.set_numerator((int)((r1.get_numerator() * r2.get_denominator())-(r1.get_denominator() * r2.get_numerator())));
	result.set_denominator((int)(r1.get_denominator() * r2.get_denominator()));
	return result;
}

/*
 * Overloading * operator to perform rational multiplication
 * (a/b) * (c/d) = ac/bd
 * Param 1: First rational number (a/b)
 * Param 2: Second rational number (c/d)
 *
 * Return : Resulting rational number.
 * */
Rational operator *(const Rational& r1, const Rational& r2)
{
	Rational result;
	result.set_numerator((int)((r1.get_numerator() * r2.get_numerator())));
	result.set_denominator((int)(r1.get_denominator() * r2.get_denominator()));
	return result;
}


/*
 * Overloading / operator to perform rational division
 * (a/b) / (c/d) = ad/bc
 * Param 1: First rational number (a/b)
 * Param 2: Second rational number (c/d)
 *
 * Return : Resulting rational number.
 * */
Rational operator /(const Rational& r1, const Rational& r2)
{
	Rational result(0,1);
	result.set_numerator((int)((r1.get_numerator() * r2.get_denominator())));
	result.set_denominator((int)(r1.get_denominator() * r2.get_numerator()));

	// divide by zero condition for Rational number
	if(result.get_denominator() == 0)
		return Rational(0,1);

	return result;
}
