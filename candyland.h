#ifndef __CANDYLAND_H
#define __CANDYLAND_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct square{
  char *color;
  char *special;
  int x;
}square_t;

typedef struct board{
   square_t *item;
   struct board *next;
   struct board *prev;
}board_t;

square_t *createSquare(char *color, char *special, int x);
void createBoard(FILE *myFile);
board_t *createSpace();
board_t *insertOnBoard(board_t *parent, board_t *space);
void traverse(board_t *start);
int randomNumber(int upperBound);






#endif
