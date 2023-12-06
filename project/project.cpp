// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "taskManagementSystem.h"

using namespace std;

int main(void)
{
    taskManagementSystem tm;
    tm.insertMachine();
    tm.insertMachine();
    tm.insertMachine();
    tm.insertMachine();
    tm.insertMachine();
    tm.insertMachine();

    BTree t(6); // A B-Tree with minimum degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed tree is ";
    t.traverse();


}