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
    virtual void Draw();

    virtual void Update(const sf::Input &input)=0;
    virtual void SetupLighting();
    GLuint* GetTextures();
    virtual void LoadComponents();

    GLuint filter; // Which Filter To Use
protected:
    list<GLDrawable*> components;
    GLuint texture[3]; // Storage For 3 Textures
private:
};
#endif	/* DRAWABLE_H */

