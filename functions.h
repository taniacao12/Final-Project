void instructions(); // display instructions
void print (int * board); // display board
void update (char bucket, int * board); // update board based on user input
void flip (int * board); // flip the board
void stringify (char * string, int * board); // convert int array into string
void listify (int * board); // convert string into int array

// helper function
int convert (char bucket); // convert user bucket of choice into integer

// might not be necessary unless we implement restart game
int * makeBoard(); // make new board
