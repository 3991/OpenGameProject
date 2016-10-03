#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>

class Editor {
    private:
        sf::RectangleShape rect_create_area;
        sf::Texture texture_background;
        sf::Texture texture_button_create;
        sf::Texture texture_button_cancel;
        sf::Texture texture_property;
        sf::Sprite sprite_background;
        sf::Sprite sprite_button_create;
        sf::Sprite sprite_button_cancel;
        sf::Sprite sprite_property;
        bool boo;
        sf::Vector2i starting_position;
        sf::Text text_create;
        sf::Text text_cancel;

        sf::Text text_object;
        sf::Text text_building;
        sf::RectangleShape rect_object;
        sf::RectangleShape rect_building;

        sf::Text text_pollution;
        sf::Text text_lifetime;
        sf::Text text_health;
        sf::Text text_love;
        sf::Text text_sleep;
        sf::Text text_safety;
        sf::Font font;
    public:
        Editor(void);
        void init(sf::RenderWindow &window);
        void update(sf::RenderWindow &window);
        void display(sf::RenderWindow &window);
};

Editor::Editor(void) {
}

void Editor::init(sf::RenderWindow &window){
    int original_x = 1920;
    int original_y = 1080;

    if(!texture_background.loadFromFile("background_editor.png")){ }
    if(!texture_button_create.loadFromFile("cancel.png")){ }
    if(!texture_button_cancel.loadFromFile("cancel.png")){ }
    if(!texture_property.loadFromFile("property.png")){ }

    if(!font.loadFromFile("onthemove.ttf")){ }

    texture_background.setSmooth(true);
    sprite_background.setTexture(texture_background);
    sprite_background.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);
    sprite_background.setPosition(sf::Vector2f((int)(window.getSize().x/2-(sprite_background.getGlobalBounds().width/2)),
                                               (int)(window.getSize().y/2-(sprite_background.getGlobalBounds().height/2))));

    texture_button_create.setSmooth(true);
    sprite_button_create.setTexture(texture_button_create);
    sprite_button_create.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);
    sprite_button_create.setPosition(sf::Vector2f(sprite_background.getGlobalBounds().left + sprite_background.getGlobalBounds().width*0.15,
                                               sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.80));


    texture_button_cancel.setSmooth(true);
    sprite_button_cancel.setTexture(texture_button_cancel);
    sprite_button_cancel.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);
    sprite_button_cancel.setPosition(sf::Vector2f(sprite_background.getGlobalBounds().left + sprite_background.getGlobalBounds().width - sprite_background.getGlobalBounds().width*0.15 - sprite_button_cancel.getGlobalBounds().width,
                                               sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.80));

    rect_create_area.setSize(sf::Vector2f(sprite_background.getGlobalBounds().width*0.60, sprite_background.getGlobalBounds().height*0.60));
    rect_create_area.setPosition(sf::Vector2f(sprite_background.getGlobalBounds().left + sprite_background.getGlobalBounds(
                                                                                                                           ).width*0.05,
                                              sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.15));
    rect_create_area.setFillColor(sf::Color(255, 255, 255));
    rect_create_area.setOutlineColor(sf::Color::Black);
    rect_create_area.setOutlineThickness(1.f);

    rect_object.setSize(sf::Vector2f(sprite_background.getGlobalBounds().width*0.01, sprite_background.getGlobalBounds().width*0.01));
    rect_object.setPosition(sf::Vector2f(rect_create_area.getGlobalBounds().left + rect_create_area.getGlobalBounds().width + sprite_background.getGlobalBounds().width*0.05,
                                              sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.15));
    rect_object.setFillColor(sf::Color(255, 255, 255));
    rect_object.setOutlineColor(sf::Color::Black);
    rect_object.setOutlineThickness(1.f);

    rect_building.setSize(sf::Vector2f(sprite_background.getGlobalBounds().width*0.01, sprite_background.getGlobalBounds().width*0.01));
    rect_building.setPosition(sf::Vector2f(rect_object.getGlobalBounds().left,
                                              rect_object.getGlobalBounds().top + rect_object.getGlobalBounds().height + sprite_background.getGlobalBounds().height*0.05));
    rect_building.setFillColor(sf::Color(255, 255, 255));
    rect_building.setOutlineColor(sf::Color::Black);
    rect_building.setOutlineThickness(1.f);


    texture_property.setSmooth(true);
    sprite_property.setTexture(texture_property);
    sprite_property.setScale((float)window.getSize().x/original_x, (float)window.getSize().y/original_y);
    sprite_property.setPosition(sf::Vector2f(rect_building.getGlobalBounds().left,
                                               rect_building.getGlobalBounds().top+80));



    text_object.setFont(font);
    text_object.setString("Object");
    text_object.setCharacterSize(window.getSize().x * 50 / original_x);
    text_object.setColor(sf::Color::Black);
    text_object.setPosition(sf::Vector2f((int)(rect_object.getGlobalBounds().left + rect_object.getGlobalBounds().width + sprite_background.getGlobalBounds().width*0.03),
                              (int)(rect_object.getGlobalBounds().top - sprite_background.getGlobalBounds().height*0.03)));

    text_building.setFont(font);
    text_building.setString("Building");
    text_building.setCharacterSize(window.getSize().x * 50 / original_x);
    text_building.setColor(sf::Color::Black);
    text_building.setPosition(sf::Vector2f((int)(text_object.getGlobalBounds().left),
                              (int)(rect_building.getGlobalBounds().top - sprite_background.getGlobalBounds().height*0.03)));

    boo = true;

    starting_position = sf::Mouse::getPosition(window);


    text_cancel.setFont(font);
    text_cancel.setString("Cancel");
    text_cancel.setCharacterSize(window.getSize().x * 50 / original_x);
    text_cancel.setColor(sf::Color::Black);
    text_cancel.setOrigin({(int)(text_cancel.getGlobalBounds().left + text_cancel.getGlobalBounds().width/2.0f),
                            (int)(text_cancel.getGlobalBounds().top + text_cancel.getGlobalBounds().height/2.0f)});
    text_cancel.setPosition({(int)(sprite_button_cancel.getGlobalBounds().left + sprite_button_cancel.getGlobalBounds().width/2.0f),
                              (int)(sprite_button_cancel.getGlobalBounds().top + sprite_button_cancel.getGlobalBounds().height/2.0f)});

    text_create.setFont(font);
    text_create.setString("Create");
    text_create.setCharacterSize(window.getSize().x * 50 / original_x);
    text_create.setColor(sf::Color::Black);
    text_create.setOrigin({(int)(text_create.getGlobalBounds().left + text_create.getGlobalBounds().width/2.0f),
                            (int)(text_create.getGlobalBounds().top + text_create.getGlobalBounds().height/2.0f)});
    text_create.setPosition({(int)(sprite_button_create.getGlobalBounds().left + sprite_button_create.getGlobalBounds().width/2.0f),
                              (int)(sprite_button_create.getGlobalBounds().top + sprite_button_create.getGlobalBounds().height/2.0f)});

    text_pollution.setFont(font);
    text_pollution.setString("Pollution");
    text_pollution.setCharacterSize(window.getSize().x * 40 / original_x);
    text_pollution.setColor(sf::Color::Black);
    text_pollution.setPosition({(int)(sprite_property.getGlobalBounds().left + sprite_property.getGlobalBounds().width) + 20,
                              (int)(sprite_property.getGlobalBounds().top) - 10});

    text_lifetime.setFont(font);
    text_lifetime.setString("Lifetime");
    text_lifetime.setCharacterSize(window.getSize().x * 40 / original_x);
    text_lifetime.setColor(sf::Color::Black);
    text_lifetime.setPosition({(int)(sprite_property.getGlobalBounds().left + sprite_property.getGlobalBounds().width) + 20,
                              (int)(text_pollution.getGlobalBounds().top + text_pollution.getGlobalBounds().height) });

    text_health.setFont(font);
    text_health.setString("Health");
    text_health.setCharacterSize(window.getSize().x * 40 / original_x);
    text_health.setColor(sf::Color::Black);
    text_health.setPosition({(int)(sprite_property.getGlobalBounds().left + sprite_property.getGlobalBounds().width) + 20,
                              (int)(text_lifetime.getGlobalBounds().top + text_lifetime.getGlobalBounds().height) });

    text_love.setFont(font);
    text_love.setString("Love");
    text_love.setCharacterSize(window.getSize().x * 40 / original_x);
    text_love.setColor(sf::Color::Black);
    text_love.setPosition({(int)(sprite_property.getGlobalBounds().left + sprite_property.getGlobalBounds().width) + 20,
                              (int)(text_health.getGlobalBounds().top + text_health.getGlobalBounds().height) });

    text_sleep.setFont(font);
    text_sleep.setString("Sleep");
    text_sleep.setCharacterSize(window.getSize().x * 40 / original_x);
    text_sleep.setColor(sf::Color::Black);
    text_sleep.setPosition({(int)(sprite_property.getGlobalBounds().left + sprite_property.getGlobalBounds().width) + 20,
                              (int)(text_love.getGlobalBounds().top + text_love.getGlobalBounds().height) });

    text_safety.setFont(font);
    text_safety.setString("Safety");
    text_safety.setCharacterSize(window.getSize().x * 40 / original_x);
    text_safety.setColor(sf::Color::Black);
    text_safety.setPosition({(int)(sprite_property.getGlobalBounds().left + sprite_property.getGlobalBounds().width) + 20,
                              (int)(text_sleep.getGlobalBounds().top + text_sleep.getGlobalBounds().height) });
}

