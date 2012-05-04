/* 
 * File:   Drawable.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 1, 2012, 3:37 PM
 */

#include "Drawable.h"

Drawable::Drawable() {
    //ctor
    filter = 0;
}

Drawable::~Drawable() {
    //dtor
}



GLuint* Drawable::GetTextures() {
    return texture;
}

void Drawable::LoadComponents() {
    list<Drawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((Drawable*)(*i))->LoadComponents();
    }
}

bool Drawable::LoadContent() {
    bool Status=true;									// Status Indicator
    list<Drawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        Status = Status && ((Drawable*)(*i))->LoadContent();
    }
    return Status;
}

void Drawable::SetupLighting() {
    // setup lighting for each component
    list<Drawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((Drawable*)(*i))->SetupLighting();
    }
}

void Drawable::Draw() {
    list<Drawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((Drawable*)(*i))->Draw();
    }
}
