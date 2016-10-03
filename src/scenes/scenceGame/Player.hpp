#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>
#define SPEED 0.5

class Player {
    private:
        sf::RectangleShape rect_player;
    public:
        Player(void);
        void up(float frame);
        void down(float frame);
        void left(float frame);
        void right(float frame);
        void update(float frame);
        void display(sf::RenderWindow &window);
};

Player::Player(void) {
    rect_player.setFillColor(sf::Color::White);
    rect_player.setOutlineColor(sf::Color::Black);
    rect_player.setOutlineThickness(2.f);
    rect_player.setPosition(sf::Vector2f(500,200));
    rect_player.setSize(sf::Vector2f(50,50));
}

void Player::update(float frame){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        left(frame);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        right(frame);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        up(frame);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        down(frame);
    }
}

void Player::up(float frame){
    rect_player.move(0, -SPEED*frame);
}

void Player::down(float frame){
    rect_player.move(0, SPEED*frame);
}

void Player::left(float frame){
    rect_player.move(-SPEED*frame, 0);
}

void Player::right(float frame){
    rect_player.move(SPEED*frame, 0);
}

void Player::display(sf::RenderWindow &window){
    window.draw(rect_player);
}
