#include <iostream> // 'cause always this
#include <list>     // for the list needed for team.h
#include <cassert> // for assert()

//#define NDEBUG    //disables assert statement

using namespace std;

#include "Piece.cpp"
#include "Piece.h"
#include "Space.cpp"
#include "Space.h"

int main()
{

  Space* testSpace = new Space();

  cout << "Testing space...\n";
  cout << "\n";

  cout << "Does this space have a piece?\n";
  cout << testSpace->hasPiece();
  assert((testSpace->hasPiece() == false) && "New test space should not have a piece.");
  cout << "\n";

  cout << "\nCreating and adding piece...\n";
  Piece samplePiece = Piece();
  testSpace->setPiece(&samplePiece);
  cout << "Does this space have a piece?\n";
  cout << testSpace->hasPiece();
  assert((testSpace->hasPiece() == true) && "Test space should have a piece.");
  cout << "\n";

  cout << "\nTesting piece via space\n";
  cout << "\nIs this piece alive?\n";
  if(testSpace->hasPiece())
    cout << testSpace->getPiece()->getAlive();
  assert((testSpace->getPiece()->getAlive() == true) && "New test piece should be alive but isn't.");

  cout << "\nKilling piece...\n";
  if(testSpace->hasPiece())
    testSpace->getPiece()->setAlive(false);
  cout << "\nIs this piece alive?\n";
  if(testSpace->hasPiece())
    cout << testSpace->getPiece()->getAlive();
  assert((testSpace->getPiece()->getAlive() == false) && "Test piece should have been killed but isn't dead.");

  cout << "\nKilling piece...\n";
  if(testSpace->hasPiece())
    testSpace->getPiece()->setAlive(false);
  cout << "\nIs this piece alive?\n";
  if(testSpace->hasPiece())
    cout << testSpace->getPiece()->getAlive();
  assert((testSpace->getPiece()->getAlive() == false) && "Killing a dead piece should result in a dead piece.");

  cout << "\nReviving piece...\n";
  if(testSpace->hasPiece())
    testSpace->getPiece()->setAlive(true);
  cout << "\nIs this piece alive?\n";
  if(testSpace->hasPiece())
    cout << testSpace->getPiece()->getAlive();
  assert((testSpace->getPiece()->getAlive() == true) && "Revived piece should be alive but isn't");

  cout << "\nReviving piece...\n";
  if(testSpace->hasPiece())
    testSpace->getPiece()->setAlive(true);
  cout << "\nIs this piece alive?\n";
  if(testSpace->hasPiece())
    cout << testSpace->getPiece()->getAlive();
  assert((testSpace->getPiece()->getAlive() == true) && "Revived live piece should be alive but isn't");

  cout << "\nChanging alive state...\n";
  if(testSpace->hasPiece())
    testSpace->getPiece()->flipAlive();
  cout << "\nIs this piece alive?\n";
  if(testSpace->hasPiece())
    cout << testSpace->getPiece()->getAlive();
  assert((testSpace->getPiece()->getAlive() == false) && "Piece should have been flipped to dead but wasn't.");
  cout << "\nChanging alive state and outputting result...\n";
  if(testSpace->hasPiece())
    cout << testSpace->getPiece()->flipAlive();
  assert((testSpace->getPiece()->getAlive() == true) && "Piece should have been flipped to alive but wasn't.");

  cout << "\nRemoving piece...\n";
  testSpace->setPiece(NULL);
  cout << "\nDoes space have a piece?\n";
  cout << testSpace->hasPiece();
  assert((testSpace->hasPiece() == false) && "Test space should not have a piece but does.");
  cout << "\n\n\n";

  Space otherSpace = Space(new Piece(0, 8));

  cout << "\nTesting team states via space\n";
  cout << "\nWhat team is this piece on?\n";
  if(otherSpace.hasPiece())
    cout << otherSpace.getPiece()->getTeam();
  assert((otherSpace.getPiece()->getTeam() == 0) && "Piece is not on assigned team (0).");

  cout << "\nWhat direction is forward for this piece?\n";
  if(otherSpace.hasPiece())
    cout << otherSpace.getPiece()->getDirection();
  assert((otherSpace.getPiece()->getDirection() == 8) && "Piece is not moving in assigned direction (8).");

  cout << "\nChanging team...\n";
  if(otherSpace.hasPiece())
    otherSpace.getPiece()->setTeam(1);
  cout << "\nWhat team is this piece on?\n";
  if(otherSpace.hasPiece())
    cout << otherSpace.getPiece()->getTeam();
  assert((otherSpace.getPiece()->getTeam() == 1) && "Piece is not on assigned team (1).");

  cout << "\nChanging direction...\n";
  if(otherSpace.hasPiece())
    otherSpace.getPiece()->setDirection(-8);
  cout << "\nWhat direction is forward for this piece?\n";
  if(otherSpace.hasPiece())
    cout << otherSpace.getPiece()->getDirection();
  assert((otherSpace.getPiece()->getDirection() == -8) && "Piece is not moving in assigned direction (-8).");

  cout << "\nChanging team and direction...\n";
  if(otherSpace.hasPiece())
    otherSpace.getPiece()->setTeamDir(2, 1);
  cout << "\nWhat team is this piece on?\n";
  if(otherSpace.hasPiece())
    cout << otherSpace.getPiece()->getTeam();
  assert((otherSpace.getPiece()->getTeam() == 2) && "Piece is not on assigned team (2).");
  cout << "\nWhat direction is forward for this piece?\n";
  if(otherSpace.hasPiece())
    cout << otherSpace.getPiece()->getDirection();
  assert((otherSpace.getPiece()->getDirection() == 1) && "Piece is not moving in assigned direction (1).");

  cout << "\nFlipping direction and outputting result...\n";
  if(otherSpace.hasPiece())
    cout << otherSpace.getPiece()->flipDirection();
  assert((otherSpace.getPiece()->getDirection() == -1) && "Piece is not moving in expected direction (-1).");

}
