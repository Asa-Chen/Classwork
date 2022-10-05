//Final project talk, Project 6
//Hopefully everything needed for first part of project



//Talk some about the code you'll have to write first
//game class you're gonna wright
//othello
class othello:public game { //derrived from author's game class
    public:



    private:
        piece board[8][8]; //create a piece or space class, then use a 2d array to create a board. [row][colum]
                            //piece class can have alot of variaton, the piece class does need to be able to switch between player colors
                            //tri state, empty, and other colors
                            //function called 'flip', changes color from one person's to another
}




//used to flip all the pieces on the board, not very necessary 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].flip();//can use i and j interchangeably
        }
    }

//change boxes 2-5 on the first row
int row = 0;
for (int i = 1; i < 5; i++) {
    board[row][i].flip();
}

//Now you gotta do the diagonals
//personal idea
//next row, n+-1, and previous row, n+-1




*anything purely virtual in game must be overridden!
//program won't compile otherwise
game* clone() { return NULL:} //called a 'stub'

display_status
//Demonstrated for loop is useful for displaying
//Bulk of first part is defining the piece and displaying the board

//In order to make a move, 
is_legal(string move) //will eventually need to reflect all the rules of the game
//For part one, needs to know what the four legal moves are. For the first part, you can make it only recognize those moves


make_move //Later on, you'll have to be more generic
//but for now, it can be constrained to the four legal moves, and can flip those four pieces
//There is a parent make move meaning that this function is not completly virtual, so, after flipping the correct piece, call the 'game make_move' function


restart //resets the board with the four pieces in the middle. Also needs to call the 'games restart'

//main will look something like this
int main() {
    Othello my_game;
    my_game.play(); //Full of a bunch of functions not needed for part one
} // edited main for part one has those removed so the program will actually compile



//Code to pull correct index numbers out of string
move = "A3"
move = "a3" 

//Even though a string is more than an array of characters, I can treat it like an array of characters

col = int(toupper(move[0]) - 'A'); //takes first character in the move string, and subtracts capital A. Uses the ASCII table to subtract the A value
                            //col = 0
move = "B3"
move = "b3"
col = int(toupper(move[0]) - 'A');// col = 1 //subtracts A from B value, which is one higher than A, so the value is 1
row = int(move[0] - '1'); // row = 2 //same thing for numbers
//the 0 or 1 in [] depends on how you setup your table, i.e. [1][1] or [0][0] as the beginning value