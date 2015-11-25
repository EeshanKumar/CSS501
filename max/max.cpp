// Max.cpp : Defines the entry point for the console application.
//

#include <iostream>

int _tmain(int argc)
{
  int num1, num2;
  std::cout << "Input two numbers: " << std::endl;
  std::cin >> num1;
  std::cin >> num2;

  if (num1 > num2)
  {
    std::cout << num1 << "is biggest" << std::endl;
  }
  else
  {
    std::cout << num2 << "is biggest" << std::endl;
  }

  return 0;
}


