all: a.out 

CC = g++ -std=c++11

a.out: main.o RequestReciever.o Request.o Utils.o Exceptions.o
	$(CC) -o main.o RequestReciever.o Request.o Utils.o Exceptions.o

main.o: main.cpp RequestReciever.h Request.h Utils.h
	$(CC) -c main.cpp

RequestReciever.o: RequestReciever.cpp RequestReciever.h Request.h Utils.h
	$(CC) -c RequestReciever.cpp

Request.o: Request.cpp Request.h Utils.h
	$(CC) -c Request.cpp

Utils.o: Utils.cpp Utils.h
	$(CC) -c Utils.cpp

Exceptions.o: Exceptions.cpp Exceptions.h
	$(CC) -c Exceptions.cpp

.PHONY: clean

clean:
	rm *.o
	rm a.out