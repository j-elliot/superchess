//=================================
// include guard
#ifndef PIECE_H
#define PIECE_H

//=================================
// forward declared dependencies
class Team;

//=================================
// included dependencies
#include "Team.h"

class Piece
{
private:
  Team* team;
  bool alive;

public:
  //constructors
  Piece();
  Piece(Team* pTeam);
  //setters
  //getters
  Team* getTeam();
};

#endif //PIECE_H
