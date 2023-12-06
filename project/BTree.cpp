#include "BTree.h"
#include<iostream>
using namespace std;
BTreeNode::BTreeNode(int T, bool isLeaf /*Data* d*/)
{
    this->T = T;
    this->isleaf = isLeaf;
    this->keys = new int[2 * T - 1];
    this->Childptr = new BTreeNode * [2 * T];
    this->numkeys = 0;
    //this->data = nullptr;
    //this->data = d;
}

BTreeNode* BTreeNode::search(int key)
{
    int index = 0;
    for (; index<numkeys && key>keys[index]; index++)
    {

    }

    if (this->isleaf && !(index < numkeys && key == keys[index]))
    {
        cout << "key not found" << endl;
        return NULL;
    }

    if (index < numkeys && key == keys[index])
    {
        cout << "Key " << key << " found in the B-tree." << std::endl;
        return this;
    }

    return Childptr[index]->search(key);
}

void BTreeNode::split(int index, BTreeNode* splitee)
{
    BTreeNode* New = new BTreeNode(splitee->T, splitee->isleaf);
    New->numkeys = T - 1;

    for (int i = 0; i < T - 1; i++)
    {
        int jmp = T + i;
        New->keys[i] = splitee->keys[jmp];
    }

    if (splitee->isleaf == false)
    {
        for (int i = 0; i < T; i++)
        {
            int jmp = T + i;
            New->Childptr[i] = splitee->Childptr[jmp];
        }
    }

    splitee->numkeys = T - 1;

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


    keys[index] = splitee->keys[T - 1];

    numkeys++;
}

void BTreeNode::insert2(int key)
{
    int index = numkeys - 1;

    if (isleaf == true)
    {
        while (index >= 0 && key < keys[index])
        {
            keys[index + 1] = keys[index];
            index--;
        }

        keys[index + 1] = key;
        numkeys++;
    }
    else
    {
        while (index >= 0 && key < keys[index])
        {
            index--;
        }


        if (Childptr[index + 1]->numkeys == 2 * T - 1)
        {

            split(index + 1, Childptr[index + 1]);


            if (key > keys[index + 1])
            {
                index++;
            }


        }
        Childptr[index + 1]->insert2(key);

    }
}

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < numkeys; i++) {
        if (isleaf == false)
            Childptr[i]->traverse();
        cout << " " << keys[i];
    }

    if (isleaf == false)
        Childptr[i]->traverse();
}














BTree::BTree(int m)
{
    root = nullptr;
    this->m = m;
    t = (m / 2) + ((m % 2) != 0);
}

BTreeNode* BTree::search(int key)
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

void BTree::insert(int key)
{
    if (root != nullptr)
    {
        if (root->numkeys == 2 * t - 1)
        {
            BTreeNode* tmp = new BTreeNode(t, 0);
            tmp->Childptr[0] = root;
            tmp->split(0, root);

            int index = 0;
            if (tmp->keys[0] < key)
            {
                index++;
            }
            tmp->Childptr[index]->insert2(key);

            root = tmp;
        }
        else
        {
            root->insert2(key);
        }
    }
    else if (root == nullptr)
    {
        root = new BTreeNode(t, 1);
        root->keys[0] = key;
        root->numkeys = 1;
    }
}
