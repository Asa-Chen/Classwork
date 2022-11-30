/***********************************
 * @File: huffTree.h
 * @Assignment: Homework 4, CS3610 fa2022
 * @Author: Asa Chen
 * @Date: November 7, 2022
 * @Info: A header file for a huffman code tree. This tree also includes some helper functions and necessary comparison overrides.
 ***********************************/
#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief A node struct for the huffman tree
 * 
 */
struct HTNode
{
    double frequency;
    char letter;
    HTNode *left;
    HTNode *right;
    HTNode()
    {
        frequency = 0;
        letter = ' ';
        left = right = nullptr;
    }
};

/**
 * @brief An overload for the vector sort function. Compares two HTNodes for higher frequency.
 * 
 * @param one Node one
 * @param two Node two
 * @return true One is higher in frequency than node two
 * @return false One is lower in frequency than node two
 */
bool sortPointVec(HTNode *one, HTNode *two);


/**
 * @brief The class for the Huffman Code tree, contains most of the functions needed for usage
 * 
 */
class HTree
{

public:
    HTNode *root;
    vector<HTNode *> orderedVec;

    /**
     * @brief Construct a new HTree object
     * 
     */
    HTree() { root = nullptr; }

    /**
     * @brief Converts a vector of pairs(double, char) to a vector of pointers to HTNodes with corresponding values
     * 
     * @param values The vector of pairs to be parsed
     * @return vector<HTNode *> - The vector of nodes
     */
    vector<HTNode *> convertVector(vector<pair<double, char>> &values)
    {
        vector<HTNode *> pointerVec;
        HTNode *tmp;
        for (int i = 0; i < values.size(); i++)
        {
            tmp = new HTNode;
            tmp->frequency = values[i].first;
            tmp->letter = values[i].second;
            pointerVec.push_back(tmp);
        }
        sort(pointerVec.begin(), pointerVec.end(), sortPointVec);
        return pointerVec;
    }

    /**
     * @brief Consolidates the last two elements of a vector of HTNodes until there is only one left, which is set as the root
     * 
     * @param values The vector to be parsed
     * @return vector<HTNode *> - A vector containing one node, the root of the tree.
     */
    vector<HTNode *> consolidateTwo(vector<HTNode *> &values)
    {
        root = new HTNode;
        HTNode *last = values[values.size() - 1];
        values.pop_back();
        root->left = last;
        HTNode *nLast = values[values.size() - 1];
        values.pop_back();
        root->right = nLast;
        root->frequency = root->left->frequency + root->right->frequency;
        values.push_back(root);
        sort(values.begin(), values.end(), sortPointVec);
        // cout << endl << last -> letter << ":" << nLast -> letter << endl;
        root = values[values.size() - 1];
        return values;
    }

    /**
     * @brief Prints the node values of the huffman tree out of order
     * 
     * @param root The start of the tree
     * @param leafCount The number of leaves, which should correspond to the number of characters
     * @param path The path to the leaf node, consisting of ones and zeroes
     */
    void printTree(HTNode *root, int &leafCount, string path)
    {
        if (root != nullptr)
        {
            printTree(root->left, leafCount, path + "0");
            if (root->left == nullptr && root->right == nullptr)
            {
                leafCount++;
                cout << endl
                     << "Character: " << root->letter << " Frequency: " << root->frequency << " LeafNumber: " << leafCount << " Path: " << path;
            }
            printTree(root->right, leafCount, path + "1");
        }
    }

    /**
     * @brief Builds an ordered vector of HTNodes for ordered printing. Vector sorted largest to smallest frequency.
     * 
     * @param root The root of the huffman tree
     * @param leafCount The number of leaf nodes, which should correspond to the number of characters
     * @param path The path to the leaf consisting of ones and zeroes
     * @param order The vector that is to be populated
     */
    void buildOrderedVec(HTNode *root, int &leafCount, string path, vector<HTNode *> &order)
    {
        if (root != nullptr)
        {
            buildOrderedVec(root->left, leafCount, path + "0", order);
            if (root->left == nullptr && root->right == nullptr)
            {
                leafCount++;
                order.push_back(root);
                sort(order.begin(), order.end(), sortPointVec);
            }
            buildOrderedVec(root->right, leafCount, path + "1", order);
        }
    }

