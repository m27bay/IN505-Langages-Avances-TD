DEBUG=yes
CC=g++
EXEC=Main

ifeq ($(DEBUG), yes)
	CFLAGS=-std=c++17 -W -Wall -Wextra -g
else
	CFLAGS=-std=c++17 -W -Wall -Wextra
endif

all: $(EXEC)

# For window
runWin : 
	./$(EXEC).exe

run : 
	./$(EXEC)

Main: Main.o CList.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

CList.o: CList.cpp CList.hpp
	$(CC) -c $(CFLAGS) $< -o $@

vg:
	valgrind ./$(EXEC)

vg2:
	valgrind --leak-check=full ./$(EXEC)

vg3:
	valgrind -v ./$(EXEC)

clean:
	rm *.o

mrproper: clean
	rm Main

# For windows
cleanWin:
	del *.o

mrproperWin: cleanWin
	del main.exe
	