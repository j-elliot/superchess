#include <iostream> // 'cause always this
#include <list>     // for the list needed for team.h
#include <cassert> // for assert()

//#define NDEBUG    //disables assert statement

using namespace std;

#include "Piece.cpp"
#include "Piece.h"
#include "Team.cpp"
#include "Team.h"

int main()
{

  Piece* testPiece = new Piece();
  cout << "\nTesting alive states\n";
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  cout << "\nKilling piece...\n";
  testPiece->setAlive(false);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  cout << "\nKilling piece...\n";
  testPiece->setAlive(false);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  cout << "\nReviving piece...\n";
  testPiece->setAlive(true);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  cout << "\nReviving piece...\n";
  testPiece->setAlive(true);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  cout << "\nChanging alive state...\n";
  testPiece->flipAlive();
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  cout << "\nChanging alive state and outputting result...\n";
  cout << testPiece->flipAlive();
  cout << "\n\n\n";

  Team testTeam = Team(0, 1);
  Team otherTeam = Team(1, -1);

  Piece teamPiece = Piece(&testTeam);


}
