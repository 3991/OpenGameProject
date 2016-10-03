#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>


namespace screenAgreement{
    class screen_Agreement : public cScreen{
        private:
             sf::Vector2i starting_position;
        public:
            screen_Agreement(void);
            virtual int Run(sf::RenderWindow &window);
    };

}

using namespace screenAgreement;

screen_Agreement::screen_Agreement(void){

}

int screen_Agreement::Run(sf::RenderWindow &window){
    sf::Event event;
    bool running = true;
    float test;

    sf::CircleShape circle_disagree(10);
    sf::CircleShape circle_agree(10);

    sf::Texture texture_rules_page;
    sf::Texture texture_rules;
    //sf::Texture texture_cursor;

    if (!texture_rules_page.loadFromFile("rules_page_c.png")){
        // erreur...
    }
    if (!texture_rules.loadFromFile("rules.png")){
        // erreur...
    }
    /*if (!texture_cursor.loadFromFile("cursor.png")){
        // erreur...
    }*/

    sf::Sprite sprite_rules_page;
    sf::Sprite sprite_rules;
    sf::Sprite sprite_cursor;

    sprite_rules_page.setTexture(texture_rules_page);
    sprite_rules.setTexture(texture_rules);
    sprite_rules.setPosition(sf::Vector2f(620, 180));
    /*sprite_cursor.setTexture(texture_cursor);
    sprite_cursor.setPosition(sf::Vector2f(1205, 205));*/


    sf::Text text_title;
    sf::Text text_agree;
    sf::Text text_disagree;
    sf::Font font;

    if (!font.loadFromFile("onthemove.ttf")) {
        // erreur...
    }

    text_title.setFont(font);
    text_title.setString("Legal Aggrements");
    text_title.setCharacterSize(80);
    text_title.setColor(sf::Color::Black);
    text_title.setPosition({window.getSize().x/3, window.getSize().y/12});


    text_agree.setFont(font);
    text_agree.setString("I agree");
    text_agree.setCharacterSize(50);
    text_agree.setColor(sf::Color::Black);
    text_agree.setPosition({980, 920});

    text_disagree.setFont(font);
    text_disagree.setString("I disagree");
    text_disagree.setCharacterSize(window.getSize().x/_FONT_SIZE_TITLE);
    text_disagree.setColor(sf::Color::Black);
    text_disagree.setPosition({700, 920});

    circle_disagree.setFillColor(sf::Color::White);
    circle_disagree.setOutlineColor(sf::Color::Black);
    circle_disagree.setOutlineThickness(1.f);
    circle_disagree.setPosition({660, 945});

    circle_agree.setFillColor(sf::Color::White);
    circle_agree.setOutlineColor(sf::Color::Black);
    circle_agree.setOutlineThickness(1.f);
    circle_agree.setPosition({950, 945});

    while (running){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                return (-1);
            }

            if(event.type == sf::Event::Resized){
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        sf::FloatRect top(1203, 181, 23, 18);
        sf::FloatRect down(1203, 891, 23, 18);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(top.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                test = sprite_rules.getGlobalBounds().top;
                test += 5;
                if(test<180){sprite_rules.setPosition(sf::Vector2f(620, test));}
            }else if(down.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                test = sprite_rules.getGlobalBounds().top;
                test -= 5;
                if(test+sprite_rules.getGlobalBounds().height>911){sprite_rules.setPosition(sf::Vector2f(620, test));}
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(circle_agree.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                return 2;
            }else if(circle_disagree.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                return -1;
            }
        }

        /*if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            if(sprite_cursor.getGlobalBounds().top > 204 && sprite_cursor.getGlobalBounds().top+sprite_cursor.getGlobalBounds().height < 886){
                starting_position.y = sf::Mouse::getPosition(window).y;
            }

            if(starting_position.y+sprite_cursor.getGlobalBounds().height >= 886){
                 starting_position.y = 884-sprite_cursor.getGlobalBounds().height;
            }else if(starting_position.y <= 204){
                 starting_position.y = 205;
            }
        }

        if(sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(sprite_cursor.getGlobalBounds().top > starting_position.y && starting_position.y != 205){//Move the rules in TOP
                test = sprite_rules.getGlobalBounds().top;
                test++;
                sprite_rules.setPosition(sf::Vector2f(620, test));
            }else if(starting_position.y != 884-sprite_cursor.getGlobalBounds().height){//Move the rules in DOWN
                test = sprite_rules.getGlobalBounds().top;
                test--;
                sprite_rules.setPosition(sf::Vector2f(620, test));
            }
            sprite_cursor.setPosition(sprite_cursor.getPosition().x, starting_position.y);
        }*/

        window.clear(sf::Color::Green);
        window.draw(sprite_rules);
        window.draw(sprite_rules_page);
        //window.draw(sprite_cursor);

        window.draw(text_title);
        window.draw(text_agree);
        window.draw(text_disagree);

        window.draw(circle_disagree);
        window.draw(circle_agree);
        window.display();
    }

    return -1;
}
