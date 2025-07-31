#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(float width, float height) : selectedItemIndex(0), gameStarted(false) {
    if (!font.loadFromFile("assets/arial.ttf")) {
        cout << "Failed to load font!" << endl;
    }

    gameTitle.setFont(font);
    gameTitle.setCharacterSize(80);
    gameTitle.setFillColor(sf::Color::White); 
    gameTitle.setString("FLYER"); 
    gameTitle.setPosition(sf::Vector2f(width / 2 - 130, 80)); 

    menuItems[0].setFont(font);
    menuItems[0].setFillColor(sf::Color::Red);
    menuItems[0].setString("START");
    menuItems[0].setPosition(sf::Vector2f(width / 2-47, height / 2 - 65));

    menuItems[1].setFont(font);
    menuItems[1].setFillColor(sf::Color::White);
    menuItems[1].setString("EXIT");
    menuItems[1].setPosition(sf::Vector2f(width / 2-35, height / 2 + 65));

    if (!backgroundTexture.loadFromFile("assets/menu.png")) {
        cout << "Failed to load background texture!" << endl;
    }
    background.setTexture(backgroundTexture);
    background.setScale(width / backgroundTexture.getSize().x, height / backgroundTexture.getSize().y);
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(background); 
    window.draw(gameTitle); 
    for (int i = 0; i < 2; i++) {
        window.draw(menuItems[i]);
    }
}

void Menu::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
        case sf::Keyboard::Up:
            if (selectedItemIndex > 0) {
                menuItems[selectedItemIndex].setFillColor(sf::Color::White);
                selectedItemIndex--;
                menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
            }
            break;

        case sf::Keyboard::Down:
            if (selectedItemIndex < 1) {
                menuItems[selectedItemIndex].setFillColor(sf::Color::White);
                selectedItemIndex++;
                menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
            }
            break;

        case sf::Keyboard::Return:
            if (selectedItemIndex == 0) {
                gameStarted = true;
            }
            else if (selectedItemIndex == 1) {
                exit(0);
            }
            break;

        default:
            break;
        }
    }
}

bool Menu::isGameStarted() const {
    return gameStarted;
}
