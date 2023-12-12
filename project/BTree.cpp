#include "BTree.h"
#include<iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//          below function comapers two strings         //

bool strcmpp(string& s1, string& s2)
{
	int size = s1.size();
	for (int i = 0; i < size; i++)
	{
		if (s1[i] < s2[i])
			return 0;
		if (s1[i] > s2[i])
			return 1;
	}
    return 0;
}

//          node implementation             //

BTreeNode::BTreeNode(bool isLeaf /*Data* d*/)
{
    this->isleaf = isLeaf;
    this->keys = new Data[3];                       // max keys: 3
    this->Childptr = new BTreeNode * [4];           // max child: 4
    this->numkeys = 0;
    
}
/*
BTreeNode* BTreeNode::search(string key)
{
    int index = 0;
    for (; index<numkeys && strcmpp(key, keys[index]); index++)
    {

    }

    

    if (index < numkeys && key == keys[index])
    {
        cout << "Key " << key << " found in the B-tree." << std::endl;
        return this;
    }
    if (this->isleaf)
    {
        cout << "key not found" << endl;
        return NULL;
    }

    return Childptr[index]->search(key);
}
*/
string BTreeNode::search(string key)
{
    int index = 0;
    while (index < numkeys && strcmpp(key, keys[index].key) > 0)
    {
        index++;
    }

    if (index < numkeys && key==keys[index].key)
    {
        cout << "Key " << key << " found in the B-tree."<< keys[index].filepath << std::endl;
        return keys[index].key;//filepath;
    }

    if (isleaf)
    {
        cout << "Key " << key << " not found in the B-tree." << std::endl;
        return "";
    }

    return Childptr[index]->search(key);
}
/*
void BTreeNode::search2(string key, string& ans)
{
    int i;
    for (i = 0; i < numkeys; i++)
    {
        if (isleaf == false)
        {
            Childptr[i]->search2(key, ans);
        }
        if (keys[i].key == key)
        {
            cout << "\n found node " << endl;
            ans = keys[i].key;
            return;
        }
    }

    if (isleaf == false)
        Childptr[i]->search2(key, ans);
}
*/
void BTreeNode::findsamekey(string key, Data*& dat)
{
    int i;
    for (i = 0; i < numkeys; i++)
    {
        if (isleaf == false)
        {
            Childptr[i]->findsamekey(key, dat);
        }
        if (keys[i].key == key)
        {
            cout << "keys match" << endl;
            dat = &keys[i];
            return;
        }
    }

    if (isleaf == false)
        Childptr[i]->findsamekey(key, dat);
}


void BTreeNode::split(int index, BTreeNode* splitee)
{
    BTreeNode* New = new BTreeNode(splitee->isleaf);
    New->numkeys = 1;                                   // min keys of a non root 

    //for (int i = 0; i < 1; i++)
    //{
        int jmp = 2 + 0;
        New->keys[0] = splitee->keys[jmp];
    //}

    if (splitee->isleaf == false)
    {
        //for (int i = 0; i < 2; i++)
        //{
            jmp = 2 + 0;
            New->Childptr[0] = splitee->Childptr[jmp];
            jmp = 2 + 1;
            New->Childptr[1] = splitee->Childptr[jmp];
        //}
    }

    splitee->numkeys = 1;

    int last = numkeys;
    while (last > index)
    {
        Childptr[last + 1] = Childptr[last];
        last--;
    }
    Childptr[index + 1] = New;

    for (int j = numkeys - 1; j >= index; j--)
    {
        keys[j + 1] = keys[j];
    }


    keys[index] = splitee->keys[1];

    numkeys++;
}

void BTreeNode::insert2(string key,string filepath)
{
    int index = numkeys - 1;

    if (isleaf == true)
    {
        while (index >= 0 && strcmpp(keys[index].key,key))
        {
            keys[index + 1] = keys[index];
            index--;
        }

        keys[index + 1].key = key;
        keys[index + 1].filepath = filepath;
        numkeys++;
    }
    else
    {
        while (index >= 0 && strcmpp(keys[index].key, key))
        {
            index--;
        }


        if (Childptr[index + 1]->numkeys == 3)//2 * 2 - 1)
        {

            split(index + 1, Childptr[index + 1]);


            if (strcmpp(key, keys[index + 1].key))
            {
                index++;
            }


        }
        Childptr[index + 1]->insert2(key,filepath);

    }
}

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < numkeys; i++) 
    {
        if (isleaf == false)
            Childptr[i]->traverse();
        cout << " " << keys[i].key;
    }

    if (isleaf == false)
        Childptr[i]->traverse();
}












