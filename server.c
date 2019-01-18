#include <sys/socket.h>
#include "networking.h"

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("main");
    printf("wkp removed\n");
    exit(0);
  }
}

void subserver(int from_client);
void process(char * name);

int main() {
  signal(SIGINT, sighandler);
  int listen_socket;
  int f;
  listen_socket = server_setup();


  while (1) {

    int client_socket = server_connect(listen_socket);
    f = fork();
    if (f == 0)
      subserver(client_socket);
    else
      close(client_socket);
  }
}

void subserver(int client_socket) {
  char buffer[BUFFER_SIZE];

  while (read(client_socket, buffer, sizeof(buffer))) {

    printf("[subserver %d] received: [%s]\n", getpid(), buffer);
    process(buffer);
    write(client_socket, buffer, sizeof(buffer));
  }//end read loop
  close(client_socket);
  exit(0);
}

void process(char * s) {
  while (*s) {
    if (*s >= 'a' && *s <= 'z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    else  if (*s >= 'A' && *s <= 'Z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    s++;
  }
}

/*
int main() {
  signal(SIGINT, sighandler);
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("ERROR: %d --> %s\n", errno, strerror(errno));
    return 1;
  }
  struct addrinfo *something, *something1;
  
  while (1) {
    // create well known pipe
    int mk_wkp = mkfifo("main", 0644);
    if (mk_wkp == - 1) {
      printf("ERROR: %d --> %s\n", errno, strerror(errno));
      return 1;
    }
    else printf("[SERVER] CREATED WELL KNOWN PIPE\n");
    // wait
    int wkp = open("main", O_RDONLY);
    // receive message
    char msg[HANDSHAKE_BUFFER_SIZE];
    read(wkp, msg, HANDSHAKE_BUFFER_SIZE);
    printf("[SERVER] CLIENT MESSAGE: %s\n", msg);
    // fork subserver
    int f = fork();
    if (f) { // parent
      // remove well known pipe
      remove("main");
      close(wkp);
      printf("[SERVER] REMOVED WELL KNOWN PIPE\n");
    }
    else { // subserver
      int to_client;
      int from_client;
      int start = 0;
      
      from_client = wkp;
      server_handshake( from_client, &to_client, msg );
      char data[BUFFER_SIZE];
      // get data from client
      while(read(from_client, data, BUFFER_SIZE)) {
	printf("[SUBSERVER %d] CLIENT MESSAGE: %s", getpid(), data);
	// process data
	int i = 0;
	while (data[i]) {
	  if (i%2)
	    data[i] = toupper(data[i]); // convert to uppercase
	  i++;
	}
	// reply to client
	int w = write(to_client, data, BUFFER_SIZE);
      }
      close(to_client);
      close(from_client);
      printf("[SUBSERVER %d] SESSION COMPLETE\n", getpid());
      return 0;
    }
  }
  return 0;
}
*/
