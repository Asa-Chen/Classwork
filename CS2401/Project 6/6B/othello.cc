/*********************
 * Asa Chen - CS2401 - Fall 2021-2022
 * Project 6A - First stage of Othello Game
 * othello.cc - Implimentation file for Othello game
*********************/
#include "othello.h"
#include "game.h"
using namespace std;


namespace main_savitch_14 {


void Othello::make_move(const string& move) {
//Convert string to coordinates
int col = (toupper(move[0]) - 'A');
int row = (move[1] - '0');
int diag_c;
int diag_r;
int diag_counter = 0;
int diag_stop = 0;
int stop = 0; //Used for flip check
if (moves_completed() == 0 || moves_completed() % 2 == 0) { //-----------------------------------------O
board[col][row].set_status('O');
//X-Axis flip check. Checks left and right of move coordinates for another friendly piece. If found, flips any opposing pieces between them.
for (int i = col - 1; i > 0; i--) {if (board[i][row].get_status() == 'O') {stop = i; break;}}
if (stop > 0) for (int i = col - 1; i > stop; i--) {board[i][row].flip();} stop = 0;
for (int i = col + 1; i < 8; i++) {if (board[i][row].get_status() == 'O') {stop = i; break;}}
if (stop > 0) for (int i = col + 1; i < stop; i++) {board[i][row].flip();} stop = 0;
//Y-Axis flip check. Checks above and below move coordinates for another friendly piece. If found, flips any opposing pieces between them.
for (int i = row - 1; i > 0; i--) {if (board[col][i].get_status() == 'O') {stop = i; break;}}
if (stop > 0) for (int i = row - 1; i > stop; i--) {board[col][i].flip();} stop = 0;
for (int i = row + 1; i < 8; i++) {if (board[col][i].get_status() == 'O') {stop = i; break;}}
if (stop > 0) for (int i = row + 1; i < stop; i++) {board[col][i].flip();} stop = 0;
//Diagonal flip check -------------------O
        //Upper left ------------------O
        if (col - 1 == 0 || row - 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row - 1;
            if (board[col-1][row-1].get_status() == 'X') {
                while (diag_c != 0 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c--; diag_r--;
                }
                if (diag_stop != 0) {
                    diag_c = col - 1; diag_r = row - 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c--; diag_r--; diag_stop--;
                    }
                }
            }
        }
        //Upper right ------------------O
        if (col + 1 == 0 || row - 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row - 1;
            if (board[col+1][row-1].get_status() == 'X') {
                while (diag_c != 8 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c++; diag_r--;
                }
                if (diag_stop != 0) {
                    diag_c = col + 1; diag_r = row - 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c++; diag_r--; diag_stop--;
                    }
                }
            }
        }
        //Lower left ------------------O
        if (col - 1 == 0 || row + 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row + 1;
            if (board[col-1][row+1].get_status() == 'X') {
                while (diag_c != 0 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c--; diag_r++;
                }
                if (diag_stop != 0) {
                    diag_c = col - 1; diag_r = row + 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c--; diag_r++; diag_stop--;
                    }
                }
            }
        }
        //Lower right ------------------O
        if (col + 1 == 0 || row + 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row + 1;
            if (board[col+1][row+1].get_status() == 'X') {
                while (diag_c != 8 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c++; diag_r++;
                }
                if (diag_stop != 0) {
                    diag_c = col + 1; diag_r = row + 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c++; diag_r++; diag_stop--;
                    }
                }
            }
        }
} else { //----------------------------------------------------------------------------------------------X
board[col][row].set_status('X');
//X-Axis flip check. Checks left and right of move coordinates for another friendly piece. If found, flips any opposing pieces between them.
for (int i = col - 1; i > 0; i--) {if (board[i][row].get_status() == 'X') {stop = i; break;}}
if (stop > 0) for (int i = col - 1; i > stop; i--) {board[i][row].flip();} stop = 0;
for (int i = col + 1; i < 8; i++) {if (board[i][row].get_status() == 'X') {stop = i; break;}}
if (stop > 0) for (int i = col + 1; i < stop; i++) {board[i][row].flip();} stop = 0;
//Y-Axis flip check. Checks above and below move coordinates for another friendly piece. If found, flips any opposing pieces between them.
for (int i = row - 1; i > 0; i--) {if (board[col][i].get_status() == 'X') {stop = i; break;}}
if (stop > 0) for (int i = row - 1; i > stop; i--) {board[col][i].flip();} stop = 0;
for (int i = row + 1; i < 8; i++) {if (board[col][i].get_status() == 'X') {stop = i; break;}}
if (stop > 0) for (int i = row + 1; i < stop; i++) {board[col][i].flip();} stop = 0;
//Diagonal flip check -------------------X
        //Upper left ------------------X
        if (col - 1 == 0 || row - 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row - 1;
            if (board[col-1][row-1].get_status() == 'O') {
                while (diag_c != 0 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c--; diag_r--;
                }
                if (diag_stop != 0) {
                    diag_c = col - 1; diag_r = row - 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c--; diag_r--; diag_stop--;
                    }
                }
            }
        }
        //Upper right ------------------X
        if (col + 1 == 0 || row - 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row - 1;
            if (board[col+1][row-1].get_status() == 'O') {
                while (diag_c != 8 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c++; diag_r--;
                }
                if (diag_stop != 0) {
                    diag_c = col + 1; diag_r = row - 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c++; diag_r--; diag_stop--;
                    }
                }
            }
        }
        //Lower left ------------------X
        if (col - 1 == 0 || row + 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row + 1;
            if (board[col-1][row+1].get_status() == 'O') {
                while (diag_c != 0 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c--; diag_r++;
                }
                if (diag_stop != 0) {
                    diag_c = col - 1; diag_r = row + 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c--; diag_r++; diag_stop--;
                    }
                }
            }
        }
        //Lower right ------------------X
        if (col + 1 == 0 || row + 1 == 0) { 
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row + 1;
            if (board[col+1][row+1].get_status() == 'O') {
                while (diag_c != 8 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c++; diag_r++;
                }
                if (diag_stop != 0) {
                    diag_c = col + 1; diag_r = row + 1;
                    while (diag_stop > 1) {
                        board[diag_c][diag_r].flip();
                        diag_c++; diag_r++; diag_stop--;
                    }
                }
            }
        }
}
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

