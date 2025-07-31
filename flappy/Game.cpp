#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(float width, float height) : windowWidth(width), windowHeight(height), gameOver(false), score(0), spacePressed(false) {
    if (!font.loadFromFile("assets/arial.ttf")) {
        cout << "Failed to load font!" <<endl;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    if (!birdTexture.loadFromFile("assets/bird.png")) {
        cout << "Failed to load bird texture!" << endl;
    }
    bird.setTexture(birdTexture);
    bird.setScale(0.25f, 0.25f); 
    bird.setPosition(width / 4, height / 2);
    birdVelocity = sf::Vector2f(0, 0);

    if (!pipeTexture.loadFromFile("assets/pipe.png")) {
        cout << "Failed to load pipe texture!" << endl;
    }

    if (!backgroundTexture.loadFromFile("assets/background.png")) {
        cout << "Failed to load background texture!" << endl;
    }
    background.setTexture(backgroundTexture);
    background.setScale(width / backgroundTexture.getSize().x, height / backgroundTexture.getSize().y);

    if (!gameOverTexture.loadFromFile("assets/gameover.png")) {
        cout << "Failed to load game over texture!" << endl;
    }
    gameOverImage.setTexture(gameOverTexture);

    //gameOverImage
    float scaleFactorX = 1.8f; 
    float scaleFactorY = 1.7f; 
    gameOverImage.setScale(scaleFactorX, scaleFactorY);
    gameOverImage.setPosition(width / 2 - (gameOverImage.getGlobalBounds().width / 2), height / 2 - (gameOverImage.getGlobalBounds().height / 2));

    if (!gameMusic.openFromFile("assets/music.ogg")) {
        cout << "Failed to load music!" << endl;
    }
    gameMusic.setLoop(true);
    gameMusic.play();

    srand(static_cast<unsigned>(time(0)));
    spawnPipes();
}

void Game::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        handleInput();
        update();
        render(window);
    }
}

void Game::handleInput() {
    if (!spacePressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !gameOver) {
        birdVelocity.y = -1.5f; 
        spacePressed = true;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        spacePressed = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && gameOver) {
        resetGame();
    }
}

void Game::update() {
    if (gameOver) return;

    birdVelocity.y += 0.01f; 
    bird.move(birdVelocity);

    
    if (bird.getPosition().y < 0 || bird.getPosition().y + bird.getGlobalBounds().height > windowHeight) {
        gameOver = true;
    }

    
    for (auto& pipe : pipes) {
        pipe.move(-0.7f, 0);
        if (bird.getGlobalBounds().intersects(pipe.getGlobalBounds())) {
            gameOver = true;
        }
    }

    
    if (!pipes.empty() && pipes.front().getPosition().x < -static_cast<int>(pipeTexture.getSize().x)) {
        pipes.erase(pipes.begin(), pipes.begin() + 2);
        spawnPipes();
        score++; 
    }

    scoreText.setString("SCORE: " + to_string(score));
}

void Game::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(background); 
    window.draw(bird);
    for (const auto& pipe : pipes) {
        window.draw(pipe);
    }
    window.draw(scoreText); 
    if (gameOver) {
        window.draw(gameOverImage);
    }
    window.display();
}

void Game::resetGame() {
    bird.setPosition(windowWidth / 4, windowHeight / 3);
    birdVelocity = sf::Vector2f(0, 0);
    pipes.clear();
    spawnPipes();
    gameOver = false;
    score = 0; 
}

void Game::spawnPipes() {
    float gap = 250.0f;
    float pipeHeight = static_cast<float>(pipeTexture.getSize().y);
    float pipeWidth = static_cast<float>(pipeTexture.getSize().x);
    float topPipeHeight = static_cast<float>(rand() % static_cast<int>(windowHeight - gap));

    sf::Sprite topPipe(pipeTexture);
    topPipe.setScale(1.0f, -1.0f); 
    topPipe.setPosition(windowWidth, topPipeHeight);

    sf::Sprite bottomPipe(pipeTexture);
    bottomPipe.setPosition(windowWidth, topPipeHeight + gap);

    pipes.push_back(topPipe);
    pipes.push_back(bottomPipe);
}
