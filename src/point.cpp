#include "point.h"

float force_x = 0;
float force_y = 150;

Point::Point(float x, float y, float vel_x, float vel_y, float mass) {

    X = x;
    Y = y;      
    Vel_x = vel_x;
    Vel_y = vel_y;
    Mass = mass;

    shape.setRadius(20.f);
    shape.setPosition(X, Y);
}

Point::Point(float x, float y, float mass, bool pinned) {
    X = x;
    Y = y;
    Mass = mass;
    this->pinned = pinned;
    this->old_x = X;
    this->old_y = Y;

    shape.setFillColor(sf::Color::White);
    shape.setRadius(15.f);
    shape.setPosition(X, Y);
}

Point::Point(){}

void Point::update_verlet(float dt) {
    if (!this->pinned) {

        Vel_x = this->X - this->old_x;
        Vel_y = this->Y - this->old_y;

        this->old_x = this->X;
        this->old_y = this->Y;

        float acc_x = force_x / this->Mass;
        float acc_y = force_y / this->Mass;

        this->X += Vel_x + acc_x * dt * dt;
        this->Y += Vel_y + acc_y * dt * dt;

        shape.setPosition(X, Y);
    }
}

void Point::update(float dt) {
    float acc_x = force_x / this->Mass;
    float acc_y = force_y / this->Mass;

    this->Vel_x += acc_x * dt;
    this->Vel_y += acc_y * dt;

    this->X += this->Vel_x * dt;
    this->Y += this->Vel_y * dt;

    shape.setPosition(X, Y);
}

void Point::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Point::constraint(int Width, int Height) {
    Vel_x = this->X - this->old_x;
    Vel_y = this->Y - this->old_y;

    if (this->X < 0) {
        this->X = 0;
        this->old_x = this->X + Vel_x;
    }
    else if (this->X > Width - 31) {
        this->X = Width - 31;
        this->old_x = this->X + Vel_x;
    }
    //Add to make a constraint to the top
    //if (this->Y < 0) {
    //    this->Y = 0;
    //    this->old_y = this->Y + Vel_y;
    //}

    else if (this->Y > Height - 50) {
        this->Y = Height - 50;
        this->old_y = this->Y + Vel_y;
    }
}

