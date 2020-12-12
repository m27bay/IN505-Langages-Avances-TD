CC=g++
CFLAGS=-W -Wall
EXEC=Main

all: $(EXEC)

Main: Main.o CString.o Definition.o Dictionary.o
	$(CC) $^ -o $@

Main.o: Main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

CString.o: CString.cpp CString.hpp
	$(CC) -c $(CFLAGS) $< -o $@

Definition.o: Definition.cpp Definition.hpp
	$(CC) -c $(CFLAGS) $< -o $@

Dictionary.o: Dictionary.cpp Dictionary.hpp
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
