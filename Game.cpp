

#include "Game.h"

using namespace std;

//constructors
Game::Game()
  : board(new Board()), numTeams(2), current(0)
{

  for(int i = 0; i < board->getX(); i++)
  {

    board->setPiece(new Piece(0, 8), 0 * board->getX() + i);
    board->setPiece(new Piece(1, -8), 7 * board->getX() + i);

  }

  inter = new TermInterface(board);

  inter->printBoard();

}
Game::Game(int tNum)
  : board(new Board()), numTeams(tNum), current(0)
{

  for(int i = 0; i < board->getX(); i++)
  {

    board->setPiece(new Piece(0, 1), 0 * board->getY() + i);
    board->setPiece(new Piece(1, -1), 7 * board->getY() + i);
  }

  inter = new TermInterface(board);

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
bool Game::getWin()
{

  //win condition: Player reaches opposite side of the board
  for(int i = 0; i < board->getX(); i++)
  {

    if(board->getTeam(i + ((1 - current) * board->getX() * 7)) == current)
    {

      cout << "\n\nwin condition met for ";
      cout << current;

      return true;

    }

  }

  return false;

}

//methods
void Game::makeMove(int start, int end)
{

  if((board->getTeam(start) == current) //is it the selected piece's turn?
      && board->getPiece(start)->getMoveValid(start, end, board->getX(), board->getTeam(end))) //is this a valid move for this piece
  {

    board->movePiece(start, end);

  }else{

    cout << "Cannot complete move...\n";

  }
}
void Game::runGame()
{

  inter = new TermInterface(board);

  inter->printValidMoves(3);

  makeMove(3, 11);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(11);

  makeMove(11, 19);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(19);

  makeMove(19, 27);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(27);

  makeMove(27, 28);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(28);

  makeMove(28, 36);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(36);

  makeMove(36, 44);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(44);

  makeMove(44, 52);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(52);

  makeMove(52, 60);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  setTurn();

  cout << "\n\n\n";

  inter->printValidMoves(59);

  makeMove(59, 51);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(51);

  makeMove(51, 50);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  setTurn();

  cout << "\n\n\n";

  inter->printValidMoves(52);

  makeMove(52, 51);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

  inter->printValidMoves(51);

  makeMove(51, 59);

  cout << "\n\n\n";

  inter->printBoard();

  getWin();

  cout << "\n\n\n";

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
