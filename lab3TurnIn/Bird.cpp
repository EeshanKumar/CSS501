#include "Bird.h"

//Constructors -- Desctructors
Bird::Bird()
{
  name = "";
  id = 0;
}
Bird::Bird(string name)
{
  this->name = name;
  id = 0;
}
Bird::Bird(string name, int id)
{
  this->name = name;
  this->id = id;
}
Bird::~Bird()
{
}

//Getters -- Setters
string Bird::getName() const
{
  return name;
}
int Bird::getId() const
{
  return id;
}
bool Bird::setName(string name)
{
  this->name = name;
  return true;
}
bool Bird::setId(int id)
{
  this->id = id;
  return true;
}

//Operator Overloads
bool Bird::operator==(const Bird &bird1) const
{
  if ((name == bird1.name) && (id == bird1.id))
  {
    return true;
  }
  return false;
}
bool Bird::operator!=(const Bird &bird1) const
{
  if ((name != bird1.name) || (id != bird1.id))
  {
    return true;
  }
  return false;
}
bool Bird::operator>(const Bird &bird1) const
{
  return (id > bird1.id);
}
bool Bird::operator>=(const Bird &bird1) const
{
  if (id == bird1.id) {
    return true;
  }
  return (id > bird1.id);
}
bool Bird::operator<(const Bird &bird1) const
{
  return (id < bird1.id);
}
bool Bird::operator<=(const Bird &bird1) const
{
  if (id == bird1.id) {
    return true;
  }
  return (id < bird1.id);
}

ostream& operator<<(ostream &outStream, const Bird &bird1)
{
  outStream << bird1.name << bird1.id;
  return outStream;
}
istream& operator>>(istream &inStream, Bird &bird1)
{
  inStream >> bird1.name >> bird1.id;
  return inStream;
}
