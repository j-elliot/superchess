

#include "Space.h"


//constructors
Space::Space()
: piece(NULL)
{}
Space::Space(Piece* startPiece)
: piece(startPiece)
{}

//setters
void Space::setPiece(Piece* newPiece)
{

  piece = newPiece;

}

//getters
bool Space::hasPiece()
{

  return piece != NULL;

}
Piece* Space::getPiece()
{

  return piece;

}
