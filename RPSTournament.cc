//#include "RPSPlayer.h"
#include "Players.cc"
#define TEST true
//compile: g++ -Wall -o out.exe RPSPlayer.cc RPSTournament.cc Players.cc 

int main() {
	//Initialization of all players
	vector<RPSPlayer*> players;
	int i, r;
	for(i = 1; i<=128; i++) {
		r = rand();
		r = r%3;
		switch(r) {
			case 0: {
				RockPlayer* rPlayer = new RockPlayer(i);
				if (TEST) cout << "Rock: " << rPlayer->GetNumber() << endl;
				players.push_back(rPlayer);
				break;
			}
			case 1: {
				ScissorPlayer* sPlayer = new ScissorPlayer(i);
				if (TEST) cout << "Scissor: " << sPlayer->GetNumber() << endl;
				players.push_back(sPlayer);
				break;
			}
			case 2: {
				PaperPlayer* pPlayer = new PaperPlayer(i);
				if (TEST) cout << "Paper: " << pPlayer->GetNumber() << endl;
				players.push_back(pPlayer);
				break;
			}
		}
	}

	//begin tournament
	cout << "Tournament begins!\n";
	for (vector<RPSPlayer*>::iterator it = players.begin(); it != players.end();) {
		if (players.size() == 1) {
			cout << "Player number " << players.front()->GetNumber();
			cout << " of type " << players.front()->GetName();
			cout << " wins the tournament!" << endl;
			break;
		}
		int count = players.size()%2;
				if (count == 1) {it++; count++;} //if there were uneven players, skip the first one.
				if (TEST) cout << "Current first player: " << (*it)->GetNumber() << endl;
				if (TEST) cout << "Current second player: " << (*(it+1))->GetNumber() << endl;
				RockPaperScissorChoice playerOneMove;
				RockPaperScissorChoice playerTwoMove;
				Result result = TIE;
				int repeat = 0;
					while ((result == TIE) && (repeat < 3)) { //this play is repeated three times to try and fix the tie
						result = (*it)->evaluatePlay(playerOneMove = (*it)->chooseMove(),playerTwoMove = (*(it+1))->chooseMove());
						//if (TEST && (repeat = 0)) cout << "Tie: " << (*it)->GetNumber() << " V.S " << (*(it+1))->GetNumber() << endl;
						repeat++;
					}
					if (result == PLAYERONEWIN) {
						if (TEST) cout << "PlayerOneWin: " << (*it)->GetNumber() << " V.S " << (*(it+1))->GetNumber() << endl;
						(*it)->addRound(playerOneMove, playerTwoMove);
						delete (*(it+1)); //delete the player from memory
						players.erase(it+1); //remove the player from the list
						it = players.begin();
					} else if (result == PLAYERTWOWIN) {
						if (TEST) cout << "PlayerTwoWin: " << (*it)->GetNumber() << " V.S " << (*(it+1))->GetNumber() << endl;
						(*(it+1))->addRound(playerTwoMove, playerOneMove);
						delete (*it); //delete the player from memory
						players.erase(it); //remove the player from the list
						it = players.begin();
					} else if (result == TIE) { //There's still a tie even after three tries
					if (TEST && (repeat != 0)) cout << "Tied 3 times: " << (*it)->GetNumber() << " V.S " << (*(it+1))->GetNumber() << endl;	
						delete (*it); //delete the player from memory
						players.erase(it); //remove the player from the list
						delete ((*it)); //delete the player from memory
						players.erase(it); //remove the player from the list
						it = players.begin();
						if (players.size() == 0) {
							cout << "The last two players tied three times. They were both eliminated." << endl;
							break;
						}
					}
				}
				return 0;
			}