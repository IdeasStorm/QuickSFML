/* 
 * File:   Box.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 1, 2012, 11:33 PM
 */

#include <GL/glew.h>

#include "Box.h"

Box::Box() {
    init();
    my_elements = elements::All;
}

void Box::init() {
    axis_angle = false;
    rotation = 0;
    xspeed = 0;
    yspeed = 0;
    xrot = 0;
    yrot = 0;
    zrot = 0;
    this->halfSize = sf::Vector3f(1, 1, 1);
    my_elements = elements::All;
}

Box::Box(sf::Vector3f position) {
    init();
    this->position = position;
}

Box::Box(sf::Vector3f position, sf::Vector3f halfsize) {
    init();
    this->position = position;
    this->halfSize = halfsize;
}

Box::Box(sf::Vector3f position, sf::Vector3f halfsize, Element my_elements) {
    init();
    this->position = position;
    this->halfSize = halfsize;
    this->my_elements = my_elements;
}

Box::Box(const Box& orig) {

}

Box::~Box() {
}

void Box::Update(const sf::Input& input) {


    //    if (input.IsKeyDown(sf::Key::PageDown)) {
    //      z += 0.02f;
    //}

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

void Box::draw() {

    GLfloat d = halfSize.z;
    GLfloat h = halfSize.y;
    GLfloat w = halfSize.x;

    if (tag == "skyBox") {
        glDisable(GL_LIGHTING);
        glPushAttrib(GL_ENABLE_BIT);
    }else {
        glEnable(GL_LIGHTING);   
    }
    glDisable(GL_TEXTURE_2D);

    if (elements::has(my_elements, elements::Front)) {
        // Front Face
        applyFaceTexture(elements::Front);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-w, -h, d);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(w, -h, d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(w, h, d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-w, h, d);
        glEnd();
    }


    if (elements::has(my_elements, elements::Back)) {
        // Back Face
        applyFaceTexture(elements::Back);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-w, -h, -d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-w, h, -d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(w, h, -d);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(w, -h, -d);
        glEnd();
    }

    if (elements::has(my_elements, elements::Top)) {
        // Top Face
        applyFaceTexture(elements::Top);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-w, h, -d);
        glTexCoord2f(1.0f, 0.0f);
        
        glVertex3f(-w, h, d);
        glTexCoord2f(1.0f, 1.0f);
                        
        glVertex3f(w, h, d);
        glTexCoord2f(0.0f, 1.0f);
        
        glVertex3f(w, h, -d);
        glEnd();
    }

    if (elements::has(my_elements, elements::Bottom)) {
        // Bottom Face
        applyFaceTexture(elements::Bottom);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-w, -h, -d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(w, -h, -d);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(w, -h, d);
        glTexCoord2f(0.0f, 1.0f);
        
        glVertex3f(-w, -h, d);
        glEnd();
    }

    if (elements::has(my_elements, elements::Right)) {
        // Right face
        applyFaceTexture(elements::Right);
        glBegin(GL_QUADS);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(w, -h, -d);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(w, h, -d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(w, h, d);
        glTexCoord2f(0.0f, 1.0f);
        
        glVertex3f(w, -h, d);
        glEnd();
    }

    if (elements::has(my_elements, elements::Left)) {
        // Left Face
        applyFaceTexture(elements::Left);
        glBegin(GL_QUADS);
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-w, -h, -d);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-w, -h, d);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-w, h, d);
        glTexCoord2f(1.0f, 0.0f);
        
        glVertex3f(-w, h, -d);
        glEnd();
    }
    if (tag == "skyBox") {
        glPopAttrib();
    }

}

bool Box::LoadContent() {
    return true;
}

void Box::SetComponents(elements::Element elements) {
    this->my_elements = elements;
}

bool elements::has(Element elements, Element test) {
    return ((elements & test) == test);
}

bool elements::has(GLuint elements, Element test) {
    return ((elements & test) == test);
}

GLDrawable* Box::Clone() {
    Box* cloned = new Box();
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

void Box::WriteInstanceCreation(FILE* outfile, string name) {
    GLDrawable::WriteInstanceCreation(outfile, name);
    if (!texture_path.empty())
        fprintf(outfile, "%s->setTexture(\"%s\");\n", name.data(), texture_path.data());
}