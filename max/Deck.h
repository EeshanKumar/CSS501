#pragma once
#include "Card.h"
#include "Hand.h"

const int NUM_CARDS_IN_DECK = 52;

class Deck
{

public:
  Deck();
  ~Deck();

  bool Shuffle();
  bool Cut();
  bool BurnCard();
  bool ReturnCard(Card card);
  bool ReturnHand(Hand hand);

  Card TopCard();
  Card DealCard();
  Hand DealHand(int numCards);

  int CountCardsRemaining();

private:
  Card deck[NUM_CARDS_IN_DECK];
}
