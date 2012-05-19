/* 
 * File:   Train.h
 * Author: mhdsyrwan
 *
 * Created on May 5, 2012, 9:44 PM
 */

#ifndef TRAIN_H
#define	TRAIN_H
#include "Model3d.h"
#include "Drawable.h"
#include <sys/time.h>
#include <SFML/Audio.hpp>

class Train : public Model3d {
public:

    Train() : Model3d("train1.3ds", "./Data/Train/1/") {
        self_control = true;
        speed = 0;
        acceleration = 0;
        push_force = 0;
        mass = 1;
        brakes_factor = 0;
        waiting_time = 10;
        alarm = false;
    }
    void Update(const sf::Input &input);
    virtual ~Train();
    
    float mass;
    float brakes_factor;
    float push_force;
    
    void Gas(float acc = 0.1) {
        StopBrakes();
        push_force = acc;
    }
    
    void Restart(float acc = 0.1){
        speed = 0;
        Gas(acc);
    }
    
    void Brakes(float bf = 0.05f){
        brakes_factor = bf;
    }
    
    void StopGas(){
        push_force = 0;
    }
    
    void StopBrakes() {
        brakes_factor = 0;
    }
    
    bool IsStopped() {
        return (fabs(speed) < 0.1);
    }
    float waiting_time;
private:
    float speed;
    float acceleration;   
    bool alarm;
};

#endif	/* TRAIN_H */

