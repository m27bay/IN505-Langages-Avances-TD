all : compile
	./../Exe/exo2

compile : exo2.o Vector.o
	g++ ../Obj/exo2.o ../Obj/Vector.o -o ../Exe/exo2

Vector.o : Vector.cpp Vector.hpp
	g++ -c -Wall Vector.cpp
	mv Vector.o ../Obj

exo2.o : exo2.cpp
	g++ -c -Wall exo2.cpp
	mv exo2.o ../Obj

vg :
	valgrind ./../Exe/exo2

vg2 :
	valgrind --leak-check=full ./../Exe/exo2

clean :
	rm ../Exe/exo2
	rm ../Obj/exo2.o
	rm ../Obj/Vector.o
