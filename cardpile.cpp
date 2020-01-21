#include "cardpile.h"
#include <random>

CardPile::CardPile(int numOfdecks) {
	for (int x = 0; x < numOfdecks; x++) {
		Deck tempDeck;
		mCards.insert(mCards.end(), tempDeck.mCards.begin(), tempDeck.mCards.end());
	}
}

std::string CardPile::print() {
	std::string output;
	for (auto &i : mCards) {
		output += i.print() + "\n";
	}
	return output;
}

void CardPile::shuffle() {
	std::random_device rd;
	std::shuffle(mCards.begin(), mCards.end(), rd);
}