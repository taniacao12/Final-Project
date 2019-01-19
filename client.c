#include "networking.h"
#include "functions.c"

void printboard (int * board) {
  int tempA[7], tempB[7];
  for (int i = 0; i < 7 ; i++) {
    tempA[i] = board[i+6];
    tempB[i] = board[i];
  }
  for (int i = 0; i < 7; i++)
    printf("{%d} ", tempA[i]);
  printf("\n    ");
  for (int i = 0; i < 7; i++)
    printf("{%d} ", tempB[i]);
  printf("\n");
  printf("     A   B   C   D   E   F   \n"); 
}

//int * editboard(int * board, char data[BUFFER_SIZE]){
	 

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
    
	//board = editboard(board, data);
	//I'm writing this here b/c other function keeps breaking but I'll transfer later
	int numinboard=0;
	
	if (*data == 'A'){
		numinboard = board[0];
		for (int i=0; i < numinboard+1; i++){
			if (!i){board[0] -= numinboard;}
			else{
				board[i]+= 1;
			}
		}		
	}
	
	else if (*data == 'B'){
		numinboard = board[1];
		for (int i=1; i < numinboard+2; i++){
			if (i==1){board[1] -= numinboard;}
			else{
				board[i]+= 1;
			}
		}		
	}
	
	else if (*data == 'C'){
		numinboard = board[0];
		for (int i=2; i < numinboard+3; i++){
			if (i==2){board[2] -= numinboard;}
			else{
				board[i]+= 1;
			}
		}		
	}
	
	else if (*data == 'D'){
		int numinboard = board[0];
		for (int i=3; i < numinboard+4; i++){
			if (i==3){board[3] -= numinboard;}
			else{
				board[i]+= 1;
			}
		}		
	}
	
	else if (*data == 'E'){
		numinboard = board[0];
		for (int i=4; i < numinboard+5; i++){
			if (i==4){board[4] -= numinboard;}
			else{
				board[i]+= 1;
			}
		}		
	}
	
	else if (*data == 'F'){
		numinboard = board[0];
		for (int i=5; i < numinboard+6; i++){
			if (i==5){board[5] -= numinboard;}
			else{
				board[i]+= 1;
			}
		}		
	}
	
	printboard(board);
	// send data to server
    int w = write(server_socket, data, BUFFER_SIZE);
    // get reponse from server
    int r = read(server_socket, data, BUFFER_SIZE);
    // display response
    printf("%s", data);
  }

}
