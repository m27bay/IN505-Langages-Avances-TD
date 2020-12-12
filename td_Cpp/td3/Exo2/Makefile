CC=g++
CFLAGS=-W -Wall -Wextra
EXEC=Main

all: $(EXEC)

# For window
runWin : 
	./$(EXEC).exe

Main: Main.o Forme.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Forme.o: Forme.cpp Forme.hpp
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
