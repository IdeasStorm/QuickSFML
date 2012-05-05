/* 
 * File:   Drawable.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 1, 2012, 3:37 PM
 */

#include "Drawable.h"

GLDrawable::GLDrawable() {
    //ctor
    filter = 0;
}

GLDrawable::~GLDrawable() {
    //dtor
}



GLuint* GLDrawable::GetTextures() {
    return texture;
}

void GLDrawable::LoadComponents() {
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((GLDrawable*)(*i))->LoadComponents();
    }
}

bool GLDrawable::LoadContent() {
    bool Status=true;									// Status Indicator
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        Status = Status && ((GLDrawable*)(*i))->LoadContent();
    }
    return Status;
}

void GLDrawable::SetupLighting() {
    // setup lighting for each component
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((GLDrawable*)(*i))->SetupLighting();
    }
}

void GLDrawable::Draw() {
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((GLDrawable*)(*i))->Draw();
    }
}
