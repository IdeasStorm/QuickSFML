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
class Drawable {
public:
    Drawable();
    virtual ~Drawable();
    virtual bool LoadGLTextures()=0;
    virtual void Draw()=0;
    void ApplyCamera();
    void UpdateCamera(const sf::Input &input);
    virtual void Update(const sf::Input &input)=0;
    virtual void SetupLighting();
    GLuint* GetTextures();

    GLuint filter; // Which Filter To Use
     GLFrame camera ;
protected:
    
    GLuint texture[3]; // Storage For 3 Textures
private:
};
#endif	/* DRAWABLE_H */

