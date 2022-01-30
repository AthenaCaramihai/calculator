#include "StringToResult.h"
#include "Calculator.h"
#include "Exceptions.h"
#include <math.h>
int check = 0;

//Method read
int StringToResult::read(int s)
{
	int ans = 0, f = 1;
	if (toSolve[s] == '(')
	{
		ans = solve(s + 1, to[s] - 1);
		read_pos = to[s] + 1;
		return ans;
	}
	else if (toSolve[s] == '-') f = -1, s += 1;
	for (; (toSolve[s] >= '0' && toSolve[s] <= '9'); s++)
		ans = ans * 10 + toSolve[s] - '0';
	read_pos = s;
	return ans * f;
}

//Method solve
int StringToResult::solve(int l, int r)
{
	Exceptions myex;
	int** stack = new int* [2];
	for (int i = 0; i < 2; i++)
		stack[i] = new int[max];


	//Daca o linie este gresita in try, se va apela catch
	try {
		int length = 0;
		if (toSolve[l] != '-')
			stack[0][++length] = 1, stack[1][length] = read(l);
		else stack[0][++length] = -1, stack[1][length] = read(l + 1);
		l = read_pos;
		int temp;
		double temp2;

		while (l <= r) {
			if (toSolve[l] == '+')
				stack[0][++length] = 1, stack[1][length] = read(l + 1);
			else if (toSolve[l] == '-')
				stack[0][++length] = -1, stack[1][length] = read(l + 1);
			else if (toSolve[l] == '*')
				temp = read(l + 1), stack[1][length] *= temp;
			else if (toSolve[l] == '#')
				temp = read(l + 1), temp2 = (double)temp, stack[1][length] = pow((double)stack[1][length], 1. / temp2 + 0.000001);
			else if (toSolve[l] == '^')
				temp = read(l + 1), stack[1][length] = pow(stack[1][length], temp);

			else {
				temp = read(l + 1);
				if (temp == 0)
					throw myex;
				stack[1][length] /= temp;

			}
			l = read_pos;
		}
		int result = 0;
		for (int i = 1; i <= length; i++)
			result += (stack[0][i] * stack[1][i]);
		return result;
	}

	catch (Exceptions& e)
	{
		check = 1;
		std::cout << e.what();

	}

}



//Default constructor
StringToResult::StringToResult()
{

	toSolve = new char[max];
	to = new int[max];
	que = new int[max];
}

//Paramterized constructor
StringToResult::StringToResult(char* str)
{
	toSolve = new char[max];
	to = new int[max];
	que = new int[max];
	strcpy(this->toSolve, str);
}

//Copy constructor
StringToResult::StringToResult(const StringToResult& str)
{
	strcpy(this->toSolve, str.toSolve);
	result = str.result;
}

//Setter for toSolve
void StringToResult::setStringToSolver(char* str)
{
	strcpy(this->toSolve, str);
}

//Getter for toSolve
char* StringToResult::getToSolver()
{
	return this->toSolve;
}

//Getter for result
int StringToResult::getResult()
{
	return this->result;
}


//Equals operator
StringToResult& StringToResult::operator=(const StringToResult& c)
{
	if (this != &c)
	{
		if (toSolve != nullptr)
		{
			delete[] toSolve;
			toSolve = nullptr;
		}
		this->toSolve = new char[max];
		strcpy(this->toSolve, c.toSolve);

		this->result = c.result;
	}
	return *this;
}


//Plus operator
StringToResult& StringToResult::operator+(const StringToResult& c)
{
	strcat(toSolve, "+");
	strcat(toSolve, c.toSolve);
	process_equation();
	return *this;
}

//Function operator
StringToResult::operator int() const
{
	return result;
}


//method for
void StringToResult::process_equation()
{
	int length = strlen(toSolve);

	//Daca introducem un singur numar, afisam un mesaj sa setam o ecuatie
	if (length < 2)
		std::cout << "Setati ecuatia!" << std::endl;
	else {
		Exceptions myex;

		try {
			for (int i = 0; i < length; i++) {
				if (toSolve[i] == '[')
					toSolve[i] = '('; //change [ into (
				else if (toSolve[i] == ']')
					toSolve[i] = ')';
			}
			int l = 0;
			int r = 0;

			for (int i = 0; i < length; i++)
			{
				if (toSolve[i] == '(')
					l++;		//numara cate paranteze deschise avem
				if (toSolve[i] == ')')
					r++;		//numara cate paranteze inchise avem
			}

			if (l != r)		//daca numarul parantezelor deschise este diferit de numarul parantezelor inchise =>
				throw myex;


			for (int i = 0; i < length; i++)
			{
				if (toSolve[i] == '(')	//numara pozitia parantezei deschise
					que[++size] = i;
				else if (toSolve[i] == ')')  //numara pozitia parantezei inchise
					to[que[size]] = i, size -= 1;
			}

			result = solve(0, length - 1);
			if (check == 0)
				std::cout << result;
			check = 0;
		}
		catch (Exceptions& e)
		{
			std::cout << e.what();
		}
	}
}

StringToResult::~StringToResult()
{
	delete[] toSolve;
	delete[] to;
	delete[] que;
}


std::ostream& operator<<(std::ostream& out, StringToResult& c)
{

	out << std::endl << "String solved :" << c.toSolve;
	out << std::endl << "Result: " << c.result << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, StringToResult& c)
{
	char* str = new char[100];
	std::cout << "String to solve: ";
	in >> str;
	c.setStringToSolver(str);

	delete[] str;
	return in;
}
