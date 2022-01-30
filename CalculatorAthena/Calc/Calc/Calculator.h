#define _CRT_SECURE_NO_WARNINGS
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <ostream>
#include <istream>
 

class Calculator
{
private:
	char* userName;
	int *lastResults;
	int numberOfResults;

	static const double PI;
	static const double E;
	

public:

	//Default constructor
	Calculator();

	//Parameterized constructor
	Calculator(char* name);

	//Copy constructor
	Calculator(const Calculator& calc);
	
	//Setter for userName
	void setName(char* name);

	//Getter for userName
	char* getName();


	//Getter for numberOfResults
	int getNumberOfResults();

	//Setter for lastResults
	void setResults(int* lastResults, int numberOfResults);

	//Getter for lastResults
	int* getLastResults();

	//Getter for mathmatical constants
	static const double getPI();
	static const double getE();
	

	//Equals operator
	Calculator& operator=(const Calculator& c);

	//Input-output stream overload operators
	friend std::ostream& operator<<(std::ostream& out, Calculator& c);
	friend std::istream& operator>>(std::istream& in, Calculator& c);

	//Less than operator
	int operator<(const Calculator& c);

	//Cast operator
	operator char* () const ;

	//Methods to compute the equations
	int add(int x, int y);
	int sub(int x, int y);
	int mult(int x, int y);
	int div(int x, int y);
	int pow(int x, int exp);
	double rad(int x );

	//Class destructor
	~Calculator();
};

#endif