//                  B tree class implementation      //

BTree::BTree()
{
    root = nullptr;
    //this->m = m;
    //t = (m / 2) + ((m % 2) != 0);
}

// calls seaching from root node  //

string BTree::search(string key)
{
    if (root != nullptr)
    {
        return root->search(key);
    }
    else
    {
        cout << "B-tree is empty." << std::endl;
        return "";
    }
}
/*
string BTree::search2(string key)
{
    if (root != NULL)
    {
        string ans = "not found"; // if no node is found this will not change
        root->search2(key,ans);
        return ans;
    }
}
*/
Data* BTree::findsamekey(string key)
{
    if (root != NULL)
    {
        Data* dat = nullptr;
        root->findsamekey(key, dat);
        return dat;
    }
    return nullptr;
}

//   addition of node takes place in node class in case of non root nodes  //
void BTree::insert(string key, string filepath, string content)
{
    /*
    ofstream outFile(filepath);
    // Check if the file is opened successfully
    if (outFile.is_open()) {

        outFile << content;

        // Close the file
        outFile.close();

        std::cout << "File created successfully.\n";
    }
    else {
        std::cerr << "Error opening the file.\n";
    }
    */

    Data* dup = findsamekey(key);
    if (dup != nullptr && dup->key == key) // found a duplicate key time for chaining
    {
        
        Data* tmp = dup->chain;
        if (tmp == nullptr)
        {
            Data* newnode = new Data(key, filepath);
            dup->chain = newnode;//new Data(key, filepath);//////////////////////////////////// why is change not reflecting ? if i use tmp
            //tmp->chain = tmp;
        }
        else
        {
            while (tmp->chain != nullptr)
            {
                tmp = tmp->chain;
            }
            tmp->chain = new Data(key, filepath);
            tmp->chain = tmp->chain;
        }
        
        return;
    }


    if (root != nullptr)
    {
        if (root->numkeys == 3)//2 * 2 - 1)
        {
            BTreeNode* tmp = new BTreeNode(0);
            tmp->Childptr[0] = root;
            tmp->split(0, root);

            int index = 0;
            if (strcmpp(key,tmp->keys[0].key))
            {
                index++;
            }
            tmp->Childptr[index]->insert2(key, filepath);

            root = tmp;
        }
        else
        {
            root->insert2(key , filepath);
        }
    }
    else if (root == nullptr)
    {
        root = new BTreeNode(1);
        root->keys[0].key = key;
        root->keys[0].filepath = filepath;
        root->numkeys = 1;
    }
}









void BTree::DeleteNode(string key) 
{
    if (root==nullptr) 
    {
        cout << "tree is empty." << endl;
        return;
    }
    //cout << "ROOT: " << root->keys << endl;
    root->Delete(key);

    // adjust root after deletion //
    BTreeNode* oldroot = root;
    if (root->numkeys == 0) 
    {
        if (root->isleaf) 
        {
            root = nullptr;
        }
        else 
        {
            root = root->Childptr[0];
        }
        delete oldroot;
    }
}



