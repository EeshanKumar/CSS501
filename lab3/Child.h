#pragma once
#include <iostream>
using namespace std;

class Child
{
  friend ostream& operator<<(ostream &outStream, const Child &c1);
  friend istream& operator>>(istream &inStream, Child &c1);

public:
//Constructors -- Destructors
  Child();
  Child(string fName);
  Child(string fName, string lName);
  Child(string fName, string lName, int age);
  ~Child();

//Getters -- Setters
  string getFirstName() const;
  string getLastName() const;
  int getAge() const;
  bool setFirstName(string fName);
  bool setLastName(string lName);
  bool setAge(int age);
  bool setFullName(string fName, string lName);

//Operator Overloads
  bool operator==(const Child &c1) const;
  bool operator!=(const Child &c1) const;
  bool operator>(const Child &c1) const;
  bool operator>=(const Child &c1) const;
  bool operator<(const Child &c1) const;
  bool operator<=(const Child &c1) const;

private:
  int age;
  string firstName;
  string lastName;
};
