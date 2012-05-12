/* 
 * File:   Box.h
 * Author: mhdsyrwan
 *
 * Created on May 1, 2012, 11:33 PM
 */

#ifndef BOX_H
#define	BOX_H
#include "Drawable.h"

using namespace std;
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
    bool has(GLuint elements,Element test);
}
using namespace elements;

class Box : public GLDrawable{
public:

    Box();
    Box(sf::Vector3f position);
    Box(sf::Vector3f position, sf::Vector3f halfsize);
    Box(sf::Vector3f position, sf::Vector3f halfsize,Element my_elements);
    Box(const Box& orig);

    GLDrawable* Clone();

    inline virtual string getClass(){
        return "Box";
    }
    void init();
    void Update(const sf::Input& input);
    bool LoadContent();
    void WriteInstanceCreation(FILE* outfile,string name);
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
    
   void setTexture(const string& path) {
        textureEnabled = true;
        Texture tex(path);
        tex.id = elements::All;
        textures.push_back(tex);
    }
 
   void setElements(Element element) {
       my_elements = element;
   }
   
   list<Texture> textures;
protected:
    void draw();
    inline void scale() {
        // does nothing, the box is self scaling object
    }
    
    inline void applyFaceTexture(Element e) {
        if (!textureEnabled || textures.empty()) 
            return;
        bool found = false;
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
            if (elements::has(i->id,e)) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));
                found = true;
                break;
            }
        }
        if (!found)
            glDisable(GL_TEXTURE_2D);
    }
private:
    Element my_elements;
    string texture_path;
    GLfloat xspeed; // X Rotation Speed
    GLfloat yspeed; // Y Rotation Speed

};

#endif	/* BOX_H */

