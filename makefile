CC = g++
CFLAGS = -Wall -pedantic -O2 -g -fsanitize=address
NAME = snake

all: main.o CEngine.o CMenu.o CGame.o CSnake.o
	$(CC) $(CFLAGS) -o $(NAME) main.o CEngine.o CMenu.o CGame.o CSnake.o
	make clean
	./$(NAME)
	clear

main.o: main.cpp CEngine.h
	$(CC) $(CFLAGS) -c main.cpp

CEngine.o: CEngine.cpp CMenu.h CGame.h
	$(CC) $(CFLAGS) -c CEngine.cpp

CMenu.o: CMenu.cpp
	$(CC) $(CFLAGS) -c CMenu.cpp

CGame.o: CGame.cpp CSnake.h
	$(CC) $(CFLAGS) -c CGame.cpp

CSnake.o: CSnake.cpp
	$(CC) $(CFLAGS) -c CSnake.cpp

clean:
	$(RM) *.o
