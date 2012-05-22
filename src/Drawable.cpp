 /* 
 * File:   Drawable.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 1, 2012, 3:37 PM
 */

#include <GL/glew.h>

#include "Drawable.h"

GLDrawable::GLDrawable() {
    //ctor
    filter = 0;
    textureEnabled = false;
    axis_angle = false;
    rotation = 0;
    position.x = 0 ;
    position.y = 0 ;
    position.z = 0 ;
    xrot=0;
    yrot=0;
    zrot=0;
    halfSize=sf::Vector3f(1,1,1);
    self_control = false;
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

void GLDrawable::GLInit() {
    // setup lighting for each component
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((GLDrawable*)(*i))->GLInit();
    }
}

void GLDrawable::Draw() {
    
    translate();
    rotate();
    scale();
    glEnable(GL_COLOR_MATERIAL);
    float specular[4] = {1,1,1,1};
    float emission[4] = {0,0,0,1};
    glColor4f(1,1,1,1);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glDisable(GL_TEXTURE_2D);
    draw();
    // end of user draw logic
    if (components.empty())
        return;
    list<GLDrawable*>::iterator i;
    
    for (i=components.begin();i!=components.end();i++){
        ((GLDrawable*)(*i))->Draw();
    }
}

void GLDrawable::scale() {
    glScalef(halfSize.x,halfSize.y,halfSize.z);
}

void GLDrawable::translate() {
    glTranslatef(position.x,position.y,position.z);
}

void GLDrawable::rotate() {
    if (axis_angle) {
        glRotatef(rotation, rotationAxis.x,rotationAxis.y,rotationAxis.z);
    } else {
        glRotatef(xrot,1,0,0);
        glRotatef(yrot,0,1,0);
        glRotatef(zrot,0,0,1);
    }
}

void GLDrawable::WriteInstanceCreation(FILE* outfile,string name) {
    fprintf(outfile,"%s *%s = new %s();\n",this->getClass().data(),name.data(),this->getClass().data());
}