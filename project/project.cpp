// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "taskManagementSystem.h"

using namespace std;

int main(void)
{
    //taskManagementSystem tm;
    
    BTree tr(3);

    tr.insert("137", "jyetdf");
    tr.insert("147", "jyetdf");
    tr.insert("157", "jyetdf");
    tr.insert("167", "jyetdf");
    tr.insert("177", "jyetdf");
    tr.insert("187", "jyetdf");
    tr.insert("197", "jyetdf");
    tr.insert("107", "jyetdf");
    tr.insert("138", "jyetdf");
    tr.insert("139", "jyetdf");
    tr.insert("140", "jyetdf");
    tr.insert("141", "jyetdf");
    tr.insert("142", "jyetdf");
    tr.insert("143", "jyetdf");

    DataList check = tr.CreateList();
    Data* node = check.head;
    cout << endl << endl;
    while (node != nullptr)
    {
        cout << node->key << endl;
        node = node->next;
    }
}