

#include "Game.h"

using namespace std;

//constructors
Game::Game()
  : board(Board()), numTeams(2), current(0)
{

  for(int i = 0; i < board.getX(); i++)
  {

    board.setPiece(new Piece(0, 1), 0 * board.getY() + i);
    board.setPiece(new Piece(1, -1), 7 * board.getY() + i);

  }

  inter = new TermInterface(&board);

  inter->printBoard();

}
Game::Game(int tNum)
  : board(Board()), numTeams(tNum), current(0)
{

  for(int i = 0; i < board.getX(); i++)
  {

    board.setPiece(new Piece(0, 1), 0 * board.getY() + i);
    board.setPiece(new Piece(1, -1), 7 * board.getY() + i);
  }

  inter = new TermInterface(&board);

  inter->printBoard();

}
//setters
void Game::setTurn()
{

  current = (current + 1) % numTeams;

}
void Game::setTurn(int newTurn)
{

  if(newTurn <= numTeams && newTurn >= 0)
  {

    current = newTurn;

  }else{

    cout << "New turn is invalid.";

  }

}
//getters
//methods
void Game::runGame()
{

  inter = new TermInterface(&board);

  inter->printValidMoves(3);

  board.movePiece(3, 11);

  cout << "\n\n\n";

  inter->printValidMoves(11);

  //principal game loop
  /**
  while(true)
  {

    inter->printBoard();

    //whose turn?
    cout << "It is ";
    cout << current;
    cout << "'s turn...\n";
    //What do they get to do?

    //did someone win?
    //whose next?
    setTurn();
  }*/

}
