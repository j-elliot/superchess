

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
int Board::getX(){

  return baseX;

}
int Board::getY(){

  return baseY;

}
int Board::getTot(){

  return basex * baseY;

}