void Editor::update(sf::RenderWindow &window){
    if(sprite_background.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && boo){
            starting_position.x = sf::Mouse::getPosition(window).x-sprite_background.getPosition().x;
            starting_position.y = sf::Mouse::getPosition(window).y-sprite_background.getPosition().y;
            boo = false;
        }

        if( sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
            sprite_background.setPosition( sf::Mouse::getPosition(window).x-starting_position.x, sf::Mouse::getPosition(window).y-starting_position.y );
            rect_create_area.setPosition(sf::Vector2f(sprite_background.getGlobalBounds().left + sprite_background.getGlobalBounds().width*0.05,
                                              sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.15));

            sprite_button_create.setPosition(sf::Vector2f(sprite_background.getGlobalBounds().left + sprite_background.getGlobalBounds().width*0.15,
                                               sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.80));

            text_create.setPosition({(int)(sprite_button_create.getGlobalBounds().left + sprite_button_create.getGlobalBounds().width/2.0f),
                                    (int)(sprite_button_create.getGlobalBounds().top + sprite_button_create.getGlobalBounds().height/2.0f)});

            sprite_button_cancel.setPosition(sf::Vector2f(sprite_background.getGlobalBounds().left + sprite_background.getGlobalBounds().width - sprite_background.getGlobalBounds().width*0.15 - sprite_button_cancel.getGlobalBounds().width,
                                               sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.80));

            text_cancel.setPosition({(int)(sprite_button_cancel.getGlobalBounds().left + sprite_button_cancel.getGlobalBounds().width/2.0f),
                                    (int)(sprite_button_cancel.getGlobalBounds().top + sprite_button_cancel.getGlobalBounds().height/2.0f)});

            rect_object.setPosition(sf::Vector2f(rect_create_area.getGlobalBounds().left + rect_create_area.getGlobalBounds().width + sprite_background.getGlobalBounds().width*0.05,
                                              sprite_background.getGlobalBounds().top + sprite_background.getGlobalBounds().height*0.15));

            text_object.setPosition(sf::Vector2f((int)(rect_object.getGlobalBounds().left + rect_object.getGlobalBounds().width + sprite_background.getGlobalBounds().width*0.03),
                                    (int)(rect_object.getGlobalBounds().top - sprite_background.getGlobalBounds().height*0.03)));

            rect_building.setPosition(sf::Vector2f(rect_object.getGlobalBounds().left,
                                              rect_object.getGlobalBounds().top + rect_object.getGlobalBounds().height + sprite_background.getGlobalBounds().height*0.05));

            text_building.setPosition(sf::Vector2f((int)(text_object.getGlobalBounds().left),
                              (int)(rect_building.getGlobalBounds().top - sprite_background.getGlobalBounds().height*0.03)));

            sprite_property.setPosition(sf::Vector2f(rect_building.getGlobalBounds().left,
                                               rect_building.getGlobalBounds().top+80));



        }

        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            boo = true;
        }
    }
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !boo){
        boo = true;
    }
}

void Editor::display(sf::RenderWindow &window){
    window.draw(sprite_background);
    window.draw(rect_create_area);
    window.draw(sprite_button_create);
    window.draw(sprite_button_cancel);
    window.draw(text_cancel);
    window.draw(text_create);
    window.draw(rect_object);
    window.draw(rect_building);
    window.draw(text_object);
    window.draw(text_building);
    window.draw(sprite_property);
    window.draw(text_pollution);
    window.draw(text_lifetime);
    window.draw(text_health);
    window.draw(text_love);
    window.draw(text_sleep);
    window.draw(text_safety);
}
