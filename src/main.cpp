#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mapa.h"
#include "Jugador.h"

enum EstadoJuego {
    INICIO,
    MOSTRAR_NIVEL,
    JUGANDO,
    GANASTE
};

int main() {

    sf::RenderWindow ventana(
        sf::VideoMode::getDesktopMode(),
        "Juego del Laberinto",
        sf::Style::Fullscreen
    );
    ventana.setFramerateLimit(10);

    sf::Font fuente;
    if (!fuente.loadFromFile("assets/fonts/PressStart2P-Regular.ttf")) {
        return 1;
    }

    sf::Text texto;
    texto.setFont(fuente);
    texto.setCharacterSize(28);
    texto.setFillColor(sf::Color::White);

    Mapa mapa;
    Jugador jugador;

    float tileSize = 32.f;
    float mapaAnchoPx = mapa.ancho() * tileSize;
    float mapaAltoPx  = mapa.alto() * tileSize;

    sf::View vista(sf::FloatRect(0, 0, mapaAnchoPx, mapaAltoPx));
    vista.setCenter(mapaAnchoPx / 2, mapaAltoPx / 2);
    ventana.setView(vista);

    EstadoJuego estado = INICIO;
    sf::Clock relojNivel;

    while (ventana.isOpen()) {

        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                ventana.close();

            if (evento.type == sf::Event::KeyPressed &&
                evento.key.code == sf::Keyboard::Escape &&
                estado == GANASTE) {
                ventana.close();
            }
        }

        ventana.clear(sf::Color::Black);

        if (estado == INICIO) {
            ventana.setView(ventana.getDefaultView());
            texto.setString("Presione ENTER\npara jugar");
            texto.setPosition(220, 240);
            ventana.draw(texto);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                estado = MOSTRAR_NIVEL;
                relojNivel.restart();
            }
        }
        else if (estado == MOSTRAR_NIVEL) {
            ventana.setView(ventana.getDefaultView());
            texto.setString("Nivel " + std::to_string(mapa.getNivel()));
            texto.setPosition(300, 260);
            ventana.draw(texto);

            if (relojNivel.getElapsedTime().asSeconds() > 2) {
                ventana.setView(vista);
                estado = JUGANDO;
            }
        }
        else if (estado == JUGANDO) {
            ventana.setView(vista);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) jugador.mover(0, -1, mapa);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) jugador.mover(0, 1, mapa);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) jugador.mover(-1, 0, mapa);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) jugador.mover(1, 0, mapa);

            mapa.dibujar(ventana);
            jugador.dibujar(ventana);

            if (mapa.esSalida(jugador.x(), jugador.y())) {
                if (mapa.getNivel() < 3) {
                    mapa.cargarNivel(mapa.getNivel() + 1);
                    jugador.reiniciar();

                    mapaAnchoPx = mapa.ancho() * tileSize;
                    mapaAltoPx  = mapa.alto() * tileSize;
                    vista = sf::View(sf::FloatRect(0, 0, mapaAnchoPx, mapaAltoPx));
                    vista.setCenter(mapaAnchoPx / 2, mapaAltoPx / 2);
                    ventana.setView(vista);

                    estado = MOSTRAR_NIVEL;
                    relojNivel.restart();
                } else {
                    estado = GANASTE;
                }
            }
        }
        else if (estado == GANASTE) {
            ventana.setView(ventana.getDefaultView());
            texto.setString("HAS GANADO");
            texto.setPosition(200, 230);
            ventana.draw(texto);

            texto.setString("Presione ESC para salir");
            texto.setPosition(120, 300);
            ventana.draw(texto);
        }

        ventana.display();
    }

    return 0;
}