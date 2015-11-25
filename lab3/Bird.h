#pragma once
#include <iostream>
using namespace std;

class Bird
{
  friend ostream& operator<<(ostream &outStream, const Bird &bird1);
  friend istream& operator>>(istream &inStream, Bird &bird1);

public:
//Constructors -- Desctructors
  Bird();
  Bird(string name);
  Bird(string name, int id);
  ~Bird();

//Getters -- Setters
  string getName() const;
  int getId() const;
  bool setName(string name);
  bool setId(int id);

//Operator Overloads
  bool operator==(const Bird &bird1) const;
  bool operator!=(const Bird &bird1) const;
  bool operator>(const Bird &bird1) const;
  bool operator>=(const Bird &bird1) const;
  bool operator<(const Bird &bird1) const;
  bool operator<=(const Bird &bird1) const;

private:
  string name;
  int id;
};
