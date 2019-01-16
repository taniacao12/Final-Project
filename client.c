//#include "pipe_networking.h"
#include "networking.h"

void instructions();

/*
int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  char data[BUFFER_SIZE];
  char user[BUFFER_SIZE];
  char start[BUFFER_SIZE];
*/

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];
  char data[BUFFER_SIZE];
  char user[BUFFER_SIZE];
  char start[BUFFER_SIZE];

  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  // welcome user and get their username
  printf("WELCOME TO TEAMANCALA!\n");
  // get user name
  printf("What is your name? ");
  fgets(user, BUFFER_SIZE, stdin);
  user[strlen(user) - 1] = 0;
  printf("Welcome %s\n", user);
  // give or skip game instructions
  instructions();

  printf("If you are ready, press ENTER to start the game.");
  fgets(start, BUFFER_SIZE, stdin);
  printf("-----------------------------------------------------\n");

  int board[2][7]; //board is just for the server, we're manually printing the game board
  for (int i = 0; i<2; i++){
    for (int j = 0; j<7; j++){
      board[i][j] = 4;
    }
  }

  //it works just testing it
  /*
  for(int i=0; i<2; i++) {
      for(int j=0;j<7;j++) {
         printf("%d ", board[i][j]);
         if(j==6){
            printf("\n");
         }
      }
   } */

  printf("           M{ } | {4} {4} {4} {4} {4} {4} |      \n");
  printf("                | {4} {4} {4} {4} {4} {4} | M{ } \n");
  printf("                   A   B   C   D   E   F   \n");

  while (1) {
    // get user input
    printf("Which cup would you like to choose? ");
    fgets(data, BUFFER_SIZE, stdin);
    //WE NEED TO SEND BOTH THE BOARD AND THE ANSWER THAT THE PERSON CHOOSES TO THE SERVER
    // send data to server
    int w = write(server_socket, data, BUFFER_SIZE);
    // get reponse from server
    int r = read(server_socket, data, BUFFER_SIZE);
    // display response
    printf("%s", data);
  }
}

void instructions() {
  char data[BUFFER_SIZE];
  printf("Do you want the game instructions? (y/n) ");
  fgets(data, BUFFER_SIZE, stdin);
  if (strcmp(data, "y\n") == 0) {
    printf("-----------------------------------------------------\n");
    printf("1.  Each player gets six cups and one mancala(M).\n");
    printf("    The cups and mandala will be formatted as shown below.\n");
    printf("           M{ } | { } { } { } { } { } { } |       <-- opponent side\n");
    printf("                | { } { } { } { } { } { } | M{ }  <-- your side\n");
    printf("2.  At the start of the game, each cup has 4 marbles.\n");
    printf("           M{ } | {4} {4} {4} {4} {4} {4} |\n");
    printf("                | {4} {4} {4} {4} {4} {4} | M{ }\n");
    printf("3.  On your turn, each player you will be asked to input your cup of choice.\n");
    printf("    All the marbles in that cup will then be distributed counter-clockwise\n");
    printf("    into the other cups and to your mancala (one per cup).\n");
    printf("      a) If the last marble distributed lands in your mancala, you get an extra play.\n");
    printf("      b) If the last marble distributed lands in an empty cup on your side of the\n");
    printf("         board, all marbles in the current cup and the cup directly above will be\n");
    printf("         placed in your mancala. Here's an example:\n");
    printf("           M{6} | {3} {5} {1} {3} {6} {2} |\n");
    printf("                | {0} {4} {2} {3} {1} {8} | M{4}\n");
    printf("                   A   B   C   D   E   F\n");
    printf("           [Player A] Cup of Choice: F\n");
    printf("           ----------- Current Board -----------\n");
    printf("           M{6} | {0} {6} {2} {4} {7} {3} |\n");
    printf("                | {0} {4} {2} {3} {1} {0} | M{10}\n");
    printf("4.  The game ends when all six cups on either side of the board are empty.\n");
    printf("    The player with remaining marbles in their cups automatically places the\n");
    printf("    remaining marbles into their own mancala. The player with the most marbles\n");
    printf("    in their mancala is the winner of the game.\n");
  }
  else if (strcmp(data,"n\n") == 0)
    return;
  else instructions();
}
