
#include <iostream>
#include "clsMyString.h"
using namespace std;

int main()
{

    clsMyDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty?  " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    cout << "\nArray Items: \n";

    MyDynamicArray.PrintList();

    MyDynamicArray.InsertAt(2, 500);
    cout << "\nArray Items after deleting item(2): \n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();

    system("pause>0");

}