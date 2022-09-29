CC = g++
CFLAGS = -Wall -pedantic -g -fsanitize=address
NAME = snake.out
LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o CEngine.o CMenu.o CGame.o CSnake.o
	$(CC) $(CFLAGS) -o $(NAME) main.o CEngine.o CMenu.o CGame.o CSnake.o $(LIB)
	make clean
	clear
	./$(NAME)

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
