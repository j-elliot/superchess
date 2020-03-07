//=================================
// include guard
#ifndef PIECE_H
#define PIECE_H

//=================================
// forward declared dependencies

//=================================
// included dependencies

class Piece
{
private:
  int teamNum;  //numeric identifier of the team
  int teamDir;  //direction the team moves forward
  bool alive;

public:
  //constructors
  Piece();
  Piece(int tn, int td);
  //destructor
  ~Piece();
  //setters
  void setAlive(bool al);
  void setTeam(int tn);
  void setDirection(int td);
  void setTeamDir(int tn, int td);
  //getters
  bool getAlive();
  int getTeam();
  int getDirection();
  //methods
  bool flipAlive();
  int flipDirection();
};

#endif //PIECE_H
