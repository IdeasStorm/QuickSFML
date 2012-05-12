/* 
 * File:   Stairs.h
 * Author: adn
 *
 * Created on May 8, 2012, 12:34 AM
 */

#ifndef STAIRS_H
#define	STAIRS_H

/*
 * Draw a staris class 
 * stairNum is the number of staris
 * half size is the size of each stair
 */


#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Box.h"
#include <list>
using namespace std;

class Stairs : public GLDrawable
{
public:
    Stairs();
    Stairs(sf::Vector3f position);
    Stairs(sf::Vector3f position, sf::Vector3f halfsize);  
    Stairs(sf::Vector3f position, sf::Vector3f halfsize,int stairNum);  
    Stairs(const Stairs& orig);    
    virtual ~Stairs();
    
    GLDrawable* Clone();
    void init();
    void initBoxes();
    void Update(const sf::Input& input);
    bool LoadContent();

    void SetComponents();
   
    inline static string getClass(){
        return "Stairs";
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
    
   void setTexture(string path) {
        textureEnabled = true;
        texture_path = path;
        LoadContent();
    }
 
protected:
    void draw();
    
private:
    int stairNum;   
    string texture_path;
    list<Box*> boxList;
};

#endif	/* STAIRS_H */

