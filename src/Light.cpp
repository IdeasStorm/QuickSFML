/* 
 * File:   Light.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 4, 2012, 3:44 PM
 */


#include "Light.h"

GLfloat* vec4(sf::Color color){
    GLfloat* res = new GLfloat[4];
    res[0] = color.r;
    res[1] = color.g;
    res[2] = color.b;
    res[3] = color.a;
    return res;
}

Light::Light() {
}

Light::Light(const Light& orig) {
}

Light::~Light() {
}

void Light::SetupLighting() {
    
    glEnable(GL_LIGHT0);
    GLfloat temp[]={position.x,position.y,position.z,1};
    glLightfv(GL_LIGHT0,GL_POSITION,temp);
    glLightfv(GL_LIGHT0,GL_AMBIENT,vec4(ambient));
    glLightfv(GL_LIGHT0,GL_DIFFUSE,vec4(diffuse));
    glLightfv(GL_LIGHT0,GL_SPECULAR,vec4(specular));
    
}

