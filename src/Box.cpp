/* 
 * File:   Box.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 1, 2012, 11:33 PM
 */

#include "Box.h"

Box::Box() {
    init();
    my_elements = elements::All;
}

void Box::init(){
    axis_angle = false;
    rotation = 0;
    xspeed = 0;
    yspeed = 0;
    xrot=0;
    yrot=0;
    zrot=0;
    this->halfSize=sf::Vector3f(1,1,1);
    my_elements = elements::All;
}

Box::Box(sf::Vector3f position){
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


void Box::Update(const sf::Input& input ){
    

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

void Box::draw(){
    
    //TODO make better mechanism
    if (textureEnabled) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[filter]);
    }
    else {
        glDisable(GL_TEXTURE_2D);
    }

    GLfloat d = halfSize.z ;
    GLfloat h = halfSize.y ;
    GLfloat w = halfSize.x ;
    glBegin(GL_QUADS);
    
    if (elements::has(my_elements,elements::Front)) {
        // Front Face
        applyFaceTexture(elements::Front);
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
        applyFaceTexture(elements::Back);
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
        applyFaceTexture(elements::Top);
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
        applyFaceTexture(elements::Bottom);
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
        applyFaceTexture(elements::Right);
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
        applyFaceTexture(elements::Left);
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
}

bool Box::LoadContent() {
    // Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
    sf::Image Image;
    if (Image.LoadFromFile(texture_path)) {
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

bool elements::has(GLuint elements, Element test){
    return ((elements & test) == test);
}

GLDrawable* Box::Clone() {
    Box* cloned = new Box();
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

void Box::WriteInstanceCreation(FILE* outfile, string name){
    GLDrawable::WriteInstanceCreation(outfile, name);
    //if (textureEnabled)
        fprintf(outfile,"%s->setTexture(\"%s\");\n",name.data(),texture_path.data());
}