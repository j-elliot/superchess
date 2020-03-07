

#include "Piece.h"

using namespace std;

//constructors
Piece::Piece()
: team(NULL), alive(true)
{}
Piece::Piece(Team* pTeam)
: team(pTeam), alive(true)
{}

//destructor
Piece::~Piece()
{}

//setters
void Piece::setAlive(bool al)
{

  alive = al;

}
void Piece::setTeam(Team* pTeam)
{

  team = pTeam;

}

//getters
bool Piece::getAlive()
{

  return alive;

}
Team* Piece::getTeam()
{

  return team;

}

bool Piece::flipAlive()
{

  alive = !alive;

  return alive;

}
