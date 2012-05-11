/* 
 * File:   Light.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 4, 2012, 3:44 PM
 */

#include <GL/gl.h>

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
    ligthEnable = true ;
}

Light::Light(const Light& orig) {
}

Light::~Light() {
}

void Light::SetupLighting() {
    
    if (ligthEnable)
    {
        glEnable(GL_LIGHT0);
        GLfloat temp[]={position.x,position.y,position.z,1};
        glLightfv(GL_LIGHT0,GL_POSITION,temp);
        glLightfv(GL_LIGHT0,GL_AMBIENT,vec4(ambient));
        glLightfv(GL_LIGHT0,GL_DIFFUSE,vec4(diffuse));
        glLightfv(GL_LIGHT0,GL_SPECULAR,vec4(specular));
        GLfloat spot_direction[] = { 0.0 , 0.0 , 0.0 };
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
        
        GLfloat colours [] = { 1.0, 1.0, 1.0, 1.0 };
        glMaterialf(GL_FRONT_AND_BACK, GL_EMISSION,colours ) ; 
        glColorMaterial ( GL_FRONT_AND_BACK, GL_SPECULAR ) ; 
        glEnable ( GL_COLOR_MATERIAL ) ; 
        glColor3f(1.0, 1.0, 1.0);
        glDisable(GL_COLOR_MATERIAL);

    }else
        glDisable(GL_LIGHT0);
    
}

