#include <iostream>
#include "board.h"
#include "moves.h"

using namespace std;

int main()
{
    setupBoard();

    while (true)
    {
        printBoard();

        if (!kingExists('K'))
        {
            cout << "Black wins\n";
            break;
        }

        if (!kingExists('k'))
        {
            cout << "White wins\n";
            break;
        }

        cout << (whiteTurn ? "White" : "Black") << " move\n";

        char c1, c2;
        int r1, r2;

        cout << "from: ";
        cin >> c1 >> r1;

        cout << "to: ";
        cin >> c2 >> r2;

        int col1 = c1 - 'a';
        int col2 = c2 - 'a';
        int row1 = 8 - r1;
        int row2 = 8 - r2;

        if (!isValidMove(row1, col1, row2, col2))
        {
            cout << "Invalid move\n";
            continue;
        }

        movePiece(row1, col1, row2, col2);
        whiteTurn = !whiteTurn;
    }

    return 0;
}