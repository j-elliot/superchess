

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

      if(board->getOccupied(i * board->getX() + j)){

        if(board->getPiece(i * board->getX() + j)->getTeam() == 0) cout << "+ ";

        if(board->getPiece(i * board->getX() + j)->getTeam() == 1) cout << "x ";

      }else if((i + j) % 2){

        cout << "0 ";

      }else{

        cout << "O ";

      }

    }

    cout << "\n";

  }

}
void TermInterface::printValidMoves(int start)
{

  if(board->getOccupied(start))
  {

    for(int i = 0; i < board->getY(); i++)
    {

      for(int j = 0; j < board->getX(); j++)
      {

        if(board->getPiece(start)->getMoveValid(start, (i * board->getX() + j), board->getX(), board->getTeam(i * board->getX() + j))) cout << "0 ";
        else {

          cout << "X ";

        }

      }

      cout << "\n";

    }

  }

}
