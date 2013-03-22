//#include "RPSPlayer.h"
#include "Players.cc"
//compile: g++ -Wall -o out.exe RPSPlayer.cc RPSTournament.cc Players.cc 

int main() {
	vector<RPSPlayer*> players;
	int i, r;
	for(i = 0; i<128; i++) {
		r = rand()%3;
		switch(r) {
			case 0: {
			RockPlayer* rPlayer = new RockPlayer(i);
			players.push_back(rPlayer);
			}
			case 1: {
			ScissorPlayer* sPlayer = new ScissorPlayer(i);
			players.push_back(sPlayer);
			}
			case 2: {
			PaperPlayer* pPlayer = new PaperPlayer(i);
			players.push_back(pPlayer);
			}
		}
	}

	
	
	return 0;
}