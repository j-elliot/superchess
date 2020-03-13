//=================================
// include guard
#ifndef GAME_H
#define GAME_H

//=================================
// forward declared dependencies
class Board;
class Piece;
class TermInterface;

//=================================
// included dependencies
#include "Board.h"
#include "Piece.h"
#include "TermInterface.h"

class Game{

  private:
    Board board;
    int numTeams;
    int current;
    TermInterface* inter;

  public:
    //constructors
    Game();
    Game(int tNum);
    //setters
    void setTurn();
    void setTurn(int newTurn);
    //getters
    //methods
    void runGame();

};

#endif //GAME_H
