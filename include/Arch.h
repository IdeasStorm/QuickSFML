/* 
 * File:   Arch.h
 * Author: mhdsyrwan
 *
 * Created on May 17, 2012, 4:25 AM
 */

#ifndef ARCH_H
#define	ARCH_H
#include "Drawable.h"

class Arch : public GLDrawable{
public:
    Arch(float r = 1) : radius(r){
        textureEnabled = true;
        halfSize = sf::Vector3f(1,1,1);
        xrot=yrot=zrot=0;
        texture_path = "Data/NeHe.bmp";
        LoadContent();
    }
    void Update(const sf::Input& input){
        
    }
    string getClass() {
        return "Arch";
    }
    
    GLDrawable *Clone();
    void draw();
    bool LoadContent();
    virtual ~Arch();
    
    Texture *texture;
    float radius;
private:
    string texture_path;
};

#endif	/* ARCH_H */

