CC=g++
CFLAGS=-W -Wall
EXEC=Main

all: $(EXEC)

Main: Main.o Point.o PointColor.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Point.o: Point.cpp Point.hpp
	$(CC) -c $(CFLAGS) $< -o $@

PointColor.o: PointColor.cpp PointColor.hpp
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
