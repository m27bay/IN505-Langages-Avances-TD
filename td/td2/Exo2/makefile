all : compile
	./../Exe/exo2

tab : compile
	./../Exe/exo2 vectorTab

list : compile
	./../Exe/exo2 vectorList

compile : exo2.o Vector.o
	g++ ../Obj/exo2.o ../Obj/Vector.o -o ../Exe/exo2

Vector.o : Vector.cpp Vector.hpp
	g++ -c -Wall Vector.cpp
	mv Vector.o ../Obj

exo2.o : exo2.cpp
	g++ -c -Wall exo2.cpp
	mv exo2.o ../Obj

debug : compileD
	./../Exe/exo2

compileD : exo2.oD Vector.oD
	g++ -g ../Obj/exo2.o ../Obj/Vector.o -o ../Exe/exo2

Vector.oD : Vector.cpp Vector.hpp NodeInt.hpp
	g++ -c -g -Wall Vector.cpp
	mv Vector.o ../Obj

exo2.oD : exo2.cpp
	g++ -c -g -Wall exo2.cpp
	mv exo2.o ../Obj

gdb :
	gdb ./../Exe/exo2

gdbList :
	gdb ./../Exe/exo2 vectorList

vg :
	valgrind ./../Exe/exo2

vgList :
	valgrind ./../Exe/exo2 vectorList

vg2 :
	valgrind --leak-check=full ./../Exe/exo2

vgList2 :
	valgrind --leak-check=full ./../Exe/exo2 vectorList

clean :
	rm ../Exe/exo2
	rm ../Obj/exo2.o
	rm ../Obj/Vector.o
