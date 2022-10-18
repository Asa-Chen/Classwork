/*******************************************
 * @File: index-tree.h
 * @Assignment: Homework 3, CS3610 fa2022
 * @Author: Asa Chen
 * @Date: October 4, 2022
 * @Info: A full implimentation file of a bianry search tree containing word occurences in a text document.
 ******************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;
#ifndef INDEX_TREE
#define INDEX_TREE

struct BSTNode
{
    string keyWord;
    map<int, int> Occurence;

    /**
     * @brief Construct a new BSTNode object
     * 
     */
    BSTNode() { keyWord = "emptyNode"; }

    /**
     * @brief print the occurence list for each word stored as a BSTNode
     * 
     */
    void printOccurence()
    {
        cout << "[";
        for (map<int, int>::iterator it = Occurence.begin(); it != Occurence.end(); it++)
        {
            cout << "<" << it->first << "," << it->second << ">";
            if (it != --Occurence.end()) {cout << ", ";}
        }
        cout << "]";
    }

    /**
     * @brief Sums all of the times a word occurs
     * 
     * @return int - The total number of word occurences in a file
     */
    int sumOccurence()
    {
        int num = 0;
        for (map<int, int>::iterator it = Occurence.begin(); it != Occurence.end(); it++)
        {
            num += it->second;
        }
        return num;
    }
    BSTNode *left;
    BSTNode *right;
};

class BTree
{
public:
    // Data------
    BSTNode *root;
    //----------

    // Methods

    // Constructor
    /**
     * @brief Construct a new BTree object
     * 
     */
    BTree()
    {
        root = nullptr;
    }

    /**
     * @brief Inserts a word into the binary tree, if the word is already present, it adds the occurence or incriments an existing occurence 
     * 
     * @param key The word to be inserted
     * @param line The line the word occurs on
     * @param root - The starting pointer for the tree
     */
    void insert(const string &key, int line, BSTNode *&root)
    {
        if (root == nullptr)
        {
            root = new BSTNode;
            root->keyWord = key;
            root->left = nullptr;
            root->right = nullptr;
            root->Occurence.insert(make_pair(line, 1));
        }
        else if (key > root->keyWord)
        {
            // Insert right
            insert(key, line, root->right);
        }
        else if (key < root->keyWord)
        {
            // Insert left
            insert(key, line, root->left);
        }
        else
        { // key == keyWord
            if (root->Occurence.find(line) == root->Occurence.end())
            {
                root->Occurence.insert(make_pair(line, 1));
            }
            else
            {
                root->Occurence[line] += 1;
            }
        }
    }

    /**
     * @brief Prints the binary tree in order
     * 
     * @param root The beginning pointer for the tree
     */
    void print(BSTNode *&root)
    {
        if (root != nullptr)
        {
            print(root->left);
            cout << root->keyWord << "  ";
            root->printOccurence();
            cout << endl;
            print(root->right);
        }
    }

    /**
     * @brief Searches the tree for a given target, if not found, returns nullptr
     * 
     * @param root The starting pointer for the tree
     * @param target The word you are searching for
     * @return BSTNode* - A pointer to the word node, if found
     */
    BSTNode* search(BSTNode *root, string target)
    {
        if (root == nullptr)
        {
        }
        else
        {
            if (root->keyWord == target)
            {
                return root;
            }
            else if (target > root->keyWord)
            {
                return search(root->right, target);
            }
            else if (target < root->keyWord)
            {
                return search(root->left, target);
            }
        }
        return nullptr;
    }

    /**
     * @brief Searches the list for the most common word in the list, based off of total occurences
     * 
     * @param root The starting pointer for the list
     * @return BSTNode* - A pointer to the most common node 
     */
    BSTNode *mostCommon(BSTNode *root)
    {
        string common = "Empty";
        int largest = 0;
        findHighest(root, common, largest);
        return search(root, common);
    }

    void findHighest(BSTNode *root, string &largest, int &largestOcc)
    {
        if (root != nullptr)
        {
            if (largestOcc < root->sumOccurence())
            {
                largestOcc = root->sumOccurence();
                largest = root->keyWord;
            }
            //cout << largest << " " << largestOcc << endl;
            findHighest(root->left, largest, largestOcc);
            findHighest(root->right, largest, largestOcc);
        }
    }
};

#endif