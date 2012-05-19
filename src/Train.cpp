
#include "Train.h"

void Train::Update(const sf::Input &input) {
    static sf::Clock clock;
    static bool waiting = false;
    
    acceleration = (1/mass) *(push_force - speed * brakes_factor);
    speed += acceleration;
    position.z += speed;
    
    if (position.z > 900 || position.z < -900) {
        position.z = -position.z;
        StopGas();
    }
    if (position.z < -150 && position.z > -200){
        StopGas();
        Brakes();
    }
    if (IsStopped() && !waiting){
        clock.Reset();
        waiting = true;
        printf("\n\n\n                         waiting\n");
    }
    if (waiting && clock.GetElapsedTime() > waiting_time) {
        Gas();
        waiting = false;
        printf("                         timed out\n");
    }

}

Train::~Train() {

}