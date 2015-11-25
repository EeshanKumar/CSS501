//VectorExample.cpp

#include "Bird.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{

  Bird bird1("eagle");
  Bird b1("duck");
  Bird b2("goose");
  vector<Bird> birds;
  vector<Bird> birds2(4, b1);

  for (int i = 0; i < birds2.size(); i++)
  {
    cout << birds2.at(i).getName() << endl;
  }

  // vector<int> first;
  // vector<int> second = { 100, 200, 300 };
  // vector<int> third = second;
  // vector<int> fourth(4, 100);
  // second.push_back(400);
  // for (int i = 0; i < second.size(); i++)
  // {
  //   cout << "val[" << i << "] = " << second[i] << endl;
  //   cout << "val[" << i << "] = " << second.at(i) << endl;
  // }

  return 0;
}
