/* 
 * File:   Arch.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 17, 2012, 4:25 AM
 */

#include <GL/glew.h>
#include <math.h>
#include "Arch.h"

Arch::~Arch() {

}

void Arch::draw() {
    if (textureEnabled) {
        glBindTexture(GL_TEXTURE_2D, texture->getPtr(filter));
        glEnable(GL_TEXTURE_2D);
    } else {
        glDisable(GL_TEXTURE_2D);
    }
    float step = 0.01f;
    const float PI = 3.14; // have more precession

    glBegin(GL_QUAD_STRIP);

    for (float angle = 0; angle < PI; angle += step) {
        float _x = radius * cos(angle);
        float _y = radius * sin(angle);
        glVertex3f(_x, _y, 0);
        glVertex3f(_x, radius, 0);

    }
    glEnd();
}

bool Arch::LoadContent() {
    if (textureEnabled)
        texture = new Texture(texture_path);
}

GLDrawable* Arch::Clone() {
    Arch * cloned = new Arch(this->radius);
    cloned->texture_path = this->texture_path;
    return cloned;
}