/* 
 * File:   Studio.h
 * Author: mhdsyrwan
 *
 * Created on May 5, 2012, 7:44 PM
 */

#ifndef STUDIO_H
#define	STUDIO_H
#include <SFML/Graphics.hpp>
#include "GLScene.h"
#include "Box.h"
#include "Light.h"
#include "Train.h"
#include <iostream>
#include <fstream>

using namespace std;

class Studio : public GLScene {
public:
    Studio();
    Studio(const Studio& orig);
    void Update(const sf::Input& input);
    void LoadComponents();
    bool LoadContent();
    void WriteCode();
    virtual ~Studio();
    
    void SetCurrentComponent(list<GLDrawable*>::iterator);
    void NextComponent();
    void PrevComponent();
    void ProcessComponent(GLDrawable *component);
    list<GLDrawable*>::iterator currentComponent;
private:
    Train *train ;
    Light *light ;
    Texture *tex_wall_noised;
    Texture *tex_wall_brown;
    Texture *tex_default;
    

};

#endif	/* STUDIO_H */

