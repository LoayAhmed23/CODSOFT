//to clear the console
#ifdef _WIN32
#define CLEAR_COMMAND "CLS"
#else
#define CLEAR_COMMAND "clear"
#endif

#include <iostream>
#include <vector>
using namespace std;


// draw the board
void drawBoard(vector<vector<char>>& board) {
    for (auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl;
        cout << "---------" << endl;
    }
}

// check who won
bool checkWin(vector<vector<char>>& board, char player) {
    //check vertical and horizontal
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    //check diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// check draw
bool checkDraw(vector<vector<char>>& board) {
    for (auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false; // if there is an empty cell -> game not done
        }
    }
    return true; // all cells are filled -> draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); //empty 3x3 board
    char currentPlayer = 'X'; // X starts
    bool gameover = false;


    while (!gameover) {
        cout << "Tic-Tac-Toe!" << endl;
        drawBoard(board);

        cout << "Player " << currentPlayer << "'s turn." << endl;

        // Get user input for row and column
        int row, col;
        do {
            cout << "Enter row (1, 2, or 3): ";
            cin >> row;
            row--;
        } while (row>2||row<0);
        do {
            cout << "Enter column (1, 2, or 3): ";
            cin >> col;
            col--;
        } while (col > 2 || col<0);


        if (board[row][col] == ' ') {        // check if cell is empty
            board[row][col] = currentPlayer;
            // check if current player won
            if (checkWin(board, currentPlayer)) {
                drawBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameover = true;
            }
            //check if draw
            else if (checkDraw(board)) {
                drawBoard(board);
                cout << "It's a draw!" << endl;
                gameover = true;
            }
            else {
                // Switch player if no win or draw
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                system(CLEAR_COMMAND); // clear console

            }
        }
        else {
            system(CLEAR_COMMAND); // clear console
            cout << "That cell is already taken. Try again." << endl;
        }
    }

    return 0;
}
