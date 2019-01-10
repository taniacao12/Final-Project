#include "pipe_networking.h"

int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  char data[BUFFER_SIZE];
  char user[BUFFER_SIZE];
  
  // welcome user and get their username
  printf("WELCOME TO TEAMANCALA!\n");
  printf("What is your name? ");
  fgets(user, BUFFER_SIZE, stdin);
  // give user the game instructions
  printf("Hi %s! Here are the rules to the game:\n", user);
  // rules
  // insert rules here
  printf("If you are ready, press ENTER to start the game.");
  fgets(user, BUFFER_SIZE, stdin);
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
