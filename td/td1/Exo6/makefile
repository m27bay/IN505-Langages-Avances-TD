all : compile
	./../exe/exo6

compile : exo6.o CString.o
	g++ ../obj/exo6.o ../obj/CString.o -o ../exe/exo6

CString.o : CString.cpp CString.hpp
	g++ -c -Wall CString.cpp
	mv CString.o ../obj

exo6.o : exo6.cpp
	g++ -c -Wall exo6.cpp
	mv exo6.o ../obj

vg :
	valgrind ./../exe/exo6

vg2 :
	valgrind --leak-check=full ./../exe/exo6

clean :
	rm ../obj/exo6.o
	rm ../obj/CString.o
