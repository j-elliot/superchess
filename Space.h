//=================================
// include guard
#ifndef SPACE_H
#define SPACE_H

//=================================
// forward declared dependencies
class Piece;

//=================================
// included dependencies
#include "Piece.h"

class Space{

  private:
    Piece* piece;

  public:
    //constructors
    Space();
    Space(Piece* startPiece);

    //setters
    void setPiece(Piece* newPiece);

    //getters
    bool hasPiece();
    Piece* getPiece();

};

#endif
