#include <iostream>
using namespace std;

void init(char board[8][8]) 
{
    char initialPieces[8] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
    for (int i = 0; i < 8; ++i)
    {
        board[0][i] = initialPieces[i];
        board[1][i] = 'P'; 
        board[6][i] = 'p'; 
        board[7][i] = tolower(initialPieces[i]);
        for (int j = 2; j < 6; ++j)
        {
            board[j][i] = ' '; 
        }
    }
}
void displayBoard(const char board[8][8])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValidCoordinate(int x, int y) 
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int main()
{
    char board[8][8];
    init(board);

    bool gameOver = false;
    int turn = 0; 
    while (!gameOver)
    {
        displayBoard(board);

        int startX, startY, endX, endY;

        cout << "Player " << (turn + 1) << ", enter the coordinates of the piece you want to move (x y): ";
        cin >> startX >> startY;
        cout << "Enter the coordinates of the destination (x y): ";
        cin >> endX >> endY;

        if (!isValidCoordinate(startX, startY) || !isValidCoordinate(endX, endY))
        {
            cout << "Invalid coordinates! Try again." << endl;
            continue;
        }

  
        char selectedPiece = board[startX][startY];
        if ((turn == 0 && islower(selectedPiece)) || (turn == 1 && isupper(selectedPiece))) 
        {
            cout << "It's not your piece! Try again." << endl;
            continue;
        }

        if (board[endX][endY] != ' ' && ((turn == 0 && !islower(board[endX][endY])) || (turn == 1 && !isupper(board[endX][endY])))) 
        {
            cout << "Illegal move! Try again." << endl;
            continue;
        }

        board[endX][endY] = selectedPiece;
        board[startX][startY] = ' ';

        turn = (turn + 1) % 2;
    }

    return 0;
}
