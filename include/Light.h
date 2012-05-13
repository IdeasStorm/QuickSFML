/* 
 * File:   Light.h
 * Author: mhdsyrwan
 *
 * Created on May 4, 2012, 3:44 PM
 */

#ifndef LIGHT_H
#define	LIGHT_H
#include <SFML/Graphics.hpp>
#include "Drawable.h"
using namespace std;
using namespace sf;

class Light {
public:
    bool ligthEnable ;
    Light();
    Light(const Light& orig);
    void SetupLighting();
    virtual ~Light();
    void init();
    void Update(const sf::Input& input);
    bool LoadContent();
    GLDrawable* Clone();
    void draw() ;
    inline virtual string getClass(){
        return "Light";
    }
//private:
    Vector3f position;
    GLfloat w;
    sf::Color diffuse;
    sf::Color ambient;
    sf::Color specular;
    

};

#endif	/* LIGHT_H */

