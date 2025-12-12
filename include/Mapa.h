#ifndef MAPA_H
#define MAPA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Mapa {
public:
    Mapa();

    void dibujar(sf::RenderWindow& ventana);
    bool esPared(int x, int y);
    bool esSalida(int x, int y);

    void cargarNivel(int nivel);
    int getNivel();

    int ancho();
    int alto();

private:
    int nivelActual;
    std::vector<std::string> lab;

    sf::Texture texPared;
    sf::Texture texPiso;
    sf::Texture texSalida;
};

#endif