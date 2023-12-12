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
    //tr.insert("uio", "uyuyu", "uyuy");
    //tr.insert("asd", "uyuyu", "uyuy");
    //tr.insert("fgh", "uyuyu", "uyuy");
    //tr.insert("lkj", "uyuyu", "uyuy");
    //tr.insert("zxc", "uyuyu", "uyuy");
    //tr.insert("vbn", "uyuyu", "uyuy");
    

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
    tr.insert("145","yfj","kjk");
    tr.traverse();

}