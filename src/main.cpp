#include <SFML/Graphics.hpp>
#include "point.h"
#include "stick.h"

int Width = 1280;
int Height = 720;

const int NumRows = 14;      
const int NumColumns = 25;    
const float CellSize = 51.1f;  

int main()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(Width, Height), "Verlet Integration", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    sf::Clock clock;

    sf::Color Red(235, 69, 95);
    sf::Color wh(0, 0, 0);
    sf::Color wa(0, 255, 202);
    sf::Color green(13, 84, 93);

    sf::VertexArray grid(sf::Lines);  // VertexArray to store the grid lines

    // Create the vertical lines of the grid
    for (int col = 0; col <= NumColumns; ++col) {
        float x = col * CellSize;
        grid.append(sf::Vertex(sf::Vector2f(x, 0.f), green));
        grid.append(sf::Vertex(sf::Vector2f(x, NumRows * CellSize), green));
    }

    // Create the horizontal lines of the grid
    for (int row = 0; row <= NumRows; ++row) {
        float y = row * CellSize;
        grid.append(sf::Vertex(sf::Vector2f(0.f, y), green));
        grid.append(sf::Vertex(sf::Vector2f(NumColumns * CellSize, y), green));
    }

    sf::RectangleShape lineShape;
    sf::RectangleShape right;
    sf::RectangleShape left;

    // Set color of the line
    lineShape.setSize(sf::Vector2f(1280, 20.f)); // Set size of the line
    lineShape.setFillColor(sf::Color::Black);
    lineShape.setPosition(0, 720);
    lineShape.setOutlineThickness(20);
    lineShape.setOutlineColor(wa);

    right.setSize(sf::Vector2f(1280, 600.f)); // Set size of the line
    right.setFillColor(wh);
    right.setPosition(1880, 0);
    right.setRotation(90);
    right.setOutlineThickness(2);
    right.setOutlineColor(wa);

    left.setSize(sf::Vector2f(0, 720.f)); // Set size of the line
    left.setFillColor(wh);
    left.setPosition(0, 0);
    left.setOutlineThickness(2);
    left.setOutlineColor(wa);

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

    Point(800, -400, 1.0, false),
    Point(900, -400, 1.0, false),
    Point(700, -500, 1.0, false),
    Point(1000, -500, 1.0, false),
    Point(800, -600, 1.0, false),
    Point(900, -600, 1.0, false),
    Point(850, -500, 1.0, false),

    Point(400, -300, 1.0, false),
    Point(500, -300, 1.0, false),
    Point(600, -300, 1.0, false),
    Point(500, -200, 1.0, false),


    Point(100, -100, 1.0, false),
    Point(150, -100, 1.0, false),
    Point(200, -100, 1.0, false),
    Point(100, -150, 1.0, false),
    Point(150, -150, 1.0, false),
    Point(200, -150, 1.0, false),
    Point(100, -200, 1.0, false),
    Point(150, -200, 1.0, false),
    Point(200, -200, 1.0, false),

    Point(1100, 100, 1.0, false),
    Point(1200, 100, 1.0, false),
    Point(1100, 200, 1.0, false),
    Point(1200, 200, 1.0, false),
    Point(1150, 150, 1.0, false),

    Point(200, 100, 1.0, true),
    Point(180, 200, 1.0, false),
    Point(150, 200, 1.0, false),
    Point(120, 200, 1.0, false),
    Point(90, 200, 1.0, false),
    Point(60, 200, 1.0, false),
    Point(30, 200, 1.0, false),
    Point(0, 200, 1.0, false),
    Point(30, 250, 1.0, false),
    Point(0, 250, 1.0, false),

    Point(1000, 20, 1.0, true),
    Point(850, 200, 1.0, false),
    Point(900, 200, 1.0, false),
    Point(800, 250, 1.0, false),
    Point(800, 280, 1.0, false),
    Point(750, 300, 1.0, false),
    Point(800, 400, 1.0, false),
    Point(900, 300, 1.0, false)

    };

    for (int i = 0; i < NUM_OBJECTS; i++) {
        points[i].shape.setFillColor(Red);
    }
      
    const int NUM_STICKS = 72;
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
    Stick(points[7], points[6], sticks->distance(points[7], points[6])),


    Stick(points[9], points[10],  100),
    Stick(points[10], points[12], 100),
    Stick(points[12], points[14],100),
    Stick(points[14], points[13],100),
    Stick(points[13], points[11],100),
    Stick(points[11], points[9], 100),

    Stick(points[9], points[15],100),
    Stick(points[10], points[15],100),
    Stick(points[12], points[15],100),
    Stick(points[14], points[15],100),
    Stick(points[13], points[15],100),
    Stick(points[11], points[15],100),

    Stick(points[16], points[17],100),
    Stick(points[17], points[18],100),
    Stick(points[17], points[19],100),
    Stick(points[19], points[16],140),
    Stick(points[18], points[19],140),

    Stick(points[20], points[21],50),
    Stick(points[21], points[22],50),
    Stick(points[22], points[25],50),
    Stick(points[25], points[28],50),
    Stick(points[28], points[27],50),
    Stick(points[27], points[26],50),
    Stick(points[26], points[23],50),
    Stick(points[23], points[20],50),
    Stick(points[20], points[24],70),
    Stick(points[24], points[21],50),
    Stick(points[24], points[22],70),
    Stick(points[24], points[26],70),
    Stick(points[24], points[27],50),
    Stick(points[24], points[28],70),
    Stick(points[24], points[25],50),
    Stick(points[24], points[23],50),
   

    Stick(points[29], points[30],100),
    Stick(points[30], points[32],100),
    Stick(points[32], points[31],100),
    Stick(points[31], points[29],100),


    Stick(points[29], points[33],70),
    Stick(points[33], points[30],70),
    Stick(points[33], points[32],70),
    Stick(points[33], points[31],70),
              
    Stick(points[34], points[35],30),              
    Stick(points[35], points[36],30),
    Stick(points[36], points[37],30),
    Stick(points[37], points[38],30),
    Stick(points[38], points[39],30),
    Stick(points[39], points[40],30),
    Stick(points[40], points[41],30),
    Stick(points[41], points[42],30),
    Stick(points[42], points[43],30),

    Stick(points[44], points[45],30),
    Stick(points[45], points[46],30),
    Stick(points[46], points[47],30),
    Stick(points[47], points[48],30),
    Stick(points[48], points[49],70),
    Stick(points[49], points[50],70),
    Stick(points[50], points[51],70),
    Stick(points[51], points[48],70),
    Stick(points[50], points[48],90),
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
        window.draw(grid);
        window.draw(lineShape);
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