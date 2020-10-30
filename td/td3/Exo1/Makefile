all : compile
	./../Exe/exo1

compile : exo1.o Point.o PointColor.o
	g++ ../Obj/exo1.o ../Obj/Point.o ../Obj/PointColor.o -o ../Exe/exo1

exo1.o : exo1.cpp
	g++ -c exo1.cpp
	mv exo1.o ../Obj

Point.o : Point.cpp Point.hpp
	g++ -c Point.cpp
	mv Point.o ../Obj

PointColor.o : PointColor.cpp PointColor.hpp
	g++ -c PointColor.cpp
	mv PointColor.o ../Obj

vg :
	valgrind ./../Exe/exo1

vg2 :
	valgrind --leaks-check=full ./../Exe/exo1

vg3 :
	valgrind -v ./../Exe/exo1

clean :
	rm ../Exe/exo1
	rm ../Obj/exo1.o
	rm ../Obj/Point.o
	rm ../Obj/PointColor.o
