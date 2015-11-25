#pragma once
enum Suit {Heart, Spade, Diamond, Club}
class Card

{
public:
  Card();
  Card(int val, Suit suit);
  ~Card();

  Suit getGuit() const;

private:
  int value;
  Suit suit;
}