    /**
     * @brief Computes the path to a node in ones (right traverses) and zeroes (left traverses)
     * 
     * @param root The root of the huffman tree
     * @param target The character value to be found
     * @param found Boolean to stop recursion
     * @param returnVal The string returned indicating the path to the node
     * @param path The non-reference path value used to store the path to each node
     * @return string The path to a particular node, returns "Empty" if not found
     */
    string computePath(HTNode *root, char target, bool &found, string &returnVal, string path)
    {
        if (root != nullptr)
        {
            if (root->letter == target)
            {
                returnVal = path;
                found = true;
                return returnVal;
            }
            else
            {
                computePath(root->left, target, found, returnVal, path + "0");
                if (found)
                {
                    return returnVal;
                }
                computePath(root->right, target, found, returnVal, path + "1");
                return returnVal;
            }
        }
        else
        {
            return "Empty";
        }
    }

    /**
     * @brief Takes a string stream and uses it to find a character value.
     * 
     * @param root The root of the huffman tree
     * @param code The stringstream used to find the char
     * @return char The char if found, returns empty char if not found
     */
    char computeCode(HTNode *root, stringstream &code)
    {
        if (root == nullptr)
        {
            return ' ';
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return root->letter;
        }
        char tmp;
        code.get(tmp);
        if (tmp == '0')
        {
            return computeCode(root->left, code);
        }
        else
        {
            return computeCode(root->right, code);
        }
    }

    /**
     * @brief Encodes a file from text to Huffman code
     * 
     * @param inputFile The name of the file to be encoded
     * @param outputFile The name of the desired output file
     */
    void encode(string inputFile, string outputFile)
    {
        fstream in_f;
        ofstream out_f;
        string line;
        char tmp;
        bool isFound = false;
        string returnVal = "Empty";
        stringstream ss;

        in_f.open(inputFile);
        if (in_f.fail())
        {
            cout << "Load Failure!" << endl;
            return;
        }
        else
        {
            out_f.open(outputFile);
            if (out_f.fail())
            {
                cout << "Storage Failure!" << endl;
                return;
            }
            while (!in_f.eof())
            {
                while (in_f.peek() == '\n' || in_f.peek() == ' ')
                {
                    in_f.get(tmp);
                    out_f << tmp;
                }
                if (in_f.eof())
                {
                    break;
                }
                getline(in_f, line);
                ss << line;
                while (ss.peek() != EOF)
                {
                    while (ss.peek() == ' ' || ss.peek() == '.' || ss.peek() == ',' || ss.peek() == ';' 
                            || ss.peek() == ':' || ss.peek() == '\'' || ss.peek() == '\"')
                    {
                        ss.get(tmp);
                        out_f << tmp;
                    }
                    if (ss.peek() == EOF)
                    {
                        out_f << '\n';
                        break;
                    }
                    ss.get(tmp);
                    out_f << computePath(root, tmp, isFound, returnVal, "");
                    isFound = false;
                    returnVal = "Empty";
                    if (ss.peek() == EOF)
                    {
                        out_f << '\n';
                        break;
                    }
                }
                ss.clear();
            }
            out_f.close();
        }
        in_f.close();
    }
    
    /**
     * @brief Decodes a file from huffman code to regular text
     * 
     * @param inputFile The input code file to be decoded
     * @param outputFile The desired output file
     */
    void decode(string inputFile, string outputFile)
    {
        fstream in_f;
        ofstream out_f;
        string line;
        char tmp;
        bool isFound = false;
        string returnVal = "Empty";
        stringstream ss;

        in_f.open(inputFile);
        if (in_f.fail())
        {
            cout << "Load Failure!" << endl;
            return;
        }
        else
        {
            out_f.open(outputFile);
            if (out_f.fail())
            {
                cout << "Storage Failure!" << endl;
                return;
            }
            while (!in_f.eof())
            {
                while (in_f.peek() == '\n' || in_f.peek() == ' ')
                {
                    in_f.get(tmp);
                    out_f << tmp;
                }
                if (in_f.eof())
                {
                    break;
                }
                getline(in_f, line);
                ss << line;
                while (ss.peek() != EOF)
                {
                    while (ss.peek() == ' ' || ss.peek() == '.' || ss.peek() == ',' || ss.peek() == ';' 
                            || ss.peek() == ':' || ss.peek() == '\'' || ss.peek() == '\"')
                    {
                        ss.get(tmp);
                        out_f << tmp;
                    }
                    if (ss.peek() == EOF)
                    {
                        out_f << '\n';
                        break;
                    }
                    out_f << computeCode(root, ss);
                    if (ss.peek() == EOF)
                    {
                        out_f << '\n';
                        break;
                    }
                }
                ss.clear();
            }
            out_f.close();
        }
        in_f.close();
    }
};

//Function info at prototype
bool sortPointVec(HTNode *one, HTNode *two)
{
    return one->frequency > two->frequency;
}

#endif