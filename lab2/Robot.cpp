#include "Robot.h"

//Constructors -- Destructors
Robot::Robot()
{
}
Robot::Robot(string robotName)
{
  name = robotName;
}
Robot::Robot(string robotName, Location start)
{
  name = robotName;
  startSpot = start;
}
Robot::~Robot()
{
}

//Getters -- Setters
string Robot::getName() const
{
  return name;
}
Location Robot::getStartPoint() const
{
  return startSpot;
}
bool Robot::setName(const string &robotName)
{
  name = robotName;
  return true;
}
bool Robot::setStartPoint(const Location &start)
{
  startSpot = start;
  return true;
}

//Functions
int Robot::FindNumPathsToTreasure(const Location &treasure) const
{
  vector<string> pathsVector;
  string path;

  findPaths(startSpot, treasure, path, pathsVector);
  return pathsVector.size();
}
void Robot::PrintTreasurePaths(const Location &treasure) const
{
  vector<string> pathsVector;
  string path;

  findPaths(startSpot, treasure, path, pathsVector);

  for (int i = 0; i < pathsVector.size(); i++)
  {
    cout << pathsVector[i] << endl;
  }
  cout << "Number of paths: " << pathsVector.size() << endl;
}

//Op Overloads
bool Robot::operator==(const Robot &robot) const
{
  return ((name == robot.name) && (startSpot == robot.startSpot));
}
bool Robot::operator!=(const Robot &robot) const
{
  return ((name != robot.name) || (startSpot != robot.startSpot));
}

ostream& operator<<(ostream &outStream, const Robot &robot)
{
  outStream << "Robot " << robot.name << " at grid spot " << robot.startSpot << endl;
  outStream << "Reporting for duty sir!" << endl;
  return outStream;
}
istream& operator>>(istream &inStream, Robot &robot)
{
  inStream >> robot.name >> robot.startSpot;
  return inStream;
}

//Private Functions
void Robot::findPaths(const Location &start, const Location &end, const string &path, vector<string>& pathsVector) const
{
  Location newStart;
  string newPath;

  if ((start == end) && (path.length > 0))
  {
    return pathsVector.push_back(path);
  }
  if (start.getY() < end.getY())
  {
    newStart = start + Location(0, 1);
    newPath = path + "N";
    findPaths(newStart, end, newPath, pathsVector);
  }
  if (start.getY() > end.getY())
  {
    newStart = start + Location(0, -1);
    newPath = path + "S";
    findPaths(newStart, end, newPath, pathsVector);
  }
  if (start.getX() < end.getX())
  {
    newStart = start + Location(1, 0);
    newPath = path + "E";
    findPaths(newStart, end, newPath, pathsVector);
  }
  if (start.getX() > end.getX())
  {
    newStart = start + Location(-1, 0);
    newPath = path + "W";
    findPaths(newStart, end, newPath, pathsVector);
  }
}
