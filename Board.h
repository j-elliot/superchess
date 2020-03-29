//=================================
// include guard
#ifndef BOARD_H
#define BOARD_H

//=================================
// forward declared dependencies
class Space;
class Piece;

//=================================
// included dependencies
#include "Space.h"
#include "Piece.h"
#include <math.h>

class Board{

  private:
    Space** spaces;

    int baseX;
    int baseY;

  public:
    //constructors
    Board();
    Board(int x, int y);

    //setters
    void setPiece(Piece* newPiece, int loc);
    void movePiece(int fromLoc, int toLoc);
    void takePiece(int takeLoc);

    //getters
    bool getOccupied(int loc);
    Piece* getPiece(int loc);
    int getTeam(int loc);
    int getDir(int loc);
    int getX();
    int getY();
    int getTot();
    int getForward(int s);
    int getForward(int s, int a);
    int getBackward(int s);
    int getBackward(int s, int a);
    int getLeft(int s);
    int getLeft(int s, int a);
    int getRight(int s);
    int getRight(int s, int a);

};

#endif //BOARD_H
