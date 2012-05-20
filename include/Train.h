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
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
class Train : public Model3d
{
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
        Buffer.LoadFromFile("./Data/Train/1/ALARME.WAV");
        sound.SetBuffer(Buffer);    
    }
    void Update(const sf::Input &input);
    void WriteInstanceCreation(FILE* outfile, string name){
        GLDrawable::WriteInstanceCreation(outfile,name);
    }
    string getClass(){
        return "Train";
    }
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
    sf::Sound sound;
    sf::SoundBuffer Buffer;
    
    void Run()
    {
        
     
    }

};

//
//class MyThread : public sf::Thread
//{
//private :
//    virtual void Run()
//    {
//        sf::SoundBuffer Buffer;
//        if (Buffer.LoadFromFile("./Data/Train/1/ALARME.WAV"))
//            {
//                sf::Sound sound;
//                sound.SetBuffer(Buffer);             
//                sound.Play();
//                while (sound.GetStatus() == sf::Sound::Playing)
//                    sf::Sleep(0.1f);
//            }
//    }
//};

#endif	/* TRAIN_H */

