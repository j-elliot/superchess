

#include "TermInterface.h"

using namespace std;

//constructors
TermInterface::TermInterface(Board* initBoard)
  : board(initBoard)
{

  board = initBoard;

}
//setters
//getters
void TermInterface::printBoard(){

  for(int i = 0; i < board->getY(); i++){

    for(int j = 0; j < board->getX(); j++){

      if(board->getOccupied(i * board->getY() + j)){

        if(board->getPiece(i * board->getY() + j)->getTeam()->getID() == 0) cout << "+ ";

        if(board->getPiece(i * board->getY() + j)->getTeam()->getID() == 1) cout << "x ";

      }else if((i + j) % 2){

        cout << "0 ";

      }else{

        cout << "O ";

      }

    }

    cout << "\n";

  }

}
