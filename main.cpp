#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "TicTacToe.h"

using namespace std;

void DisplayMenu();

void DisplayMenu(string *P1, string *P2);

void NewGame();

int main() {
    int choice;

    do {
        DisplayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                NewGame();
                break;
            case 2:
                cout << "Thank you for playing Tic Tac Toe" << endl;
                getch();
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
        system("cls");
    } while (choice != 2);
    return 0;
}

void DisplayMenu() {
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|   TIC TAC TOE - std:222529018     |" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;

    cout << "1. New Game" << endl;
    cout << "2. Exit" << endl;
    cout << "Choice: ";
}

void DisplayMenu(string *P1, string *P2){
    system("cls");
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|   TIC TAC TOE - std:222529018     |" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "Enter the name of Player One: ";
    cin >> *P1;

    cout << "Enter the name of Player Two: ";
    cin >> *P2;
}

void NewGame(){
    string player1;
    string player2;

    DisplayMenu(&player1, &player2);

    TTT game = TTT(player1, player2);
    game.StartTTT();
}