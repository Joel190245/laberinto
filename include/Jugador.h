#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Graphics.hpp>
#include "Mapa.h"

class Jugador {
public:
    Jugador();

    void dibujar(sf::RenderWindow& ventana);
    void mover(int dx, int dy, Mapa& mapa);

    int x();
    int y();

    void reiniciar();

private:
    int posX;
    int posY;

    sf::Texture texJugador;
    sf::Sprite sprite;
};

#endif