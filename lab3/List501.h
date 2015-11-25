#pragma once
#include <cstddef>
#include <iostream>
#include <fstream>
using namespace std;

template <class ItemType>
class List501
{
public:

  friend ostream& operator<<(ostream &outStream, const List501<ItemType> &list1)
  {
    Node *pNode;
    pNode = list1.head;
    while (pNode != NULL)
    {
      ItemType *itemPtr;
      itemPtr = pNode->data;
      outStream << *itemPtr;
      pNode = pNode->next;
    }
    return outStream;
  }

//Constructors -- Desctructors
  List501();
  List501(const List501<ItemType> &srcList);
  ~List501();

//Operator Overloads
  List501<ItemType> operator+(const List501<ItemType> &list1) const;
  List501<ItemType>& operator+=(const List501<ItemType> &list1);

  bool operator==(const List501<ItemType> &list1) const;
  bool operator!=(const List501<ItemType> &list1) const;

  List501<ItemType>& operator=(const List501<ItemType> &list1);

//Functions
  bool BuildList(string fileName);
  bool Insert(ItemType *obj);
  bool Remove(ItemType target, ItemType &result);
  bool Peek(ItemType target, ItemType &result);
  bool isEmpty();
  void DeleteList();
  bool Merge(List501 &list1);

private:
  struct Node{
    ItemType *data;
    Node *next;
  };
  Node *head;

  bool insertByNodePtr(Node *nodePtr);
};


//Constructors -- Destructors
template <class ItemType>
List501<ItemType>::List501()
{
  head = NULL;
}
template <class ItemType>
List501<ItemType>::List501(const List501 &srcList)
{
  head = NULL;
  *this = srcList;
}
template <class ItemType>
List501<ItemType>::~List501()
{
  this->DeleteList();
}

//Operator Overloads
template <class ItemType>
List501<ItemType> List501<ItemType>::operator+(const List501<ItemType> &list1) const
{
  List501<ItemType> returnList;
  returnList = *this;
  returnList += list1;
  return returnList;
}
template <class ItemType>
List501<ItemType>& List501<ItemType>::operator+=(const List501<ItemType> &list1)
{
  List501<ItemType> srcList;
  srcList = list1;
  this->Merge(srcList);
  return *this;
}
template <class ItemType>
bool List501<ItemType>::operator==(const List501 &list1) const
{
  Node *leftNodePtr, *rightNodePtr;
  //Null case, Same pointer case
  if (this->head == list1.head)
  {
    return true;
  }
  leftNodePtr = this->head;
  rightNodePtr = list1.head;
  while (leftNodePtr != NULL && rightNodePtr != NULL)
  {
    if (*(leftNodePtr->data) != *(rightNodePtr->data))
    {
      return false;
    }
    leftNodePtr = leftNodePtr->next;
    rightNodePtr = rightNodePtr->next;
  }
  if (leftNodePtr != NULL || rightNodePtr != NULL)
  {
    return false;
  }
  return true;
}
template <class ItemType>
bool List501<ItemType>::operator!=(const List501 &list1) const
{
  return (!(*this == list1));
}

template <class ItemType>
List501<ItemType>& List501<ItemType>::operator=(const List501<ItemType> &srcList)
{
  Node *srcNodePtr, *destNodePtr, *insNodePtr;
  ItemType srcItem;

  if (*this == srcList){
    return *this;
  }
  this->DeleteList();
  if (srcList.head == NULL) {
    return *this;
  }

  srcNodePtr = srcList.head;
  srcItem = *(srcNodePtr->data);
  destNodePtr = new Node;
  destNodePtr->data = new ItemType(srcItem);
  this->head = destNodePtr;

  srcNodePtr = srcNodePtr->next;

  while (srcNodePtr != NULL)
  {
    srcItem = *(srcNodePtr->data);
    insNodePtr = new Node;
    insNodePtr->data = new ItemType(srcItem);
    destNodePtr->next = insNodePtr;

    destNodePtr = destNodePtr->next;
    srcNodePtr = srcNodePtr->next;
  }
  destNodePtr->next = NULL;
  return *this;
}

//Functions
template <class ItemType>
bool List501<ItemType>::BuildList(string fileName)
{
  ifstream inputFile;
  inputFile.open(fileName.c_str());
  while (inputFile.is_open())
  {
    ItemType insItem;
    inputFile >> insItem;
    if (inputFile.eof())
    {
      inputFile.close();
      return true;
    }
    Insert(&insItem);
  }
  return false;
}

