#ifndef CELL_H
#define CELL_H

#define _NB_SIZE 40

class Cell{
    public:
        Cell();
        Cell(float column, float line);
        virtual ~Cell();
        void init();
        void setPosition(float column, float line);
        int getSize();
        bool containts(int x, int y);
        void display(sf::RenderWindow &window);
    protected:
    private:
        sf::RectangleShape rectangle;
        sf::Font font;
        sf::Text protectedtText;
};


#endif // CELL_H
