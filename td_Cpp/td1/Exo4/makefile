CC=g++
CFLAGS=-W -Wall
EXEC=main

all: $(EXEC)

main: main.o Point.o
	$(CC) $^ -o $@

main.o: main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Point.o: Point.cpp Point.hpp
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
