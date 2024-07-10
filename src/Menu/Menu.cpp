#include "../../include/Menu/Menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
{
}

int Menu::choiceMainMenu()
{
    int choice;
    // setColor.SetColor();
    cout << CYAN << "* - - - MAIN MENU - - -*" << RESET << endl;
    cout << CYAN<< "1."<< RESET << " Play with other player" << endl;
    cout << CYAN<< "2."<< RESET << " Play with Bot" << endl;
    cout << CYAN<< "3."<< RESET << " Watch Match" << endl;
    cout << CYAN<< "4."<< RESET << " Player's Information" << endl;
    cout << CYAN<< "5."<< RESET << " Guild" << endl;
    cout << CYAN<< "6."<< RESET << " Setting" << endl;
    cout << CYAN<< "7."<< RESET << " Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int Menu::choicePlayWithBot()
{
    int choice;
    cout << CYAN << "* - - - Play with Bot - - -*" << RESET << endl;
    cout << GREEN << "1. Easy" << RESET << endl;
    cout << YELLOW << "2. Normal" << RESET << endl;
    cout << RED << "3. Hard" << RESET << endl;
    cout << "0. Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

Menu::~Menu()
{
}