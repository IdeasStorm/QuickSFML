/* 
 * File:   Box.h
 * Author: mhdsyrwan
 *
 * Created on May 1, 2012, 11:33 PM
 */

#ifndef BOX_H
#define	BOX_H
#include "Drawable.h"

class Box : public Drawable{
public:
    Box();
    Box(const Box& orig);
    
    void Update(const sf::Input& input );
    bool LoadGLTextures();
    void Draw();
    virtual ~Box();
    GLfloat height;
    GLfloat width;
    GLfloat depth;
    
private:
    float myt ;
//    GLFrame camera;
    GLfloat xrot; // X Rotation
    GLfloat yrot; // Y Rotation
    GLfloat xspeed; // X Rotation Speed
    GLfloat yspeed; // Y Rotation Speed
    GLfloat z; // Depth Into The Screen

};

#endif	/* BOX_H */

