/***********************************
 * @File: huffman.cc
 * @Assignment: Homework 4, CS3610 fa2022
 * @Author: Asa Chen
 * @Date: November 7, 2022
 * @Info: A main program meant to demonstrate encoding and decoding using a huffman code tree. 
 ***********************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "huffTree.h"
using namespace std;

/**
 * @brief loads the alphabet from a file, this set of code is used in so many switch cases that 
 *         it seemed better to write a function for loading.
 * 
 * @param alpha The name of the input file
 * @param values A vector of characters and frequencies as a pair
 */
void loadAlpha(string alpha, vector<pair<double, char>> &values);

/**
 * @brief Comparison override for vector sort function. Implements comparison of two pairs for higher frequency
 * 
 * @param one One of the compared pairs
 * @param two One of the compared pairs
 * @return true Yes one - frequency is higher than two
 * @return false No one - frequency is lower than two
 */
bool sortFreq(const pair<double, char> &one, const pair<double, char> &two);


int main(int argc, char *argv[])
{
    ifstream fins;
    ofstream fouts;
    string alphabet = "alpha.txt";
    string inFileName = "";
    string outFileName = "";
    string returnVal = "Empty";
    bool isFound = false;
    HTree tree;
    // HTNode *tmp;
    vector<HTNode *> tmp;
    string choice;
    int cCase;
    int zero = 0;
    int aveLength = 0;
    vector<pair<double, char>> values;

    if (argc == 1)
    {
        cCase = 3;
    }
    else if (argc == 2)
    {
        if (strcmp("-h", argv[1]) == 0)
        {
            cCase = 3;
        }
        else if (strcmp("-p", argv[1]) == 0)
        {
            cCase = 4;
        }
        else
        {
            cCase = 5;
        }
    }
    else if (argc == 3)
    {
        cCase = 5;
    }
    else if (argc == 4)
    {
        if (strcmp("-e", argv[1]) == 0)
        {
            cCase = 1;
            inFileName = argv[2];
            outFileName = argv[3];
        }
        else if (strcmp("-d", argv[1]) == 0)
        {
            cCase = 2;
            inFileName = argv[2];
            outFileName = argv[3];
        }
        else
        {
            cCase = 5;
        }
    }

    switch (cCase)
    {
        // case 1: -e (valid)
        // case 2: -d (valid)
        // case 3: -h or nothing
        // case 4: -p
        // case 5: invalid input
        //-------------
        //-e
    case 1:
        cout << "File '" << inFileName << "' encoded to '" << outFileName << "':" << endl;
        // Read alpha, load tree
        loadAlpha(alphabet, values);
        tmp = tree.convertVector(values);
        while (tmp.size() > 1)
        {
            tmp = tree.consolidateTwo(tmp);
        }
        // Encode
        tree.encode(inFileName, outFileName);

        break;

        //-------------
        //-d
    case 2:
        cout << "File '" << inFileName << "' decoded to '" << outFileName << "':" << endl;
        // Read in alpha, load tree
        loadAlpha(alphabet, values);
        tmp = tree.convertVector(values);
        while (tmp.size() > 1)
        {
            tmp = tree.consolidateTwo(tmp);
        }
        tree.decode(inFileName, outFileName);

        break;
        //-------------
        //-h
    case 3:
        cout << "help case:" << endl;
        cout << "To use this program, run the program with the options (-e,-d,-p,-h):" << endl;
        cout << "-e: Encode file, usage: ./<program> -e <infile> <outfile>" << endl;
        cout << "-d: Decode file, usage: ./<program> -d <infile> <outfile>" << endl;
        cout << "-p: Print file, usage: ./<program> -p" << endl;
        cout << "-h: Help case, uage: ./<program> -h" << endl;
        break;
        //-------------
        //-p
    case 4:
        cout << "print case:" << endl;
        // Read in alpha
        loadAlpha(alphabet, values);
        tmp = tree.convertVector(values);
        while (tmp.size() > 1)
        {
            tmp = tree.consolidateTwo(tmp);
        }
        tree.buildOrderedVec(tree.root, zero, "", tree.orderedVec);
        for (int i = 0; i < tree.orderedVec.size(); i++)
        {
            cout << endl
                 << "Character: " << tree.orderedVec[i]->letter << " Frequency: " << tree.orderedVec[i]->frequency << " Path: " << tree.computePath(tree.root, tree.orderedVec[i]->letter, isFound, returnVal, "");
            isFound = false;
            returnVal = "Empty";
            aveLength += tree.computePath(tree.root, tree.orderedVec[i]->letter, isFound, returnVal, "").length();
        }
        aveLength = aveLength / tree.orderedVec.size();
        cout << endl;
        cout << "Average code length: " << aveLength << endl;

        break;

        //-------------
        // Invalid
    case 5:
        cout << "Error in program, please retry with valid inputs" << endl;
        return 0;
        break;
    }

    return 0;
}

//Function info at prototype
void loadAlpha(string alpha, vector<pair<double, char>> &values)
{
    fstream fin;
    string line;
    string word;
    char character;
    double freq;
    stringstream ss;
    fin.open(alpha);
    if (fin.fail())
    {
        cout << "Load Failure!" << endl;
        return;
    }
    else
    {
        while (!fin.eof())
        {
            while (fin.peek() == '\n' || fin.peek() == ' ')
            {
                fin.ignore();
            }
            if (fin.eof())
            {
                break;
            }
            getline(fin, line);
            ss << line;
            while (ss.peek() != EOF)
            {
                while (ss.peek() == '\n' || ss.peek() == ' ')
                {
                    ss.ignore();
                }
                if (ss.peek() == EOF)
                {
                    break;
                }
                ss >> word;
                character = word[0];
                character = tolower(character);
                while (ss.peek() == '\n' || ss.peek() == ' ')
                {
                    ss.ignore();
                }
                if (ss.peek() == EOF)
                {
                    break;
                }
                ss >> word;
                freq = stod(word);
                values.push_back(make_pair(freq, character));
            }
            ss.clear();
        }

        sort(values.begin(), values.end(), sortFreq);
    }

    fin.close();
}

//Function info at prototype
bool sortFreq(const pair<double, char> &one, const pair<double, char> &two)
{
    return one.first > two.first;
}

// old encode marker
// old decode marker
