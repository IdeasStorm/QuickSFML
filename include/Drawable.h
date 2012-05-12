/* 
 * File:   Drawable.h
 * Author: mhdsyrwan
 *
 * Created on May 1, 2012, 3:37 PM
 */

#ifndef DRAWABLE_H
#define	DRAWABLE_H
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

class Texture {
private:
    GLuint texture[3];
    string filename;
public:
    GLuint id;
    GLuint getPtr(int mode) {
        if (mode < 3 )
            return texture[mode];
        else {
            printf("Warning : Wrong texture mode");
            return -1;
        }
    }
    Texture(const string &texture_path) : filename(texture_path){
        if (!LoadContent())
            printf("Warning : Texture not loaded");
    }
    
    inline bool LoadContent() {
        // Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
        sf::Image Image;
        if (Image.LoadFromFile(filename)) {
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
};

class GLDrawable {
public:
    GLDrawable();
    virtual ~GLDrawable();

    virtual bool LoadContent();
    void Draw();

    virtual void Update(const sf::Input &input) = 0;
    virtual void GLInit();
    GLuint* GetTextures();
    virtual void LoadComponents();
    bool textureEnabled;
    GLuint filter; // Which Filter To Use
    virtual string getClass() = 0;

    virtual void DisableTexture() {
        textureEnabled = false;
    }

    virtual void WriteInstanceCreation(FILE* outfile, string name);

    virtual GLDrawable* Clone() = 0;

    sf::Vector3f position;
    sf::Vector3f halfSize;

    void setRotation(sf::Vector3f axis, GLfloat rotation) {
        axis_angle = true;
        rotationAxis = axis;
        this->rotation = rotation;
    }

    void setRotation(GLfloat yaw, GLfloat pitch, GLfloat roll) {
        axis_angle = false;
        xrot = pitch;
        yrot = yaw;
        zrot = roll;
    }

    void setAxisRotation() {
        axis_angle = true;
    }

    void setYawPitchRollRotation() {
        axis_angle = false;
    }

    GLfloat xrot; // X Rotation
    GLfloat yrot; // Y Rotation
    GLfloat zrot; // Z Rotation

    bool self_control;

    string tag;
protected:
    list<GLDrawable*> components;
    GLuint texture[3]; // Storage For 3 Textures

    sf::Vector3f rotationAxis;
    GLfloat rotation; //  Rotation
    bool axis_angle; // rotation based on axis and angle       
    // overridable internal helpers 

    virtual void scale();
    virtual void translate();
    virtual void rotate();
    virtual void draw() = 0;
private:
};
#endif	/* DRAWABLE_H */

