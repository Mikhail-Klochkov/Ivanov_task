all:
	g++ -c _func_.cpp
	g++ -c main.cpp
	g++ -o prog main.o _func_.o
	./prog

