/* 
 * File:   SkyBox.h
 * Author: adn
 *
 * Created on May 12, 2012, 11:45 PM
 */

#ifndef SKYBOX_H
#define	SKYBOX_H

#include "Drawable.h"
#include "SFML/Graphics.hpp"

class SkyBox : public GLDrawable{
public:
    SkyBox();
    SkyBox(const SkyBox& orig);
    virtual ~SkyBox();
    void init();   
    void Update(const sf::Input& input);
    bool LoadContent();
    bool setTextures(string path);
    inline virtual string getClass(){
        return "SkyBox";
    }
    
     GLDrawable* Clone();
     
    
    //void SetComponents();
    void draw();
private:
    string texture_path[6];
    GLuint skyBoxTexture[6][3]; // Storage For 3 Textures

};

#endif	/* SKYBOX_H */

