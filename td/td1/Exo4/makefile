all : compile
	./../Exe/exo4

compile : exo4.o Point.o
	g++ ../Obj/exo4.o ../Obj/Point.o -o ../Exe/exo4

exo4.o : exo4.cpp
	g++ -c exo4.cpp
	mv exo4.o ../Obj

Point.o : Point.cpp Point.hpp
	g++ -c Point.cpp
	mv Point.o ../Obj

clean :
	rm ../Exe/exo4
	rm ../Obj/exo4.o
	rm ../Obj/Point.o
