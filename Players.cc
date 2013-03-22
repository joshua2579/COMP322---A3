#include "RPSPlayer.h"
//depending on how you compile you may need to include a .cc file as well above


class RockPlayer : public RPSPlayer {
public:
  RockPlayer() {
    playerType = ROCKPLAYER;
  }

  RockPlayer(int num) {
    playerType = ROCKPLAYER;
    playerNumber = num;
  }

  //always choose rock
  RockPaperScissorChoice chooseMove() {
    return ROCK;
  }
};

class ScissorPlayer : public RPSPlayer {
public:
  ScissorPlayer() {
    playerType = SCISSORPLAYER;
  }

  ScissorPlayer(int num) {
    playerType = SCISSORPLAYER;
    playerNumber = num;
  }

  //always choose rock
  RockPaperScissorChoice chooseMove() {
    return SCISSOR;
  }
};

class PaperPlayer : public RPSPlayer {
public:
  PaperPlayer() {
    playerType = PAPERPLAYER;
  }

  PaperPlayer(int num) {
    playerType = PAPERPLAYER;
    playerNumber = num;
  }

  //always choose rock
  RockPaperScissorChoice chooseMove() {
    return PAPER;
  }
};

// class BeatOpponentsPreviousMovePlayer : public RPSPlayer {
// private:
//  RockPaperScissorChoice opponentsPreviousMove;
// public:
//   //Chooses the move that beats the opponent's previous move
//   RockPaperScissorChoice chooseMove() {
//     opponentsPreviousMove = myOpponentMoves.back();
//     switch (opponentsPreviousMove) {
//       case ROCK:
//       return PAPER;
//       case PAPER:
//       return SCISSOR;
//       case SCISSOR:
//       return ROCK;
//     }
//   }
// };

// class SmartPlayer : public RPSPlayer {
// private:
//   int rocks, papers, scissors;
//   vector<RockPaperScissorChoice>::iterator it;
// public:
//   //Iterates through all the opponents' previous moves and beats the most frequent one.
//   RockPaperScissorChoice chooseMove() {
//     rocks = papers = scissors = 0;
//     for(it = myOpponentMoves.begin(); it < myOpponentMoves.end(); it++) {
//       switch (*it) {
//         case ROCK:
//         rocks++;
//         case PAPER:
//         papers++;
//         case SCISSOR:
//         scissors++;
//       }
//       if ((rocks >= papers) && (rocks >= scissors)) {
//         return PAPER;
//       } else if ((papers >= rocks) && (papers >= scissors)) {
//         return SCISSOR;
//       } else { //scissor is the most frequent move
//         return ROCK;
//       }
//     }
//   }
// };