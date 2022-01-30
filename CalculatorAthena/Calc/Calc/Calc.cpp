#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Calculator.h"
#include "StringToResult.h"
#include "Exceptions.h"
#include "Menu.h"

int main()
{
    
    char* nume = new char[30];
    std::cout << "Nume utilizator: ";
    std::cin >> nume;
    Menu m = Menu(nume);
    m.printWelcome();
    std::cout << std::endl;
    m.show();
        
      
       
        
    
    system("pause");
}
