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

void displayGuesses(int arr[], int counter) {
    for (int i = 0; i < counter; i++) {
        if (i == counter - 1) {
            cout << arr[i];
        }
        else {
            cout << arr[i] << ", ";
        }
    }



}

void gameplayLoop(int choice, int gameType) {
    int attempts = 5;
    int guess = 0;
    int randNum = 0;
    int valueArray[] = { 10, 100, 1000 };
    int previousGuessArray[5] = {0};
    int counter = 0;

    if (choice == 1) {
        randNum = rand() % 10;
    }
    else if (choice == 2) {
        randNum = rand() % 100;
    }
    else {
        randNum = rand() % 1000;
    }

    while (attempts != 0) {

        if (previousGuessArray[0] != 0) {
            cout << "Previous guesses are: ";
            displayGuesses(previousGuessArray, counter);
            cout << endl;
        }

        cout << "Enter a number between 1 and " << valueArray[choice - 1] << endl;
        cin >> guess;
        if (cin.fail()) {
            cout << "Must enter a valid integer";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            if (guess > randNum || guess < randNum) {
                cout << "Incorrect guess" << endl;

                previousGuessArray[counter] = guess;
                counter++;

                attempts--;
            }
        }

        if (attempts == 0) {
            cout << "Too bad, looks like you couldn't get the right guess. The correct number was " << randNum << ". You can always try again" << endl;
        }

    }

    attempts = 5;
   
}

int main()
{
    int userChoice = 0;
    int userGuess = 0;
    int userAttempt = 5;

    while (true) {
        cout << "Welcome to the Number Guessing Game!\n" << "Choose an option below to get started\n" << "1. Easy Mode\n" << "2. Hard Mode\n" << "3. Exit" << endl;
        cin >> userChoice;

        if (cin.fail()) {
            cout << "Invalid response" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if (userChoice == 3) {
            break;
        }

        if (userChoice == 1) {
            printMenu();
            cin >> userChoice;
            if (cin.fail()) {
                cout << "Invalid response" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (userChoice < 1 || userChoice > 3) {
                cout << "Response must be between 1 and 3" << endl;
            }
            else {
                gameplayLoop(userChoice, 0);
            }
        }

        if (userChoice == 2) {
            printMenu();
            cin >> userChoice;
        }

    }
    return 0;
}


