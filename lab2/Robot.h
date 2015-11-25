#pragma once
#include "Location.h"
#include <vector>
#include <iostream>
using namespace std;

class Robot
{
    friend ostream& operator<<(ostream &outStream, const Robot &robot);
    friend istream& operator>>(istream &inStream, Robot &robot);

public:
//Constructors -- Destructors
    Robot();
    Robot(string robotName);
    Robot(string robotName, Location start);
    ~Robot();

//Getters -- Setters
    string getName() const;
    Location getStartPoint() const;
    bool setName(const string &robotName);
    bool setStartPoint(const Location &start);

//Functions
    int FindNumPathsToTreasure(const Location &treasure) const;
    void PrintTreasurePaths(const Location &treasure) const;

//Op Overloads
    bool operator==(const Robot &robot) const;
    bool operator!=(const Robot &robot) const;

private:
    string name;
    Location startSpot;

    void findPaths(const Location &start, const Location &end, const string &path, vector<string>& pathsVector) const;
};
