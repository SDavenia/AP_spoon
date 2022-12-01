CC=g++

INCDIR=.
OBJDIR=.

CFLAGS = -c -I$(INCDIR) #indicates all header gcc -c is compile all files including headers to obtain .o files
OBJECTS:= main.o $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))
#$(patsubst %.cpp,%.o,$(wildcard src/*.cpp))
#CQuadratic_Equation_functions.o CCoeffs_functions.o 


output.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
$(OBJDIR)/%.o: $(OBJDIR)/%.cpp
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -rf *.o *.x
