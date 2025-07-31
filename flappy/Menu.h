#pragma once

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(float width, float height);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Event event);
    bool isGameStarted() const;

private:
    sf::Font font;
    sf::Text gameTitle;
    sf::Text menuItems[2];
    sf::Texture backgroundTexture; 
    sf::Sprite background; 
    int selectedItemIndex;
    bool gameStarted;
};
