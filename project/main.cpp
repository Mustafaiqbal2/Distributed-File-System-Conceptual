// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "taskManagementSystem.h"

using namespace std;

int main(void)
{
    //taskManagementSystem tm;
    //tm.menu();
    BTree tr;
    tr.insert("abc", "1", "uyuy");
    tr.insert("def", "2", "uyuy");
    tr.insert("ghi", "3", "uyuy");
    tr.insert("jkl", "4", "uyuy");
    tr.insert("mno", "5", "uyuy");
    tr.insert("pqr", "6", "uyuy");
    tr.insert("stu", "7", "uyuy");
    tr.insert("vwx", "8", "uyuy");
    tr.insert("xyz", "9", "uyuy");

    
    tr.insert("qwe", "10", "uyuy");
    tr.insert("rty", "11", "uyuy");
    tr.insert("uio", "12", "uyuy");
    tr.insert("asd", "13", "uyuy");
    tr.insert("fgh", "14", "uyuy");
    tr.insert("lkj", "15", "uyuy");
    tr.insert("zxc", "16", "uyuy");
    tr.insert("vbn", "17", "uyuy");
    

    tr.traverse();
    cout << endl;
    
    // testing search //
    cout<<tr.search("abc")<<endl;
    cout<<tr.search("def")<< endl;
    cout<<tr.search("ghi")<< endl;
    cout<<tr.search("jkl")<< endl;
    cout<<tr.search("mno")<< endl;
    cout<<tr.search("pqr")<< endl;
    cout<<tr.search("stu")<< endl;
    cout<<tr.search("vwx")<< endl;
    cout<<tr.search("xyz")<< endl;
    cout<<tr.search("jnm")<< endl;
    cout<<tr.search("asd")<< endl;
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

    /*
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
    */

    tr.DeleteNode("abc");
    tr.DeleteNode("def");
    tr.DeleteNode("ghi");
    tr.DeleteNode("jkl");
    tr.DeleteNode("mno");
    tr.DeleteNode("pqr");
    tr.DeleteNode("stu");
    tr.DeleteNode("vwx");
    tr.DeleteNode("xyz");
    tr.DeleteNode("qwe");
    tr.DeleteNode("rty");
    cout<<tr.search("def")<<endl;
    tr.insert("145","18","kjk");
    tr.traverse();
    cout << endl;


    tr.search("asd");
    tr.search("fgh");
    tr.search("lkj");
    tr.search("zxc");
    tr.search("vbn");
    tr.search("145");

}