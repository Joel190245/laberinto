CXX = g++
CXXFLAGS = -Iinclude -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJ = bin/Jugador.o bin/Mapa.o bin/main.o
TARGET = laberinto

all: $(TARGET)

bin/Jugador.o: src/Jugador.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -c src/Jugador.cpp -o bin/Jugador.o

bin/Mapa.o: src/Mapa.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -c src/Mapa.cpp -o bin/Mapa.o

bin/main.o: src/main.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o bin/main.o

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf bin *.exe $(TARGET)

run:
	./$(TARGET)
