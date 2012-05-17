/* 
 * File:   Railway.h
 * Author: adn
 *
 * Created on May 17, 2012, 5:57 PM
 */

#ifndef RAILWAY_H
#define	RAILWAY_H

#include "Box.h"
class Railway : public GLDrawable
{
public:
    Railway();
    Railway(sf::Vector3f position, sf::Vector3f halfsize);
    Railway(const Railway& orig);
    void init();
    virtual ~Railway();
    
    inline virtual string getClass(){
        return "Railway";
    }
    
    bool LoadContent() {
    return true;
    }
    
    void Update(const sf::Input &input){
        
    }
    
    GLDrawable* Clone() {
        Railway* cloned = new Railway();
        cloned->position = position;
        cloned->halfSize = halfSize;
        if (axis_angle)
            cloned->setRotation(rotationAxis, rotation);
        else
            cloned->setRotation(yrot, xrot, zrot);
        if (textureEnabled) {
            cloned->setTexture(texture_path);
        } else {
            cloned->texture_path = texture_path;
        }
        return cloned;
    }
    
    void WriteInstanceCreation(FILE* outfile, string name) {
    GLDrawable::WriteInstanceCreation(outfile, name);
    if (!texture_path.empty())
        fprintf(outfile, "%s->setTexture(\"%s\");\n", name.data(), texture_path.data());
    }
    
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
        texture_path = path;
        Texture tex(path);
        tex.id = elements::All;
        textures.push_back(tex);
    }
   
   inline void applyFaceTexture() {
        if (!textureEnabled || textures.empty()) 
            return;
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));                
                break;
        }
        
    }
   list<Texture> textures;
protected:
       void draw(){
           glPushMatrix();                   
           left->Draw();
           glPopMatrix();
           glPushMatrix() ;                  
           right->Draw();
           glPopMatrix();
           list<GLDrawable*>::iterator i;
           for(i=cross.begin();i!=cross.end();i++){
               glPushMatrix();                   
                GLDrawable *t = *i;
                t->Draw();
                glPopMatrix();
           }
       }
private:
    string texture_path;
    Box *left;
    Box *right;
    list<GLDrawable*> cross;
};

#endif	/* RAILWAY_H */

