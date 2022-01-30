#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "Calculator.h"
#include "StringToResult.h"
class Menu
{
	char* name;
	const char strWelcome[100] = { "Welcome " };

public:

	//Default constructor
	Menu();

	//Parameterized constructor 
	Menu(char* n);

	//Copy constructor
	Menu(const Menu& m);

	//Equals operator
	Menu& operator=(const Menu& m);

	//Setter for name
	void setName(char* n);

	//Getter for name
	char* getName();

	//Method for displaying Welcome
	void printWelcome();

	//Method for choices
	void show();

	//Class destructor
	~Menu();
};