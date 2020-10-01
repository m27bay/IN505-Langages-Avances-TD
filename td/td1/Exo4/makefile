all : compile
	./../exe/exo4

compile : exo4.o Point.o
	g++ ../obj/exo4.o ../obj/Point.o -o ../exe/exo4

exo4.o : exo4.cpp
	g++ -c exo4.cpp
	mv exo4.o ../obj

Point.o : Point.cpp Point.hpp
	g++ -c Point.cpp
	mv Point.o ../obj

clean :
	rm ../exe/exo4
	rm ../obj/exo4.o
	rm ../obj/Point.o
