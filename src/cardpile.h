#pragma once
#include <vector>

#include "deck.h"

class CardPile {
 public:
  std::vector<Card*> m_cards_;
  std::vector<Card*> m_original_cards_;
  explicit CardPile(int num_of_decks);
  void refresh();
  std::string print();
  void shuffle();
};
