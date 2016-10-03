#ifndef FPS_H
#define FPS_H

#include <list>

class Fps{

    public:
        Fps();
        virtual ~Fps();
        void setFPS(int fps);
        void setFPSMoyenne(int fps);
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
        int getFPS();
        int getFPSMoyenne();
        void display(sf::RenderWindow &window);
        void calculate();
        float getFrameTime();
    protected:
    private:
        int fps, x, y;
        std::list<int>::iterator i;
        std::list<int> fpsList;
        int moyenne;
        sf::Text text;
        sf::Font font;
        sf::Clock clock, clockBis;
        float nombre, elapsed, old;
        float latest;
};

#endif // FPS_H
