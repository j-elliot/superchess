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
    int getTeam(int loc);//write test
    int getX();
    int getY();
    int getTot();

};

#endif //BOARD_H
