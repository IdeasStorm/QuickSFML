/* 
 * File:   Cylinder.cpp
 * Author: adn
 * 
 * Created on May 13, 2012, 10:06 PM
 */

#include "Cylinder.h"

Cylinder::Cylinder():Sphere(){
}

Cylinder::Cylinder(sf::Vector3f position):Sphere(position)
{
}

Cylinder::Cylinder(sf::Vector3f position, sf::Vector3f halfsize):Sphere(position,halfsize){    
}

Cylinder::Cylinder(sf::Vector3f position, GLfloat radius,GLfloat height){
    init();
    this->position = position;
    this->halfSize.x = radius;
    this->halfSize.y = height;
    this->halfSize.z = radius;
}

Cylinder::Cylinder(const Cylinder& orig) {
}

Cylinder::~Cylinder() {
}

void Cylinder::draw(){
    glPushMatrix();
    int numMajor=100;
    int numMinor=100;
    float height=this->halfSize.y*2;
    float radius=this->halfSize.x;
    
    double majorStep = height / numMajor;
    double minorStep = 2.0 * M_PI / numMinor;
    int i, j;
    double a;
    for (i = 0; i < numMajor; ++i) {
        GLfloat z0 = 0.5 * height - i * majorStep;
        GLfloat z1 = z0 - majorStep;
        if(all)
             applyTexture(); 
        else
            applyArroundTexture();
        glBegin(GL_TRIANGLE_STRIP);
        for (j = 0; j <= numMinor; ++j) {
            a = j * minorStep;
            GLfloat x = radius * cos(a);
            GLfloat y = radius * sin(a);
            
            glNormal3f(x / radius, y / radius, 0.0);
            glTexCoord2f(j / (GLfloat) numMinor, i / (GLfloat) numMajor);
            glVertex3f(x, y, z0);

            glNormal3f(x / radius, y / radius, 0.0);
            glTexCoord2f(j / (GLfloat) numMinor, (i + 1) / (GLfloat) numMajor);
            glVertex3f(x, y, z1);
        }
        glEnd();
    }    
    glPopMatrix();
}
GLDrawable* Cylinder::Clone() {
    Cylinder *cloned = new Cylinder();
    cloned->position = position;
    cloned->halfSize = halfSize;
    if (axis_angle)
        cloned->setRotation(rotationAxis, rotation);
    else
        cloned->setRotation(yrot, xrot, zrot);
    if (textureEnabled) {
        cloned->setTexture(texture_path);
    } else {
        cloned->texture_path = texture_path;
    }
    return cloned;
}