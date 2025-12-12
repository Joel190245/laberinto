#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mapa.h"
#include "Jugador.h"

int main() {

    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Laberinto - 3 Niveles");
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
            if (mapa.getNivel() < 3) {
                mapa.cargarNivel(mapa.getNivel() + 1);
                jugador.reiniciar();
            } else {
                std::cout << "¡Has completado los 3 niveles!" << std::endl;
                ventana.close();
            }
        }

        ventana.clear();
        mapa.dibujar(ventana);
        jugador.dibujar(ventana);
        ventana.display();
    }

    return 0;
}