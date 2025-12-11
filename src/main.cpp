#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Jugador.h"
#include <iostream>

int main() {
    sf::RenderWindow ventana(sf::VideoMode(640, 480), "Juego del Laberinto");
    ventana.setFramerateLimit(10); 

    Mapa mapa;
    Jugador jugador;

    while (ventana.isOpen()) {

        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) jugador.mover(0, -1, mapa);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) jugador.mover(0, 1, mapa);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) jugador.mover(-1, 0, mapa);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) jugador.mover(1, 0, mapa);

        
        if (mapa.esSalida(jugador.x(), jugador.y())) {
            std::cout << "¡Has llegado a la salida!" << std::endl;
            ventana.close();
        }

        ventana.clear();
        mapa.dibujar(ventana);
        jugador.dibujar(ventana);
        ventana.display();
    }

    return 0;
}
