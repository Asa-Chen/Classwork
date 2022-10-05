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
using namespace std;
#ifndef INDEX_TREE.H
#define INDEX_TREE.H


struct BSTNode {
string key_word;
vector<int> occurence_list;
}; 

class Tree {

};


#endif