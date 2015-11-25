#include "Location.h"
#include "Robot.h"
#include <iostream>
using namespace std;

int main()
{
  Location start, treasure;
  cout << "Input starting and treasure points";
  cout << "Ex: 1 2 3 5 corresponds to (1,2) -> (3,5)" << endl;

  cin >> start;
  cin >> treasure;

  Robot rob("Rob", start);

  rob.PrintTreasurePaths(treasure);

  /*
  int numPaths = rob.FindNumPathsToTreasure(treasure);
  cout << "Number of paths from " << start << " to " << treasure << " is " << numPaths << endl;

  //Testing Location Code
  Location loc1, loc2;

  cout << "Input loc1: " << endl;
  cin >> loc1;

  cout << "Input loc2: " << endl;
  cin >> loc2;

  // loc1.setCoordinates(1,2);
  // loc2.setCoordinates(2,3);

  cout << "Starting at " << loc1 << endl;
  cout << "Ending at " << loc2 << endl;

  Location add, subtract, negate;

  add = loc1 + loc2;
  subtract = loc1 - loc2;
  negate = -loc1;

  cout << "Adding loc1 and loc2 makes " << add << endl;
  cout << "Subtracting loc1 - loc2 makes " << subtract << endl;
  cout << "Negating loc1 = " << negate << endl;


  //Testing Robot Code
  Robot imposter;
  Robot c3p0("C3P0");
  Robot r2d2("R2D2", loc2);

  imposter.setName("C3P0");
  imposter.setStartPoint(loc2);
  c3p0.setStartPoint(loc2);
  cout << c3p0.getName() << " and " << r2d2.getName() << " are friends!" << endl;
  cout << "They started at " << c3p0.getStartPoint() << " and " << r2d2.getStartPoint() << " respectively" << endl;

  cout << imposter;
  cout << c3p0;
  cout << r2d2;

  cout << "(imposter == c3p0) = " << (imposter == c3p0) << endl;
  cout << "(imposter == r2d2) = " << (imposter == r2d2) << endl;
  cout << "(imposter != r2d2) = " << (imposter != r2d2) << endl;
  */
}
