all : compile
	./../exe/exo5

compile : exo5.o Segment.o
	g++ ../obj/exo5.o ../obj/Segment.o ../obj/Point.o -o ../exe/exo5

exo5.o : exo5.cpp
	g++ -c exo5.cpp
	mv exo5.o ../obj

Segment.o : Segment.cpp Segment.hpp
	g++ -c Segment.cpp
	mv Segment.o ../obj

clean :
	rm ../obj/exo5.o
	rm ../obj/Segment.o
