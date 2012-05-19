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

class Train : public Model3d {
public:

    Train() : Model3d("train1.3ds", "./Data/Train/1/") {
        self_control = true;
        speed = 0;
        acceleration = 0;
        push_force = 0;
        mass = 1;
        brakes_factor = 0;     
        temp=position.z;
    }
    void Update(const sf::Input &input);
    virtual ~Train();
    
    float mass;
    float brakes_factor;
    float push_force;
    
    void Gas(float acc = 0.1) {
        push_force = 0.1;
    }
    
    void Restart(float acc = 0.1){
        speed = 0;
        Gas(acc);
    }
    
    void Brakes(float bf = 0.1f){
        brakes_factor = bf;
    }
    
    void StopGas(){
        push_force = 0;
    }
    
    void StopBrakes() {
        brakes_factor = 0;
    }
private:
    float speed;
    float acceleration;   
    float temp;
};

#endif	/* TRAIN_H */

