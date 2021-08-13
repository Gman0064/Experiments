
#include <SFML/Graphics.hpp>
#include <string>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    private:
        std::string obj_name;
        sf::Vector2f obj_size;
        sf::RectangleShape shape;
        sf::FloatRect collider;

        //Physics
        const float GRAVITY = 1;
        const float TERMINAL_VELOCITY = 20;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
    public:
        GameObject(std::string name, sf::Vector2f size);

        void UpdateCollider();
        void UpdatePhysics();
        void Render();
        void Move(int x, int y);
        void Move(sf::Vector2f velocity);

        //Getters
        std::string getName() { return obj_name; }
        sf::RectangleShape getShape() { return shape; }
        sf::FloatRect getCollider() { return collider; }

        //Setters
        void setName(std::string new_name);
        void setShapeFillColor(sf::Color color);
        void setPosition(sf::Vector2f position);
};

#endif