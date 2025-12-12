#include "Mapa.h"

Mapa::Mapa() {
    nivelActual = 1;
    cargarNivel(1);
}

void Mapa::cargarNivel(int nivel) {
    nivelActual = nivel;

    if (nivel == 1) {
        lab = {
            "###############",
            "#M     #      #",
            "# ### ### #### #",
            "# #     #      #",
            "# # ##### #### #",
            "# #     #    # #",
            "# ### # #### # #",
            "#     #      # #",
            "##### ######   #",
            "#           ##S#",
            "###############"
        };

        texPared.loadFromFile("assets/nivel1/pared.png");
        texPiso.loadFromFile("assets/nivel1/piso.png");
        texSalida.loadFromFile("assets/nivel1/salida.png");
    }

    else if (nivel == 2) {
        lab = {
            "###################",
            "#M        #     S#",
            "# ####### # ##### #",
            "#       # #       #",
            "####### # ####### #",
            "#       #         #",
            "# ##### ######### #",
            "#     #           #",
            "# ### ########### #",
            "#                 #",
            "###################"
        };

        texPared.loadFromFile("assets/nivel2/pared.png");
        texPiso.loadFromFile("assets/nivel2/piso.png");
        texSalida.loadFromFile("assets/nivel2/salida.png");
    }

    else if (nivel == 3) {
        lab = {
            "#####################",
            "#M        #        #",
            "# ####### # ###### #",
            "#       # #      # #",
            "####### # ####### # #",
            "#       #       # # #",
            "# ##### ######### # #",
            "#     #           # #",
            "# ### ########### # #",
            "#   #             S #",
            "#####################"
        };

        texPared.loadFromFile("assets/nivel3/pared.png");
        texPiso.loadFromFile("assets/nivel3/piso.png");
        texSalida.loadFromFile("assets/nivel3/salida.png");
    }
}

bool Mapa::esPared(int x, int y) {
    return lab[y][x] == '#';
}

bool Mapa::esSalida(int x, int y) {
    return lab[y][x] == 'S';
}

int Mapa::getNivel() {
    return nivelActual;
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