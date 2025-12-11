#include "Jugador.h"

Jugador::Jugador() {
    posX = 1;
    posY = 1;

    texJugador.loadFromFile("assets/jugador.png");
    sprite.setTexture(texJugador);

    sprite.setScale(1,1);
}

void Jugador::dibujar(sf::RenderWindow& ventana) {
    sprite.setPosition(posX * 32, posY * 32);
    ventana.draw(sprite);
}

void Jugador::mover(int dx, int dy, Mapa& mapa) {
    int nx = posX + dx;
    int ny = posY + dy;

    if (!mapa.esPared(nx, ny)) {
        posX = nx;
        posY = ny;
    }
}

int Jugador::x() { return posX; }
int Jugador::y() { return posY; }
