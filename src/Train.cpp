
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
        alarm=false;
        waiting = true;
        printf("\n\n\n                         waiting\n");
        
    }
    if (waiting && clock.GetElapsedTime() > waiting_time) {
        Gas();        
        waiting = false;
        printf("                         timed out\n");
    }
    if (waiting && clock.GetElapsedTime() > waiting_time-2 && !alarm) {
        alarm=true;
        sf::SoundBuffer Buffer;
        if (Buffer.LoadFromFile("./Data/Train/1/ALARME.WAV"))
        {
            sf::Sound sound;
            sound.SetBuffer(Buffer);             
            sound.Play();
            while (sound.GetStatus() == sf::Sound::Playing);
        }

    }

}

Train::~Train() {

}