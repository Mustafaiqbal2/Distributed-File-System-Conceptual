// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "taskManagementSystem.h"

using namespace std;

int main(void)
{
    //taskManagementSystem tm;
    //tm.menu();
    BTree tr(6);
    tr.insert("abc", "uyuyu", "uyuy");
    tr.insert("def", "uyuyu", "uyuy");
    tr.insert("ghi", "uyuyu", "uyuy");
    tr.insert("jkl", "uyuyu", "uyuy");
    tr.insert("mno", "uyuyu", "uyuy");
    tr.insert("pqr", "uyuyu", "uyuy");
    tr.insert("stu", "uyuyu", "uyuy");
    tr.insert("vwx", "uyuyu", "uyuy");
    tr.insert("xyz", "uyuyu", "uyuy");

    
    tr.insert("qwe", "uyuyu", "uyuy");
    tr.insert("rty", "uyuyu", "uyuy");
    tr.insert("uio", "uyuyu", "uyuy");
    tr.insert("asd", "uyuyu", "uyuy");
    tr.insert("fgh", "uyuyu", "uyuy");
    tr.insert("lkj", "uyuyu", "uyuy");
    tr.insert("zxc", "uyuyu", "uyuy");
    tr.insert("vbn", "uyuyu", "uyuy");
    

    tr.traverse();
    cout << endl;
    

    cout<<tr.search2("abc");
    cout<<tr.search2("def");
    cout<<tr.search2("ghi");
    cout<<tr.search2("jkl");
    cout<<tr.search2("mno");
    cout<<tr.search2("pqr");
    cout<<tr.search2("stu");
    cout<<tr.search2("vwx");
    cout<<tr.search2("xyz");
    cout << endl;
    cout << endl;


    Data* d = tr.findsamekey("def");
    if (d == nullptr)
    {
        cout << endl << "null" << endl;
    }
    else
        cout << d->key << endl;
    cout << endl;
    cout << endl;
    
    tr.insert("asd", "gbv", "uyuy");
    cout << endl;
    cout << endl;
    DataList gh = tr.CreateList();
    Data* tra = gh.head;
    while (tra != nullptr)
    {
        cout << tra->key << endl;
        tra = tra->next;
    }

}