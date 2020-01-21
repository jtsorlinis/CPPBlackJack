#include <iostream>
#include "cardpile.h"
#include "player.h"
#include "table.h"
#include <algorithm>
#include <time.h>

int numOfPlayers = 5;
int numOfDecks = 8;
int baseBet = 10;
int minCards = 40;

int rounds = 10000;
int verbose = 0;

int main() {
	Table table1(numOfPlayers,numOfDecks,baseBet,minCards,verbose);
	table1.mCardPile.shuffle();

	clock_t start;
	double duration;
	start = clock();

	int x = 0;
	while (++x < rounds) {
		if (verbose > 0) {
			std::cout << "Round " << x << "\n";
		}
		if (verbose == 0 && rounds > 1000 and x % (rounds / 100) == 0) {
			std::cout << "\tProgress: " << ((float)x/rounds)*100 << "%\r";
		}
		
		table1.startRound();
		table1.checkEarnings();
	}

	for (auto& player : table1.mPlayers) {
		std::cout << "Player " << player.mPlayerNum << " earnings: " << player.mEarnings << "\t\tWin Percentage: " << (50 + (player.mEarnings / (rounds * baseBet) * 50)) << "\n";
	}
	std::cout << "Casino earnings: " << table1.mCasinoEarnings << "\n";

	duration = (clock() - start)/(double)CLOCKS_PER_SEC;
	std::cout << "\nPlayed " << x << " rounds in " << duration << " seconds.";
}
