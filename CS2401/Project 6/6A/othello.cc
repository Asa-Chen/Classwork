/*********************
 * Asa Chen - CS2401 - Fall 2021-2022
 * Project 6A - First stage of Othello Game
 * othello.cc - Implimentation file for Othello game
*********************/
#include "othello.h"
using namespace std;


namespace main_savitch_14 {


void Othello::make_move(const string& move) {
//Convert string to coordinates
int col = (toupper(move[0]) - 'A');
int row = (move[1] - '0');
int stop; //Used for flip check
board[col][row].set_status('O'); //This does not feel correct, because the function needs to acccept moves from both sides
//X-Axis flip check. Checks left and right of move coordinates for another friendly piece. If found, flips any opposing pieces between them.
for (int i = col; i > 0; i--) {if (board[i][row].get_status() == 'O') stop = i;}
for (int i = col - 1; i > stop; i--) {board[i][row].flip();}
for (int i = col; i < 8; i++) {if (board[i][row].get_status() == 'O') stop = i;}
for (int i = col + 1; i < stop; i++) {board[i][row].flip();}
//Y-Axis flip check. Checks above and below move coordinates for another friendly piece. If found, flips any opposing pieces between them.
for (int i = row; i > 0; i--) {if (board[col][i].get_status() == 'O') stop = i;}
for (int i = row - 1; i > stop; i--) {board[col][i].flip();}
for (int i = row; i < 8; i++) {if (board[col][i].get_status() == 'O') stop = i;}
for (int i = row + 1; i < stop; i++) {board[col][i].flip();}
//Diagonal flip check.
//To be implimented
game::make_move(move);
}

void Othello::restart() {
    for (int i = 0; i < 8; i++) { //Resets all the pieces to '-'
        for (int j = 0; j < 8; j++) {
            board[i][j].set_status('-');
        }
    }
    board[3][3].set_status('O'); //Resets the middle of the board
    board[4][4].set_status('O');
    board[3][4].set_status('X');
    board[4][3].set_status('X');
    game::restart();
}

void Othello::display_status() const {
    cout << B_RED << "\nGame In Session: Player1 is O, Player2 is X" << B_BLACK << endl; //Top line in Red
    cout << B_WHITE << BLACK << "!INPUT YOUR MOVE LETTER FIRST! I.E. -> A0" << B_BLACK << WHITE; //Next line in White
    cout << endl << ' ';
    for (int i = 65; i < 73; i++) {char c = i; cout << setw(3) << setfill(' ') << c << "  ";} //Letter coordinates, deduced from ASCII values
    cout << endl << ' ';
    for (int i = 0; i < 8; i++) {cout << '|' << setw(4) << setfill('#') << '|';} //Box top row
    cout << endl;
    for (int j = 0; j < 8; j++) { //Loop displays the pieces and dividing lines for the entire board
        cout << j;
        for (int i = 0; i < 8; i++) {cout << "| " << board[i][j].get_color() << board[i][j].get_status() << WHITE << " |";}
        cout << endl << ' ';
        for (int i = 0; i < 8; i++) {cout << '|' << setw(4) << setfill('-') << '|';}
        cout << endl;
    }
}

bool Othello::is_legal(const string& move) const {
    //convert string to coordinates
    int col = (toupper(move[0]) - 'A');
    int row = (move[1] - '0');
    //Check if the spot is already used.
    if (board[col][row].get_status() == 'O' || board[col][row].get_status() == 'X') {return false;}
    //Check if the pieces to the left or right are an 'X'. Legal case
    if (board[col - 1][row].get_status() == 'X' || board[col + 1][row].get_status() == 'X') {return true;}
    //Check if the pieces above or below are an 'X'. Legal case
    else if (board[col][row - 1].get_status() == 'X' || board[col][row + 1].get_status() == 'X') {return true;} 
    else {return false;} //Illegal case, everything that does not qualify for cases above.
    }


}//Namespace ending