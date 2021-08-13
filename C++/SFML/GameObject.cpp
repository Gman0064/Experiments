#include "Game.h"
#include "GameObject.h"

GameObject::GameObject(std::string name, sf::Vector2f size)
{
    obj_name = name;
    obj_size = size;
    shape = sf::RectangleShape(size);
    collider = shape.getGlobalBounds();
    velocity = sf::Vector2f(0, 0);
    acceleration = sf::Vector2f(0, GRAVITY);
}

void GameObject::UpdateCollider() {
    collider = shape.getGlobalBounds();
}

void GameObject::UpdatePhysics() {
    velocity += acceleration;
    if (velocity.x > TERMINAL_VELOCITY) {
        velocity.x = TERMINAL_VELOCITY;
    }
    if (velocity.y > TERMINAL_VELOCITY) {
        velocity.y = TERMINAL_VELOCITY;
    }

    Move(velocity);
}

void GameObject::Move(sf::Vector2f velocity) {
    shape.move(velocity.x, velocity.y);
}

void GameObject::Move(int x, int y) {
    shape.move(x, y);
}

void GameObject::setShapeFillColor(sf::Color new_color) {
    shape.setFillColor(new_color);
}

void GameObject::setPosition(sf::Vector2f new_position) {
    shape.setPosition(new_position);
}