# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -Wall -std=c++11

# Define the output executable name
TARGET = test

# Define the source files
SRC = src/Board/Board.cpp src/Game/Game.cpp src/Player/Player.cpp src/Menu/Menu.cpp src/FileManager/FileManager.cpp src/Bot/Bot.cpp test.cpp

# Define the object files
OBJ = $(SRC:.cpp=.o)

# Define the default target
all: $(TARGET)

# Define how to build the target executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Define how to build the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Define the clean target
clean:
	rm -f $(OBJ) $(TARGET)