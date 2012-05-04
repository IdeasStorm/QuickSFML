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
using namespace std;
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

    bool LoadGLTextures();

    void init();
    void Update(const sf::Input& input);
    bool LoadContent();

    void Draw();
    void SetComponents(Element elements);
    virtual ~Box();

    void setDepth(GLfloat depth) {
        this->halfSize.z = depth / 2.0f;
    }

    GLfloat getDepth() const {
        return this->halfSize.z * 2;
    }

    void setWidth(GLfloat width) {
        this->halfSize.x = width / 2.0f;
    }

    GLfloat getWidth() const {
        return halfSize.x * 2;
    }

    void setHeight(GLfloat height) {
        this->halfSize.y = height / 2.0f;
    }

    GLfloat getHeight() const {
        return halfSize.y * 2;
    }
    
   void setTexture(string path) {
        texture_path = path;
        LoadContent();
    }
 
       
private:

    Vector3 position;
    Vector3 halfSize;
    Vector3 rotationAxis;
    GLfloat rotation; //  Rotation

    bool axis_angle; // rotation based on axis and angle
    
    void setAxisRotation() {
        axis_angle = true;
    }
    
    void setYawPitchRollRotation() {
        axis_angle = false;
    }
    
    // Yaw, pitch, Roll

    GLfloat xrot; // X Rotation
    GLfloat yrot; // Y Rotation
    GLfloat zrot; // Z Rotation
       
private:
    Element my_elements;
    string texture_path;
    GLfloat xspeed; // X Rotation Speed
    GLfloat yspeed; // Y Rotation Speed

};

#endif	/* BOX_H */

