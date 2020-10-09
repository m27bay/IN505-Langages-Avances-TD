all : compile
	./../Exe/exo1

compile : exo1.o CString.o
	g++ ../Obj/exo1.o ../Obj/CString.o -o ../Exe/exo1

CString.o : CString.cpp CString.hpp
	g++ -c -Wall CString.cpp
	mv CString.o ../Obj

exo1.o : exo1.cpp
	g++ -c -Wall exo1.cpp
	mv exo1.o ../Obj

vg :
	valgrind ./../Exe/exo1

vg2 :
	valgrind --leak-check=full ./../Exe/exo1

clean :
	rm ../Exe/exo1
	rm ../Obj/exo1.o
	rm ../Obj/CString.o
