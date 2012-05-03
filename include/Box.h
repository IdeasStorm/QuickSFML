/* 
 * File:   Box.h
 * Author: mhdsyrwan
 *
 * Created on May 1, 2012, 11:33 PM
 */

#ifndef BOX_H
#define	BOX_H
#include "Drawable.h"
#include "core.h"
using namespace cyclone;
namespace elements {
        enum Element{
        None = 0x0,
        Top = 0x1,
        Bottom = 0x2,
        Right = 0x4,
        Left = 0x8,
        Front = 0x10,
        Back = 0x20,
        Sides = Front | Back | Left | Right,
        All = Top | Bottom | Sides,
        OpenBox = Sides | Bottom,
        FlippedOpenBox = Sides | Top,
        LeftOpened = All & (~Left),
        RightOpened = All & (~Right),
        FrontOpened = All & (~Front),
        BackOpened = All & (~Back)  
    };
    bool has(Element elements,Element test);
}
using namespace elements;
class Box : public Drawable{
public:

    Box();
    Box(Vector3 position);
    Box(Vector3 position, Vector3 halfsize);
    Box(Vector3 position, Vector3 halfsize,Element my_elements);
    Box(const Box& orig);
    void init();
    void Update(const sf::Input& input);
    bool LoadContent();
    void Draw();
    void SetComponents(Element elements);
    virtual ~Box();
    GLfloat height;
    GLfloat width;
    GLfloat depth;
    Vector3 position;
    Vector3 halfSize;
    
private:
    Element my_elements;
    GLfloat xrot; // X Rotation
    GLfloat yrot; // Y Rotation
    GLfloat xspeed; // X Rotation Speed
    GLfloat yspeed; // Y Rotation Speed
    GLfloat z; // Depth Into The Screen

};

#endif	/* BOX_H */

