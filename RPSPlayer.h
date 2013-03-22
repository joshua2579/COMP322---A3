#include <vector>
using namespace std;
#include <iostream>
#include <string>

//enum to represent a move choice. This allows headers in the below functions to
//take as input RockPaperScissorChoice instead of an int, which
//could lead to confusion since there are more than 3 ints.
enum RockPaperScissorChoice { ROCK, PAPER, SCISSOR };

//enum to represent result from a round
enum Result { PLAYERONEWIN, PLAYERTWOWIN, TIE};
enum PlayerType { SCISSORPLAYER, ROCKPLAYER, PAPERPLAYER};

class RPSPlayer {
protected:
  vector<RockPaperScissorChoice> myMoves;
  vector<RockPaperScissorChoice> myOpponentMoves;
  int playerNumber;
  PlayerType playerType;

public:

  ~RPSPlayer() {
  	vector<RockPaperScissorChoice>().swap(myMoves);
  	vector<RockPaperScissorChoice>().swap(myOpponentMoves);
  }

  int GetNumber() {
  	return playerNumber;
  }

  string GetName() {
  	if (playerType == SCISSORPLAYER) {return "SCISSORPLAYER";}
  	if (playerType == ROCKPLAYER) {return "ROCKPLAYER";}
  	else {return "PAPERPLAYER";}
  }

  //virtual function that should be overridden in inheriting classes
  virtual RockPaperScissorChoice chooseMove() = 0;

  //This method should return a Result enum representing whether p1 won (PLAYERONEWIN), p2 won (PLAYERTWOWIN), or a tie (TIE)
  static Result evaluatePlay(RockPaperScissorChoice p1, RockPaperScissorChoice p2);

  //stores the results of a move into myMoves and myOpponentMoves. This information *could*
  //be used by chooseMove() or it could be ignored.
  void addRound(RockPaperScissorChoice myMove, RockPaperScissorChoice opponentMove);
};
