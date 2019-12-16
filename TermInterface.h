//=================================
// include guard
#ifndef TERMINTERFACE_H
#define TERMINTERFACE_H

//=================================
// forward declared dependencies
class Board;

//=================================
// included dependencies
#include "Board.h"



class TermInterface{

  private:
    Board* board;

  public:
    //constructors
    TermInterface(Board* initBoard);
    //setters
    //getters
    void printBoard();

};

#endif //TERMINTERFACE_H
