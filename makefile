all: client server

client: client.o networking.o
	gcc -o client client.o networking.o

server: fserver.o networking.o
	gcc -o server server.o networking.o

client.o: client.c networking.h
	gcc -c client.c

fserver.o: fserver.c networking.h
	gcc -c fserver.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm *.o
	rm *~
