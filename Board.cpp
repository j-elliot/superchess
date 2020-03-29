

#include "Board.h"

using namespace std;

Board::Board()
  : baseX(8), baseY(8)
{

  spaces = (Space**)malloc(sizeof(Space *) * baseX * baseY);

  for(int i = 0; i < baseX; i++){
    for (int j = 0; j < baseY; j++){

      spaces[i * baseY + j] = new Space();

    }
  }

}
Board::Board(int x, int y)
  : baseX(x), baseY(y)
{

  spaces = (Space**)malloc(sizeof(Space *) * baseX * baseY);

  //add catch to ensure baseX > 1

  for(int i = 0; i < baseX; i++){
    for (int j = 0; j < baseY; j++){

      spaces[i * baseY + j] = new Space();

    }
  }
}

  //setters
void Board::setPiece(Piece* newPiece, int loc){

  if(!(spaces[loc]->hasPiece())){

    spaces[loc]->setPiece(newPiece);

  }else{

    cout << "Space is already occupied\n";

  }

}
void Board::movePiece(int fromLoc, int toLoc){

  if(spaces[fromLoc]->hasPiece()){

    if(!spaces[toLoc]->hasPiece()){

      spaces[toLoc]->setPiece(spaces[fromLoc]->getPiece());
      spaces[fromLoc]->setPiece(NULL);

    }else{

      cout << "Destination occupied\n";

    }

  }else{

    cout << "Origin unoccupied\n";

  }

}
void Board::takePiece(int takeLoc){

  if(spaces[takeLoc]->hasPiece()){

    spaces[takeLoc]->setPiece(NULL);

  }else{

    cout << "No piece to take\n";

  }

}
//getters
bool Board::getOccupied(int loc){

  return spaces[loc]->hasPiece();

}
Piece* Board::getPiece(int loc){

  if(spaces[loc]->hasPiece()){

    return spaces[loc]->getPiece();

  }else{

    return NULL;

  }
}
int Board::getTeam(int loc){

  if(spaces[loc]->hasPiece()){

    return spaces[loc]->getPiece()->getTeam();

  }else{

    return -1;

  }
}
int Board::getDir(int loc){

  if(spaces[loc]->hasPiece()){

    return spaces[loc]->getPiece()->getDirection();

  }else{

    return 0;

  }
}
int Board::getX(){

  return baseX;

}
int Board::getY(){

  return baseY;

}
int Board::getTot(){

  return baseX * baseY;

}
int Board::getForward(int s)
{

  int a = getDir(s);

  if(a != 0)
  {

    return s + a;

  }else{

    return -1;

  }

}
int Board::getForward(int s, int a)
{

  return s + a;

}
int Board::getBackward(int s)
{

  int a = getDir(s);

  if(a != 0)
  {

    return s - a;

  }else{

    return -1;

  }

}
int Board::getBackward(int s, int a)
{

  return s - a;

}
int Board::getLeft(int s)
{

  int a = getDir(s);

  if(a != 0)
  {


    return round(s + ((1 / ((a + 0.0) / baseX)) * (pow(-1, ((abs(a) - 1) / (baseX - 1)) + 1))));

  }else{

    return -1;

  }

}
int Board::getLeft(int s, int a)
{

  return round(s + ((1 / ((a + 0.0) / baseX)) * (pow(-1, ((abs(a) - 1) / (baseX - 1)) + 1))));

}
int Board::getRight(int s)
{

  int a = getDir(s);

  if(a != 0)
  {

    return round(s - ((1 / ((a + 0.0) / baseX)) * (pow(-1, ((abs(a) - 1) / (baseX - 1)) + 1))));

  }else{

    return -1;

  }

}
int Board::getRight(int s, int a)
{

  return round(s - ((1 / ((a + 0.0) / baseX)) * (pow(-1, ((abs(a) - 1) / (baseX - 1)) + 1))));

}

/**
In order to get the left and right turns working consistently for pieces moving
across the board as well as up and down it, I had to invent a bit of math. In
the formula seen below, the starting point +- the inverse of a/x gives the
magnitude but flips the sign when crossing the board vs ascending or descending.
To rectify this, the rest is a switch that flips the sign when a = 1 or -1. when
the magnitude of one, the numerator (|a| - 1) resolves to zero, making the
exponent of -1 to be 1, leaving a negative factor, flipping the sign of result
of the rest of the formula. When a is equal to the width x, as when the piece's
forward is up or down the board, (|a| - 1) = (x - 1), which is the denominator,
resolving the fraction to 1, which, when added to 1 is 2, making -1^2 = 1, not
flipping the sign for the main part of the formula. Took me a bit to figure this
one out, and I wanted a clear explanation of how it works...

So I wrote the math, I wrote this long explanation of the math, and then I
that left and write when crossing the board depends upon the layout of the
board. I wrote my worksheet to match how the computer lays things out on the
screen - at present. The computer, because it's looping through a linear array,
just fills the screen as it does with text, left to right and up to down,
starting at 0 and going in rows of 8 to 63. If, on the other, I up the screen as
might be more intuitive with a counting representation rather than a text
representation, going left to right and down to up, then a left and right turn
would remain identical for up and down travel, but be flipped for across travel.
My forst solution was correct but for the wrong layout. The computer and the
math don't know anything about two dimensions. They only have the one. I'll
preserve my work here because I'm proud of it and might be able to use it later
for something else, but otherwise it will be the simpler version with the
understanding that layout needs to be modified. I will need to remember this
episode for an interview question...

return (s + (1 / (a / baseX))) * (pow(-1, (((abs(a) - 1) / (baseX - 1)) + 1)));
*/
