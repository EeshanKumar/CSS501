#include "Child.h"

//Constructors -- Destructors
Child::Child()
{
  firstName = "";
  lastName = "";
  age = 0;
}
Child::Child(string fName)
{
  firstName = fName;
  lastName = "";
  age = 0;
}
Child::Child(string fName, string lName)
{
  firstName = fName;
  lastName = lName;
  age = 0;
}
Child::Child(string fName, string lName, int age)
{
  firstName = fName;
  lastName = lName;
  this->age = age;
}
Child::~Child()
{
}

//Getters -- Setters
string Child::getFirstName() const
{
  return firstName;
}
string Child::getLastName() const
{
  return lastName;
}
int Child::getAge() const
{
  return age;
}
bool Child::setFirstName(string fName)
{
  firstName = fName;
}
bool Child::setLastName(string lName)
{
  lastName = lName;
}
bool Child::setAge(int age)
{
  this->age = age;
}
bool Child::setFullName(string fName, string lName)
{
  firstName = fName;
  lastName = lName;
}

//Operator Overloads
bool Child::operator==(const Child &c1) const
{
  if ((firstName == c1.firstName) && (lastName == c1.lastName) && (age == c1.age))
  {
    return true;
  }
  return false;
}
bool Child::operator!=(const Child &c1) const
{
  if ((firstName != c1.firstName) && (lastName != c1.lastName) && (age != c1.age))
  {
    return true;
  }
  return false;
}
bool Child::operator>(const Child &c1) const
{
  return (lastName > c1.lastName);
}
bool Child::operator>=(const Child &c1) const
{
  if (*this == c1) {
    return true;
  }
  return (lastName > c1.lastName);
}
bool Child::operator<(const Child &c1) const
{
  return (lastName < c1.lastName);
}
bool Child::operator<=(const Child &c1) const
{
  if (*this == c1) {
    return true;
  }
  return (lastName < c1.lastName);
}

//Friend functions
ostream& operator<<(ostream &outStream, const Child &c1)
{
  outStream << c1.firstName << c1.lastName << c1.age;
  return outStream;
}
istream& operator>>(istream &inStream, Child &c1)
{
  inStream >> c1.firstName >> c1.lastName >> c1.age;
  return inStream;
}
