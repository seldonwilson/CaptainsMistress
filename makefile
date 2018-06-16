cap: main.o Board.o
	g++ -std=c++14 -o cap main.o Board.o

main.o: main.cpp Board.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c main.cpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c Board.cpp