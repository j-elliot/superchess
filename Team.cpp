//=================================
#include "Team.h"

//constructors
Team::Team(int tNum, int arrow)
: num(tNum), forward(arrow), win(0)
{}
//setters
//getters
int Team::getID()
{

  return num;
  
}
