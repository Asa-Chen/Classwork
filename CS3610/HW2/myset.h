/****************************************
 * #File: myset.h
 * #Assignment: Homework 2, CS3610 fa2022
 * #Author: Asa Chen
 * #Date: September 26, 2022
 * #Info: A full implimentation/header file for a STL set of integers. This file includes all the
 *       functionality and overrided operators required to manipulate the set, clear the set, and
 *       compare to other sets.
 ***************************************/
#include <cstdlib>
#include <string>
#include <set>
#ifndef MYSET_H
#define MYSET_H
using namespace std;

class MySet
{

public:
    // Default Constructor
    /**
     * Function: MySet
     * @brief Constructs a new My Set object.
     */
    MySet() { set<int> List; }

    // Operators
    /**
     * Operator: +
     * @brief Plus operator, addess the integer parameter to the list.
     * @param target - The int target you'd like to add.
     * @return MySet, the original object with the target parameter added.
     */
    MySet operator+(int target);
    /**
     * Operator: -
     * @brief Minus operator, removes the target parameter from the set.
     * @param target - The int target you'd like to remove.
     * @return MySet, returns the original object with the target parameter removed.
     */
    MySet operator-(int target);
    /**
     * Operator: +
     * @brief Set plus operator, combines the parameter obj2 set with this object's list.
     * @param obj2 - The set you'd like to combine with this object's list.
     * @return MySet - A new set object, with the parameter set combined with List.
     */
    MySet operator+(MySet obj2);
    /**
     * Operator: *
     * @brief Set intersection operator, combines the common elements in both sets into a new set.
     * @param obj2 - The set you'd like to combine with this object's list.
     * @return MySet - A new set containing the intersection of the parameter set and this object's set.
     */
    MySet operator*(MySet obj2);
    /**
     * Operator: -
     * @brief Set difference operator, returns a new set containing all of the elements in this object's list that are not in the parameter's list.
     * @param obj2 - The parameter object containing the set you'd like to subtract from this object's set.
     * @return MySet - A new set containing only the difference between the two sets.
     */
    MySet operator-(MySet obj2);
    /**
     * Operator: <=
     * @brief Subset operator, returns a boolean true or false. Checks if this object's set is a subset of the parameter's set.
     * @param obj2 - The set object you'd like to check.
     * @return true - Yes, this object's set is a subset of the parameter.
     * @return false - No, this object's set is not a subset of the parameter.
     */
    bool operator<=(MySet obj2);
    /**
     * Operator: >=
     * @brief Superset operator, checks if the parameter set is a subset of this object's set.
     * @param obj2 - The set object you'd like to check.
     * @return true - Yes, the parameter's set is a subset of this object's set.
     * @return false - No, the parameter's set is not a subset of this object.
     */
    bool operator>=(MySet obj2);
    /**
     * Operator: ==
     * @brief Equality operator, compares this object's set to the parameter set for the same elements.
     * @param obj2 - The set object you'd like to check for equality.
     * @return true - Yes, these two set have the same elements.
     * @return false - No, these two sets don't have the same elements.
     */
    bool operator==(MySet obj2);
    /**
     * Function: get_list
     * @brief Accesses the list object
     * @return set<int>& - The list contained in this object, by reference.
     */
    set<int> &get_list() { return List; }
    /**
     * Function: toString
     * @brief Returns the object set in string format, e.g. {1, 2, 3}
     * @return string - The string of all values stored in the set.
     */
    string toString();
    /**
     * Function: clear
     * @brief Wipes the list clean, leaving you with an empty list.
     */
    void clear();
    /**
     * Function: size
     * @brief Returns the current size of the list.
     * @return int - The size of the list in integer format.
     */
    int size();

private:
    set<int> List;
};

/**
 * Operator: ^
 * @brief Set search operator, searches the list for an inputed value. Returns true or false.
 * @param target - The integer value you'd like to search for.
 * @param obj - The set you want to search.
 * @return true - Yes, the value is stored in the list.
 * @return false - No, the value is not stored in the list.
 */
bool operator^(int target, MySet obj)
{
    int val = *obj.get_list().find(target);
    if (val != target)
    {
        return false;
    }
    return true;
}

int MySet::size()
{
    return List.size();
}

MySet MySet::operator+(int target)
{
    get_list().insert(target);
    return *this;
}

MySet MySet::operator-(int target)
{
    List.erase(target);
    return *this;
}

