CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

SRC = src/main.cpp src/editor.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = mini_editeur

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
