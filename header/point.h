#pragma once
#include <SFML/Graphics.hpp>


class Point {

public:
    float X = 0, Y = 0, Vel_x = 0, Vel_y = 0, Mass = 0, old_x = 0, old_y = 0;
    bool pinned = false;
    sf::CircleShape shape;

    Point(float x, float y, float vel_x, float vel_y, float mass);
    Point(float x, float y, float mass, bool pinned);
    Point();
   
    void update_verlet(float dt);

    void update(float dt);

    void render(sf::RenderWindow& window);

    void constraint(int Width, int Height);
};