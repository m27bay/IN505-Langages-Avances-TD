test : compile
	./test

compile :
	g++ test.cpp -o test

clean :
	rm test

############################

exo1 : compile1
	./exo1

compile1 :
	g++ exo1.cpp -o exo1

clean1 :
	rm exo1

############################

exo2 : compile2
	./exo2

compile2 :
	g++ exo2.cpp -o exo2

clean2 :
	rm exo2

############################

exo3 : compile3
	./exo3

compile3 :
	g++ exo3.cpp -o exo3

clean3 :
	rm exo3

############################

exo4 : compile4
	./exo4

compile4 : exo4.o Point.o
	g++ exo4.o Point.o -o exo4

exo4.o : exo4.cpp
	g++ -c exo4.cpp

clean4 :
	rm exo4.o
	rm Point.o

############################

exo5 : compile5
	./exo5

compile5 : exo5.o Segment.o Point.o
	g++ exo5.o Segment.o Point.o -o exo5

exo5.o : exo5.cpp
	g++ -c exo5.cpp

Segment.o : Segment.cpp Segment.hpp
	g++ -c Segment.cpp

Point.o : Point.cpp Point.hpp
	g++ -c Point.cpp

clean5 :
	rm exo5.o
	rm Segment.o

############################

cleanAll :
	clean1
	clean2
	clean3
	clean4
	clean5
