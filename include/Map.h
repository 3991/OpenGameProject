#ifndef MAP_H
#define MAP_H

#include "../include/Cell.h"

#define _NB_CELL_WIDTH 20
#define _NB_CELL_HEIGH 15

#define _HYDROGEN 1
#define _OXYGEN 2

class Map{
    public:
        Map();
        virtual ~Map();
        void init();
        void detect(sf::RenderWindow &window);
        void display(sf::RenderWindow &window);
    protected:
    private:
        sf::Vector2i starting_position;
        sf::RectangleShape recTest;
        sf::RectangleShape rectangle;
        float column, line;
        int symbolsLayer[_NB_CELL_HEIGH][_NB_CELL_WIDTH];
        sf::Font font;
        sf::Text protectedText;
        sf::Text protectedText2;
        bool activ;
};

#endif // MAP_H
