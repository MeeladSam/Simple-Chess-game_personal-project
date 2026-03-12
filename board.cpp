#include <iostream>
#include "board.h"

using namespace std;

char board[8][8];
bool whiteTurn = true;

void setupBoard()
{
    char temp[8][8] =
    {
        {'r','n','b','q','k','b','n','r'},
        {'p','p','p','p','p','p','p','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'P','P','P','P','P','P','P','P'},
        {'R','N','B','Q','K','B','N','R'}
    };

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = temp[i][j];
        }
    }
}

void printBoard()
{
    cout << "\n  a b c d e f g h\n";

    for (int i = 0; i < 8; i++)
    {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << 8 - i << endl;
    }

    cout << "  a b c d e f g h\n\n";
}

bool kingExists(char kingChar)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == kingChar)
            {
                return true;
            }
        }
    }
    return false;
}