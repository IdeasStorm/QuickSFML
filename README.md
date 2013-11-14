What is QuickSFML
=================
QuickSFML is a component-based SFML Application Model for OpenGL Apps, you can fork and build ,quickly, your SFML app.

Repo Contents
=============
this repo includes 
- Component-based Application Model
- A Demo App "just a simple metro station" built on it

Features
========
- Fully OOP 
- Drawable class to inherit from
- Any Drawable can have child components
- Scene class to organize your components
- Assimp Model Loader, provided as Model3d class that you can use by simply passing model file path.
- A Light Class (not fully implemented)
- A Camera Class integerated into the scene (original code of the caner taken from nehe tutorial) 
- Remember that all amazing features of SFML is available.

State
=====
Pre-Alpha

Requirements
============

- assimp 3d model loader

```sh
wget http://downloads.sourceforge.net/project/assimp/assimp-2.0/assimp--2.0.863-sdk.zip?r=http%3A%2F%2Fassimp.sourceforge.net%2Fmain_downloads.html&ts=1337526195&use_mirror=garr
tar xvfz assimp--2.0.863-sdk.zip
cd assimp--2.0.863-sdk
sudo apt-get cmake libboost-all-dev
sudo make install
```

- sfml
you can either install it from repo `sudo apt-get install libsfml-dev` or you can download the source and compile it. see http://sfml-dev.org


Quick Start Guide
=================
- create a new class derived from class `GLScene`
- override `LoadComponents()` method and call the base at the end of it
- override `Update(input)` to set your Update logic (using keyboard+mouse)
- run your instance in `main.cpp`


```cpp
  class MyClass : public GLScene {
    void LoadComponents(){
      //TODO Load your components
      MyComp comp;
      components.push_back(comp);
    }

    void Update(const sf::Input &input) {
      // TOOD add your update logic
    }
  }
```

```cpp
  int main() {
    MyClass instance(args);
    return instance.Run();
  }
```

Implementing Components
========================
```cpp
#ifndef TRAIN_H
#define        TRAIN_H
#include "Model3d.h"
#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Train : public Model3d
{
public:

    GLFrame *camera ;
    Light *light ;
    bool Enablelight ;
    
    Train(bool enablelight = true ) : Model3d("metro.3DS", "./Data/Train/1/") {
        self_control = true;
        speed = 0;
        camera = NULL ;
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
        
        light  = new Light(sf::Vector3f(-40.900002,40,position.z + 50),45,false);
        light->w = 0 ;
        light->EXPONENT = 1 ;
        light->setDirection(sf::Vector3f(0,0,1));
        light->lightNum = GL_LIGHT7;
        //left->ligthEnable = false ;
        components.push_back(light); 
        user_controlled = false;
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
    bool user_controlled;
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
```

Imprtant Notes
==============
- to make use of your Update() method, you should set "self_control" as true for your Drawable Component, in additon of setting "update_child_controls" as true in your scene/parent component

Known Bugs
==========
- sometimes the executable won't run because of a problem in openal library (if you are using sound)

TODO List
=========
- Cleaning 
- organizing files
- adding some gets/sets instead of public members

Thanks To
=========
- The Amazing SFML
- Assimp Model Loader
- Nehe Tuturials