void BTreeNode::Delete(string key) 
{
    
    int index = 0;

    for (int i = 0; index < numkeys && strcmpp(key, keys[index].key); i++)
    {
        index = index + 1;
    }

   //BTreeNode* todel = search(key);

    if (index < numkeys && keys[index].key == key) 
    {

        /*
        if (std::remove(keys[index].filepath.c_str()) == 0) {
            std::cout << "File deleted successfully.\n";
        } else {
            std::cerr << "Error deleting the file.\n";
        }
        */
        // if removal from leaf, simply remove
        if (isleaf==true)
        {
            int i = index + 1;
            while (i < numkeys)
            {
                keys[i - 1] = keys[i];
                i++;
            }
            numkeys = numkeys - 1;

            //if (todel != nullptr)
            //{
              //  delete todel;
            //}
            
        }

        else
        {
            string tmpkey = "";
            tmpkey = keys[index].key;

            // first check left childern (if it has greater than min keys) to replace with inorder predecessor //
            if (Childptr[index]->numkeys > 1) 
            {
                string predecessorkey = "";
                string predecessorfilepath = "";
                BTreeNode* cur = Childptr[index];
                while (cur->isleaf==false)
                {
                    cur = cur->Childptr[cur->numkeys];
                }
                // the last key of the leaf is our inorder predecessor
                predecessorkey = cur->keys[cur->numkeys - 1].key;
                predecessorfilepath = cur->keys[cur->numkeys - 1].filepath;
                // replace
                keys[index].key = predecessorkey;
                keys[index].filepath = predecessorfilepath;
                // delete predecessor
                Childptr[index]->Delete(predecessorkey);
            }

            // otherwise check right childern to replace with inorder successor //
            else if (Childptr[index + 1]->numkeys > 1) 
            {
                string successorkey = "";
                string successorfilepath = "";
                BTreeNode* cur = Childptr[index + 1];
                while (cur->isleaf==false)
                {
                    cur = cur->Childptr[0];
                }
                // the first key of the leaf is our inorder seccessor
                successorkey =  cur->keys[0].key;
                successorfilepath =  cur->keys[0].filepath;
                // replace
                keys[index].key = successorkey;
                keys[index].filepath = successorfilepath;
                // delete successor
                Childptr[index + 1]->Delete(successorkey);
            }

            // otherwise merge left and right childern and recall delete
            else 
            {
                BTreeNode* firstchild = Childptr[index];
                BTreeNode* rightchild = Childptr[index + 1];

                firstchild->keys[1] = keys[index];

                int i = 0;
                while (i < rightchild->numkeys)
                {
                    int jmp = i + 2;
                    firstchild->keys[jmp] = rightchild->keys[i + 1 - 1];
                    i++;
                }

                if (firstchild->isleaf == false)
                {
                    int i = 0;
                    while (i <= rightchild->numkeys)
                    {
                        int jmp = i + 2;
                        firstchild->Childptr[jmp] = rightchild->Childptr[i];
                        i++;
                    }
                }

                i = index + 1;
                while (i < numkeys)
                {
                    keys[i - 1] = keys[i];
                    i++;
                }

                i = index + 2;
                while (i <= numkeys)
                {
                    Childptr[i - 1] = Childptr[i];
                    i++;
                }

                firstchild->numkeys = firstchild->numkeys + rightchild->numkeys + 1;

                numkeys = numkeys - 1;

                delete (rightchild);


               // merge(index);
                Childptr[index]->Delete(tmpkey);
            }
        }
            
    }
    else 
    {
        if (isleaf==true) 
        {
            cout <<"key does not exist\n";
            return;
        }
        /*
        bool flag = false;
        if (index == numkeys)
        {
            flag = true;
        }
        */
        int subtr = 0;
        if (index == numkeys)
        {
            subtr = 1;
        }

        //bool flag = ((index == numkeys) ? true : false);

        if (Childptr[index]->numkeys < 2)
        {
            
            if (index != 0 && Childptr[index - 1]->numkeys >= 2)
            {
                FindReplacementFromBack(index);
            }

            else if (index != numkeys && Childptr[index + 1]->numkeys >= 2)
            {
                FindReplacementFromNext(index);
            }
                
            else
            {
                if (index == numkeys)
                {
                    //merge(index-1);
                    BTreeNode* firstchild = Childptr[index - 1];
                    BTreeNode* rightchild = Childptr[index - 1 + 1];

                    firstchild->keys[2 - 1] = keys[index - 1];

                    int i = 0;
                    while (i < rightchild->numkeys)
                    {
                        int jmp = i + 2;
                        firstchild->keys[jmp] = rightchild->keys[i + 1 - 1];
                        i++;
                    }

                    if (firstchild->isleaf == false)
                    {
                        int i = 0;
                        while (i <= rightchild->numkeys)
                        {
                            int jmp = i + 2;
                            firstchild->Childptr[jmp] = rightchild->Childptr[i];
                            i++;
                        }
                    }

                    i = index - 1 + 1;
                    while (i < numkeys)
                    {
                        keys[i - 1] = keys[i];
                        i++;
                    }

                    i = index - 1 + 2;
                    while (i <= numkeys)
                    {
                        Childptr[i - 1] = Childptr[i];
                        i++;
                    }

                    firstchild->numkeys = firstchild->numkeys + rightchild->numkeys + 1;

                    numkeys = numkeys - 1;

                    delete (rightchild);
                }
                else
                {
                    //merge(index);
                    BTreeNode* firstchild = Childptr[index];
                    BTreeNode* rightchild = Childptr[index + 1];

                    firstchild->keys[2 - 1] = keys[index];

                    int i = 0;
                    while (i < rightchild->numkeys)
                    {
                        int jmp = i + 2;
                        firstchild->keys[jmp] = rightchild->keys[i + 1 - 1];
                        i++;
                    }

                    if (firstchild->isleaf == false)
                    {
                        int i = 0;
                        while (i <= rightchild->numkeys)
                        {
                            int jmp = i + 2;
                            firstchild->Childptr[jmp] = rightchild->Childptr[i];
                            i++;
                        }
                    }

                    i = index + 1;
                    while (i < numkeys)
                    {
                        keys[i - 1] = keys[i];
                        i++;
                    }

                    i = index + 2;
                    while (i <= numkeys)
                    {
                        Childptr[i - 1] = Childptr[i];
                        i++;
                    }

                    firstchild->numkeys = firstchild->numkeys + rightchild->numkeys + 1;

                    numkeys = numkeys - 1;

                    delete (rightchild);
                }
            }

            
        }


        if (subtr && index > numkeys)
        {
            Childptr[index - 1+1-1]->Delete(key);
        }
        else
        {
            Childptr[index]->Delete(key);
        }
    }
    return;
}

