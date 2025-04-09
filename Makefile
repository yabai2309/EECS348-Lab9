
# Compiler and flags
CC := g++
CFLAGS= -Wall

main.exe: main.o
	$(CC) $(CFLAGS) -o main main.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o