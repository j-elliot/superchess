

#include "Piece.h"

using namespace std;

Piece::Piece(){}

Piece::Piece(Team* pTeam)
: team(pTeam)
{}

Team* Piece::getTeam()
{

  return team;

}
