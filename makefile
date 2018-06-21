cap: main.o Board.o TextOutput.o GameLogic.o
	g++ -std=c++14 -o cap main.o Board.o TextOutput.o GameLogic.o

main.o: main.cpp 
	g++ -std=c++14 -Wextra -Wall -pedantic -c main.cpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c Board.cpp

TextOutput.o: TextOutput.cpp TextOutput.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c TextOutput.cpp

GameLogic.o: GameLogic.cpp GameLogic.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c GameLogic.cpp

clean: 
	rm *.o cap
