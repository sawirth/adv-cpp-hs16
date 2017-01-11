# Declaration of variables
CC = g++ -std=c++11
CC_FLAGS = -w

# File names
EXEC = run
SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cc
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
