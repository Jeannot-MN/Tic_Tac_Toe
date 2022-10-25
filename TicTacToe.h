#include <iostream>

using namespace std;

class TTT {

private:
    string P1;
    string P2;
    int Board[3][3] = {{0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0}};

public:
    TTT(string P1, string P2);

    void StartTTT();

    void DisplayBoard();

    int CheckProgress();

    int CheckAndPlaceInput(int PlayerTurn);
};

TTT::TTT(string P1, string P2) {
    this->P1 = P1;
    this->P2 = P2;
}

void TTT::StartTTT() {
    int playerTurn = 1;
    int gameProgress;
    do {
        DisplayBoard();
        CheckAndPlaceInput(playerTurn);

        gameProgress = CheckProgress();
        playerTurn = (playerTurn % 2) + 1;

        DisplayBoard();
        if (gameProgress == 1) {
            cout << P1 << " (Player1) wins the game!" << endl;
        } else if (gameProgress == 2) {
            cout << P2 << " (Player2) wins the game!" << endl;
        } else if (gameProgress == 3) {
            cout << "Tie between " << P1 << "(Player1) and  "<< P2 << " (Player2)" << endl;
        }
    } while (gameProgress == 0);
    cout << "Press any key to continue..." << endl;
    getch();
}

void TTT::DisplayBoard() {
    system("cls");
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|   TIC TAC TOE - std:222529018     |" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;

    for (int r = 0; r < 3; r++) {
        cout << "\t" << "+-+-+-+-+-+-+" << endl;
        cout << "\t";
        for (int c = 0; c < 3; c++) {
            if (Board[r][c] == 0) {
                cout << "|   ";
            } else {
                cout << "| " << Board[r][c] << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "\t" << "+-+-+-+-+-+-+" << endl;
}

int TTT::CheckProgress() {
    for (int r = 0; r < 3; r++) {
        if (Board[r][0] != 0 && Board[r][0] == Board[r][1] && Board[r][0] == Board[r][2]) return Board[r][0];
    }

    for (int c = 0; c < 3; c++) {
        if (Board[0][c] != 0 && Board[0][c] == Board[1][c] && Board[0][c] == Board[2][c]) return Board[0][c];
    }

    if (Board[0][0] != 0 && Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2]) return Board[0][0];

    if (Board[0][2] != 0 && Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0]) return Board[0][2];

    bool isBoardFull = true;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if(Board[r][c] == 0) isBoardFull = false;
        }
    }
    if(isBoardFull) return 3;

    return 0;
}

int TTT::CheckAndPlaceInput(int PlayerTurn) {
    int row, col;

    cout << ((PlayerTurn == 1) ? P1 : P2) << " select placement(1-3:1-3)" << endl;
    do {
        do {
            cout << "Row: ";
            cin >> row;
            if (row < 1 || row > 3) {
                cout << "Invalid row address" << endl;
            }
        } while (row < 1 || row > 3);

        cout << "Column: ";
        cin >> col;
        if (col < 1 || col > 3) {
            cout << "Invalid column address" << endl;
            continue;
        }

        if (Board[row - 1][col - 1] != 0) {
            cout << "Invalid board placement, position is already occupied" << endl;
        }
    } while (col < 1 || col > 3 || Board[row - 1][col - 1] != 0);

    Board[row - 1][col - 1] = PlayerTurn;
    return 0;
}