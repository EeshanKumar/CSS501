#pragma once
#include <string>
using namespace std;

class Bird
{
public:
  Bird();
  Bird(string name);
  ~Bird();

  string getName() const;

private:
  string name;
  int wingSpan;
  bool flu;

}