void Othello::compute_moves(queue<string>& moves) const {
string tmp = "  ";
for (int i = 65; i < 73; i++) {
    tmp[0] = i;
    for (int i = 48; i < 56; i++) {
        tmp[1] = i;
        //cout << tmp;
        if (is_legal(tmp) == true) {moves.push(tmp);}
    }
}
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
    //Used only for part 2
    if (moves_completed() == 0 || moves_completed() % 2 == 0) { cout << "Player 1," << endl;}
    else {cout << "Player 2," << endl;}
}

bool Othello::is_game_over() const {
    bool game_end = true;
    queue<string> moves_1;
    compute_moves(moves_1);
    if (!moves_1.empty()) {game_end = false;}


    return game_end;
}

bool Othello::is_legal(const string& move) const {
    //convert string to coordinates
    int col = (toupper(move[0]) - 'A');
    int row = (move[1] - '0');
    bool is_legal = false;
    int diag_c;
    int diag_r;
    int diag_counter = 0;
    int diag_stop;
    int stop = 9; //used for axis scanning purposes
    //Check if the spot is already used.
    if (board[col][row].get_status() == 'O' || board[col][row].get_status() == 'X') {return false;}
    if (moves_completed() == 0 || moves_completed() % 2 == 0) { //------------------------------------O
        //Check if the pieces to the left or right are an 'X'. Legal case
        if (board[col - 1][row].get_status() == 'X' || board[col + 1][row].get_status() == 'X') {
            stop = 9;
            if (col - 2 > 0) {
            for (int i = col - 2; i > 0; i--) {if (board[i][row].get_status() == 'O') stop = i;}
            }
            if (col + 2 < 8) {
            for (int i = col + 2; i < 8; i++) {if (board[i][row].get_status() == 'O') stop = i;}
            }
            if (stop != 9) {is_legal = true;}
        }
        //Check if the pieces above or below are an 'X'. Legal case
        if (board[col][row - 1].get_status() == 'X' || board[col][row + 1].get_status() == 'X') {
            stop = 9;
            if (row - 2 > 0) {
            for (int i = row - 2; i > 0; i--) {if (board[col][i].get_status() == 'O') stop = i;}
            }
            if (row + 2 < 8) {
            for (int i = row + 2; i < 8; i++) {if (board[col][i].get_status() == 'O') stop = i;}
            }
            if (stop != 9) {is_legal = true;}
        }
        //Check upper left -----------------------O
        if (col - 1 == 0 || row - 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row - 1;
            if (board[col-1][row-1].get_status() == 'X') {
                while (diag_c != 0 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c--; diag_r--;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        }
        //Check upper right -----------------------O
        if (col + 1 == 0 || row - 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row - 1;
            if (board[col+1][row-1].get_status() == 'X') {
                while (diag_c != 8 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c++; diag_r--;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        }
        //Check lower left -----------------------O
        if (col - 1 == 0 || row + 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row + 1;
            if (board[col-1][row+1].get_status() == 'X') {
                while (diag_c != 0 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c--; diag_r++;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        }
        //Check lower right -----------------------O
        if (col + 1 == 0 || row + 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row + 1;
            if (board[col+1][row+1].get_status() == 'X') {
                while (diag_c != 8 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'O') {diag_stop = diag_counter; break;}
                diag_c++; diag_r++;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        }
    } else { //-------------------------------------------------------------------------------------X
        //Check if the pieces to the left or right are an 'O'. Legal case
        if (board[col - 1][row].get_status() == 'O' || board[col + 1][row].get_status() == 'O') {
            stop = 9;
            if (col - 2 > 0){
            for (int i = col - 2; i > 0; i--) {if (board[i][row].get_status() == 'X') stop = i;}
            }
            if (col + 2 < 8) {
            for (int i = col + 2; i < 8; i++) {if (board[i][row].get_status() == 'X') stop = i;}
            }
            if (stop != 9) {is_legal = true;}
        }
        //Check if the pieces above or below are an 'O'. Legal case
        if (board[col][row - 1].get_status() == 'O' || board[col][row + 1].get_status() == 'O') {
            stop = 9;
            if (row - 2 > 0) {
            for (int i = row - 2; i > 0; i--) {if (board[col][i].get_status() == 'X') stop = i;}
            }
            if (row + 2 < 8) {
            for (int i = row + 2; i < 8; i++) {if (board[col][i].get_status() == 'X') stop = i;}
            }
            if (stop != 9) {is_legal = true;}
        }
        //Check upper left -----------------------X
        if (col - 1 == 0 || row - 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row - 1;
            if (board[col-1][row-1].get_status() == 'O') {
                while (diag_c != 0 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c--; diag_r--;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        }
        //Check upper right -----------------------X
        if (col + 1 == 0 || row - 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row - 1;
            if (board[col+1][row-1].get_status() == 'O') {
                while (diag_c != 8 && diag_r != 0) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c++; diag_r--;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        }
        //Check lower left -----------------------X
        if (col - 1 == 0 || row + 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col - 1; diag_r = row + 1;
            if (board[col-1][row+1].get_status() == 'O') {
                while (diag_c != 0 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c--; diag_r++;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        }
        //Check lower right -----------------------X
        if (col + 1 == 0 || row + 1 == 0) {
            //do nothing
        } else {
            diag_stop = 0; diag_counter = 0; diag_c = col + 1; diag_r = row + 1;
            if (board[col+1][row+1].get_status() == 'O') {
                while (diag_c != 8 && diag_r != 8) {
                diag_counter++;
                if (board[diag_c][diag_r].get_status() == 'X') {diag_stop = diag_counter; break;}
                diag_c++; diag_r++;
                }
                if (diag_stop != 0) {is_legal = true;}
            }
        } 
    }

    return is_legal; //If none of the above cases are returned, return false.
    }

game::who Othello::winning() const {
int Player1 = 0;
int Player2 = 0;
for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        if (board[i][j].get_status() == 'O') {Player1++;}
        else if (board[i][j].get_status() == 'X') {Player2++;}
    }
}
if (Player1 > Player2) {return HUMAN;}
else if (Player2 > Player1) {return COMPUTER;}
else {return NEUTRAL;}
}

}//Namespace ending