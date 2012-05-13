/* 
 * File:   Sphere.cpp
 * Author: adn
 * 
 * Created on May 13, 2012, 3:41 PM
 */

#include "Sphere.h"

Sphere::Sphere() {
     init();
}

Sphere::Sphere(sf::Vector3f position){
     init();
     this->position = position;
}

Sphere::Sphere(sf::Vector3f position, GLfloat radius){
    init();
    this->position = position;
    this->halfSize.x = radius;
    this->halfSize.y = radius;
    this->halfSize.z = radius;
}

Sphere::Sphere(sf::Vector3f position, sf::Vector3f halfsize){
    init();
    this->position = position;
    if(halfsize.x==halfsize.y==halfsize.z)
    {
        this->halfSize = halfsize;
    }
}

Sphere::Sphere(const Sphere& orig){
    
}

void Sphere::init(){
    axis_angle = false;
    rotation = 0;
    xspeed = 0;
    yspeed = 0;
    xrot=0;
    yrot=0;
    zrot=0;
    this->halfSize=sf::Vector3f(1,1,1);   
}

Sphere::~Sphere() {
}

GLDrawable* Sphere::Clone() {
    Sphere* cloned = new Sphere();
    cloned->position = position;
    cloned->halfSize = halfSize;
    if (axis_angle)
        cloned->setRotation(rotationAxis,rotation);
    else
        cloned->setRotation(yrot,xrot,zrot);
    if (textureEnabled){
        cloned->setTexture(texture_path);
    }else {
        cloned->texture_path = texture_path;
    }
    return cloned;
}


void Sphere::Update(const sf::Input& input ){

    if (input.IsKeyDown(sf::Key::Up)) {
        xspeed -= 0.01f;
    }
    if (input.IsKeyDown(sf::Key::Down)) {
        xspeed += 0.01f;
    }
    if (input.IsKeyDown(sf::Key::Right)) {
        yspeed += 0.01f;
    }
    if (input.IsKeyDown(sf::Key::Left)) {
        yspeed -= 0.01f;
    }
    xrot += xspeed;
    yrot += yspeed;
    
    rotation += xspeed;    
}

void Sphere::draw(){
    int lats=10;
    int longs=10;
    int i, j;
    glDisable(GL_TEXTURE_2D);
    for(i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);

        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++) {
            double lng = 2 * M_PI * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);

            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr0, y * zr0, z0);
            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
    
//    GLfloat d = halfSize.z ;
//    GLfloat h = halfSize.y ;
//    GLfloat w = halfSize.x ;
//    
//    glDisable(GL_TEXTURE_2D);
//    if (elements::has(my_elements,elements::Front)) {
//        // Front Face
//        applyFaceTexture(elements::Front);
//        glBegin(GL_QUADS);
//        glNormal3f(0.0f, 0.0f, 1.0f);
//        glTexCoord2f(0.0f, 0.0f);
//        glVertex3f(-w, -h, d);
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(w, -h, d);
//        glTexCoord2f(1.0f, 1.0f);
//        glVertex3f(w, h, d);
//        glTexCoord2f(0.0f, 1.0f);
//        glVertex3f(-w, h, d);
//        glEnd();
//    }
//    
//    
//    if (elements::has(my_elements,elements::Back)) {
//        // Back Face
//        applyFaceTexture(elements::Back);
//        glBegin(GL_QUADS);
//        glNormal3f(0.0f, 0.0f, -1.0f);
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(-w, -h, -d);
//        glTexCoord2f(1.0f, 1.0f);
//        glVertex3f(-w, h, -d);
//        glTexCoord2f(0.0f, 1.0f);
//        glVertex3f(w, h, -d);
//        glTexCoord2f(0.0f, 0.0f);
//        glVertex3f(w, -h, -d);
//        glEnd();
//    }
//    
//    if (elements::has(my_elements,elements::Top)) {
//        // Top Face
//        applyFaceTexture(elements::Top);
//        glBegin(GL_QUADS);
//        glNormal3f(0.0f, 1.0f, 0.0f);
//        glTexCoord2f(0.0f, 1.0f);
//        glVertex3f(-w, h, -d);
//        glTexCoord2f(0.0f, 0.0f);
//        glVertex3f(-w, h, d);
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(w, h, d);
//        glTexCoord2f(1.0f, 1.0f);
//        glVertex3f(w, h, -d);
//        glEnd();
//    }
//    
//    if (elements::has(my_elements,elements::Bottom)) {
//        // Bottom Face
//        applyFaceTexture(elements::Bottom);
//        glBegin(GL_QUADS);
//        glNormal3f(0.0f, -1.0f, 0.0f);
//        glTexCoord2f(1.0f, 1.0f);
//        glVertex3f(-w, -h, -d);
//        glTexCoord2f(0.0f, 1.0f);
//        glVertex3f(w, -h, -d);
//        glTexCoord2f(0.0f, 0.0f);
//        glVertex3f(w, -h , d);
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(-w, -h, d);
//        glEnd();
//    }
//    
//    if (elements::has(my_elements,elements::Right)) {
//        // Right face
//        applyFaceTexture(elements::Right);
//        glBegin(GL_QUADS);
//        glNormal3f(1.0f, 0.0f, 0.0f);
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(w, -h, -d);
//        glTexCoord2f(1.0f, 1.0f);
//        glVertex3f(w, h, -d);
//        glTexCoord2f(0.0f, 1.0f);
//        glVertex3f(w, h, d);
//        glTexCoord2f(0.0f, 0.0f);
//        glVertex3f(w, -h, d);
//        glEnd();
//    }
//
//    if (elements::has(my_elements,elements::Left)) {
//        // Left Face
//        applyFaceTexture(elements::Left);
//        glBegin(GL_QUADS);
//        glNormal3f(-1.0f, 0.0f, 0.0f);
//        glTexCoord2f(0.0f, 0.0f);
//        glVertex3f(-w, -h, -d);
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(-w, -h, d);
//        glTexCoord2f(1.0f, 1.0f);
//        glVertex3f(-w, h, d);
//        glTexCoord2f(0.0f, 1.0f);
//        glVertex3f(-w, h, -d);
//        glEnd();
//    }
}