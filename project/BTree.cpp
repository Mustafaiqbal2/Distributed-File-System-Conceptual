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

bool strcmppp(string& s1, string& s2)
{
    int size = s1.size();
    for (int i = 0; i < size; i++)
    {
        if (s1[i] < s2[i])
            return -1;
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

    if (index < numkeys && strcmppp(key, keys[index].key) == 0)
    {
        cout << "Key " << keys[index].key << " found in the B-tree." << std::endl;
        return keys->key;//filepath;
    }

    if (isleaf)
    {
        cout << "Key " << keys[index].key << " not found in the B-tree." << std::endl;
        return "";
    }

    return Childptr[index]->search(key);
}

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
    New->numkeys = 1; // min keys of a non root 

    for (int i = 0; i < 1; i++)
    {
        int jmp = 2 + i;
        New->keys[i] = splitee->keys[jmp];
    }

    if (splitee->isleaf == false)
    {
        for (int i = 0; i < 2; i++)
        {
            int jmp = 2 + i;
            New->Childptr[i] = splitee->Childptr[jmp];
        }
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

BTree::BTree(int m)
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
    }
}

string BTree::search2(string key)
{
    if (root != NULL)
    {
        string ans = "not found"; // if no node is found this will not change
        root->search2(key,ans);
        return ans;
    }
}

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
    if (!root) 
    {
        cout << "B-tree is empty." << endl;
        return;
    }
    cout << "ROOT: " << root->keys << endl;
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
    while (index < numkeys && strcmpp(key, keys[index].key) > 0)
    {
        index++;
    }

    int idx = 0;
    while (idx < numkeys && strcmpp(key, keys[idx].key))
        ++idx;

    index = idx;
    cout << index << endl;

   //BTreeNode* todel = search(key);

    if (index < numkeys && keys[index].key == key) 
    {

        if (std::remove(keys[index].filepath.c_str()) == 0) {
            std::cout << "File deleted successfully.\n";
        } else {
            std::cerr << "Error deleting the file.\n";
        }
        // if removal from leaf, simply remove
        if (isleaf)
        {
            for (int i = index + 1; i < numkeys; ++i)
            {
                keys[i - 1] = keys[i];
            }
            numkeys--;

            //if (todel != nullptr)
            //{
              //  delete todel;
            //}
            
        }

        else
        {
            string k = keys[index].key;

            // first check left childern to replace with inorder predecessor //
            if (Childptr[index]->numkeys >= 3) 
            {
                string predecessor = "";
                BTreeNode* cur = Childptr[index];
                while (!cur->isleaf)
                {
                    cur = cur->Childptr[cur->numkeys];
                }
                // the last key of the leaf is our inorder predecessor
                predecessor = cur->keys[cur->numkeys - 1].key;
                // replace
                keys[index].key = predecessor;
                // delete predecessor
                Childptr[index]->Delete(predecessor);
            }

            // otherwise check right childern to replace with inorder successor //
            else if (Childptr[index + 1]->numkeys >= 3) 
            {
                string successor = "";
                BTreeNode* cur = Childptr[index + 1];
                while (!cur->isleaf)
                {
                    cur = cur->Childptr[0];
                }
                // the first key of the leaf is our inorder seccessor
                successor =  cur->keys[0].key;
                // replace
                keys[index].key = successor;
                // delete successor
                Childptr[index + 1]->Delete(successor);
            }

            // otherwise merge left and right childern and recall delete
            else 
            {
                /*
                BTreeNode* child = Childptr[index];
                BTreeNode* rightchild = Childptr[index + 1];

                child->keys[T - 1] = keys[index];

                for (int i = 0; i < rightchild->numkeys; ++i)
                {
                    int jmp = i + T;
                    child->keys[jmp] = rightchild->keys[i];
                }

                if (child->isleaf==false) 
                {
                    for (int i = 0; i <= rightchild->numkeys; ++i)
                    {
                        int jmp = i + T;
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

                child->numkeys = child->numkeys + rightchild->numkeys + 1;

                numkeys=numkeys-1;

                delete (rightchild);
                */


                merge(index);
                Childptr[index]->Delete(k);
            }
        }
            
    }
    else 
    {
        if (isleaf) 
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


        bool flag = ((index == numkeys) ? true : false);

        if (Childptr[index]->numkeys < 3)
        {
            // If the previous child(C[idx-1]) has more than t-1 keys, borrow a key
            // from that child
            if (index != 0 && Childptr[index - 1]->numkeys >= 3)
                borrowFromPrev(index);

            // If the next child(C[idx+1]) has more than t-1 keys, borrow a key
            // from that child
            else if (index != numkeys && Childptr[index + 1]->numkeys >= 3)
                borrowFromNext(index);

            // Merge C[idx] with its sibling
            // If C[idx] is the last child, merge it with its previous sibling
            // Otherwise merge it with its next sibling
            else
            {
                if (index != numkeys)
                {
                    merge(index);
                }
                else
                {
                    merge(index - 1);
                }
            }
        }


        if (flag && index > numkeys)
        {
            Childptr[index - 1]->Delete(key);
        }

        else
        {
            Childptr[index]->Delete(key);
        }
    }
    return;
}

void BTreeNode::borrowFromPrev(int idx)
{

    BTreeNode* child = Childptr[idx];
    BTreeNode* sibling = Childptr[idx - 1];

    // The last key from C[idx-1] goes up to the parent and key[idx-1]
    // from parent is inserted as the first key in C[idx]. Thus, the  loses
    // sibling one key and child gains one key

    // Moving all key in C[idx] one step ahead
    for (int i = child->numkeys - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    // If C[idx] is not a leaf, move all its child pointers one step ahead
    if (!child->isleaf)
    {
        for (int i = child->numkeys; i >= 0; --i)
            child->Childptr[i + 1] = child->Childptr[i];
    }

    // Setting child's first key equal to keys[idx-1] from the current node
    child->keys[0] = keys[idx - 1];

    // Moving sibling's last child as C[idx]'s first child
    if (!child->isleaf)
        child->Childptr[0] = sibling->Childptr[sibling->numkeys];

    // Moving the key from the sibling to the parent
    // This reduces the number of keys in the sibling
    keys[idx - 1] = sibling->keys[sibling->numkeys - 1];

    child->numkeys += 1;
    sibling->numkeys -= 1;

    return;
}

// A function to borrow a key from the C[idx+1] and place
// it in C[idx]
void BTreeNode::borrowFromNext(int idx)
{

    BTreeNode* child = Childptr[idx];
    BTreeNode* sibling = Childptr[idx + 1];

    // keys[idx] is inserted as the last key in C[idx]
    child->keys[(child->numkeys)] = keys[idx];

    // Sibling's first child is inserted as the last child
    // into C[idx]
    if (!(child->isleaf))
        child->Childptr[(child->numkeys) + 1] = sibling->Childptr[0];

    //The first key from sibling is inserted into keys[idx]
    keys[idx] = sibling->keys[0];

    // Moving all keys in sibling one step behind
    for (int i = 1; i < sibling->numkeys; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    // Moving the child pointers one step behind
    if (!sibling->isleaf)
    {
        for (int i = 1; i <= sibling->numkeys; ++i)
            sibling->Childptr[i - 1] = sibling->Childptr[i];
    }

    // Increasing and decreasing the key count of C[idx] and C[idx+1]
    // respectively
    child->numkeys += 1;
    sibling->numkeys -= 1;

    return;
}

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