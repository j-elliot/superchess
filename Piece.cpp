

#include "Piece.h"

using namespace std;

//constructors
Piece::Piece()
: teamNum(0), teamDir(8), alive(true)
{}
Piece::Piece(int tn, int td)
: teamNum(tn), teamDir(td), alive(true)
{}

//destructor
Piece::~Piece()
{}

//setters
void Piece::setAlive(bool al)
{

  alive = al;

}
void Piece::setTeam(int tn)
{

  teamNum = tn;

}
void Piece::setDirection(int td)
{

  teamDir = td;

}
void Piece::setTeamDir(int tn, int td)
{

  teamNum = tn;

  teamDir = td;

}

//getters
bool Piece::getAlive()
{

  return alive;

}
int Piece::getTeam()
{

  return teamNum;

}
int Piece::getDirection()
{

  return teamDir;

}
bool Piece::getMoveValid(int start, int end, int boardX, int takeTeam)
{

  int deltaX = (abs((start % boardX) - (end % boardX)));
  int deltaY = (abs((start / boardX) - (end / boardX)));

  if(((deltaX + deltaY) == 1)   //can move only to spaces up down left and right
      && (takeTeam == -1))      //cannot move to an occupied space
    return true;

  return false;

}

//methods
bool Piece::flipAlive()
{

  alive = !alive;

  return alive;

}
int Piece::flipDirection()
{

  teamDir = teamDir * -1;

  return teamDir;

}
