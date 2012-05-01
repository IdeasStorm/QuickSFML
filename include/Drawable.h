/* 
 * File:   Drawable.h
 * Author: mhdsyrwan
 *
 * Created on May 1, 2012, 3:37 PM
 */

#ifndef DRAWABLE_H
#define	DRAWABLE_H

#include <SFML/Graphics.hpp>

class Drawable
{
    public:
        Drawable();
        virtual ~Drawable();
        virtual bool LoadGLTextures();
        virtual void Draw();
        GLuint* GetTextures();

        GLfloat	xrot;				// X Rotation
        GLfloat	yrot;				// Y Rotation
        GLfloat xspeed;				// X Rotation Speed
        GLfloat yspeed;				// Y Rotation Speed
        GLfloat	z;			// Depth Into The Screen
        GLuint	filter;				// Which Filter To Use
    protected:
        GLuint	texture[3];			// Storage For 3 Textures
    private:
};
#endif	/* DRAWABLE_H */

