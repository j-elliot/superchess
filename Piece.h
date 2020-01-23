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
  //destructor
  ~Piece();
  //setters
  void setAlive(bool al);
  void setTeam(Team* pTeam);
  //getters
  bool getAlive();
  Team* getTeam();
  //methods
  bool flipAlive();
};

#endif //PIECE_H
