#include <SFML/Graphics.hpp>
#include "../include/Map.h"

#include <iostream>

Map::Map(){
    rectangle.setSize({40, 40});
    column = 0, line = 0;

    if (!font.loadFromFile("arial.ttf")){
        // erreur...
    }

    activ = false;
}

Map::~Map(){
}

void Map::init(){
    /*float column = 0, line = 0;
    for(unsigned int a = 0; a<_NB_CELL_WIDTH*_NB_CELL_HEIGH; a++){
        //c = Cell(column, line);
        //c.init();
        cells.push_back(Cell(column, line));

        column += c.getSize()+1;

        if(column > c.getSize()*_NB_CELL_WIDTH){
            line += c.getSize()+1;
            column = 0;
        }
    }*/
    for(unsigned int i=0; i<_NB_CELL_HEIGH; i++){
        for(unsigned int j=0; j<_NB_CELL_WIDTH; j++){
            symbolsLayer[i][j] = _HYDROGEN;
        }
    }
    symbolsLayer[5][5] = _OXYGEN;

    recTest.setSize({40, 40});
    recTest.setFillColor(sf::Color::Black);
}

void Map::display(sf::RenderWindow &window){
    /*for(unsigned int a = 0; a<cells.size(); a++){
        cells[a].display(window);
    }*/
    for(unsigned int i=0; i<_NB_CELL_HEIGH; i++){
        for(unsigned int j=0; j<_NB_CELL_WIDTH; j++){
            rectangle.setPosition({column, line});
            rectangle.setFillColor(sf::Color::Black);
            window.draw(rectangle);

            if(symbolsLayer[i][j] == _HYDROGEN){
                protectedText.setString("H");

            }else if(symbolsLayer[i][j] == _OXYGEN){
                protectedText.setString("O");
            }else if(symbolsLayer[i][j] == 4){
                protectedText.setString("H2O");
            }else{
                protectedText.setString("");
            }
            protectedText.setFont(font);
            protectedText.setColor(sf::Color::White);
            protectedText.setCharacterSize(20);
            protectedText.setOrigin(protectedText.getGlobalBounds().width/2, protectedText.getGlobalBounds().height/2);
            protectedText.setPosition(rectangle.getPosition().x + rectangle.getGlobalBounds().width/2, rectangle.getPosition().y + rectangle.getGlobalBounds().height/2);
            window.draw(protectedText);

            column += 40+1;
        }
        line += 40+1;
        column = 0;
    }
    column = 0;line = 0;

    if(activ){
        window.draw(recTest);
        window.draw(protectedText2);
    }

}

void Map::detect(sf::RenderWindow &window){
    for(unsigned int i=0; i<_NB_CELL_HEIGH; i++){
        for(unsigned int j=0; j<_NB_CELL_WIDTH; j++){
            if(sf::FloatRect(j*40+j,i*40+i,40,40).contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){

                if( sf::Mouse::isButtonPressed(sf::Mouse::Left) && !activ){
                    if(symbolsLayer[i][j] == _HYDROGEN){
                        protectedText2.setString("H");
                        symbolsLayer[i][j] = 3;
                    }else{
                        protectedText2.setString("O");
                        symbolsLayer[i][j] = 3;
                    }

                    protectedText2.setFont(font);
                    protectedText2.setColor(sf::Color::White);
                    protectedText2.setCharacterSize(20);
                    protectedText2.setOrigin(protectedText2.getGlobalBounds().width/2, protectedText2.getGlobalBounds().height/2);
                    protectedText2.setPosition(recTest.getPosition().x + recTest.getGlobalBounds().width/2, recTest.getPosition().y + recTest.getGlobalBounds().height/2);
                }

                if( sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    starting_position.x = sf::Mouse::getPosition(window).x;
                    starting_position.y = sf::Mouse::getPosition(window).y;
                    activ = true;
                }

                if( sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
                    recTest.setPosition( starting_position.x/*+(rectTitle.getSize().x-starting_position.x)*/ , starting_position.y );
protectedText2.setPosition(recTest.getPosition().x + recTest.getGlobalBounds().width/2, recTest.getPosition().y + recTest.getGlobalBounds().height/2);



                }
                if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && activ){
                    symbolsLayer[i][j] = 4;
                    activ = false;
                }
            }
        }
    }
}
