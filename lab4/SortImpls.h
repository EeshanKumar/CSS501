#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

void MergeSort(vector<int> &array, int first, int last);
void Merge(vector<int> &array, int first, int mid, int last);
void IterativeMergeSort(vector<int> &array, int first, int last);
void QuickSort(vector<int> &array, int first, int last);
int Partition(vector<int> &array, int first, int last);
void BubbleSort(vector<int> &array, int first, int last);
void InsertSort(vector<int> &array, int first, int last);

void MergeSort(vector<int> &array, int first, int last)
{
  if (first < last)
  {
    int mid = first + (last - first) / 2;
    MergeSort(array, first, mid);
    MergeSort(array, mid + 1, last);
    Merge(array, first, mid, last);
  }
}

void Merge(vector<int> &array, int first, int mid, int last)
{
  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;

  int size = last - first + 1;
  int *tempArr = new int[size];
  int index = 0;

  while ((first1 <= last1) && (first2 <= last2))
  {
    if (array[first1] < array[first2])
    {
      tempArr[index] = array[first1];
      first1++;
    }
    else
    {
      tempArr[index] = array[first2];
      first2++;
    }
    index++;
  }
  while (first1 <= last1)
  {
    tempArr[index] = array[first1];
    first1++;
    index++;
  }
  while (first2 <= last2)
  {
    tempArr[index] = array[first2];
    first2++;
    index++;
  }
  for (index = 0; index < size; index++)
  {
    array[first] = tempArr[index];
    first++;
  }
  delete tempArr;
}

void IterativeMergeSort(vector<int> &array, int first, int last)
{
  int size = last - first + 1;
  int levels = log2(size) + 1;
  int *tempArr = new int[size];

  for (int i = 0; i < levels; i++)
  {
    int binSize = pow(2, i);
    int index = 0;
    for (int j = 0; j < size; j += binSize * 2)
    {
      int first1 = j;
      int last1 = j + binSize - 1;
      int first2 = j + binSize;
      int last2 = j + (2 * binSize) - 1;

      if ((size - j) <= binSize)
      {
        while (first1 <= last1)
        {
          tempArr[index] = array[first1];
          first1++;
          index++;
        }
        continue;
      }

      if ((size - j) <= (binSize * 2))
      {
        last2 = size - 1;
      }

      while ((first1 <= last1) && (first2 <= last2))
      {
        if (array[first1] < array[first2])
        {
          tempArr[index] = array[first1];
          first1++;
        }
        else
        {
          tempArr[index] = array[first2];
          first2++;
        }
        index++;
      }
      while (first1 <= last1)
      {
        tempArr[index] = array[first1];
        first1++;
        index++;
      }
      while (first2 <= last2)
      {
        tempArr[index] = array[first2];
        first2++;
        index++;
      }
    }
    //Copy back into original array
    int firstCopy = first;
    for (int index = 0; index < size; index++)
    {
      array[firstCopy] = tempArr[index];
      firstCopy++;
    }
  }
  delete tempArr;
}

void QuickSort(vector<int> &array, int first, int last)
{
  if (first < last)
  {
    int pivotPoint;
    if ((last - first) < 5)
    {
      InsertSort(array, first, last);
      return;
    }
    pivotPoint = Partition(array, first, last);
    QuickSort(array, first, pivotPoint - 1);
    QuickSort(array, pivotPoint + 1, last);
  }
  return;
}

int Partition(vector<int> &array, int first, int last)
{
  int pivotValue = array[last];
  int right = last - 1;
  int left = first;

  while (left < right)
  {
    while (array[left] < pivotValue)
    {
      left++;
    }
    while (array[right] > pivotValue)
    {
      right--;
    }
    if (left < right)
    {
      int temp = array[left];
      array[left] = array[right];
      array[right] = temp;
    }
  }
  array[last] = array[left];
  array[left] = pivotValue;
  return left;
}


void BubbleSort(vector<int> &array, int first, int last)
{
  for (int i = 0; i <= last; i++)
  {
    int currLocationFlag = 0;
    while (currLocationFlag < last - i)
    {
      if (array[currLocationFlag] > array[currLocationFlag + 1])
      {
        int temp = array[currLocationFlag];
        array[currLocationFlag] = array[currLocationFlag + 1];
        array[currLocationFlag + 1] = temp;
      }
      currLocationFlag++;
    }
  }
  return;
}

void InsertSort(vector<int> &array, int first, int last)
{
  for (int i = 1; i <= last; i++)
  {
    if (array[i] > array[i - 1])
    {
      continue;
    }
    int temp = array[i];
    int spot = i - 1;
    while ((temp < array[spot]) && (spot >= 0))
    {
      array[spot + 1] = array[spot];
      spot--;
    }
    array[spot + 1] = temp;
  }
  return;
}
