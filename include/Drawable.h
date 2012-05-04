/* 
 * File:   Drawable.h
 * Author: mhdsyrwan
 *
 * Created on May 1, 2012, 3:37 PM
 */

#ifndef DRAWABLE_H
#define	DRAWABLE_H
#include <SFML/Graphics.hpp>
#include "glframe.h"
#include "list"
using namespace std;
class Drawable {
public:
    Drawable();
    virtual ~Drawable();
    virtual bool LoadContent();
    virtual void Draw();
    void ApplyCamera();
    void UpdateCamera(const sf::Input &input);
    virtual void Update(const sf::Input &input)=0;
    virtual void SetupLighting();
    GLuint* GetTextures();
    void LoadComponents();

    GLuint filter; // Which Filter To Use
     GLFrame camera ;
protected:
    list<Drawable*> components;
    GLuint texture[3]; // Storage For 3 Textures
private:
};
#endif	/* DRAWABLE_H */

