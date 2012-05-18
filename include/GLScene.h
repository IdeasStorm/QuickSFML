/* 
 * File:   GLScene.h
 * Author: mhdsyrwan
 *
 * Created on May 5, 2012, 2:08 PM
 */

#ifndef GLSCENE_H
#define	GLSCENE_H

#define TRUE true
#define FALSE false

#include <SFML/System.hpp>
#include "Drawable.h"
#include "glframe.h"
#include <stdio.h>
using namespace std;

class GLScene {
public:
    GLScene(char* title = "");
    GLScene(const GLScene& orig);

    virtual void LoadComponents();
    virtual bool LoadContent();
    int InitGL();

    virtual void Draw();
    virtual void Update(const sf::Input &input);

    virtual void SetupLighting() {

    }

    int Run();
    GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
    sf::Window window;
    bool update_child_controls;

    virtual ~GLScene();
protected:
    list<GLDrawable*> components;

    GLFrame *camera,*camera2,*camera3 ;
    GLFrame *cameraEnable ;
    bool default_lighting;
private:


    bool fullscreen; // Fullscreen Flag Set To Fullscreen Mode By Default
    bool vsync; // Turn VSYNC on/off
    bool light; // Lighting ON/OFF ( NEW )

    GLfloat xrot; // X Rotation
    GLfloat yrot; // Y Rotation
    GLfloat xspeed; // X Rotation Speed
    GLfloat yspeed; // Y Rotation Speed

    GLfloat LightAmbient[4];
    GLfloat LightDiffuse[4];
    GLfloat LightPosition[4];
    GLfloat LightSpecular[4];

    GLuint filter; // Which Filter To Use
    GLuint texture[3]; // Storage For 3 Textures

};

#endif	/* GLSCENE_H */

