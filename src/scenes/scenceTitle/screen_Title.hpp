#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>

#define _FONT_SIZE_TITLE 150
#define _FONT_SIZE_SUBTITLE 50

namespace screenTitle{
    class screen_Title : public cScreen{
        private:
        public:
            screen_Title(void);
            virtual int Run(sf::RenderWindow &window);
    };

}

using namespace screenTitle;

screen_Title::screen_Title(void){

}

int screen_Title::Run(sf::RenderWindow &window){
    sf::Event event;
    bool running = true;
    sf::Text text_title_start;
    sf::Text text_title_time;
    sf::Text text_title_continue;
    sf::Text text_continue_button;
    sf::Font font;
    sf::Vector2u windowsize;
    int width;
    int height;
    int old_x = 1920;
    int old_y = 1080;
    int font_size_title = 93.75;
    int font_size_subtitle = 31.25;
    int old_font;

    if (!font.loadFromFile("onthemove.ttf")) {
        // error...
    }

    text_title_start.setFont(font);
    text_title_start.setString("You took");
    text_title_start.setCharacterSize(window.getSize().x * _FONT_SIZE_TITLE / old_x); /* resize adpatation*/
    //text_title_start.setCharacterSize(font_size_title);
    //text_title_start.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
    text_title_start.setColor(sf::Color::Black);
    text_title_start.setPosition({window.getSize().x/18, window.getSize().y/6});

    text_title_time.setFont(font);
    text_title_time.setString("4.52 seconds");
    text_title_time.setCharacterSize(window.getSize().x * _FONT_SIZE_TITLE / old_x);
    //text_title_time.setCharacterSize(font_size_title);
    //text_title_time.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
    text_title_time.setStyle(sf::Text::Bold);
    text_title_time.setColor(sf::Color::Red);
    text_title_time.setPosition({text_title_start.getPosition().x+text_title_start.getGlobalBounds().width+20/*margin*/, window.getSize().y/6});

    text_title_continue.setFont(font);
    text_title_continue.setString("to read this title");
    text_title_continue.setCharacterSize(window.getSize().x * _FONT_SIZE_TITLE / old_x);
    //text_title_continue.setCharacterSize(font_size_title);
    //text_title_continue.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
    text_title_continue.setColor(sf::Color::Black);
    text_title_continue.setPosition({text_title_time.getPosition().x+text_title_time.getGlobalBounds().width+20/*margin*/, window.getSize().y/6});

    text_continue_button.setFont(font);
    text_continue_button.setString("Press SPACE to continue or ESC to exit");
    text_continue_button.setCharacterSize(window.getSize().x * _FONT_SIZE_SUBTITLE / old_x);
    //text_continue_button.setCharacterSize(font_size_subtitle);
    //text_continue_button.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
    text_continue_button.setColor(sf::Color::Black);
    text_continue_button.setOrigin((int)(text_continue_button.getGlobalBounds().width/2.0f), (int)(text_continue_button.getGlobalBounds().height/2.0f));
    text_continue_button.setPosition({window.getSize().x/2.0f, window.getSize().y-(window.getSize().y/4.0f)});


    while (running){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                return (-1);
            }

            if(event.type == sf::Event::Resized){
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));


                //text_title_start.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
                text_title_start.setCharacterSize(window.getSize().x * text_title_start.getCharacterSize() / old_x);
                text_title_start.setPosition({window.getSize().x/18, window.getSize().y/6});

                //text_title_time.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
                text_title_time.setCharacterSize(window.getSize().x * text_title_time.getCharacterSize() / old_x);
                text_title_time.setPosition({text_title_start.getPosition().x+text_title_start.getGlobalBounds().width+20, window.getSize().y/6});

                //text_title_continue.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
                text_title_continue.setCharacterSize(window.getSize().x * text_title_continue.getCharacterSize() / old_x);
                text_title_continue.setPosition({text_title_time.getPosition().x+text_title_time.getGlobalBounds().width+20, window.getSize().y/6});

                //text_continue_button.setScale((float)window.getSize().x/old_x, (float)window.getSize().y/old_y);
                text_continue_button.setCharacterSize(window.getSize().x * text_continue_button.getCharacterSize() / old_x);
                text_continue_button.setPosition({window.getSize().x/2, window.getSize().y-(window.getSize().y/4)});

            }else{
                old_x = window.getSize().x;
                old_y = window.getSize().y;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                return (1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                return (-1);
            }
        }

        window.clear(sf::Color::White);
        window.draw(text_title_start);
        window.draw(text_title_time);
        window.draw(text_title_continue);
        window.draw(text_continue_button);
        window.display();
    }

    return -1;
}
