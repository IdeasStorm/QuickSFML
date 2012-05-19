
#include "Train.h"

void Train::Update(const sf::Input &input) {
    acceleration = (1/mass) *(push_force - speed * brakes_factor);
    speed += acceleration;
    position.z += speed;
    int ElapsedTime = Clock.GetElapsedTime();   
    if(speed==0)
        temp=position.z;
    if(ElapsedTime % 35 == 0)
    {        
        Restart(0.1);
        StopBrakes();
        position.z = temp;
    }
    if (position.z > 900 || position.z < -900) {
        position.z = -position.z;
        StopGas();
    }
    if (position.z < -50 && position.z > -200){
        StopGas();
        Brakes();
    }

}

Train::~Train() {

}