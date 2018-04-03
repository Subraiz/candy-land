#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "candyland.h"

board_t *start;

board_t *insertOnBoard(board_t *parent, board_t *child){
  if(parent == NULL){
    parent = child;
    start = parent;
    return start;
  }
  else{
    while (parent->next != NULL) {
      parent = parent->next;
    }
    parent->next = child;
    child->prev = parent;
    return start;
  }
}

board_t *createSpace(){ // This function simply creates a new node in this case the node is just a square on the board.
  board_t *new = (board_t*)malloc(sizeof(board_t));
  new->item = NULL;
  new->prev = NULL;
  new->next = NULL;

  return new;
}

void createBoard(FILE *myFile){
  char dummy; // This is here to take in the '\n' and start reading the next line.

  while (!feof(myFile)) { // Run this part until it is at the last line of the file.
    char *color = (char*)malloc(10);
    char *special = (char*)malloc(10);
    int x = 0;

    board_t *node = createSpace(); // Creates a new node.

    fscanf(myFile, "%s%s%d%c", color, special, &x, &dummy); // Scans the file for information.

    node->item = createSquare(color, special, x); // Creates the payload for the Node.
    insertOnBoard(start, node); // Inserts the node onto the board starting with the start space.
  }

  /*if (feof(myFile)) {
    puts("Done Reading.");
  }*/

}

square_t *createSquare(char *color, char *special, int x){ // This creates the information for the square.
  square_t *square = (square_t*)malloc(sizeof(square_t));

  square->color = color;
  square->special = special;
  square->x = x;

  return square;
}

void traverse(board_t *start){ // This function was just to test if the board was made correctly.
  board_t *temp = start;

  while (temp->next != NULL) {
    printf("%s %s %d\n", temp->item->color, temp->item->special, temp->item->x); // Print out all of the board information.
    temp = temp->next;
  }

}

int randomNumber(int upperBound){
//this is the simple rn generator that generates a random number between 1 and upperBound
    int j;
    j=1+(rand() % upperBound);
    return j;
}

void playGame(board_t *start){
  board_t *head = start;
  int counter = 0;
  int rn;

  printf("%s%s\n", "You are currently on square: ", head->item->color);

  while ((strcmp(head->item->special, "WIN")) != 0) {
    char dummy;
    board_t *player;
    player = head;

    printf("%s\n", "Press enter to roll the die.");
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    rn = randomNumber(4);

    printf("%s %d\n", "The random number is: ", rn);


    // If the square to go to is RED //
    if(rn == 1){
      while ((int)(strcmp(player->next->item->color, "RED")) != 0) {
        if((strcmp(player->item->special, "WIN")) == 0){
          printf("%s\n", "Stay on the current square!");
          player = head->prev;
          break;
        }
        player = player->next;
      }
      player = player->next;
      if((strcmp(player->item->special, "GOBACK")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->prev;
        }
      }
      else if((strcmp(player->item->special, "GOFORWARD")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->next;
        }
      }
    }

    // If the Square to go to is BLUE //
    if (rn == 2) {
      while ((int)(strcmp(player->next->item->color, "BLUE")) != 0) {

        if((strcmp(player->item->special, "WIN")) == 0){
          printf("%s\n", "Stay on the current square!");
          player = head->prev;
          break;
        }
        player = player->next;
      }
      player = player->next;
      if((strcmp(player->item->special, "GOBACK")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->prev;
        }
      }
      if((strcmp(player->item->special, "GOFORWARD")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->next;
        }
      }
    }
    // If the Square to go to is ORANGE //
    if (rn == 3) {
      while ((int)(strcmp(player->next->item->color, "ORANGE")) != 0) {
        if((strcmp(player->item->special, "WIN")) == 0){
          printf("%s\n", "Stay on the current square!");
          player = head->prev;
          break;
        }
        player = player->next;
      }
      player = player->next;
      if((strcmp(player->item->special, "GOBACK")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->prev;
        }
      }
      if((strcmp(player->item->special, "GOFORWARD")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->next;
        }
      }
    }

    // If the Swuare to go to is GREEN //
    if (rn == 4) {
      while ((int)(strcmp(player->next->item->color, "GREEN")) != 0) {
        if((strcmp(player->item->special, "WIN")) == 0){
          printf("%s\n", "Stay on the current square!");
          player = head->prev;
          break;
        }
        player = player->next;
      }
      player = player->next;
      if((strcmp(player->item->special, "GOBACK")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->prev;
        }
      }
      if((strcmp(player->item->special, "GOFORWARD")) == 0){
        printf("%s%s %d\n", "You landed on a special square: ", player->item->special, player->item->x);
        for(int x = 0; x < player->item->x; x++){
          player = player->next;
        }
      }
    }
    printf("\n%s%s\n", "You are currently at square: ", player->item->color);

    head = player;
    counter ++;
  }
  if ((strcmp(head->item->special, "WIN")) == 0){
    printf("%s\n%s%d%s\n", "Congratulations you have won!", "It took a total of: ", counter, " tries.");
  }


  //printf("%s\n", player->item->color);
}

int main(){
  FILE *fp;
  fp = fopen("board.txt", "r");

  createBoard(fp);
  //traverse(start); // Displays the current board.
  playGame(start);
  return 0;
}
