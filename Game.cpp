

#include "Game.h"

using namespace std;

//constructors
Game::Game()
  : currentBoard(Board()), numTeams(2), current(0)
{

  teams = (Team**)malloc(sizeof(Team *) * numTeams);

  for(int i = 0; i < numTeams; i++){

    int forward = 0;
    if(i%4 == 0) forward = 8;
    if(i%4 == 1) forward = -8;
    if(i%4 == 2) forward = 1;
    if(i%4 == 3) forward = -1;

    teams[i] = new Team(i, forward);

  }

  for(int i = 0; i < currentBoard.getX(); i++)
  {

    currentBoard.setPiece(new Piece(teams[0]), 0 * currentBoard.getY() + i);
    currentBoard.setPiece(new Piece(teams[1]), 7 * currentBoard.getY() + i);

  }

  inter = new TermInterface(&currentBoard);

  inter->printBoard();

}
Game::Game(int tNum)
  : currentBoard(Board()), numTeams(tNum), current(0)
{

  teams = (Team**)malloc(sizeof(Team *) * numTeams);

  for(int i = 0; i < numTeams; i++){

    int forward = 0;
    if(i%4 == 0) forward = 8;
    if(i%4 == 1) forward = -8;
    if(i%4 == 2) forward = 1;
    if(i%4 == 3) forward = -1;

    teams[i] = new Team(i, forward);

  }

  for(int i = 0; i < currentBoard.getX(); i++)
  {

    currentBoard.setPiece(new Piece(teams[0]), 0 * currentBoard.getY() + i);
    currentBoard.setPiece(new Piece(teams[1]), 7 * currentBoard.getY() + i);
  }

  inter = new TermInterface(&currentBoard);

  inter->printBoard();

}
//setters
void Game::runGame()
{

  inter = new TermInterface(&currentBoard);

  //principal game loop
  while(true)
  {

    inter->printBoard();

    //whose turn?
    cout << "It is ";
    cout << current;
    cout << "'s turn...";
    //What do they get to do?

    //did someone win?
    //whose next?
    current = current++ % numTeams;
  }

}
//getters
