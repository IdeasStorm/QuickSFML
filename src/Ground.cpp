/* 
 * File:   Ground.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 2, 2012, 8:17 PM
 */

#include <GL/gl.h>
#include <SFML/Window/Input.hpp>
#include <stdlib.h>

#include "Ground.h"

Ground::Ground() {
    rot=0;
}

Ground::Ground(const Ground& orig) {
}

Ground::~Ground() {
}

void Ground::Draw() {
 glLoadIdentity(); // Reset The View
    glTranslatef(0.0f, 0.0f, -5.0);

    glRotatef(rot, 1.0f, 0.0f, 0.0f);
    glRotatef(rot, 0.0f, 1.0f, 0.0f);

    

    glBegin(GL_QUADS);
    
    // Front Face
    glColor3f(23,5,12);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    
    glVertex3f(1.0f, -1.0f, 1.0f);
    
    glVertex3f(1.0f, 1.0f, 1.0f);
    
    glVertex3f(-1.0f, 1.0f, 1.0f);
    // Back Face
    glNormal3f(0.0f, 0.0f, -1.0f);
    
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    glVertex3f(-1.0f, 1.0f, -1.0f);
    
    glVertex3f(1.0f, 1.0f, -1.0f);
    
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Top Face
    
    glTexCoord2f(0.0f, 1.0f);
    
    glTexCoord2f(0.0f, 0.0f);
    
    glTexCoord2f(1.0f, 0.0f);
    
    glTexCoord2f(1.0f, 1.0f);
    
    // Right face
    
    
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    glVertex3f(1.0f, 1.0f, -1.0f);
    
    glVertex3f(1.0f, 1.0f, 1.0f);
    
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Left Face
    
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    glVertex3f(-1.0f, -1.0f, 1.0f);
    
    glVertex3f(-1.0f, 1.0f, 1.0f);
    
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
}

bool  Ground::LoadGLTextures() {
    return true;
}

void Ground::Update(const sf::Input& input) {
    if (input.IsKeyDown(sf::Key::A))
        rot++;
}