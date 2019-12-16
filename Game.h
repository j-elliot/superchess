//=================================
// include guard
#ifndef GAME_H
#define GAME_H

//=================================
// forward declared dependencies
class Board;
class Piece;
class Team;
class TermInterface;

//=================================
// included dependencies
#include "Board.h"
#include "Piece.h"
#include "Team.h"
#include "TermInterface.h"

class Game{

  private:
    Board currentBoard;
    int numTeams;
    int current;
    Team** teams;
    TermInterface* inter;

  public:
    //constructors
    Game();
    Game(int tNum);
    //setters
    void runGame();
    //getters

};

#endif //GAME_H
