#include "pipe_networking.h"

int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  char data[BUFFER_SIZE];
  char user[BUFFER_SIZE];
  char start[BUFFER_SIZE];
  // welcome user and get their username
  printf("WELCOME TO TEAMANCALA!\n");
  // get user name
  printf("What is your name? ");
  fgets(user, BUFFER_SIZE, stdin);
  user[strlen(user) - 1] = 0;
  // give or skip game instructions
  instructions();
  printf("If you are ready, press ENTER to start the game.");
  fgets(start, BUFFER_SIZE, stdin);
  printf("------------------------------------------------\n");

  char board[12];
  while (1) {
    // get user input
    printf("ENTER MESSAGE: ");
    fgets(data, BUFFER_SIZE, stdin);
    // send data to server
    int w = write(to_server, data, BUFFER_SIZE);
    // get reponse from server
    int r = read(from_server, data, BUFFER_SIZE);
    // display response
    printf("[%s] SERVER MESSAGE: %s", user, data);
  }
}

void instructions() {
  char data[BUFFER_SIZE];
  printf("Do you want the game instructions? (y/n)");
  fgets(data, BUFFER_SIZE, stdin);
  while (data) {
    if (data == "y")
      instructions();
    if (data == "n")
      break;
  }
}