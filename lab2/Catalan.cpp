#include <cstdlib>
#include <iostream>
using namespace std;

int FindCatalan(int n);

int main(int argc, char* argv[])
{
  int n;
  if (argc <=1 )
  {
    cout << "Find Catalan number for n = ";
    cin >> n;
  }
  else
  {
    n = atoi(argv[1]);
  }
  cout << "Catalan of " << n << " = " << FindCatalan(n) << endl;
}

int FindCatalan(int n)
{
  if (n == 0)
  {
    return 1;
  }

  int sum = 0;

  for (int i = 0; i < n; i++)
  {
    sum += FindCatalan(i) * FindCatalan(n - 1 - i);
  }

  return sum;
}

//Catalan numbers
// c0 = 1
// c1 = c0 * c(0-0) = 1
// c2 = c0 * c(1-0) + c1 * c(1-1) = 1 + 1 = 2
// c3 = c0 * c(2-0) + c1 * c(2-1) + c2 * (c2-2) = 2 + 1 + 2 = 5
// c4 = c0 * c(3-0) + c1 * c(3-1) + c2 * c(3-2) + c3 * c(3-3) = 5 + 2 + 2 + 5
