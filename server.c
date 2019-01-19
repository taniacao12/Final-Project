#include <sys/socket.h>
#include "networking.h"

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("main");
    printf("wkp removed\n");
    exit(0);
  }
}

void subserver(int player1, int player2);
void process(char * name);

int main() {
  signal(SIGINT, sighandler);
  int listen_socket;
  int f;
  listen_socket = server_setup();
	
  while (1) {
    int player1; 
    int player2;
		
    player1 = server_connect(listen_socket);
    printf("[server] player1 connected... waiting for player2\n");
		
    player2= server_connect(listen_socket);
    printf("[server] player2 connected!\n");
    char send[100];
    char send1[100];
    strcpy(send, "player 2 connected!\n");
    write(player1, send, 100);
    strcpy(send1, "Connected! You are player 2\n");
    write(player2, send1, 100);
		
    f = fork();
    if (f == 0)
      subserver(player1, player2);
    else{
      close(player1);
    }
    //int client_socket = server_connect(listen_socket);
  }
}

void subserver(int player1, int player2) {
	char buffer[BUFFER_SIZE];
	
	//permits player1 to play
	write(player1, buffer, sizeof(buffer));
	
	while (read(player1, buffer, sizeof(buffer))) {

    printf("[subserver %d] received: [%s]\n", getpid(), buffer);
    process(buffer);
    write(player2, buffer, sizeof(buffer));
  
  }
  close(player1);
  exit(0);
}

//process is converting it back into an array
void process(char * s) {
  while (*s) {
    if (*s >= 'a' && *s <= 'z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    else  if (*s >= 'A' && *s <= 'Z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    s++;  
  }
}
