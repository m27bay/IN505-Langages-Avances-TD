all : compile
	./../Exe/exo7

compile : exo7.o Definition.o
	g++ ../Obj/exo7.o ../Obj/Definition.o ../Obj/CString.o -o ../Exe/exo7

Definition.o : Definition.cpp Definition.hpp
	g++ -c -Wall Definition.cpp
	mv Definition.o ../Obj

exo7.o : exo7.cpp
	g++ -c -Wall exo7.cpp
	mv exo7.o ../Obj

vg :
	valgrind ./../Exe/exo7

vg2 :
	valgrind --leak-check=full ./../Exe/exo7

clean :
	rm ../Exe/exo7
	rm ../Obj/exo7.o
	rm ../Obj/Definition.o
