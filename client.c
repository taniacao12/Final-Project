#include "networking.h"
#include "functions.c"

int main() {
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
  while (user == "") {
    fgets(user, BUFFER_SIZE, stdin);
    user[strlen(user) - 1] = 0;
  }
  printf("Welcome %s!\n", user);
  // give or skip game instructions
  instructions();  
  printf("Waiting for other player to join...\n");
  char receive[100];
  read(server_socket, receive, 100);
  printf("%s\n", receive);
  
  printf("If you are ready, press ENTER to start the game.");  
  fgets(start, BUFFER_SIZE, stdin);
  printf("-----------------------------------------------------\n");

  // board created to send to server
  int board[14] = {4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 0};
  
  print(board);
  
  while (1) {
    // player A waits for confirmation from the server to start
    int r0 = read(server_socket, data, BUFFER_SIZE);
	
    // get player A user input
    printf("Which cup would you like to choose? ");
    fgets(data, BUFFER_SIZE, stdin);
  
    // update board based on player A's input
    update(data, board);
    print(board);

    // flip the results so it matches the orientation of the opponent
    flip(board);
    
    // convert results (board data) into a string
    char results[BUFFER_SIZE];
    stringify(results, board));
    
    // send string to the server
    int w = write(server_socket, results, BUFFER_SIZE);
	
    // wait for and recieve player B's results from server
    int r = read(server_socket, results, BUFFER_SIZE);
    
    // convert player B's string results back into an array
    listify(results, board);
    printBoard(board);
  }
  return 0;
}
