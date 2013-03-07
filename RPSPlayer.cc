#include "RPSPlayer.h"

Result RPSPlayer::evaluatePlay(RockPaperScissorChoice p1, RockPaperScissorChoice p2) {
	switch (p1) {
		case ROCK:
		switch (p2) {
			case ROCK:
			return TIE;
			case PAPER:
			return PLAYERTWOWIN;
			case SCISSOR:
			return PLAYERONEWIN;
		}
		case PAPER:
		switch (p2) {
			case ROCK:
			return PLAYERONEWIN;
			case PAPER:
			return TIE;
			case SCISSOR:
			return PLAYERTWOWIN;
		}
		case SCISSOR:
		switch (p2) {
			case ROCK:
			return PLAYERTWOWIN;
			case PAPER:
			return PLAYERONEWIN;
			case SCISSOR:
			return TIE;
		}
		default:
		return TIE;
	}
}

void RPSPlayer::addRound(RockPaperScissorChoice myMove, RockPaperScissorChoice opponentMove) {
	myMoves.push_back(myMove);
	myOpponentMoves.push_back(opponentMove);
}