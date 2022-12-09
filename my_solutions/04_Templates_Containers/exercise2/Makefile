CC=g++

INCDIR=include

CFLAGS = -c -I$(INCDIR)
OBJECTS:= main.o $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))

output.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *.o *.x

