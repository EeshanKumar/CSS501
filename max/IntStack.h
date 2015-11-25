#pragma once
class IntStack
{

public:
  IntStack();
  ~IntStack();

  bool Push(int val);
  bool Pop(int &val);
  bool Peek(int &val);
  int Size();
  // bool Clear();
  // bool isEmpty();
  // bool isFull();
}
