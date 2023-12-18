#include <iostream>

using namespace std;

void printMenu() {
    cout << "Select a game mode\n" << "1. 1 and 10\n" << "2. 1 and 100\n" << "3. 1 and 1000" << endl;
}

bool validateChoice(int num) {
    if (num < 1 || num > 3) {
        cout << "Number must be between 1 and 3";
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    int userChoice = 0;
    int userGuess = 0;
    int userAttempt = 5;

    while (true) {
        cout << "Welcome to the Number Guessing Game!\n" << "Choose an option below to get started\n" << "1. Easy Mode\n" << "2. Hard Mode\n" << "3. Exit" << endl;
        cin >> userChoice;

        if (cin.fail() || validateChoice(userChoice)) {
            cout << "Invalid response" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        }

        if (userChoice == 3) {
            break;
        }

        if (userChoice == 1) {
            printMenu();
            cin >> userChoice;
        }

        if (userChoice == 2) {
            printMenu();
        }

    }
    return 0;
}


