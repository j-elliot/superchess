#include <iostream> // 'cause always this
#include <list>     // for the list needed for team.h
#include <cassert> // for assert()

//#define NDEBUG    //disables assert statement

using namespace std;

#include "Board.cpp"
#include "Board.h"
#include "Game.cpp"
#include "Game.h"
#include "Piece.cpp"
#include "Piece.h"
#include "Space.cpp"
#include "Space.h"
#include "TermInterface.cpp"
#include "TermInterface.h"

int main()
{

  cout << "\nCreating test game...\n";
  Game* testGame = new Game();

  cout << "\nLaunching game...\n";
  testGame->runGame();
  assert(true && "Yes");
  cout << "\n";

}
