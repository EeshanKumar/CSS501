#include "Location.h"

//Constructors - Destructors
Location::Location()
{
  xCoordinate = 0;
  yCoordinate = 0;
}
Location::Location(int x, int y)
{
  xCoordinate = x;
  yCoordinate = y;
}
Location::~Location()
{
}

//Getters - Setters
int Location::getX() const
{
  return xCoordinate;
}
int Location::getY() const
{
  return yCoordinate;
}
bool Location::setX(int x)
{
  xCoordinate = x;
  return true;
}
bool Location::setY(int y)
{
  yCoordinate = y;
  return true;
}
bool Location::setCoordinates(int x, int y)
{
  xCoordinate = x;
  yCoordinate = y;
  return true;
}

//Op Overloads
Location Location::operator+(const Location &loc) const
{
  Location result(xCoordinate, yCoordinate);
  result += loc;
  return result;
}
Location Location::operator+=(const Location &loc)
{
  xCoordinate += loc.xCoordinate;
  yCoordinate += loc.yCoordinate;
  return *this;
}

Location Location::operator-(const Location &loc) const
{
  Location result(xCoordinate, yCoordinate);
  result -= loc;
  return result;
}
Location Location::operator-=(const Location &loc)
{
  xCoordinate -= loc.xCoordinate;
  yCoordinate -= loc.yCoordinate;
  return *this;
}

Location Location::operator-() const
{
  Location result(-xCoordinate, -yCoordinate);
  return result;
}

bool Location::operator==(const Location &loc) const
{
  return ((xCoordinate == loc.xCoordinate) && (yCoordinate == loc.yCoordinate));
}
bool Location::operator!=(const Location &loc) const
{
  return ((xCoordinate != loc.xCoordinate) || (yCoordinate != loc.yCoordinate));
}

ostream& operator<<(ostream &outStream, const Location &loc)
{
  outStream << "(" << loc.xCoordinate << ", " << loc.yCoordinate << ")";
  return outStream;
}
istream& operator>>(istream &inStream, Location &loc)
{
  int x, y;
  inStream >> x >> y;
  loc.setCoordinates(x, y);
  return inStream;
}
