CXX=g++
CXXFLAGS=-std=c++17 

all: Board.o Cell.o 


Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

Cell.o: Cell.cpp Cell.hpp MyException.cpp MyException.hpp
	$(CXX) $(CXXFLAGS) -c Cell.cpp -o Cell.o

main.o: main.cpp Board.h 
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out

buildAndRun: all main.o
	$(CXX) $(CXXFLAGS) Board.o Cell.o main.o
	./a.out
