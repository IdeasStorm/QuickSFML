/* 
 * File:   SkyBox.cpp
 * Author: adn
 * 
 * Created on May 12, 2012, 11:45 PM
 */

#include "SkyBox.h"

SkyBox::SkyBox() {
    init();
}

SkyBox::SkyBox(const SkyBox& orig) {
}

SkyBox::~SkyBox() {
}

void SkyBox::init(){
    axis_angle = false;
    rotation = 0;
    xrot=0;
    yrot=0;
    zrot=0;
    this->halfSize=sf::Vector3f(1,1,1);
}

void SkyBox::Update(const sf::Input& input)
{
}

bool SkyBox::LoadContent()
{
    sf::Image Image[6];
    bool check = true;
    check*= Image[0].LoadFromFile(texture_path[0]);
    check*= Image[1].LoadFromFile(texture_path[1]);
    check*= Image[2].LoadFromFile(texture_path[2]);
    check*= Image[3].LoadFromFile(texture_path[3]);
    check*= Image[4].LoadFromFile(texture_path[4]);
    check*= Image[5].LoadFromFile(texture_path[5]);
    
    
    if (check) {
        // TODO change this
        for(int i=0;i<6;i++)
        {
            
            glGenTextures(3, &skyBoxTexture[i][0]); // Create Three Textures

            // Create Nearest Filtered Texture
            glBindTexture(GL_TEXTURE_2D, skyBoxTexture[i][0]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexImage2D(GL_TEXTURE_2D, 0, 3, Image[i].GetWidth(), Image[i].GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Image[i].GetPixelsPtr());

            // Create Linear Filtered Texture
            glBindTexture(GL_TEXTURE_2D, skyBoxTexture[i][1]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D, 0, 3, Image[i].GetWidth(), Image[i].GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Image[i].GetPixelsPtr());

            // Create MipMapped Texture
            glBindTexture(GL_TEXTURE_2D, skyBoxTexture[i][2]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            gluBuild2DMipmaps(GL_TEXTURE_2D, 3, Image[i].GetWidth(), Image[i].GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, Image[i].GetPixelsPtr());
            return true;
        }
    }

    return false;
}

void SkyBox::draw(){
    glPushMatrix();
 
    // Reset and transform the matrix.
    glLoadIdentity();

    glPushAttrib(GL_ENABLE_BIT);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
 
    // Just in case we set all vertices to white.
    glColor4f(1,1,1,1);
 
    // Render the front quad
     glBindTexture(GL_TEXTURE_2D, skyBoxTexture[0][filter]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the left quad
      glBindTexture(GL_TEXTURE_2D, skyBoxTexture[1][filter]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
    glEnd();
 
    // Render the back quad
      glBindTexture(GL_TEXTURE_2D, skyBoxTexture[2][filter]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
 
    glEnd();
 
    // Render the right quad    
     glBindTexture(GL_TEXTURE_2D, skyBoxTexture[3][filter]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the top quad
     glBindTexture(GL_TEXTURE_2D, skyBoxTexture[4][filter]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 0); glVertex3f( -0.5f,  0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f,  0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the bottom quad
//     glBindTexture(GL_TEXTURE_2D, skyBoxTexture[5][filter]);
//    glBegin(GL_QUADS);
//        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
//        glTexCoord2f(0, 1); glVertex3f( -0.5f, -0.5f,  0.5f );
//        glTexCoord2f(1, 1); glVertex3f(  0.5f, -0.5f,  0.5f );
//        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
//    glEnd();
// 
    // Restore enable bits and matrix
    glPopAttrib();
    glPopMatrix();
    
    glEnd();
}

GLDrawable* SkyBox::Clone()
{        
}

bool SkyBox::setTextures(string path)
{
    string temp = path;
    texture_path[0] = path.append("front");
    path=temp;
    texture_path[1] = path.append("left");
    path=temp;
    texture_path[2] = path.append("back");
    path=temp;
    texture_path[3] = path.append("right");
    path=temp;
    texture_path[4] = path.append("top");
    path=temp;
    texture_path[5] = path.append("top");
    path=temp;
    for(int i=0;i<6;i++)
    {
        texture_path[i].append(".jpg");
    }
}