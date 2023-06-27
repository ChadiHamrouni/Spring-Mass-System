#include <SFML/Graphics.hpp>
#include "../header/point.h"
#include "../header/stick.h"

int Width = 1280;
int Height = 720;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(Width, Height), "Verlet Integration", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    sf::Clock clock;
    sf::Color red(235, 69, 95);
    sf::Color blue(0, 255, 202);
    sf::Color green(13, 84, 93);

    sf::RectangleShape floor;
    sf::RectangleShape right;
    sf::RectangleShape left;

    // Setting up the borders
    floor.setSize(sf::Vector2f(1280, 20.f)); 
    floor.setFillColor(sf::Color::Black);
    floor.setPosition(0, 720);
    floor.setOutlineThickness(20);
    floor.setOutlineColor(blue);

    right.setSize(sf::Vector2f(1280, 600.f)); // Set size of the line
    right.setFillColor(sf::Color::Black);
    right.setPosition(1880, 0);
    right.setRotation(90);
    right.setOutlineThickness(2);
    right.setOutlineColor(blue);

    left.setSize(sf::Vector2f(0, 720.f)); // Set size of the line
    left.setFillColor(sf::Color::Black);
    left.setPosition(0, 0);
    left.setOutlineThickness(2);
    left.setOutlineColor(blue);

    // Creating the points & Sticks (This solution isn't scalable, in the future structure creation will be dynamic)
    const int NUM_OBJECTS = 54;
    Point points[NUM_OBJECTS] = {

    Point(200, 200, 10.0, false),
    Point(300, 200, 10.0, false),
    Point(300, 300, 10.0, false),
    Point(200, 300, 10.0, false),
    Point(640, 10, 1.0, true),
         
    Point(300, 300, 1.0, false),
    Point(400, 300, 1.0, false),
    Point(400, 400, 1.0, false),
    Point(300, 400, 1.0, false),

    };

    for (int i = 0; i < NUM_OBJECTS; i++) {
        points[i].shape.setFillColor(red);
    }
      
    const int NUM_STICKS = 13;
    Stick sticks[NUM_STICKS] = {
  
    Stick(points[0], points[1], sticks->distance(points[0], points[1])),
    Stick(points[1], points[2], sticks->distance(points[1], points[2])),
    Stick(points[2], points[3],  sticks->distance(points[2], points[3])),
    Stick(points[3], points[0],  sticks->distance(points[3], points[0])),
    Stick(points[0], points[2],  sticks->distance(points[0], points[2])),
    Stick(points[4], points[2],   150.f),

    Stick(points[0], points[5],  100),
    Stick(points[5], points[6], sticks->distance(points[5], points[6])),
    Stick(points[5], points[7], sticks->distance(points[5], points[7])),
    Stick(points[5], points[8], sticks->distance(points[5], points[8])),
    Stick(points[8], points[7], sticks->distance(points[8], points[7])),
    Stick(points[8], points[6], sticks->distance(points[8], points[6])),
    Stick(points[7], points[6], sticks->distance(points[7], points[6]))

    };

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart(); // get the time elapsed since the last restart and restart the clock
        float dt = elapsed.asSeconds(); 

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       // Update all points
        for (int i = 0; i < NUM_OBJECTS; i++) {
            points[i].update_verlet(dt);
        }

        // Update all sticks
        for (int i = 0; i < NUM_STICKS; i++) {
             sticks[i].update(dt);
        }
       // Apply Constraints
        for (int i = 0; i < NUM_OBJECTS; i++) {
            points[i].constraint(Width, Height);
        }

        window.clear(sf::Color::Black);
    
        window.draw(floor);
        window.draw(right);
        window.draw(left);

        // Render all Points & Sticks
        for (int i = 0; i < NUM_STICKS; i++) {
            sticks[i].render(window);
        }
        
        for (int i = 0; i < NUM_OBJECTS; i++) {
            points[i].render(window);
        }        
        window.display();
    }
    
    return 0;
}
