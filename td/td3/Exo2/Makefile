CC=g++
CFLAGS=-W -Wall
EXEC=Main

all: $(EXEC)

Main: Main.o Forme.o Point.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Forme.o: Forme.cpp Forme.hpp
	$(CC) -c $(CFLAGS) $< -o $@

Point.o: ../Exo1/Point.cpp ../Exo1/Point.hpp
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
