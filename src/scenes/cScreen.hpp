#ifndef Included_cScreen_H
#define Included_cScreen_H

#include <SFML/Graphics.hpp>

class cScreen
{
public :
    virtual int Run(sf::RenderWindow &App) = 0;
};

#endif // Included_cScreen_H


