#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Game {
public:
    Game(float width, float height);
    void run(sf::RenderWindow& window);

private:
    void handleInput();
    void update();
    void render(sf::RenderWindow& window);
    void resetGame();
    void spawnPipes();

    sf::Sprite bird;
    sf::Texture birdTexture;
    sf::Vector2f birdVelocity;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    std::vector<sf::Sprite> pipes;
    sf::Texture pipeTexture;

    float windowWidth;
    float windowHeight;

    bool gameOver;
    bool spacePressed;

    sf::Font font;
    sf::Text scoreText;
    int score;

    sf::Texture gameOverTexture;
    sf::Sprite gameOverImage;

    sf::Music gameMusic;
};
