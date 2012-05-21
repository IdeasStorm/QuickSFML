
#include "Train.h"
void Train::Update(const sf::Input &input) {

    static sf::Clock clock;
    static bool waiting = false;
    
    acceleration = (1/mass) *(push_force - speed * brakes_factor);
    speed += acceleration;
    position.z += speed;
    
    if (position.z > 900 || position.z < -900) {
        position.z = -position.z;
        //comingSound.SetPosition(this->position);
        comingSound.Play();
        StopGas();
    }
    if (position.z < -250 && position.z > -300){
        StopGas();
        Brakes();
    }
    if (IsStopped() && !waiting){
        clock.Reset();
        alarm=false;
        waiting = true;
        printf("\n\n\n                         waiting\n");        
        
    }
    if (waiting && clock.GetElapsedTime() > waiting_time) {
        Gas();        
        waiting = false;        
        printf("                         timed out\n");
    }
    if (waiting && clock.GetElapsedTime() > waiting_time-4 && !alarm) {
        alarm=true;
            sound.SetBuffer(Buffer);             
            //sound.SetPitch(0.6);
            //sound.SetAttenuation(0.4);
            sound.SetRelativeToListener(true);
            sound.SetPosition(this->position);
            sound.SetMinDistance(100);
            sound.Play();
            //movmetnSound.SetPosition(this->position);
            movmetnSound.Play();
    }
    
    
    left->position = sf::Vector3f(-40.900002,0,position.z + 0) ;
    //right->position = sf::Vector3f(20.900002,30.399998,position.z + 345.799866); 
    GLfloat temp[] = {-40.900002,0,position.z + 0, 1};
    //GLfloat temp2[] = {20.900002,30.399998,position.z + 345.799866, 1};
    glLightfv(left->lightNum, GL_POSITION, temp);
    //glLightfv(right->lightNum, GL_POSITION, temp2);
    
  //  camera->SetOrigin(position.x+8.3,position.y+15,position.z);
}
Train::~Train() {

}