cap: main.o Board.o TextOutput.o InputString.o
	g++ -std=c++14 -o cap main.o Board.o TextOutput.o InputString.o

main.o: main.cpp 
	g++ -std=c++14 -Wextra -Wall -pedantic -c main.cpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c Board.cpp

TextOutput.o: TextOutput.cpp TextOutput.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c TextOutput.cpp

InputString.o: InputString.cpp InputString.hpp
	g++ -std=c++14 -Wextra -Wall -pedantic -c InputString.cpp

clean:  
	rm *.o cap
