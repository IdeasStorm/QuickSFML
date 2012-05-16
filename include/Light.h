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

class Light :  public GLDrawable{
public:
    bool ligthEnable ;
    Light();
    Light(sf::Vector3f pos , float ang,bool EnableSphere);
    Light(const Light& orig);
    void GLInit();
    virtual ~Light();
    void init();
    void setDirection(sf::Vector3f);
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
    GLenum lightNum;
    //static GLenum lightNum = GL_LIGHT0;
    GLfloat spot_direction[3] ;
    sf::Color diffuse;
    sf::Color ambient;
    sf::Color specular;
    bool EnableSphere ;
    Sphere *sphere ;

};

#endif	/* LIGHT_H */

