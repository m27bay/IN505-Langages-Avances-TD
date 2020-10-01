all : compile
	./../Exe/exo6

compile : exo6.o CString.o
	g++ ../Obj/exo6.o ../Obj/CString.o -o ../Exe/exo6

CString.o : CString.cpp CString.hpp
	g++ -c -Wall CString.cpp
	mv CString.o ../Obj

exo6.o : exo6.cpp
	g++ -c -Wall exo6.cpp
	mv exo6.o ../Obj

vg :
	valgrind ./../Exe/exo6

vg2 :
	valgrind --leak-check=full ./../Exe/exo6

clean :
	rm ../Exe/exo6
	rm ../Obj/exo6.o
	rm ../Obj/CString.o
