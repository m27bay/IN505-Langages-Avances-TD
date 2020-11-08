CC=g++
CFLAGS=-W -Wall -Wextra
EXEC=Main

all: $(EXEC)

# For window
runWin : 
	./$(EXEC).exe

Main: Main.o CList.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

CList.o: CList.cpp CList.hpp
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
	