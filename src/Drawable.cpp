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


void Drawable::SetupLighting() {
    
}

GLuint* Drawable::GetTextures() {
    return texture;
}
