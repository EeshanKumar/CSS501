#include "Bird.h"

Bird::Bird()
{
}

Bird::Bird(string name)
{
  this->name = name;
}

string Bird::getName() const
{
  return name;
}

Bird::~Bird()
{
}

