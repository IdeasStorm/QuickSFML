/* 
 * File:   Box.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 1, 2012, 11:33 PM
 */

#include "Box.h"

Box::Box() {
    init();
    my_elements = elements::FrontOpened;
}

void Box::init(){
    z = -5.0f;
    xspeed = 0;
    yspeed = 0;
    xrot=0;
    yrot=0;
    depth = 2.0f;
    height = 2.0f;
    width = 2.0f;
    my_elements = elements::All;
}

Box::Box(Vector3 position){
    init();
    this->position = position;
}

Box::Box(Vector3 position, Vector3 halfsize) {
    init();
    this->position = position;
    this->halfSize = halfsize;
}

Box::Box(Vector3 position, Vector3 halfsize, Element my_elements) {
    init();
    this->position = position;
    this->halfSize = halfsize;
    this->my_elements = my_elements;
}

Box::Box(const Box& orig) {

}

Box::~Box() {
}


void Box::Update(const sf::Input& input){
    
    if (input.IsKeyDown(sf::Key::PageUp)) {
        z -= 0.02f;
    }
    if (input.IsKeyDown(sf::Key::PageDown)) {
        z += 0.02f;
    }
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
    if (input.IsKeyDown(sf::Key::O)) {
        depth += 0.1f;
    }
}

void Box::Draw(){
    glLoadIdentity(); // Reset The View
    glTranslatef(position.x,position.y,position.z);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    
    glBindTexture(GL_TEXTURE_2D, texture[filter]);
    GLfloat d = depth  / 2.0;
    GLfloat h = height / 2.0;
    GLfloat w = width  / 2.0;
    glBegin(GL_QUADS);
    
    if (elements::has(my_elements,elements::Front)) {
        // Front Face
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-w, -h, d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(w, -h, d);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(w, h, d);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-w, h, d);
    }
    
    if (elements::has(my_elements,elements::Back)) {
        // Back Face
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-w, -h, -d);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-w, h, -d);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(w, h, -d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(w, -h, -d);
    }
    
    if (elements::has(my_elements,elements::Top)) {
        // Top Face
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-w, h, -d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-w, h, d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(w, h, d);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(w, h, -d);
    }
    
    if (elements::has(my_elements,elements::Bottom)) {
        // Bottom Face
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-w, -h, -d);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(w, -h, -d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(w, -h , d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-w, -h, d);
    }
    
    if (elements::has(my_elements,elements::Right)) {
        // Right face
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(w, -h, -d);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(w, h, -d);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(w, h, d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(w, -h, d);
    }

    if (elements::has(my_elements,elements::Left)) {
        // Left Face
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-w, -h, -d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-w, -h, d);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-w, h, d);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-w, h, -d);
    }
    glEnd();
    xrot += xspeed;
    yrot += yspeed;
}

bool Box::LoadContent() {
    // Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
    sf::Image Image;
    if (Image.LoadFromFile("./Data/NeHe.bmp")) {
        // TODO change this

        glGenTextures(3, &texture[0]); // Create Three Textures

        // Create Nearest Filtered Texture
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.GetWidth(), Image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Image.GetPixelsPtr());

        // Create Linear Filtered Texture
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.GetWidth(), Image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Image.GetPixelsPtr());

        // Create MipMapped Texture
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, Image.GetWidth(), Image.GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, Image.GetPixelsPtr());
        return true;
    }

    return false;
}

void Box::SetComponents(elements::Element elements) {
    this->my_elements = elements;
}

bool elements::has(Element elements, Element test){
    return ((elements & test) == test);
}