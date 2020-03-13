#include <iostream> // 'cause always this
#include <list>     // for the list needed for team.h
#include <cassert> // for assert()
#include <cstdlib>     //for math stuff such as absolute value

//#define NDEBUG    //disables assert statement

using namespace std;

#include "Piece.cpp"
#include "Piece.h"

int main()
{

  Piece* testPiece = new Piece();

  cout << "\nTesting alive states\n";
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  assert((testPiece->getAlive() == true) && "New test piece should be alive but isn't.");

  cout << "\nKilling piece...\n";
  testPiece->setAlive(false);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  assert((testPiece->getAlive() == false) && "Test piece should have been killed but isn't dead.");

  cout << "\nKilling piece...\n";
  testPiece->setAlive(false);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  assert((testPiece->getAlive() == false) && "Killing a dead piece should result in a dead piece.");

  cout << "\nReviving piece...\n";
  testPiece->setAlive(true);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  assert((testPiece->getAlive() == true) && "Revived piece should be alive but isn't");

  cout << "\nReviving piece...\n";
  testPiece->setAlive(true);
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  assert((testPiece->getAlive() == true) && "Revived live piece should be alive but isn't");

  cout << "\nChanging alive state...\n";
  testPiece->flipAlive();
  cout << "\nIs this piece alive?\n";
  cout << testPiece->getAlive();
  assert((testPiece->getAlive() == false) && "Piece should have been flipped to dead but wasn't.");
  cout << "\nChanging alive state and outputting result...\n";
  cout << testPiece->flipAlive();
  assert((testPiece->getAlive() == true) && "Piece should have been flipped to alive but wasn't.");
  cout << "\n\n\n";

  Piece teamPiece = Piece(0, 8);

  cout << "\nTesting team states\n";
  cout << "\nWhat team is this piece on?\n";
  cout << teamPiece.getTeam();
  assert((teamPiece.getTeam() == 0) && "Piece is not on assigned team (0).");

  cout << "\nWhat direction is forward for this piece?\n";
  cout << teamPiece.getDirection();
  assert((teamPiece.getDirection() == 8) && "Piece is not moving in assigned direction (8).");

  cout << "\nChanging team...\n";
  teamPiece.setTeam(1);
  cout << "\nWhat team is this piece on?\n";
  cout << teamPiece.getTeam();
  assert((teamPiece.getTeam() == 1) && "Piece is not on assigned team (1).");

  cout << "\nChanging direction...\n";
  teamPiece.setDirection(-8);
  cout << "\nWhat direction is forward for this piece?\n";
  cout << teamPiece.getDirection();
  assert((teamPiece.getDirection() == -8) && "Piece is not moving in assigned direction (-8).");

  cout << "\nChanging team and direction...\n";
  teamPiece.setTeamDir(2, 1);
  cout << "\nWhat team is this piece on?\n";
  cout << teamPiece.getTeam();
  assert((teamPiece.getTeam() == 2) && "Piece is not on assigned team (2).");
  cout << "\nWhat direction is forward for this piece?\n";
  cout << teamPiece.getDirection();
  assert((teamPiece.getDirection() == 1) && "Piece is not moving in assigned direction (1).");

  cout << "\nFlipping direction and outputting result...\n";
  cout << teamPiece.flipDirection();
  assert((teamPiece.getDirection() == -1) && "Piece is not moving in expected direction (-1).");
  cout << "\n";

  cout << "\nTesting move validation...\n";
  cout << "\nChecking move from 28 to 29...\n";
  cout << teamPiece.getMoveValid(28, 29, 8, -1);
  assert((teamPiece.getMoveValid(28, 29, 8, -1) == true) && "Piece should be able to make this move but can't.");
  cout << "\nChecking move from 28 to 27...\n";
  cout << teamPiece.getMoveValid(28, 27, 8, -1);
  assert((teamPiece.getMoveValid(28, 27, 8, -1) == true) && "Piece should be able to make this move but can't.");
  cout << "\nChecking move from 28 to 36...\n";
  cout << teamPiece.getMoveValid(28, 36, 8, -1);
  assert((teamPiece.getMoveValid(28, 36, 8, -1) == true) && "Piece should be able to make this move but can't.");
  cout << "\nChecking move from 28 to 20...\n";
  cout << teamPiece.getMoveValid(28, 20, 8, -1);
  assert((teamPiece.getMoveValid(28, 20, 8, -1) == true) && "Piece should be able to make this move but can't.");
  cout << "\nChecking move from 28 to 37...\n";
  cout << teamPiece.getMoveValid(28, 37, 8, -1);
  assert((teamPiece.getMoveValid(28, 37, 8, -1) == false) && "Piece shouldn't be able to make this move but can.");
  cout << "\nChecking move from 28 to 21...\n";
  cout << teamPiece.getMoveValid(28, 21, 8, -1);
  assert((teamPiece.getMoveValid(28, 21, 8, -1) == false) && "Piece shouldn't be able to make this move but can.");
  cout << "\nChecking move from 28 to 19...\n";
  cout << teamPiece.getMoveValid(28, 19, 8, -1);
  assert((teamPiece.getMoveValid(28, 19, 8, -1) == false) && "Piece shouldn't be able to make this move but can.");
  cout << "\nChecking move from 28 to 35...\n";
  cout << teamPiece.getMoveValid(28, 35, 8, -1);
  assert((teamPiece.getMoveValid(28, 35, 8, -1) == false) && "Piece shouldn't be able to make this move but can.");
  cout << "\nChecking move to space occupied by ally\n";
  cout << teamPiece.getMoveValid(28, 29, 8, 0);
  assert((teamPiece.getMoveValid(28, 29, 8, 0) == false) && "Piece shouldn't be able to make this move but can.");
  cout << "\nChecking move to space occupied by enemy\n";
  cout << teamPiece.getMoveValid(28, 29, 8, 1);
  assert((teamPiece.getMoveValid(28, 29, 8, 1) == false) && "Piece shouldn't be able to make this move but can.");
  cout << "\n";

}
