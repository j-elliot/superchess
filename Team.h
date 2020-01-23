//=================================
// include guard
#ifndef TEAM_H
#define TEAM_H

//=================================
// forward declared dependencies
class Space;
class Piece;

//=================================
// included dependencies
#include "Space.h"
#include "Piece.h"

class Team{

private:
  int num;
  int forward; //a multiplier used to determine which direction they should be going
  int win; //0 for playing, 1 for win state, -1 for loss state
  list <Piece> teamPieces;

public:
  //constructors
  Team(int tNum, int arrow);
  //setters
  //getters
  int getID();

};

#endif //BOARD_H
