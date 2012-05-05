/* 
 * File:   Drawable.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 1, 2012, 3:37 PM
 */

#include "Drawable.h"

DrawableGL::DrawableGL() {
    //ctor
    filter = 0;
}

DrawableGL::~DrawableGL() {
    //dtor
}



GLuint* DrawableGL::GetTextures() {
    return texture;
}

void DrawableGL::LoadComponents() {
    list<DrawableGL*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((DrawableGL*)(*i))->LoadComponents();
    }
}

bool DrawableGL::LoadContent() {
    bool Status=true;									// Status Indicator
    list<DrawableGL*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        Status = Status && ((DrawableGL*)(*i))->LoadContent();
    }
    return Status;
}

void DrawableGL::SetupLighting() {
    // setup lighting for each component
    list<DrawableGL*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((DrawableGL*)(*i))->SetupLighting();
    }
}

void DrawableGL::Draw() {
    list<DrawableGL*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((DrawableGL*)(*i))->Draw();
    }
}
