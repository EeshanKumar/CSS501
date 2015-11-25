#include <iostream>
using namespace std;
#include "Bird.h"
#include "Child.h"
#include "List501.h"

int main()
{
  // while (true)
  {
    Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
    c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
    Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13),
    c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
    Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
    List501<Child> class1, class2, soccer, chess;

    int a = 1, b = -1, c = 13;

    class1.Insert(&c1);
    class1.Insert(&c2);
    class1.Insert(&c3);
    class1.Insert(&c4);
    class1.Insert(&c5);
    class1.Insert(&c6);
    class1.Insert(&c5);
    cout << "class1: " << class1 << endl;

    if (class1.Insert(&c1))
    {
      cout << "ERROR::: Duplicate" << endl;
    }
    class2.Insert(&c4);
    class2.Insert(&c5);
    class2.Insert(&c6);
    class2.Insert(&c7);
    class2.Insert(&c10);
    cout << "Class2: " << class2 << endl;

    class1.Merge(class2);
    class2.Merge(class1);
    class1.Merge(class2);
    class1.Merge(class1);
    cout << "class1 and 2 Merged: " << class1 << endl;
    if (!class2.isEmpty())
    {
      cout << "ERROR:: Class2 should be empty empty" << endl;
    }
    class1.Remove(c4, c11);
    class1.Remove(c5, c11);
    class1.Remove(c11, c11);
    if (class1.Remove(c1, c11))
    {
      cout << "Removed from class1, student " << c11 << endl;
    }
    cout << "class1: " << class1 << endl;
    soccer.Insert(&c6);
    soccer.Insert(&c4);
    soccer.Insert(&c9);
    cout << "soccer: " << soccer << endl;
    soccer += class1;
    cout << "soccer += class1 : " << soccer << endl;

    List501<Child> football = soccer;
    if (football == soccer)
    {
      cout << "football: " << football << endl;
    }
    if (football.Peek(c6, c11))
    {
      cout << c11 << " is on the football team" << endl;
    }
    soccer.DeleteList();
    if (!soccer.isEmpty())
    {
      cout << "ERROR: soccer should be empty" << endl;
    }
    List501<int> numbers;
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout << "These are the numbers: " << numbers << endl;
    numbers.DeleteList();

    //List Tests with Bird
    List501<Bird> list1;
    string fileName = "Birds.txt";

    bool returnBool = list1.BuildList(fileName);

    cout << "Your list (Return Value = " << returnBool << "): " << endl;
    cout << list1 << endl << endl;

    Bird b1("Eagle", 1);
    Bird r1Bird;
    returnBool = list1.Remove(b1, r1Bird);

    cout << "Trying to remove Bird " << b1 << endl;
    cout << "Your return was " << r1Bird << endl;
    cout << "Your list (Return Value = " << returnBool << "): " << endl;
    cout << list1 << endl << endl;

    Bird b2("Tern", 44);
    Bird r2Bird;
    returnBool = list1.Remove(b2, r2Bird);

    cout << "Trying to remove Bird " << b2 << endl;
    cout << "Your return was " << r2Bird << endl;
    cout << "Your list (Return Value = " << returnBool << "): " << endl;
    cout << list1 << endl << endl;

    Bird b3("Warbler", 34);
    Bird r3Bird;
    returnBool = list1.Remove(b3, r3Bird);

    cout << "Trying to remove Bird " << b3 << endl;
    cout << "Your return was " << r3Bird << endl;
    cout << "Your list (Return Value = " << returnBool << "): " << endl;
    cout << list1 << endl << endl;

    cout << "Your list beofre DeleteList was called: " << endl;
    cout << list1 << endl;
    cout << "Your list is empty: " << list1.isEmpty() << endl;
    list1.DeleteList();
    cout << "Your list after DeleteList was called: " << endl;
    cout << list1 << endl;
    cout << "Your list is empty: " << list1.isEmpty() << endl << endl;

    List501<Bird> list2;
    List501<Bird> list3;

    list2.BuildList(fileName);
    list3 = list2;
    cout << "List 2: " << list2 << endl;
    cout << "List 3: " << list3 << endl;
    cout << "list3 == list2? " << (list3 == list2) << endl;
    cout << "list3 != list2? " << (list3 != list2) << endl << endl;

    list2.DeleteList();
    cout << "List 2: " << list2 << endl;
    cout << "List 3: " << list3 << endl;
    cout << "list3 == list2? " << (list3 == list2) << endl;
    cout << "list3 != list2? " << (list3 != list2) << endl << endl;

    Bird b11("Tom", 15), b12("Peter", 99), b13("Tern", 44), b14("Eagle", 1),
    b15("New", 0), b16("Tom", 15), b17("Peter", 99), b18("Tern", 44), b19("Eagle", 1),
    b20("New", 0);

    List501<Bird> list4 = list3;
    List501<Bird> list5;
    list5.Insert(&b11);
    list5.Insert(&b12);
    list5.Insert(&b13);
    list5.Insert(&b14);
    list5.Insert(&b15);
    cout << "List 4: " << list4 << endl;
    cout << "List 5: " << list5 << endl;
    cout << "Trying to merge list5 into list4" << endl;
    list4.Merge(list5);
    cout << "List 4: " << list4 << endl;
    cout << "List 5: " << list5 << endl << endl;

    List501<Bird> list6 = list3;
    List501<Bird> list7, list8;
    list7.Insert(&b16);
    list7.Insert(&b17);
    list7.Insert(&b18);
    list7.Insert(&b19);
    list7.Insert(&b20);
    cout << "List 6: " << list6 << endl;
    cout << "List 7: " << list7 << endl;
    cout << "list8 = list6 + list7" << endl;
    list8 = list6 + list7;
    cout << "List 6: " << list6 << endl;
    cout << "List 7: " << list7 << endl;
    cout << "List 8: " << list8 << endl << endl;

    cout << "List 6: " << list6 << endl;
    cout << "List 7: " << list7 << endl;
    cout << "list6 += list7" << endl;
    list6 += list7;
    cout << "List 6: " << list6 << endl;
    cout << "List 7: " << list7 << endl << endl;
  }

  // /*
  // Bird tests
  // */
  // //Constructors test
  // Bird b1;
  // Bird b2("b2");
  // Bird b3("b3", 33);
  // cout << "b1 = " << b1 << endl;
  // cout << "b2 = " << b2 << endl;
  // cout << "b3 = " << b3 << endl;

  // Bird b4("name", 55);
  // Bird b5;
  // //Setters test
  // b5.setName("name");
  // b5.setId(55);
  // //Operator == Test
  // if (b4 == b5) {
  //   cout << "Those birds equal each other" << endl;
  //   //Outstream test
  //   cout << "b4 = " << b4 << endl;
  //   cout << "b5 = " << b5 << endl;
  // }
  // b4.setName("newName");
  // b5.setId(56);
  // //Operator != Test
  // if (b4 != b5) {
  //   cout << "Those birds no longer equal each other" << endl;
  //   //Getters test
  //   cout << "b4 = " << b4.getName() << b4.getId() << endl;
  //   cout << "b5 = " << b5.getName() << b5.getId() << endl;
  // }

  // //Operator > Test
  // if (b3 > b2)
  // {
  //   cout << "b3 > b2" << endl;
  //   cout << "b3 = " << b3 << endl;
  //   cout << "b2 = " << b2 << endl;
  // }
  // //Operator >= Test
  // b3.setId(0);
  // if (b3 >= b2)
  // {
  //   cout << "b3 >= b2" << endl;
  //   cout << "b3 = " << b3 << endl;
  //   cout << "b2 = " << b2 << endl;
  // }
  // //Operator < Test
  // if (b1 < b4)
  // {
  //   cout << "b1 < b4" << endl;
  //   cout << "b1 = " << b1 << endl;
  //   cout << "b4 = " << b4 << endl;
  // }
  // //Operator <= Test
  // if (b1 <= b4)
  // {
  //   cout << "b1 <= b4" << endl;
  //   cout << "b1 = " << b1 << endl;
  //   cout << "b4 = " << b4 << endl;
  // }

  // //InStream test
  // cout << "Input a bird name and id" << endl;
  // cin >> b1;
  // cout << "Your inputted bird is = " << b1 << endl;
  return 0;
}