MySet MySet::operator+(MySet obj2)
{
    MySet tmp;
    set<int>::iterator ptr;
    for (ptr = List.begin(); ptr != List.end(); ptr++)
    {
        {
            tmp.get_list().insert(*ptr);
        }
    }
    for (ptr = obj2.get_list().begin(); ptr != obj2.get_list().end(); ptr++)
    {
        {
            tmp.get_list().insert(*ptr);
        }
    }
    return tmp;
}

MySet MySet::operator*(MySet obj2)
{
    MySet tmp;
    set<int>::iterator ptr;
    set<int>::iterator ptr2;
    if (List.size() >= obj2.get_list().size())
    {
        for (ptr = List.begin(); ptr != List.end(); ptr++)
        {
            for (ptr2 = obj2.get_list().begin(); ptr2 != obj2.get_list().end(); ptr2++)
            {
                if (*ptr == *ptr2)
                {
                    tmp.get_list().insert(*ptr);
                }
            }
        }
    }
    else
    {
        for (ptr2 = obj2.get_list().begin(); ptr2 != obj2.get_list().end(); ptr2++)
        {
            for (ptr = List.begin(); ptr != List.end(); ptr++)
            {
                if (*ptr2 == *ptr)
                {
                    tmp.get_list().insert(*ptr2);
                }
            }
        }
    }
    return tmp;
}

MySet MySet::operator-(MySet obj2)
{
    MySet tmp = *this;
    set<int>::iterator ptr;
    set<int>::iterator ptr2;
    for (ptr = List.begin(); ptr != List.end(); ptr++)
    {
        for (ptr2 = obj2.get_list().begin(); ptr2 != obj2.get_list().end(); ptr2++)
        {
            if (*ptr == *ptr2)
            {
                tmp.get_list().erase(*ptr);
            }
        }
    }
    return tmp;
}

bool MySet::operator<=(MySet obj2)
{
    set<int>::iterator ptr;
    set<int>::iterator ptr2;
    if (List.size() > obj2.get_list().size())
    {
        return false;
    }
    for (ptr = List.begin(); ptr != List.end(); ptr++)
    {
        for (ptr2 = obj2.get_list().begin(); ptr2 != obj2.get_list().end(); ptr2++)
        {
            if (ptr2 == obj2.get_list().end() && *ptr2 != *obj2.get_list().end())
            {
                return false;
            }
        }
    }
    return true;
}

bool MySet::operator>=(MySet obj2)
{
    set<int>::iterator ptr;
    set<int>::iterator ptr2;
    if (List.size() < obj2.get_list().size())
    {
        return false;
    }
    for (ptr = obj2.get_list().begin(); ptr != obj2.get_list().end(); ptr++)
    {
        for (ptr2 = List.begin(); ptr2 != List.end(); ptr2++)
        {
            if (ptr2 == List.end() && *ptr2 != *List.end())
            {
                return false;
            }
        }
    }
    return true;
}

bool MySet::operator==(MySet obj2)
{
    set<int>::iterator ptr;
    set<int>::iterator ptr2;
    if (List.size() != obj2.get_list().size())
    {
        return false;
    }
    for (ptr = obj2.get_list().begin(); ptr != obj2.get_list().end(); ptr++)
    {
        for (ptr2 = List.begin(); ptr2 != List.end(); ptr2++)
        {
            if (ptr2 == List.end() && *ptr2 != *List.end())
            {
                return false;
            }
        }
    }
    for (ptr = List.begin(); ptr != List.end(); ptr++)
    {
        for (ptr2 = obj2.get_list().begin(); ptr2 != obj2.get_list().end(); ptr2++)
        {
            if (ptr2 == obj2.get_list().end() && *ptr2 != *obj2.get_list().end())
            {
                return false;
            }
        }
    }
    return true;
}

string MySet::toString()
{
    string setlist = "{";
    if (get_list().empty() == true)
    {
        return "{}";
    }
    if (get_list().size() == 1)
    {
        setlist += to_string(*get_list().begin());
        setlist += "}";
        return setlist;
    }
    int size = get_list().size();
    int counter = 1;
    set<int>::iterator ptr;
    for (ptr = get_list().begin(); ptr != get_list().end(); ptr++)
    {
        setlist += to_string(*ptr);
        if (counter != size)
        {
            setlist += ", ";
        }
        counter++;
    }
    setlist += "}";
    return setlist;
}

void MySet::clear()
{
    if (!List.empty())
    {
        List.clear();
    }
}

#endif