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
    
    BTree t(6);     // A B-Tree with order 6 and degree ceil (order/2)
    t.insert("abc");
    t.insert("def");
    t.insert("ghi");
    t.insert("jkl");
    t.insert("mno");
    t.insert("pqr");
    t.insert("stu");
    t.insert("vw");
    t.insert("xy");

    cout << "Traversal of the constructed tree is ";
    t.traverse();


}