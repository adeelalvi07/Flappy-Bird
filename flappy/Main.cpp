#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

int main() {
    
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Flappy Bird");

    Menu menu(window.getSize().x, window.getSize().y);
    Game game(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            menu.handleInput(event);
        }

        if (menu.isGameStarted()) {
            game.run(window);
        }
        else {
            window.clear();
            menu.draw(window);
            window.display();
        }
    }

    return 0;
}
