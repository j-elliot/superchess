/**
I Need:
A piece
A board
a game engine

*/
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <iostream> // 'cause always this
#include <iterator> //also for list
#include <list>     //for list
#include <string>   // For string stuff

using namespace std;

#include "Board.cpp"
#include "Board.h"
#include "Game.cpp"
#include "Game.h"
#include "Piece.cpp"
#include "Piece.h"
#include "Space.cpp"
#include "Space.h"
#include "Team.cpp"
#include "Team.h"
#include "TermInterface.cpp"
#include "TermInterface.h"
/**



//The Game object has to do a lot of things.
//It has to tell the board what moves to make.
//It has to validate those moves as legal.
//It has to check to see if a condition is triggered by a given move.
//It has to handle triggered events such as win/loss and special moves.
class Game{

private:
  Board currentBoard;
  //int numTeams;
  //Team* current;
  //Team* teams;
  //int winTeam;
  TermInterface* inter;

public:
  //constructors
  Game(){

    //numTeams = 2;
    currentBoard = Board();

    /**teams = (Team**)malloc(sizeof(Team *) * numTeams);

    for(int i = 0; i < numTeams; i++){

      //this would not work for more than two teams
      teams[i] = new Team(i, (1+i*(-2))*currentBoard.getY());

    }

    for(int i = 0; i < currentBoard.getX(); i++){

      currentBoard.setPiece(new Piece(), 0 * currentBoard.getY() + i);
      currentBoard.setPiece(new Piece(), 7 * currentBoard.getY() + i);

    }

    inter = new TermInterface(&currentBoard);

    inter->printBoard();

  }
  //setters
  void runGame(){

    //principal game loop
    while(true){

    //whose turn?
    cout << "It is ";
    //cout << curTeam;
    cout << "'s turn...";
    //What do they get to do?

    //did someone win?
    //whose next?
    //curTeam = curTeam++ % numTeams;
    }

  }
  //getters

};
*/

// test driver
int main(){

  //initialize game
  Game newGame = Game(2);

  return 0;

}
