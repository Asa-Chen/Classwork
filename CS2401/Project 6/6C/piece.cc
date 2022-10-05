/*********************
 * Asa Chen - CS2401 - Fall 2021-2022
 * Project 6A - First stage of Othello Game
 * piece.cc - Implimentation file for Othello game piece class
*********************/
#include "piece.h"
using namespace std;

void piece::set_status(char t) {
        status = t;
        if (t == 'X') {
            color = RED;
        } else if (t == 'O') {
            color = BLUE;
        }
}


void piece::flip() {
    if (status == 'O') {
        status = 'X';
        color = RED;
    } else if (status == 'X') {
        status = 'O';
        color = BLUE;
    } else {
        //do nothing
    }
}