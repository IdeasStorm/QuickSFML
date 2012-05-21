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

    GLFrame *camera ;
    Light *right , *left ;
    bool Enablelight ;
    Train(bool enablelight = true ) : Model3d("train1.3ds", "./Data/Train/1/") {
        self_control = true;
        speed = 0;
        Enablelight = enablelight ;
        acceleration = 0;
        push_force = 0;
        mass = 1;
        brakes_factor = 0;
        waiting_time = 10;
        alarm = false;
        Buffer.LoadFromFile("./Data/Train/1/alarm.wav");
        sound.SetBuffer(Buffer);    
        movmetnBuffer.LoadFromFile("./Data/Train/1/metro.wav");
        movmetnSound.SetBuffer(movmetnBuffer);       
        if(!comingBuffer.LoadFromFile("./Data/Train/1/metroComing.wav"))
            abort();
        comingSound.SetBuffer(comingBuffer);           
        Light *right  = new Light(sf::Vector3f(20.900002,30.399998,position.z + 345.799866),90,true);
        right->ambient = sf::Color(1,1,1);
        right->diffuse = sf::Color(1,1,1);
        right->specular = sf::Color(0,0,0);
        right->lightNum = GL_LIGHT6;
        right->w = 1 ;
        right->EXPONENT = 200 ;
        right->setDirection(sf::Vector3f(0,0,1));
        right->ligthEnable = false ;
        right->GLInit();
        components.push_back(right);
        
        
        left  = new Light(sf::Vector3f(-40.900002,0,position.z + 0),90,true);
        left->ambient = sf::Color(1,1,1);
        left->diffuse = sf::Color(1,1,1);
        left->specular = sf::Color(0,0,0);
        left->w = 1 ;
        left->EXPONENT = 200 ;
        left->setDirection(sf::Vector3f(0,0,1));
        left->lightNum = GL_LIGHT7;
        //left->ligthEnable = false ;
        left->GLInit() ;
        components.push_back(left); 

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
    sf::Sound movmetnSound;
    sf::SoundBuffer movmetnBuffer;
    sf::Sound comingSound;
    sf::SoundBuffer comingBuffer;
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

