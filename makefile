CC = g++
CFLAGS = -Wall -pedantic -O2 -g -fsanitize=address
NAME = snake.out

all: main.o CEngine.o CMenu.o CGame.o CSnake.o
	$(CC) $(CFLAGS) -o $(NAME) main.o CEngine.o CMenu.o CGame.o CSnake.o
	make clean
	./$(NAME)
	clear

main.o: main.cpp CEngine.h
	$(CC) $(CFLAGS) -c main.cpp

CEngine.o: CEngine.h CEngine.cpp CMenu.h CGame.h
	$(CC) $(CFLAGS) -c CEngine.h CEngine.cpp

CMenu.o: CMenu.h CMenu.cpp
	$(CC) $(CFLAGS) -c CMenu.h CMenu.cpp

CGame.o: CGame.h CGame.cpp CSnake.h
	$(CC) $(CFLAGS) -c CGame.h CGame.cpp

CSnake.o: CSnake.h CSnake.cpp
	$(CC) $(CFLAGS) -c CSnake.h CSnake.cpp

clean:
	$(RM) *.o
