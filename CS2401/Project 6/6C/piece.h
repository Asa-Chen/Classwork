/*********************
 * Asa Chen - CS2401 - Fall 2021-2022
 * Project 6A - First stage of Othello Game
 * piece.h - Header file for Othello game piece class
*********************/
#include <string>
#include "colors.h"
#ifndef PIECE_H
#define PIECE_H
using namespace std;


class piece {
    public:
    piece() {background = BLACK; color = WHITE; status = '-';}
    char get_status() const {return status;}
    string get_color() const {return color;} //Don't know if needed
    void set_status(char t);
    void flip();
    private:
    string background;
    string color;
    char status;

};



#endif