#include <iostream> // 'cause always this
#include <list>     // for the list needed for team.h
#include <cassert> // for assert()

//#define NDEBUG    //disables assert statement

using namespace std;

#include "Board.cpp"
#include "Board.h"
#include "Piece.cpp"
#include "Piece.h"
#include "Space.cpp"
#include "Space.h"

int main()
{

  cout << "\nCreating board...\n";
  Board* testBoard = new Board();

  cout << "\nHow many columns are there?\n";
  cout << testBoard->getX();
  assert((testBoard->getX() == 8) && "Board does not have 8 columns");
  cout << "\n";

  cout << "\nHow many rows are there?\n";
  cout << testBoard->getY();
  assert((testBoard->getY() == 8) && "Board does not have 8 rows");
  cout << "\n";

  cout << "\nHow many spaces are there?\n";
  cout << testBoard->getTot();
  assert((testBoard->getTot() == 64) && "Board does not have 64 spaces");
  cout << "\n";

  cout << "\nIs there a piece on space 0?\n";
  cout << testBoard->getOccupied(0);
  assert((testBoard->getOccupied(0) == false) && "Space zero has a piece but shouldn't.");
  cout << "\n";

  cout << "\nAdding piece to space 0...\n";
  testBoard->setPiece(new Piece(), 0);
  cout << "\nIs there a piece on space 0?\n";
  cout << testBoard->getOccupied(0);
  assert((testBoard->getOccupied(0) == true) && "Space zero doesn't have a piece but should.");
  cout << "\n";

  cout << "\nMoving piece from 0 to 1...\n";
  testBoard->movePiece(0, 1);
  cout << "\nIs there a piece on space 0?\n";
  cout << testBoard->getOccupied(0);
  assert((testBoard->getOccupied(0) == false) && "Space zero does have a piece but shouldn't.");
  cout << "\nIs there a piece on space 1?\n";
  cout << testBoard->getOccupied(1);
  assert((testBoard->getOccupied(1) == true) && "Space one doesn't have a piece but should.");
  cout << "\n";

  cout << "\nRemoving piece from space 1...\n";
  testBoard->takePiece(1);
  cout << "\nIs there a piece on space 1?\n";
  cout << testBoard->getOccupied(1);
  assert((testBoard->getOccupied(1) == false) && "Space zero does have a piece but shouldn't.");
  cout << "\n";

  cout << "\nStress testing...\n";
  cout << "\nAdding piece to space 2...\n";
  testBoard->setPiece(new Piece(), 2);
  cout << "\nAttempting to add piece to occupied space\n";
  cout << "\nAdding piece to space 2...\n";
  testBoard->setPiece(new Piece(), 2);
  cout << "\nIs there a piece on space 2?\n";
  cout << testBoard->getOccupied(2);
  assert((testBoard->getOccupied(2) == true) && "Space two doesn't have a piece but should.");
  cout << "\n";

  cout << "\nAdding piece to space 3...\n";
  testBoard->setPiece(new Piece(), 3);
  cout << "\nAttempting to move a piece to an occupied space\n";
  cout << "\nMoving piece from space 2 to space 3...\n";
  testBoard->movePiece(2, 3);
  cout << "\nIs there a piece on space 2?\n";
  cout << testBoard->getOccupied(2);
  assert((testBoard->getOccupied(2) == true) && "Space two doesn't have a piece but should.");
  cout << "\nIs there a piece on space 3?\n";
  cout << testBoard->getOccupied(3);
  assert((testBoard->getOccupied(3) == true) && "Space three doesn't have a piece but should.");
  cout << "\n";

  cout << "\nAttempting to move a piece from an unoccupied space\n";
  cout << "\nMoving piece from space 4 to space 5...\n";
  testBoard->movePiece(4, 5);
  cout << "\nIs there a piece on space 4?\n";
  cout << testBoard->getOccupied(4);
  assert((testBoard->getOccupied(4) == false) && "Space four does have a piece but shouldn't.");
  cout << "\nIs there a piece on space 5?\n";
  cout << testBoard->getOccupied(5);
  assert((testBoard->getOccupied(5) == false) && "Space three does have a piece but shouldn't.");
  cout << "\n";

  cout << "\nAttempting to move a piece from an unoccupied space to an occupied space\n";
  cout << "\nMoving piece from space 4 to space 3...\n";
  testBoard->movePiece(4, 3);
  cout << "\nIs there a piece on space 4?\n";
  cout << testBoard->getOccupied(4);
  assert((testBoard->getOccupied(4) == false) && "Space four does have a piece but shouldn't.");
  cout << "\nIs there a piece on space 3?\n";
  cout << testBoard->getOccupied(3);
  assert((testBoard->getOccupied(3) == true) && "Space three doesn't have a piece but should.");
  cout << "\n";

  cout << "\nAttempting to take a piece from an unoccupied space\n";
  cout << "\nTaking piece from space 4...\n";
  testBoard->takePiece(4);
  cout << "\nIs there a piece on space 4?\n";
  cout << testBoard->getOccupied(4);
  assert((testBoard->getOccupied(4) == false) && "Space four does have a piece but shouldn't.");
  cout << "\n";

  cout << "\nAttempting to get reference to a piece from an unoccupied space\n";
  Piece* nullPiece = testBoard->getPiece(4);
  cout << "\nIs there a piece on space 4?\n";
  cout << testBoard->getOccupied(4);
  assert((testBoard->getOccupied(4) == false) && "Space four does have a piece but shouldn't.");
  assert((nullPiece == NULL) && "nullPiece is not null.");
  cout << "\n";

  cout << "\nCreating mini board...\n";
  Board miniBoard = Board(3, 3);

  cout << "\nCreating piece and adding to space 4...\n";
  Piece newPiece = Piece(1, -1);
  miniBoard.setPiece(&newPiece, 4);
  cout << "\nIs there a piece on space 4?\n";
  cout << miniBoard.getOccupied(4);
  assert((miniBoard.getOccupied(4) == true) && "Space four doesn't have a piece but should.\n");
  cout << "\n";

  cout << "\nMember function test of piece via board...\n";
  cout << "\nWhat is the team of the piece on space 4?\n";
  cout << miniBoard.getPiece(4)->getTeam();
  assert((miniBoard.getPiece(4)->getTeam() == 1) && "This piece's team should be 1 but isn't.\n");
  cout << "\nChanging team of piece on space 4...\n";
  miniBoard.getPiece(4)->setTeam(2);
  cout << "\nWhat is the team of the piece on space 4?\n";
  cout << miniBoard.getPiece(4)->getTeam();
  assert((miniBoard.getPiece(4)->getTeam() == 2) && "This piece's team should be 2 but isn't.\n");
  cout << "\n";





}
