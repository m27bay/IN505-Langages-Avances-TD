CC=g++
CFLAGS=-W -Wall
EXEC=Main

all: $(EXEC)

Main: Main.o Vector.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Vector.o: Vector.cpp Vector.hpp
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
