/* 
 * File:   Light.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 4, 2012, 3:44 PM
 */

#include <GL/gl.h>

#include "Light.h"

Light::Light() {
}

Light::Light(const Light& orig) {
}

Light::~Light() {
}

void Light::SetupLighting() {
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,vec4(ambient));
    glLightfv(GL_LIGHT0,GL_AMBIENT,vec4(ambient));
    glLightfv(GL_LIGHT0,GL_AMBIENT,vec4(ambient));
    
}

GLfloat* vec4(sf::Color color){
    GLfloat *res =  {color.r,color.g,color.b,color.a};
    return res;
}