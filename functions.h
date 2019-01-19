void instructions(); // display instructions
void printBoard(int * board); // display board
int convert(char bucket); // convert user bucket of choice into integer
int * updateBoard(char bucket, int * board); // update board based on user input
int * flipBoard(int board[]); // flip the board

// might not be necessary unless we implement restart game
int * makeBoard(); // make new board