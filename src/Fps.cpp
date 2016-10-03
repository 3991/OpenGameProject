#include <SFML/Graphics.hpp>

#include <iostream>

#include "../include/Fps.h"
#include <sstream>

Fps::Fps(){

    latest=0;
}

Fps::~Fps(){
}

int Fps::getFPS(){

    return this->fps;
}

void Fps::setFPS(int fps){

    this->fps = fps;
}

void Fps::setFPSMoyenne(int fps){

    moyenne = 0;
    fpsList.push_back(fps);

    for(i=fpsList.begin(); i != fpsList.end(); i++){

        moyenne += *i;
    }

    moyenne = moyenne / fpsList.size();
}

int Fps::getFPSMoyenne(){

    return this->moyenne;
}

void Fps::display(sf::RenderWindow &window){

    if (!font.loadFromFile("arial.ttf")){

        std::cout << "Error loading arial.ttf" << std::endl;
    }

    text.setFont(font);

    /* Contatenation */
    std::string jour = ", M : ";

    std::string result;
    std::stringstream sstm;

    sstm << getFPS() << jour << getFPSMoyenne();
    result = sstm.str();

    text.setString(result);


    text.setCharacterSize(24); // Pixel
    text.setPosition(getX(),getY());
    text.setColor(sf::Color::Black);

    window.draw(text);
}

void Fps::calculate(){

    elapsed = clockBis.getElapsedTime().asSeconds();

    if(elapsed > 1){

        setFPS(nombre);
        setFPSMoyenne(nombre);
        nombre = 0;

        clockBis.restart();

    }

    //  std::cout << nombre << std::endl;
    nombre++;
}

float Fps::getFrameTime(){

    old = latest;
    latest = clock.getElapsedTime().asMilliseconds();
    clock.restart();

    return old;
}

void Fps::setX(int x){

    this->x = x;
}

void Fps::setY(int y){

    this->y = y;
}

int Fps::getX() const{

    return this->x;
}

int Fps::getY() const{

    return this->y;
}
