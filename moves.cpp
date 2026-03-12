#include "moves.h"
#include "board.h"

char toSmall(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + 32;
    }
    return ch;
}

bool isWhitePiece(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

bool isBlackPiece(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

bool isPathClearStraight(int row1, int col1, int row2, int col2)
{
    if (row1 == row2)
    {
        int start, end;

        if (col1 < col2)
        {
            start = col1 + 1;
            end = col2;
        }
        else
        {
            start = col2 + 1;
            end = col1;
        }

        for (int i = start; i < end; i++)
        {
            if (board[row1][i] != '.')
            {
                return false;
            }
        }
    }
    else if (col1 == col2)
    {
        int start, end;

        if (row1 < row2)
        {
            start = row1 + 1;
            end = row2;
        }
        else
        {
            start = row2 + 1;
            end = row1;
        }

        for (int i = start; i < end; i++)
        {
            if (board[i][col1] != '.')
            {
                return false;
            }
        }
    }

    return true;
}

bool isPathClearDiagonal(int row1, int col1, int row2, int col2)
{
    int rowStep;
    int colStep;

    if (row2 > row1)
    {
        rowStep = 1;
    }
    else
    {
        rowStep = -1;
    }

    if (col2 > col1)
    {
        colStep = 1;
    }
    else
    {
        colStep = -1;
    }

    int i = row1 + rowStep;
    int j = col1 + colStep;

    while (i != row2 && j != col2)
    {
        if (board[i][j] != '.')
        {
            return false;
        }

        i += rowStep;
        j += colStep;
    }

    return true;
}

bool validPawnMove(int row1, int col1, int row2, int col2, char piece)
{
    if (piece == 'P')
    {
        if (col1 == col2 && row2 == row1 - 1 && board[row2][col2] == '.')
        {
            return true;
        }

        if (col1 == col2 && row1 == 6 && row2 == 4 && board[5][col1] == '.' && board[4][col1] == '.')
        {
            return true;
        }

        if ((col2 == col1 + 1 || col2 == col1 - 1) && row2 == row1 - 1 && isBlackPiece(board[row2][col2]))
        {
            return true;
        }
    }
    else if (piece == 'p')
    {
        if (col1 == col2 && row2 == row1 + 1 && board[row2][col2] == '.')
        {
            return true;
        }

        if (col1 == col2 && row1 == 1 && row2 == 3 && board[2][col1] == '.' && board[3][col1] == '.')
        {
            return true;
        }

        if ((col2 == col1 + 1 || col2 == col1 - 1) && row2 == row1 + 1 && isWhitePiece(board[row2][col2]))
        {
            return true;
        }
    }

    return false;
}

bool validRookMove(int row1, int col1, int row2, int col2)
{
    if (row1 == row2 || col1 == col2)
    {
        return isPathClearStraight(row1, col1, row2, col2);
    }

    return false;
}

bool validBishopMove(int row1, int col1, int row2, int col2)
{
    if ((row2 - row1 == col2 - col1) || (row2 - row1 == -(col2 - col1)))
    {
        return isPathClearDiagonal(row1, col1, row2, col2);
    }

    return false;
}

bool validKnightMove(int row1, int col1, int row2, int col2)
{
    int dr = row1 - row2;
    if (dr < 0)
    {
        dr = -dr;
    }

    int dc = col1 - col2;
    if (dc < 0)
    {
        dc = -dc;
    }

    if ((dr == 2 && dc == 1) || (dr == 1 && dc == 2))
    {
        return true;
    }

    return false;
}

bool validQueenMove(int row1, int col1, int row2, int col2)
{
    if (row1 == row2 || col1 == col2)
    {
        return isPathClearStraight(row1, col1, row2, col2);
    }

    if ((row2 - row1 == col2 - col1) || (row2 - row1 == -(col2 - col1)))
    {
        return isPathClearDiagonal(row1, col1, row2, col2);
    }

    return false;
}

bool validKingMove(int row1, int col1, int row2, int col2)
{
    int dr = row1 - row2;
    if (dr < 0)
    {
        dr = -dr;
    }

    int dc = col1 - col2;
    if (dc < 0)
    {
        dc = -dc;
    }

    if (dr <= 1 && dc <= 1)
    {
        return true;
    }

    return false;
}

bool isValidMove(int row1, int col1, int row2, int col2)
{
    if (row1 < 0 || row1 > 7 || row2 < 0 || row2 > 7 || col1 < 0 || col1 > 7 || col2 < 0 || col2 > 7)
    {
        return false;
    }

    char piece = board[row1][col1];
    char target = board[row2][col2];

    if (piece == '.')
    {
        return false;
    }

    if (whiteTurn)
    {
        if (!isWhitePiece(piece))
        {
            return false;
        }

        if (isWhitePiece(target))
        {
            return false;
        }
    }
    else
    {
        if (!isBlackPiece(piece))
        {
            return false;
        }

        if (isBlackPiece(target))
        {
            return false;
        }
    }

    char p = toSmall(piece);

    if (p == 'p')
    {
        return validPawnMove(row1, col1, row2, col2, piece);
    }

    if (p == 'r')
    {
        return validRookMove(row1, col1, row2, col2);
    }

    if (p == 'n')
    {
        return validKnightMove(row1, col1, row2, col2);
    }

    if (p == 'b')
    {
        return validBishopMove(row1, col1, row2, col2);
    }

    if (p == 'q')
    {
        return validQueenMove(row1, col1, row2, col2);
    }

    if (p == 'k')
    {
        return validKingMove(row1, col1, row2, col2);
    }

    return false;
}

void movePiece(int row1, int col1, int row2, int col2)
{
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = '.';

    if (board[row2][col2] == 'P' && row2 == 0)
    {
        board[row2][col2] = 'Q';
    }

    if (board[row2][col2] == 'p' && row2 == 7)
    {
        board[row2][col2] = 'q';
    }
}