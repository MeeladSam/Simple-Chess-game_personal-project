#ifndef BOARD_H
#define BOARD_H

extern char board[8][8];
extern bool whiteTurn;

void setupBoard();
void printBoard();
bool kingExists(char kingChar);

#endif