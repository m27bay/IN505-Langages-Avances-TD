all : compile
	./../Exe/exo3

compile : exo3.o Definition.o CString.o Dictionary.o
	g++ ../Obj/exo3.o ../Obj/Definition.o ../Obj/CString.o ../Obj/Dictionary.o -o ../Exe/exo3

Definition.o : Definition.cpp Definition.hpp
	g++ -c -Wall Definition.cpp
	mv Definition.o ../Obj

exo3.o : exo3.cpp
	g++ -c -Wall exo3.cpp
	mv exo3.o ../Obj

CString.o : CString.cpp CString.hpp
	g++ -c -Wall CString.cpp
	mv CString.o ../Obj

Dictionary.o : Dictionary.cpp Dictionary.hpp
	g++ -c -Wall Dictionary.cpp
	mv Dictionary.o ../Obj


vg :
	valgrind ./../Exe/exo3

vg2 :
	valgrind --leak-check=full ./../Exe/exo3

vg3 :
	valgrind -v ./../Exe/exo3

clean :
	rm ../Exe/exo3
	rm ../Obj/exo3.o
	rm ../Obj/Definition.o
	rm ../Obj/Dictionary.o
