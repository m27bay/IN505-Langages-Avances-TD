all : compile
	./../Exe/exo2

compile : exo2.o Forme.o
	g++ ../Obj/exo2.o ../Obj/Forme.o-o ../Exe/exo2

exo2.o : exo2.cpp
	g++ -c exo2.cpp
	mv exo2.o ../Obj

Forme.o : Forme.cpp Forme.hpp
	g++ -c Forme.cpp
	mv Forme.o ../Obj

vg :
	valgrind ./../Exe/exo2

vg2 :
	valgrind --leaks-check=full ./../Exe/exo2

vg3 :
	valgrind -v ./../Exe/exo2

clean :
	rm ../Exe/exo2
	rm ../Obj/exo2.o
	rm ../Obj/Forme.o
