/* 
 * File:   Studio.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 5, 2012, 7:44 PM
 */

#include "Studio.h"

Studio::Studio() {
    currentComponent = components.end();
}

Studio::Studio(const Studio& orig) {
}

Studio::~Studio() {
}

void Studio::LoadComponents(){
    
}

void Studio::Update(const sf::Input& input){
    static bool N_was_down = false;
    static bool T_was_down = false;
    static bool eq_was_down = false;
    static bool minus_was_down = false;
    
    if (input.IsKeyDown(sf::Key::N) )  {
        N_was_down = true;
    } else if (N_was_down) {
        N_was_down = false;
        Box *box = new Box();
        box->setTexture("Data/NeHe.bmp");
        box->DisableTexture();
        box->setTexture("Data/NeHe.bmp");
        components.push_back(box);
        SetCurrentComponent(components.begin());
    }
    
    if (input.IsKeyDown(sf::Key::T) )  {
        T_was_down = true;
    } else if (T_was_down) {
        T_was_down = false;
        Box *box = new Box();
        box->setTexture("Data/NeHe.bmp");
        box->DisableTexture();
        components.push_back(box);
    }
    
    if (input.IsKeyDown(sf::Key::Subtract) )  {
        minus_was_down = true;
    } else if (minus_was_down) {
        minus_was_down = false;
        PrevComponent();
    }
    
    if (input.IsKeyDown(sf::Key::Equal) )  {
        eq_was_down = true;
    } else if (eq_was_down) {
        eq_was_down = false;
        NextComponent();
    }
    
    float s = 0.1f;
    if (input.IsKeyDown(sf::Key::LControl)) {
        s *=0.1f;
    }
    
    sf::Vector3f *field;
    if (input.IsKeyDown(sf::Key::LShift)) {
        field = &(((Box*)(*currentComponent))->halfSize);
    }else {
        field = &(((Box*)(*currentComponent))->position);
    }
    if (input.IsKeyDown(sf::Key::Right)) {
        *field += sf::Vector3f(s,0,0);
        (((Box*)(*currentComponent))->position) += sf::Vector3f(s,0,0);
    }
    if (input.IsKeyDown(sf::Key::Left)) {
        *field += sf::Vector3f(-s,0,0);
        (((Box*)(*currentComponent))->position) += sf::Vector3f(-s,0,0);
    }
    if (input.IsKeyDown(sf::Key::Up)) {
        *field += sf::Vector3f(0,0,s);
        (((Box*)(*currentComponent))->position) += sf::Vector3f(0,0,s);
    }
    if (input.IsKeyDown(sf::Key::Down)) {
        *field += sf::Vector3f(0,0,-s);
        (((Box*)(*currentComponent))->position) += sf::Vector3f(0,0,-s);
    }
    if (input.IsKeyDown(sf::Key::PageUp)) {
        *field += sf::Vector3f(0,s,0);
        (((Box*)(*currentComponent))->position) += sf::Vector3f(0,s,0);
    }
    if (input.IsKeyDown(sf::Key::PageDown)) {
        *field += sf::Vector3f(0,-s,0);
        (((Box*)(*currentComponent))->position) += sf::Vector3f(0,-s,0);
    }
    
}

void Studio::SetCurrentComponent(list<GLDrawable*>::iterator comp) {
    if (currentComponent != components.end())
        (*currentComponent)->textureEnabled = true;
    currentComponent = comp;
    (*currentComponent)->textureEnabled = false;
}

void Studio::NextComponent(){
   //if (currentComponent != components.end())
    (*currentComponent)->textureEnabled = true;
    currentComponent++;
    (*currentComponent)->textureEnabled = false;
}
void Studio::PrevComponent() {
   //if (currentComponent != components.end())
    (*currentComponent)->textureEnabled = true;
    currentComponent--;
    (*currentComponent)->textureEnabled = false;
}