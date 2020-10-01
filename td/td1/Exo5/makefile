all : compile
	./../Exe/exo5

compile : exo5.o Segment.o
	g++ ../Obj/exo5.o ../Obj/Segment.o ../Obj/Point.o -o ../Exe/exo5

exo5.o : exo5.cpp
	g++ -c exo5.cpp
	mv exo5.o ../Obj

Segment.o : Segment.cpp Segment.hpp
	g++ -c Segment.cpp
	mv Segment.o ../Obj

clean :
	rm ../Exe/exo5
	rm ../Obj/exo5.o
	rm ../Obj/Segment.o
