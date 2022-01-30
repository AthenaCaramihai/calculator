#include "Calculator.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

//Static attributes declaration
const double Calculator::PI = 3.14159265;
const double Calculator::E = 2.71;

//Default constructor
Calculator::Calculator()
{
	this->userName = new char[30];
	this->lastResults = new int[1000];
	this->numberOfResults = 0;
}

//Paramterized constructor
Calculator::Calculator(char* name)
{
	this->userName = new char[30];
	this->lastResults = new int[1000];
	strcpy(userName, name);
	this->numberOfResults = 0;

}

//Setter for userName
void Calculator::setName(char* name) {
	strcpy(userName, name);
}
char* Calculator::getName()
{
	return this->userName;
}

//Getter for userName
int* Calculator::getLastResults()
{
	return this->lastResults;
}

//Setter for lastResults
void Calculator::setResults(int* lastResults, int numberOfResults)
{
	if (lastResults != nullptr && numberOfResults > 0) {
		if (this->lastResults != nullptr) {
			delete[] this->lastResults;
		}
		this->lastResults = new int[numberOfResults];
		this->numberOfResults = numberOfResults;
		for (int i = 0; i < numberOfResults; i++)
			this->lastResults[i] = lastResults[i];
	}
}


//Getter for numberOfResults
int Calculator::getNumberOfResults()
{
	return numberOfResults;
}

//Copy constructor
Calculator::Calculator(const Calculator& c)
{
	strcpy(this->userName, c.userName);
	this->numberOfResults = c.numberOfResults;
	for (int i = 0; i < c.numberOfResults; i++)
	{
		this->lastResults[i] = c.lastResults[i];
	}
}

//Getter for mathmatical constants
const double Calculator::getPI()
{
	return PI;
}

const double Calculator::getE()
{
	return E;
}

//Class destructor
Calculator::~Calculator()
{
	delete[]userName;
	delete[]lastResults;
}

//Equals operator
Calculator& Calculator::operator=(const Calculator& c)
{
	
	if (this != &c)
	{
		 
		if (userName != nullptr)
		{
			delete[] userName;
			userName = nullptr;
		}

		if (lastResults != nullptr)
		{
			delete[] lastResults;
			lastResults = nullptr;
		}

		this->userName = new char[30];
		strcpy(this->userName, c.userName);
		this->lastResults = new int[1000];
		

		for (int i = 0; i <c.numberOfResults; i++)
		{
			this->lastResults[i] = c.lastResults[i];
		}

		this->numberOfResults = c.numberOfResults;
	}
	return *this;
}

//Less than operator
int Calculator::operator<(const Calculator& c)
{
	if (this->numberOfResults < c.numberOfResults)
		return 1;
	return 0;
}

//Cast operator
Calculator::operator char* () const
{
	return userName;
}

//Methods to compute the equations
int Calculator::add(int x, int y)
{
	lastResults[numberOfResults++] = x + y;
	return x + y;
}

int Calculator::sub(int x, int y)
{
	lastResults[numberOfResults++] = x - y;
	return x - y;
}

int Calculator::mult(int x, int y)
{
	lastResults[numberOfResults++] = x * y;
	return x*y;
}

int Calculator::div(int x, int y)
{
	lastResults[numberOfResults++] = x / y;
	return x/y;
}

int Calculator::pow(int x, int exp)
{
	int result = 1;
	for (int i = 0; i < exp; i++)
		result *= x;
	lastResults[numberOfResults++] = result;
	return result;
}

double Calculator::rad(int x)
{
	double result = sqrt(x);
	lastResults[numberOfResults++] = result;
	return result;
}

//Input-output stream overload operators
std::ostream& operator<<(std::ostream& out, Calculator& c)
{
	out <<"Name "<< c.userName<<std::endl;
	out << "Number of results " << c.numberOfResults << std::endl;
	out << "Last results\n";
	for (int i = 0; i < c.numberOfResults; i++)
		out << c.lastResults[i] << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Calculator& c)
{
	char* name = new char[30];
	std::cout << "Name: ";
	
	in >> name;
	c.setName(name);

	delete[] name;
	return in;
}
