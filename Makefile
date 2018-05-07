CXX = clang++-5.0
CXXFLAGS = -std=c++17

make: main.cpp Board.o Cell.o MyException.o
	$(CXX) $(CXXFLAGS) main.cpp *.o -o a.out
	valgrind --tool=memcheck ./a.out

Board.o: Board.cpp Cell.cpp MyException.cpp Board.h Cell.hpp MyException.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
	$(CXX) $(CXXFLAGS) -c Cell.cpp -o Cell.o
	$(CXX) $(CXXFLAGS) -c MyException.cpp -o MyException.o

clean:
	rm *.o a.out
