#include <iostream>
#include "src/lab5.hpp"
#include <string>

using namespace std;

CircularLinkedList<string> buildMonopolyBoard();

int main() {
    auto board = buildMonopolyBoard();

    cout << "Welcome to Monopoly!\n";
    cout << "------------------------------------------\n";
    cout << "Type 'r' to roll the dice, 'q' to quit.\n\n";

    char input;
    while (true) {
        cout << "You are currently on: " << board.getCurrent() << "\n";
        cout << "> ";
        cin >> input;

        if (input == 'q') {
            cout << "Goodbye!\n";
            break;
        } else if (input == 'r') {
            int roll = board.rollAndMove();
            cout << "You rolled a " << roll << "!\n";
            cout << "Now you are on: " << board.getCurrent() << "\n\n";
        } else {
            cout << "Invalid input. Type 'r' or 'q'.\n";
        }
    }

    return 0;
}
