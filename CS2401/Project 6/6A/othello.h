/*********************
 * Asa Chen - CS2401 - Fall 2021-2022
 * Project 6A - First stage of Othello Game
 * othello.h - Header file for Othello game
*********************/
#include <iostream>
#include <iomanip>
#include "game.h"
#include "colors.h"
#include "piece.h"

#ifndef OTHELLO_H
#define OTHELLO_H
using namespace std;
namespace main_savitch_14 {
    class Othello:public game {
        public:
        Othello() {} //Default Constructor, not sure its needed...
        void make_move(const string& move); //Overridden in .cc file
        void restart(); //Overridden in .cc file
        game* clone() const {return NULL;} //Stub
        void compute_moves(queue<string>& moves) const {}; //Stub
        void display_status() const; //Overridden in .cc file
        int evaluate() const {return 0;}; //Stub
        bool is_game_over() const {return NULL;}; //Stub
        bool is_legal(const string& move) const; //Overridden in .cc file

        private:
        piece board[8][8];

    };

}

#endif



