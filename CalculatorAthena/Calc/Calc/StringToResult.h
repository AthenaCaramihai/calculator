#define _CRT_SECURE_NO_WARNINGS
#ifndef STRINGTORESULT_HEADER
#define STRINGTORESULT_HEADER
#include "Calculator.h"
#include <iostream>

class StringToResult
{
private:
	char* toSolve;
	int result;
	int* to;
	int* que;
	int read_pos;
	int size;

	//static atributte
	//!!!!!!!!!!!!
	const int max = 1000;

	//Methods
	int read(int s);
	int solve(int l, int r);

public:

	//Default constructor
	StringToResult();

	//Parameterized constructor
	StringToResult(char* str);

	//Copy constructor
	StringToResult(const StringToResult& str);

	//Setter for toSolve
	void setStringToSolver(char* str);
	//Getter for toSolve
	char* getToSolver();

	//Getter for result
	int getResult();

	//Equals operator
	StringToResult& operator=(const StringToResult& c);

	//Input-output stream overload operators
	friend std::ostream& operator<<(std::ostream& out, StringToResult& c);
	friend std::istream& operator>>(std::istream& in, StringToResult& c);

	//Plus operator
	StringToResult& operator+(const StringToResult& c);

	//Function operator
	operator int() const;

	//Method
	void process_equation();

	//Class destructor
	~StringToResult();


};
#endif
