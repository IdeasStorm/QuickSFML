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
using namespace std;

class GLDrawable {
public:
    GLDrawable();
    virtual ~GLDrawable();

    virtual bool LoadContent();
    void Draw();

    virtual void Update(const sf::Input &input) =0;
    virtual void GLInit();
    GLuint* GetTextures();
    virtual void LoadComponents();
    bool textureEnabled;
    GLuint filter; // Which Filter To Use
    virtual void DisableTexture() {
        textureEnabled = false;
    }
    
   sf::Vector3f position;
   sf::Vector3f halfSize;
   
   void setRotation(sf::Vector3f axis, GLfloat rotation) {
       axis_angle = true;
       rotationAxis  = axis;
       this->rotation = rotation;
   }
   
   void setRotation(GLfloat yaw,GLfloat pitch,GLfloat roll){
       axis_angle = false;
       xrot  = pitch;
       yrot  = yaw;
       zrot  = roll;
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

