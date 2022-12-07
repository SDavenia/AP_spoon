CC=g++

INCDIR=include
OBJDIR=src

CFLAGS = -c -I$(INCDIR) 
OBJECTS:= main.o $(patsubst %.cpp,%.o,$(wildcard $(OBJDIR)/*.cpp)) #objects are all cpp files and all .o files in src

output.x: $(OBJECTS) #main.o and an object file for each
	$(CC) $(OBJECTS) -o $@ 	#g++ all object files .o
main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp
$(OBJDIR)/%.o: $(OBJDIR)/%.cpp 
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -rf *.o *.x
	rm $(OBJDIR)/*.o

