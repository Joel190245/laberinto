#include "Mapa.h"
#include <iostream>

Mapa::Mapa() {


    lab = {
        "###############",
        "#M     #      #",
        "# ### ### ######",
        "# #     #      #",
        "# # ##### #### #",
        "# #     #    # #",
        "# ### # #### # #",
        "#     #      # #",
        "##### ######   #",
        "#           ##S#",
        "###############"
    };

    texPared.loadFromFile("assets/pared.png");
    texPiso.loadFromFile("assets/piso.png");
    texSalida.loadFromFile("assets/salida.png");
}

bool Mapa::esPared(int x, int y) {
    return lab[y][x] == '#';
}

bool Mapa::esSalida(int x, int y) {
    return lab[y][x] == 'S';
}

int Mapa::ancho() {
    return lab[0].size();
}

int Mapa::alto() {
    return lab.size();
}

void Mapa::dibujar(sf::RenderWindow& ventana) {

    sf::Sprite sprite;

    for (int y = 0; y < alto(); y++) {
        for (int x = 0; x < ancho(); x++) {

            if (lab[y][x] == '#') {
                sprite.setTexture(texPared);
            }
            else if (lab[y][x] == 'S') {
                sprite.setTexture(texSalida);
            }
            else {
                sprite.setTexture(texPiso);
            }

            sprite.setPosition(x * 32, y * 32);
            ventana.draw(sprite);
        }
    }
}
