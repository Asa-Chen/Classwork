/***********************************
 * @File: indexing.cc
 * @Assignment: Homework 3, CS3610 fa2022
 * @Author: Asa Chen
 * @Date: October 4, 2022
 * @Info: A main program meant to demonstrate the functionality of a binary search tree, index-tree.h.
 ***********************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "index-tree.h"
using namespace std;

/**
 * @brief Displays a terminal menu used by the user to manipulate the tree
 * 
 * @return char - the choice made by the user, between 1 and 4 inclusive
 */
char menu();

/**
 * @brief The main program used by the application to load the ignore file, text file, and menu options
 * 
 * @param argc Command line arguments
 * @param argv Command line arguments
 * @return int - stops the program
 */
int main(int argc, char *argv[])
{
    ifstream fins;
    ofstream fouts;
    stringstream ss;
    set<string> ignoreList;
    string ignoreFileName = "ignore.txt";
    string filename = "Alan-Turing.txt";
    string line;
    string word;
    string target;
    BTree index;
    BSTNode *tmp;
    char choice = ' ';
    int lineNum = 1;

    fins.open(ignoreFileName);
    if (!fins.fail())
    {
        // do something
        cout << "Ignore File Load Successful\n";
        while (!fins.eof())
        {
            while (fins.peek() == '\n' || fins.peek() == ' ')
            {
                fins.ignore();
            }
            if (fins.eof())
            {
                break;
            }
            getline(fins, line);
            ss << line;
            while (ss.peek() != EOF)
            {
                ss >> word;
                for (int i = 0; i < word.size(); i++)
                {
                    word[i] = tolower(word[i]);
                }
                ignoreList.insert(word);
            }
            ss.clear();
        }
        fins.close();
    }

    fins.open(filename);
    if (!fins.fail())
    {
        // do something
        cout << "File Load Successful\n";
    }
    while (!fins.eof())
    {
        while (fins.peek() == '\n' || fins.peek() == ' ')
        {
            fins.ignore();
            lineNum++;
        }
        if (fins.eof())
        {
            break;
        }
        getline(fins, line);
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
            for (int i = 0; i < word.size(); i++)
            {
                word[i] = tolower(word[i]);
            }
            word.erase(remove(word.begin(), word.end(), '('), word.end());
            word.erase(remove(word.begin(), word.end(), ')'), word.end());
            word.erase(remove(word.begin(), word.end(), ','), word.end());
            word.erase(remove(word.begin(), word.end(), '.'), word.end());
            word.erase(remove(word.begin(), word.end(), ':'), word.end());
            word.erase(remove(word.begin(), word.end(), ';'), word.end());
            word.erase(remove(word.begin(), word.end(), '['), word.end());
            word.erase(remove(word.begin(), word.end(), ']'), word.end());
            word.erase(remove(word.begin(), word.end(), '{'), word.end());
            word.erase(remove(word.begin(), word.end(), '}'), word.end());
            word.erase(remove(word.begin(), word.end(), '"'), word.end());
            word.erase(remove(word.begin(), word.end(), '!'), word.end());
            word.erase(remove(word.begin(), word.end(), '?'), word.end());
            // word.erase(remove(word.begin(),word.end(),'£'),word.end());
            if (ignoreList.find(word) == ignoreList.end())
            {
                size_t pos = word.find("'s");
                if (pos != word.npos)
                {
                    word.erase(pos, 2);
                }
                pos = word.find("'");
                if (pos != word.npos)
                {
                    word.erase(pos, 1);
                }
                index.insert(word, lineNum, index.root);
                // word = *ignoreList.begin();
            }
        }
        lineNum++;
        ss.clear();
    }

    while (choice != '4')
    {
        choice = menu();
        switch (choice)
        {
        case '1':
            // do something
            index.print(index.root);
            break;
        case '2':
            // do something
            cout << "Please input a search target: ";
            cin >> target;
            for (int i = 0; i < target.length(); i++)
            {
                target[i] = tolower(target[i]);
            }
            tmp = index.search(index.root, target);
            if (tmp != nullptr)
            {
                cout << "Word Found: " << tmp->keyWord;
                tmp->printOccurence();
                cout << endl
                     << "Occured: " << tmp->sumOccurence() << " Times" << endl;
            }
            else
            {
                cout << endl << "WORD NOT FOUND!" << endl;
            }

            break;
        case '3':
            tmp = index.mostCommon(index.root);
            cout << endl << "Most common word: " << tmp->keyWord;
            tmp->printOccurence();
            cout << endl
                 << "Occured: " << tmp->sumOccurence() << " Times" << endl;
            // do something
            break;
        case '4':
            cout << "ending the program\n";
            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
    }

    fins.close();

    return 0;
}

char menu()
{
    char choice;

    cout << "Pick from the following: \n";
    cout << "Option 1: Display Index(s) in order\n";
    cout << "Option 2: Search for a word\n";
    cout << "Option 3: Find the most common word\n";
    cout << "Option 4: Quit\n";
    cin >> choice;

    return choice;
}