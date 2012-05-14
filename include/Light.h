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
#include "Sphere.h"
using namespace std;
using namespace sf;

class Light :  public Sphere{
public:
    bool ligthEnable ;
    Light(sf::Vector3f pos , float ang);
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
    GLfloat w;
    float angle ;
    GLfloat spot_direction[3] ;
    sf::Color diffuse;
    sf::Color ambient;
    sf::Color specular;
    

};

#endif	/* LIGHT_H */

