# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Automatically find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Object files are the same as source files but with .cpp replaced by .o
OBJS = $(SRCS:.cpp=.o)

# Output executable name
EXEC = main

# Default target: build the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Rule to compile each .cpp file to a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets (they don't correspond to actual files)
.PHONY: clean
