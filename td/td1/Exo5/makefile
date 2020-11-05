CC=g++
CFLAGS=-W -Wall
EXEC=Main

all: $(EXEC)

Main: Main.o Segment.o Point.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Point.o: ../Exo4/Point.cpp ../Exo4/Point.hpp
	$(CC) -c $(CFLAGS) $< -o $@

Segment.o: Segment.cpp Segment.hpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm *.o

mrproper: clean
	rm Main

# For windows
cleanWin:
	del *.o

mrproperWin: cleanWin
	del main.exe
