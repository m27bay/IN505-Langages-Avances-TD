CC=g++
CFLAGS=-W -Wall
EXEC=main

all: $(EXEC)

main: main.o Segment.o Point.o
	$(CC) $^ -o $@

main.o: main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Point.o: ../Exo4/Point.cpp ../Exo4/Point.hpp
	$(CC) -c $(CFLAGS) $< -o $@

Segment.o: Segment.cpp Segment.hpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm *.o

mrproper: clean
	rm main

# For windows
cleanWin:
	del *.o

mrproperWin: cleanWin
	del main.exe
