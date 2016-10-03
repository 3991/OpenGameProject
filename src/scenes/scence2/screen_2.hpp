#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>

namespace screen2{
    class screen_2 : public cScreen{
        private:
        public:
            screen_2(void);
            virtual int Run(sf::RenderWindow &App);
    };

}

using namespace screen2;

screen_2::screen_2(void){

}

int screen_2::Run(sf::RenderWindow &App){
    sf::Event Event;
    bool running = true;


    while (running){
        while (App.pollEvent(Event)){
            if (Event.type == sf::Event::Closed){
                return (-1);
            }
        }



        App.clear(sf::Color::Blue);

        App.display();
    }

    return -1;
}
