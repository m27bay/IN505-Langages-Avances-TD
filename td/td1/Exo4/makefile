all : compile
	./exo4

compile : exo4.o Point.o
	g++ exo4.o Point.o -o exo4

exo4.o : exo4.cpp
	g++ -c exo4.cpp

Point.o : Point.cpp Point.hpp
	g++ -c Point.cpp

clean :
	rm exo4.o
	rm Point.o
