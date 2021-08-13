#include <SFML/Graphics.hpp>
#include <string>

#include "GameObject.h"

#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        int max_framerate = 60;
        std::string window_name;
        sf::Vector2f window_size;
        std::vector<GameObject*> game_objects;
    public:
        Game(std::string name, sf::Vector2f size);
        //int Run();
        //void Close();
};

#endif