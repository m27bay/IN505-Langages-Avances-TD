CC=g++
CFLAGS=-W -Wall
EXEC=Main

all: $(EXEC)

Main: Main.o Definition.o CString.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

CString.o:../Exo6/CString.cpp ../Exo6/CString.hpp
	$(CC) -c $(CFLAGS) $< -o $@

Definition.o: Definition.cpp Definition.hpp
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
