#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "Game.h"

Game::Game(std::string name, sf::Vector2f size) {
    window_name = name;
    window_size = size;
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), window_name);
    window.setFramerateLimit(max_framerate);

    GameObject platform("Platform", sf::Vector2f(800.f, 50.f));
    platform.setShapeFillColor(sf::Color::Red);
    platform.setPosition(sf::Vector2f(0, 550));

    GameObject player("Player", sf::Vector2f(50.f, 50.f));
    player.setShapeFillColor(sf::Color::Blue);

    game_objects.push_back(&player);
    game_objects.push_back(&platform);

    window.setActive();

    while (window.isOpen())
    {
        player.UpdateCollider();
        platform.UpdateCollider();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        if(!player.getCollider().intersects(platform.getCollider())) {
            player.UpdatePhysics();
        }

        window.clear();

        window.draw(platform.getShape());
        window.draw(player.getShape());

        // Drawing objects that get added to the GameObjects vector, needs fixing!!
        //
        // for (int i = 0; i < game_objects.size(); i++) {
        //     GameObject *object = game_objects.at(i);
        //     window.draw(object.getShape());
        // }

        window.display();
    }
}