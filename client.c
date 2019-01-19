#include "networking.h"
#include "functions.c"

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
  printf("Waiting for other player to join...\n");
  
  printf("If you are ready, press ENTER to start the game.");
  fgets(start, BUFFER_SIZE, stdin);
  printf("-----------------------------------------------------\n");

  //board created to send to server
  int board[14] = {4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 0};
  printboard(board);
  
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