template <class ItemType>
bool List501<ItemType>::Insert(ItemType *obj)
{
  Node *nodePtr;
  Node *insNodePtr = new Node();
  ItemType *insItemPtr = new ItemType(*obj);
  insNodePtr->data = insItemPtr;

  if (head == NULL)
  {
    head = insNodePtr;
    insNodePtr->next = NULL;
    return true;
  }
  if (*(head->data) == *insItemPtr)
  {
    delete insItemPtr;
    delete insNodePtr;
    return false;
  }
  if (*(head->data) > *insItemPtr)
  {
    insNodePtr->next = head;
    head = insNodePtr;
    return true;
  }

  nodePtr = head;
  while (nodePtr->next != NULL)
  {
    ItemType *currItemPtr = (nodePtr->next)->data;
    if (*currItemPtr == *insItemPtr)
    {
      delete insItemPtr;
      delete insNodePtr;
      return false;
    }
    if (*currItemPtr > *insItemPtr)
    {
      break;
    }
    nodePtr = nodePtr->next;
  }
  insNodePtr->next = nodePtr->next;
  nodePtr->next = insNodePtr;
  return true;
}

template <class ItemType>
bool List501<ItemType>::Remove(ItemType target, ItemType &result)
{
  if (head == NULL) {
    return false;
  }
  if (*(head->data) == target)
  {
    result = *(head->data);
    delete head->data;
    Node *tempNodePtr;
    tempNodePtr = head;
    head = head->next;
    delete tempNodePtr;
    return true;
  }

  Node *nodePtr = head;
  while (nodePtr->next != NULL){
    ItemType *currItemPtr = (nodePtr->next)->data;
    if (*currItemPtr == target)
    {
      result = *currItemPtr;
      delete currItemPtr;
      Node *tempNodePtr;
      tempNodePtr = nodePtr->next;
      nodePtr->next = (nodePtr->next)->next;
      delete tempNodePtr;
      return true;
    }
    nodePtr = nodePtr->next;
  }
  return false;
}

template <class ItemType>
bool List501<ItemType>::Peek(ItemType target, ItemType &result)
{
  if (head == NULL) {
    return false;
  }
  if (*(head->data) == target)
  {
    result = *(head->data);
    return true;
  }

  Node *nodePtr = head;
  while (nodePtr->next != NULL){
    ItemType *currItemPtr = (nodePtr->next)->data;
    if (*currItemPtr == target)
    {
      result = *currItemPtr;
      return true;
    }
    nodePtr = nodePtr->next;
  }
  return false;
}

template <class ItemType>
bool List501<ItemType>::isEmpty()
{
  if (head == NULL)
  {
    return true;
  }
  return false;
}

template <class ItemType>
void List501<ItemType>::DeleteList()
{
  while (head != NULL)
  {
    Node *tempNodePtr;
    tempNodePtr = head;
    head = head->next;
    delete tempNodePtr->data;
    delete tempNodePtr;
  }
}

template <class ItemType>
bool List501<ItemType>::Merge(List501<ItemType> &list1)
{
  Node *insNodePtr;
  if (this->head == list1.head)
  {
    return true;
  }
  if (list1.isEmpty()) {
    return true;
  }
  if (this->isEmpty())
  {
    this->head = list1.head;
    list1.head = NULL;
    return true;
  }
  while (!list1.isEmpty())
  {
    insNodePtr = list1.head;
    list1.head = list1.head->next;
    insertByNodePtr(insNodePtr);
  }
  return true;
}

template <class ItemType>
bool List501<ItemType>::insertByNodePtr(Node *insNodePtr)
{
  Node *nodePtr;

  if (*(head->data) == *(insNodePtr->data))
  {
    delete insNodePtr->data;
    delete insNodePtr;
    return false;
  }
  if (*(head->data) > *(insNodePtr->data))
  {
    insNodePtr->next = head;
    head = insNodePtr;
    return true;
  }

  nodePtr = head;
  while (nodePtr->next != NULL)
  {
    if (*((nodePtr->next)->data) == *(insNodePtr->data))
    {
      delete insNodePtr->data;
      delete insNodePtr;
      return false;
    }
    if (*((nodePtr->next)->data) > *(insNodePtr->data))
    {
      break;
    }
    nodePtr = nodePtr->next;
  }
  insNodePtr->next = nodePtr->next;
  nodePtr->next = insNodePtr;
}
