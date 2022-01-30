#include "Menu.h"


//Default constructor
Menu::Menu()
{
	name = new char[30];
}

//Paramterized constructor
Menu::Menu(char* n)
{
	name = new char[30];
	strcpy(name, n);
}

//Copy constructor
Menu::Menu(const Menu& m)
{
	strcpy(name, m.name);
}

Menu::~Menu()
{
	delete[] name;
}

//Equals operator
Menu& Menu::operator=(const Menu& m)
{
	if (this != &m)
	{
		delete[] name;
		this->name = new char[strlen(m.name) + 1];
		strcpy_s(this->name, strlen(m.name) + 1, m.name);
	}
	return *this;
}

//Setter for name
void Menu::setName(char* n)
{
	strcpy(name, n);
}

//Getter for name
char* Menu::getName()
{
	return name;
}

//Method for displaying Welcome
void Menu::printWelcome()
{
	std::cout << strWelcome << " to the best Scientific Calculator, " << name << " !!!";

}

//Method for choices
void Menu::show()
{
	Calculator c = Calculator();
	StringToResult s = StringToResult();
	int option;

	while (true) {
		std::cout << "1.Adunarea a doua numere" << std::endl;
		std::cout << "2.Scaderea a doua numere" << std::endl;
		std::cout << "3.Inmultirea a doua numere" << std::endl;
		std::cout << "4.Impartirea a doua numere" << std::endl;
		std::cout << "5.Ridicare la o putere" << std::endl;
		std::cout << "6.Radical" << std::endl;
		std::cout << "7.Rezolvare input complex" << std::endl;
		std::cout << "8.Exit" << std::endl;
		std::cout << "Alege optiune: " << std::endl;

		std::cin >> option;

		if (option == 1)
		{
			int x, y;
			std::cout << "Primul numar" << std::endl;
			std::cin >> x;
			std::cout << "Al doilea numar" << std::endl;
			std::cin >> y;

			int result = c.add(x, y);

			std::cout << "Rezultat: " << result << std::endl;
		}

		if (option == 2)
		{
			int x, y;
			std::cout << "Primul numar" << std::endl;
			std::cin >> x;
			std::cout << "Al doilea numar" << std::endl;
			std::cin >> y;

			int result = c.sub(x, y);

			std::cout << "Rezultat: " << result << std::endl;
		}
		if (option == 3)
		{
			int x, y;
			std::cout << "Primul numar" << std::endl;
			std::cin >> x;
			std::cout << "Al doilea numar" << std::endl;
			std::cin >> y;

			int result = c.mult(x, y);

			std::cout << "Rezultat: " << result << std::endl;
		}
		if (option == 4)
		{
			int x, y;
			std::cout << "Primul numar" << std::endl;
			std::cin >> x;
			std::cout << "Al doilea numar" << std::endl;
			std::cin >> y;

			int result = c.div(x, y);

			std::cout << "Rezultat: " << result << std::endl;
		}
		if (option == 5)
		{
			int x, y;
			std::cout << "Numarul: " << std::endl;
			std::cin >> x;
			std::cout << "Puterea: " << std::endl;
			std::cin >> y;

			int result = c.pow(x, y);

			std::cout << "Rezultat: " << result << std::endl;
		}
		if (option == 6)
		{
			int x;
			std::cout << "Numarul: " << std::endl;
			std::cin >> x;


			double result = c.rad(x);

			std::cout << "Rezultat: " << result << std::endl;
		}
		if (option == 7)
		{
			char* str;
			str = new char[100];
			std::cout << "Input: ";
			std::cin >> str;
			s.setStringToSolver(str);
			std::cout << "Rezultat: ";
			s.process_equation();
			std::cout << std::endl;
		}
		if (option == 8)
		{
			std::cout << "Bye" << std::endl;
			break;
		}
		std::cout << std::endl;

	}
}
