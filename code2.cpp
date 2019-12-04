/**
I Need:
A piece
A board
a game engine
minimize everything: the board has two spaces in one direction, the piece moves
one space only, and win condition is moving that one space. One player to start.

*/
#include <iostream> // 'cause always this
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <string>   // For string stuff

using namespace std;

class Piece{

  private:
    int team;
    bool alive;

  public:
    //constructors
    Piece(){

      team = 0;

    }
    Piece(int startTeam){

      team = startTeam;

    }

    //setters
    void setTeam(int newTeam){

      team = newTeam;

    }

    //getters
    int getTeam(){

      return team;

    }

};

class Space{

  private:
    Piece* piece;
    int x;

  public:
    //constructors
    Space(){

      piece = NULL;
      x = 0;

    }
    Space(int locx){

      piece = NULL;
      x = locx;

    }
    Space(Piece* startPiece){

      piece = startPiece;
      x = 0;

    }
    Space(Piece* startPiece, int locx){

      piece = startPiece;
      x = locx;

    }

    //setters
    void setPiece(Piece* newPiece){

      piece = newPiece;

    }

    void setLocation(int newx){

      x = newx;

    }

    //getters
    bool hasPiece(){

      return piece != NULL;

    }
    Piece* getPiece(){

      return piece;

    }

    int getLocation(){

      return x;

    }

};
/**
class Board{

  Space[] spaces;

};

class Game{

  private:
    Board currentBoard;

};
*/
// test driver
int main(){

  //initialize pieces
  Piece testPiece1;
  Piece testPiece2(1);

  //use team variables
  cout << "First test piece is on team ";
  cout << testPiece1.getTeam();
  cout << "\n";
  cout << "Second test piece is on team ";
  cout << testPiece2.getTeam();
  cout << "\n";

  cout << "First test piece is switching sides...\n";
  testPiece1.setTeam(1);

  cout << "First test piece is on team ";
  cout << testPiece1.getTeam();
  cout << "\n";

  //erase pieces
  testPiece1.~Piece();

  //initialize spaces
  Space testSpace1(1);
  Space testSpace2(&testPiece2, 2);

  cout << "Space 1 has location ";
  cout << testSpace1.getLocation();
  cout << "\n";
  cout << "Space 2 has location ";
  cout << testSpace2.getLocation();
  cout << "\n";
  cout << "Space 1 has a piece on it? ";
  cout << testSpace1.hasPiece();
  cout << "\n";
  cout << "Space 2 has a piece on it? ";
  cout << testSpace2.hasPiece();
  cout << "\n";
  cout << "Space 1 has a piece on it on team ";
  if(testSpace1.hasPiece()){

    cout << testSpace2.getPiece()->getTeam();

  }else{

    cout << "\nspace 1 has no piece on it";

  }
  cout << "\n";
  cout << "Space 2 has a piece on it on team ";
  if(testSpace2.hasPiece()){

    cout << testSpace2.getPiece()->getTeam();

  }else{

    cout << "\nspace 2 has no piece on it";

  }
  cout << "\n";



  return 0;

}