int BTreeNode::FindReplacementFromBack(int idx)
{

    BTreeNode* firstchild;
    firstchild=Childptr[idx];
    BTreeNode* secondchild;
    secondchild=Childptr[idx - 1];

    int i = firstchild->numkeys - 1;
    while (i >= 0)
    {
        firstchild->keys[i + 1] = firstchild->keys[i];
        i--;
    }

    if (firstchild->isleaf == false)
    {
        int i = firstchild->numkeys;
        while (i >= 0)
        {
            firstchild->Childptr[i + 1] = firstchild->Childptr[i];
            i--;
        }

    }
    firstchild->keys[0] = keys[idx - 1];
    if (firstchild->isleaf == false)
    {
        firstchild->Childptr[0] = secondchild->Childptr[secondchild->numkeys];
    }

    keys[idx - 1] = secondchild->keys[secondchild->numkeys - 1];

    secondchild->numkeys = secondchild->numkeys - 1;
    firstchild->numkeys = firstchild->numkeys + 1;

    return 1;
}

int BTreeNode::FindReplacementFromNext(int idx)
{

    BTreeNode* Firstchild;
    Firstchild = Childptr[idx];
    BTreeNode* secondchild;
    secondchild = Childptr[idx + 1];
    Firstchild->keys[(Firstchild->numkeys)] = keys[idx];
    if (Firstchild->isleaf == false)
    {
        Firstchild->Childptr[(Firstchild->numkeys) + 1] = secondchild->Childptr[0];
    }
    keys[idx] = secondchild->keys[0];
    int i = 1;
    while (i < secondchild->numkeys)
    {
        secondchild->keys[i - 1] = secondchild->keys[i];
        i++;
    }
    if (secondchild->isleaf == false)
    {
        int i = 1;
        while (i <= secondchild->numkeys)
        {
            secondchild->Childptr[i - 1] = secondchild->Childptr[i];
            i++;
        }
    }
    Firstchild->numkeys = Firstchild->numkeys + 1;
    secondchild->numkeys = secondchild->numkeys - 1;

    return 1;
}
/*
void BTreeNode::merge(int index)
{
    BTreeNode* child = Childptr[index];
    BTreeNode* rightchild = Childptr[index + 1];

    child->keys[3 - 1] = keys[index];

    for (int i = 0; i < rightchild->numkeys; ++i)
    {
        int jmp = i + 3;
        child->keys[jmp] = rightchild->keys[i];
    }

    if (child->isleaf == false)
    {
        for (int i = 0; i <= rightchild->numkeys; ++i)
        {
            int jmp = i + 3;
            child->Childptr[jmp] = rightchild->Childptr[i];
        }
    }

    for (int i = index + 1; i < numkeys; ++i)
    {
        keys[i - 1] = keys[i];
    }

    for (int i = index + 2; i <= numkeys; ++i)
    {
        Childptr[i - 1] = Childptr[i];
    }

    child->numkeys += rightchild->numkeys + 1;

    numkeys--;

    delete (rightchild);

    return;
}
*/
// linked list creation inorder  //
void  BTreeNode::rectrav(DataList& head)
{
    int i;
    for (i = 0; i < numkeys; i++) 
    {
        if (isleaf == false)
        {
            Childptr[i]->rectrav(head);
        }
        head.add(keys[i]);
        // if nodes are chained add them to ll //
        if (keys[i].chain != nullptr)
        {
            Data* c = keys[i].chain;
            while (c != nullptr)
            {
               
                head.add(*c);
                c = c->chain;
            }
        }

    }

    if (isleaf == false)
        Childptr[i]->rectrav(head);
}

DataList BTreeNode::CreateList()
{
    DataList head;
    rectrav(head);
    return head;
}

// basically creates a linked list od all the data nodes(in ascending order)
DataList BTree::CreateList()
{
   
    if (root != NULL)
    {
        return root->CreateList();
    }
    
}