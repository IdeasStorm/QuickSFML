/* 
 * File:   Cylinder.h
 * Author: adn
 *
 * Created on May 13, 2012, 10:06 PM
 */

#ifndef CYLINDER_H
#define	CYLINDER_H
#include "Sphere.h"

class Cylinder : public Sphere{
public:
    Cylinder();
    Cylinder(sf::Vector3f position);    
    Cylinder(sf::Vector3f position, sf::Vector3f halfsize);
    Cylinder(sf::Vector3f position, GLfloat radius,GLfloat height);    
    Cylinder(const Cylinder& orig);
    
    inline virtual string getClass(){
        return "Cylinder";
    }
    
    
    void setTexture(const string& path) {
        texture_path = path;
        textureEnabled = true;
        LoadContent();
        Texture tex(path);  
        tex.id=0;
        all=true;
        textures.push_back(tex);
    } 
    
    void setTopTexture(const string& path) {
        texture_path = path;
        textureEnabled = true;
        LoadContent();
        Texture tex(path);  
        tex.id=1;
        textures.push_back(tex);
    } 
    
    void setBottomTexture(const string& path) {
        texture_path = path;
        textureEnabled = true;
        LoadContent();
        Texture tex(path);  
        tex.id=2;
        textures.push_back(tex);
    } 
    
    void setArroundTexture(const string& path) {
        texture_path = path;
        textureEnabled = true;
        LoadContent();
        Texture tex(path);  
        tex.id=3;
        textures.push_back(tex);
    } 
    
    inline void applyTexture() {
        if (!textureEnabled || textures.empty()) 
            return;
        bool found = false;
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
            if(i->id == 0){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));
                break;
            }
        }
    }
    
    inline void applyTopTexture() {
        if (!textureEnabled || textures.empty()) 
            return;
        bool found = false;
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
            if(i->id == 1){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));
                break;
            }
        }
    }
    
    inline void applyBottomTexture() {
        if (!textureEnabled || textures.empty()) 
            return;        
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
            if(i->id == 2){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));
                break;
            }
        }
    }
    
    inline void applyArroundTexture() {
        if (!textureEnabled || textures.empty()) 
            return;
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
            if(i->id == 3){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));
                break;
            }
        }
    }
    
    
    virtual ~Cylinder();
    void draw();    
private:
    string texture_path;
    bool all;
};

#endif	/* CYLINDER_H */

