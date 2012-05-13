/* 
 * File:   Sphere.h
 * Author: adn
 *
 * Created on May 13, 2012, 3:41 PM
 */

#ifndef SPHERE_H
#define	SPHERE_H

#include <string>
#include "Drawable.h"

class Sphere : public GLDrawable{
public:
    
    Sphere();
    Sphere(sf::Vector3f position);
    Sphere(sf::Vector3f position, GLfloat radius);    
    Sphere(sf::Vector3f position, sf::Vector3f halfsize);  
    Sphere(const Sphere& orig);

    GLDrawable* Clone();

    inline virtual string getClass(){
        return "Sphere";
    }
    void init();
    void Update(const sf::Input& input);
    //bool LoadContent();
    //void WriteInstanceCreation(FILE* outfile,string name);
    
    virtual ~Sphere();

    void setRadius(GLfloat radius) {
        this->halfSize.x = radius;
        this->halfSize.y = radius;
        this->halfSize.z = radius;
    }

    GLfloat getRadius() const {
        return this->halfSize.x;
    }
    
   void setTexture(const string& path) {
        texture_path = path;
        textureEnabled = true;
        LoadContent();
    } 
   
   list<Texture> textures;
protected:
    void draw();
    inline void scale() {
        // does nothing, the box is self scaling object
    }
    
   inline void applyFaceTexture() {
        if (!textureEnabled || textures.empty()) 
            return;
        bool found = false;
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
            //if (elements::has(i->id,e)) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));
                found = true;
                break;
            //}
        }
        if (!found)
            glDisable(GL_TEXTURE_2D);
    }
private:    
    string texture_path;
    GLfloat xspeed; // X Rotation Speed
    GLfloat yspeed; // Y Rotation Speed
};

#endif	/* SPHERE_H */

