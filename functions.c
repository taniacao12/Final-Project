void instructions(); // display instructions
void printBoard(int board[]); // display board
int makeBoard(); // make new board
int updateBoard (int bucket); // update board based on user input

int updateBoard (int bucket) {
	return 0;
}

int makeboard() {
  int board[14]; //board is just for the server, we're manually printing the game board
  for (int i = 0; i < 14; i++){
    if (i == 6 || i == 13)
      board[i] = 0;
    else
      board[i] = 4;
  }
  return board;
}

void printboard (int board[]) {
  for (int i = 0; i < 14; i++)
		printf("{%d} ", board[i]);
	printf("\n");
}

void instructions() {
  char data[BUFFER_SIZE];
  printf("Do you want the game instructions? (y/n) ");
  fgets(data, BUFFER_SIZE, stdin);
  if (strcmp(data, "y\n") == 0) {
    printf("-----------------------------------------------------\n");
    printf("1.  Each player gets six buckets and one mancala(M).\n");
    printf("    The buckets and mandala will be formatted as shown below.\n");
    printf("           M{ } | { } { } { } { } { } { } |       <-- opponent side\n");
    printf("                | { } { } { } { } { } { } | M{ }  <-- your side\n");
    printf("2.  At the start of the game, each bucket has 4 marbles.\n");
    printf("           M{ } | {4} {4} {4} {4} {4} {4} |\n");
    printf("                | {4} {4} {4} {4} {4} {4} | M{ }\n");
    printf("3.  On your turn, each player you will be asked to input your bucket of choice.\n");
    printf("    All the marbles in that bucket will then be distributed counter-clockwise\n");
    printf("    into the other buckets and to your mancala (one per bucket).\n");
    printf("      a) If the last marble distributed lands in your mancala, you get an extra play.\n");
    printf("      b) If the last marble distributed lands in an empty bucket on your side of the\n");
    printf("         board, all marbles in the current bucket and the bucket directly above will be\n");
    printf("         placed in your mancala. Here's an example:\n");
    printf("           M{6} | {3} {5} {1} {3} {6} {2} |\n");
    printf("                | {0} {4} {2} {3} {1} {8} | M{4}\n");
    printf("                   A   B   C   D   E   F\n");
    printf("           [Player A] Bucket of Choice: F\n");
    printf("           ----------- Current Board -----------\n");
    printf("           M{6} | {0} {6} {2} {4} {7} {3} |\n");
    printf("                | {0} {4} {2} {3} {1} {0} | M{10}\n");
    printf("4.  The game ends when all six buckets on either side of the board are empty.\n");
    printf("    The player with remaining marbles in their buckets automatically places the\n");
    printf("    remaining marbles into their own mancala. The player with the most marbles\n");
    printf("    in their mancala is the winner of the game.\n");
  }
  else if (strcmp(data,"n\n") == 0)
    return;
  else instructions();
}
