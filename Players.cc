#include "RPSPlayer.h"
//depending on how you compile you may need to include a .cc file as well above


class RockPlayer : public RPSPlayer {
public:
  //always choose rock
  RockPaperScissorChoice chooseMove() {
    return ROCK;
  }
};

class OtherPlayer : public RPSPlayer {
public:
  //always choose rock
  RockPaperScissorChoice chooseMove() {
    return ROCK;
  }
};

class YetOtherPlayer : public RPSPlayer {
public:
  //always choose rock
  RockPaperScissorChoice chooseMove() {
    return ROCK;
  }
};