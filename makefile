TARGET = laberinto

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

CXX = g++
CXXFLAGS = -I$(INC_DIR) -std=c++17

SFML = -lsfml-graphics -lsfml-window -lsfml-system

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(SFML)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)
	
run: $(TARGET)
	./$(TARGET)
