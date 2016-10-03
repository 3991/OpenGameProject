#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

#include "src/scenes/screens.hpp"
#include <stdio.h>
#include <stdlib.h>

#define _WINDOW_WIDTH 1200
#define _WINDOW_HEIGHT 675

#define _WINDOW_WIDTHd 1920
#define _WINDOW_HEIGHTd 1080



int main(int argc, char** argv){
    std::vector<cScreen*> Screens;
    int screen = 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow app(sf::VideoMode(_WINDOW_WIDTH, _WINDOW_HEIGHT), "It took you 4 seconds to read this title", /*sf::Style::Resize |*/ sf::Style::Close, settings);
    app.setFramerateLimit(60);
    app.setMouseCursorVisible(true);


    screen_Game sGame;
    Screens.push_back(&sGame);


    screen_Title sTitle;
    Screens.push_back(&sTitle);

    screen_Agreement sAgreement;
    Screens.push_back(&sAgreement);






    screen_2 s2;
    Screens.push_back(&s2);

    while (screen >= 0){
        screen = Screens[screen]->Run(app);
    }

    return EXIT_SUCCESS;
}

