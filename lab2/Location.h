#pragma once
#include <iostream>
using namespace std;

class Location
{
    friend ostream& operator<<(ostream &outStream, const Location &loc);
    friend istream& operator>>(istream &inStream, Location &loc);

public:
//Constructors - Destructors
    Location();
    Location(int x, int y);
    ~Location();

//Getters - Setters
    int getX() const;
    int getY() const;
    bool setX(int x);
    bool setY(int y);
    bool setCoordinates(int x, int y);

//Op Overloads
    Location operator+(const Location &loc) const;
    Location operator+=(const Location &loc);

    Location operator-(const Location &loc) const;
    Location operator-=(const Location &loc);

    Location operator-() const;

    bool operator==(const Location &loc) const;
    bool operator!=(const Location &loc) const;

private:
    int xCoordinate;
    int yCoordinate;
};
