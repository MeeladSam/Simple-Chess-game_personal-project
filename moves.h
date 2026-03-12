#pragma once
#ifndef MOVES_H
#define MOVES_H

char toSmall(char ch);
bool isWhitePiece(char ch);
bool isBlackPiece(char ch);

bool isPathClearStraight(int row1, int col1, int row2, int col2);
bool isPathClearDiagonal(int row1, int col1, int row2, int col2);

bool validPawnMove(int row1, int col1, int row2, int col2, char piece);
bool validRookMove(int row1, int col1, int row2, int col2);
bool validBishopMove(int row1, int col1, int row2, int col2);
bool validKnightMove(int row1, int col1, int row2, int col2);
bool validQueenMove(int row1, int col1, int row2, int col2);
bool validKingMove(int row1, int col1, int row2, int col2);

bool isValidMove(int row1, int col1, int row2, int col2);
void movePiece(int row1, int col1, int row2, int col2);

#endif