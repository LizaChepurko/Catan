# ID 211548268
# Mail: lizachep@gmail.com

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -pthread

# Target executable
TARGET = Demo

# Source files
SRCS = Demo.cpp Hextile.cpp node.cpp Board.cpp player.cpp Catan.cpp CardBank.cpp Utils.cpp
TEST_SRCS = test_Card.cpp test_node.cpp test_player.cpp player.cpp Board.cpp node.cpp CardBank.cpp Hextile.cpp

# Header files
HDRS = Hextile.hpp node.hpp Board.hpp player.hpp Settlement.hpp Catan.hpp Card.hpp CardBank.hpp Utils.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Additional libraries
LDLIBS = -L/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
TEST_LDLIBS = -lgtest -lgtest_main -lpthread

# Default rule
all: $(TARGET)

# Rule to link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

# Rule to link and run the test executable
test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o test_executable $(TEST_OBJS) $(TEST_LDLIBS)
	./test_executable

# Rule to compile source files to object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(TARGET) $(OBJS) $(TEST_OBJS) test_executable

# Rule to build and run demo
catan: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean test catan
