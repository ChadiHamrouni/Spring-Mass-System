# Spring-Mass-System
![Spring Mass Structures](https://github.com/ChadiHamrouni/Spring-Mass-System/assets/69485266/e295b348-d7c2-436f-b281-a8cded1e1f26)

### Description
* This project implements a **Verlet integration based Spring-Mass System using C++ & SFML**.
In this implementation collision is ignored since it's not the purpose of the project. 
Verlet Integration is implemented in the function **update_verlet** inside the Point class. After taking the timestep (dt) as a parameter update_verlet will update the positions of the points in the following way:
If the point is not pinned (static):
1. We calculate the current velocity **vel_x & vel_y** by subtracting the old position **old_x & old_y** from the current position **x & y**.
2. We store the current positions as old positions inside **old_x & old_y** to be used in the next frame.
3. We calculate the accelerations using F = ma.
4. We apply the Verlet equation by adding the current position to the velocities calculated in step 1 and add the acceleration calculated in step 3 and we by dt².

The full verlet equation looks like this:

**New Position = Current Position + Current Velocity + Acceleration * Dt²**

Which translates in our code to:

this->x += vel_x + acc_x * dt * dt;<br>
this->y += vel_y + acc_y * dt * dt;

5. we set the new position using the predefined function **setPosition(x, y)**

The **update_verlet** will be called in each frame to update the positions, since we setup SFML to run our window on 60 FPS it will be called 60 times per second.

### Build
* In order to run this project you need to have SFML setup on your machine.
Here's a quick tutorial: https://youtu.be/VWWSc2nqrEA.

### Notes
* While making new structures making make sure to give enough support by providing an adequate number of constriants (sticks) or the structure can either collapse, explode or behave in an unexpected way.
* The creation of structures in a static way as I did in the main is inefficient and should be replaced with dynamic allocation and freeing up memory after usage. 
