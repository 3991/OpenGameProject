#include <SFML/Graphics.hpp>
#include "../include/Cell.h"
#include <iostream>
#include "cstdlib"

Cell::Cell(){
}

Cell::Cell(float column, float line){
    rectangle.setSize({_NB_SIZE, _NB_SIZE});
    rectangle.setPosition({column, line});
    rectangle.setFillColor(sf::Color::Black);
    if (!font.loadFromFile("arial.ttf")){
        // erreur...
    }

    protectedtText.setString("O");
    protectedtText.setFont(font);
    /*int t = rand()%(3-1) +1;
    if(t == 1){
        protectedtText.setString("H");
        protectedtText.setColor(sf::Color::White);
    }else{
        protectedtText.setString("O");
        protectedtText.setColor(sf::Color::Red);
    }*/

    //protectedtText.setCharacterSize(20);

    //protectedtText.setOrigin(protectedtText.getGlobalBounds().width/2, protectedtText.getGlobalBounds().height/2);
   // protectedtText.setPosition(rectangle.getPosition().x + rectangle.getGlobalBounds().width/2, rectangle.getPosition().y + rectangle.getGlobalBounds().height/2);
}

Cell::~Cell(){
}


void Cell::setPosition(float column, float line){
    rectangle.setPosition({column, line});
}

int Cell::getSize(){
    return _NB_SIZE;
}

void Cell::init(){
    /*if (!font.loadFromFile("arial.ttf")){
        // erreur...
    }

    protectedtText.setFont(font);*/
    int t = rand()%(3-1) +1;
    if(t == 1){
        protectedtText.setString("H");
        protectedtText.setColor(sf::Color::White);
    }else{
        protectedtText.setString("O");
        protectedtText.setColor(sf::Color::Red);
    }

    protectedtText.setCharacterSize(20);

    protectedtText.setOrigin(protectedtText.getGlobalBounds().width/2, protectedtText.getGlobalBounds().height/2);
    protectedtText.setPosition(rectangle.getPosition().x + rectangle.getGlobalBounds().width/2, rectangle.getPosition().y + rectangle.getGlobalBounds().height/2);
}

bool Cell::containts(int x, int y){
    if(rectangle.getGlobalBounds().contains(x, y)){
        return true;
    }else{
        return false;
    }
}

void Cell::display(sf::RenderWindow &window){
    window.draw(rectangle);
    window.draw(protectedtText);
}
