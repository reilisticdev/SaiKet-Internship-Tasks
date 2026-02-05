#include <iostream>
#include <limits> // For input cleaning
#include <string> 

using namespace std;

// --- GLOBAL VARIABLES ---
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';
string player1Name = "Player 1";
string player2Name = "Player 2";

// --- FUNCTIONS ---

// 1. Draw the Board (The Visuals)
void drawBoard() {
    // Clear screen hack (works on Windows)
    system("cls");

    cout << "\n   TIC - TAC - TOE   " << endl;
    cout << "=====================" << endl;
    cout << " " << player1Name << " (X)  -  " << player2Name << " (O)" << endl;
    cout << "=====================\n" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
    cout << "\n=====================" << endl;
}

// 2. Logic: Did someone win?
bool checkWin() {
    // Check Rows & Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Cols
    }
    // Check Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

// 3. Logic: Is it a draw?
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false; // Found a number, not full yet
    return true;
}

// 4. Logic: Switch Turns
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// 5. Logic: Place Marker
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

// --- MAIN GAME LOOP ---
int main() {
    cout << "Enter name for Player 1 (X): ";
    getline(cin, player1Name);
    cout << "Enter name for Player 2 (O): ";
    getline(cin, player2Name);

    drawBoard();

    while (true) {
        cout << "\n" << (currentPlayer == 'X' ? player1Name : player2Name) << ", enter a slot (1-9): ";
        int slot;
        cin >> slot;

        // Input Validation (Prevent crashes)
        if (cin.fail() || slot < 1 || slot > 9) {
            cin.clear(); // Reset error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            cout << "Invalid input! Please enter a number 1-9." << endl;
            // Wait for user to read message
            cin.ignore();
            cin.get();
            continue;
        }

        if (placeMarker(slot)) {
            drawBoard();

            if (checkWin()) {
                cout << "\n*******************************" << endl;
                cout << "  WINNER: " << (currentPlayer == 'X' ? player1Name : player2Name) << "!" << endl;
                cout << "*******************************\n" << endl;
                break;
            }
            if (checkDraw()) {
                cout << "\n*******************************" << endl;
                cout << "  DRAW GAME!" << endl;
                cout << "*******************************\n" << endl;
                break;
            }
            switchPlayer();
        }
        else {
            cout << "Spot taken! Try another one." << endl;
            cin.ignore();
            cin.get(); // Pause so they see the error
            drawBoard();
        }
    }

    // Keep window open at end
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}