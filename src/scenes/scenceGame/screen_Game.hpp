#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "../../../include/Fps.h"
#include "Player.hpp"
#include "Editor.hpp"

namespace screenGame{
    enum State{activate, desactivate};
    class screen_Game : public cScreen{
        private:
            float frame;
            Fps mainFps;
            Player player;
            State sEditor;
            State sMenu;
            Editor editor;
        public:
            screen_Game(void);
            virtual int Run(sf::RenderWindow &window);
    };
}

using namespace screenGame;

screen_Game::screen_Game(void){

}

int screen_Game::Run(sf::RenderWindow &window){
    sf::Event event;
    bool running = true;
    int original_x = 1920;
    int original_y = 1080;
    sEditor = desactivate;
    sMenu = desactivate;

    sf::Texture texture_background;
    sf::Texture texture_button;
    sf::Texture texture_menu;

    sf::Sprite sprite_background;
    sf::Sprite sprite_button;
    sf::Sprite sprite_menu;

    sf::Text text_anything;
    sf::Text text_money;
    sf::Text text_day;
    sf::Text text_friends;
    sf::Text text_menu_create_thing;
    sf::Text text_menu_team_work;
    sf::Text text_menu_money;
    sf::Text text_menu_big_company;
    sf::Text text_menu_world;
    sf::Text text_menu_go_away;
    sf::Font font;

    if(!texture_background.loadFromFile("background.png")){ }
    if(!texture_button.loadFromFile("button.png")){ }
    if(!texture_menu.loadFromFile("menu_temp.png")){ }

    texture_background.setSmooth(true);
    sprite_background.setTexture(texture_background);
    sprite_background.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);

    texture_button.setSmooth(true);
    sprite_button.setTexture(texture_button);
    sprite_button.setPosition({window.getSize().x*0.05, window.getSize().y*0.02});
    sprite_button.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);

    texture_menu.setSmooth(true);
    sprite_menu.setTexture(texture_menu);
    sprite_menu.setPosition({window.getSize().x*0.03, window.getSize().y*0.08});
    sprite_menu.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);



    if(!font.loadFromFile("onthemove.ttf")){ }

    text_anything.setFont(font);
    text_anything.setString("ANYTHING");
    text_anything.setCharacterSize(window.getSize().x * 50 / original_x);
    text_anything.setColor(sf::Color::Black);
    text_anything.setOrigin({(int)(text_anything.getGlobalBounds().left + text_anything.getGlobalBounds().width/2.0f),
                            (int)(text_anything.getGlobalBounds().top + text_anything.getGlobalBounds().height/2.0f)});
    text_anything.setPosition({(int)(sprite_button.getGlobalBounds().left + sprite_button.getGlobalBounds().width/2.0f),
                              (int)(sprite_button.getGlobalBounds().top + sprite_button.getGlobalBounds().height/2.0f)});


    text_money.setFont(font);
    text_money.setCharacterSize(window.getSize().x * 50 / original_x);
    text_money.setColor(sf::Color::Black);
    text_money.setPosition({(int)(window.getSize().x-window.getSize().x*0.05),
                           (int)(window.getSize().y*0.02)});

    text_day.setFont(font);
    text_day.setCharacterSize(window.getSize().x * 50 / original_x);
    text_day.setColor(sf::Color::Black);
    text_day.setPosition({(int)(text_money.getPosition().x -window.getSize().x*0.10),
                         (int)(window.getSize().y*0.02)});

    text_friends.setFont(font);
    text_friends.setCharacterSize(window.getSize().x * 50 / original_x);
    text_friends.setColor(sf::Color::Black);
    text_friends.setPosition({(int)(text_day.getPosition().x - window.getSize().x*0.15),
                             (int)(window.getSize().y*0.02)});

    std::string currency = "$";
    int m = 0;
    std::stringstream ss;
    ss << currency << m;
    std::string str = ss.str();
    text_money.setString(str);

    std::string day = "Day ";
    int d = 1;
    std::stringstream sss;
    sss << day << d;
    std::string strr = sss.str();
    text_day.setString(strr);

    std::string friends = " Friend(s)";
    int f = 0;
    std::stringstream ssss;
    ssss << f << friends;
    std::string strrr = ssss.str();
    text_friends.setString(strrr);


    text_menu_create_thing.setFont(font);
    text_menu_create_thing.setString("Create a Thing");
    text_menu_create_thing.setCharacterSize(window.getSize().x * 50 / original_x);
    text_menu_create_thing.setColor(sf::Color::Black);
    text_menu_create_thing.setPosition({(int)(sprite_menu.getPosition().x + 15),
                              (int)(sprite_menu.getPosition().y)});

    text_menu_team_work.setFont(font);
    text_menu_team_work.setString("Team Work");
    text_menu_team_work.setCharacterSize(window.getSize().x * 50 / original_x);
    text_menu_team_work.setColor(sf::Color::Black);
    text_menu_team_work.setPosition({(int)(sprite_menu.getPosition().x + 15),
                              (int)(text_menu_create_thing.getPosition().y + text_menu_create_thing.getGlobalBounds().height + 15)});

    text_menu_money.setFont(font);
    text_menu_money.setString("Money");
    text_menu_money.setCharacterSize(window.getSize().x * 50 / original_x);
    text_menu_money.setColor(sf::Color::Black);
    text_menu_money.setPosition({(int)(sprite_menu.getPosition().x + 15),
                              (int)(text_menu_team_work.getPosition().y + text_menu_team_work.getGlobalBounds().height + 15)});

    text_menu_big_company.setFont(font);
    text_menu_big_company.setString("Big Company");
    text_menu_big_company.setCharacterSize(window.getSize().x * 50 / original_x);
    text_menu_big_company.setColor(sf::Color::Black);
    text_menu_big_company.setPosition({(int)(sprite_menu.getPosition().x + 15),
                              (int)(text_menu_money.getPosition().y + text_menu_big_company.getGlobalBounds().height + 15)});

    text_menu_world.setFont(font);
    text_menu_world.setString("World");
    text_menu_world.setCharacterSize(window.getSize().x * 50 / original_x);
    text_menu_world.setColor(sf::Color::Black);
    text_menu_world.setPosition({(int)(sprite_menu.getPosition().x + 15),
                              (int)(text_menu_big_company.getPosition().y + text_menu_world.getGlobalBounds().height + 15)});

    text_menu_go_away.setFont(font);
    text_menu_go_away.setString("Go Away");
    text_menu_go_away.setCharacterSize(window.getSize().x * 50 / original_x);
    text_menu_go_away.setColor(sf::Color::Black);
    text_menu_go_away.setPosition({(int)(sprite_menu.getPosition().x + 15),
                              (int)(text_menu_world.getPosition().y + text_menu_go_away.getGlobalBounds().height + 15)});

    editor.init(window);

    while (running){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                return (-1);
            }

            if(event.type == sf::Event::Resized){
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                sprite_background.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);
                sprite_button.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                return (2);
            }
        }

        frame = mainFps.getFrameTime();
        if(frame > 30){
            frame = 29;
        }

        player.update(frame);
        editor.update(window);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(text_menu_create_thing.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                sEditor = activate;
                sMenu = desactivate;
            }else if(text_menu_team_work.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                std::cout << "Not available" << std::endl;
            }else if(text_menu_big_company.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                std::cout << "Not available" << std::endl;
            }else if(text_menu_world.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                std::cout << "Not available" << std::endl;
            }else if(text_menu_go_away.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                return -1;
            }else if(text_menu_money.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                 std::cout << "Not available" << std::endl;
            }else if(text_anything.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                sMenu = activate;
            }else{
                sMenu = desactivate;
            }
        }




        window.clear(sf::Color(0,0,0));
        window.draw(sprite_background);
        player.display(window);
        window.draw(sprite_button);

        if(sMenu == activate){
            window.draw(sprite_menu);
            window.draw(text_menu_create_thing);
            window.draw(text_menu_team_work);
            window.draw(text_menu_money);
            window.draw(text_menu_big_company);
            window.draw(text_menu_world);
            window.draw(text_menu_go_away);
        }

        window.draw(text_anything);
        window.draw(text_money);
        window.draw(text_day);
        window.draw(text_friends);

        if(sEditor == activate){
            editor.display(window);
        }
        window.display();
    }

    return -1;
}
