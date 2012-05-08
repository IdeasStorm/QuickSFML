/* 
 * File:   Stairs.cpp
 * Author: adn
 * 
 * Created on May 8, 2012, 12:34 AM
 */

#include "Stairs.h"
#include "Box.h"

Stairs::Stairs() {
    init();
}

Stairs::Stairs(sf::Vector3f position){    
    init();
    this->position = position;    
    initBoxes();
}

Stairs::Stairs(sf::Vector3f position, sf::Vector3f halfsize){
    init();
    this->position = position;
    this->halfSize = halfsize;
    initBoxes();
}

Stairs::Stairs(sf::Vector3f position, sf::Vector3f halfsize, int stairNum)
{
    init();
    this->position = position;
    this->halfSize = halfsize;
    this->stairNum = stairNum;
    initBoxes();
}

Stairs::Stairs(const Stairs& orig){
    
}


Stairs::~Stairs() {
}


void Stairs::init(){
    axis_angle = false;
    rotation = 0;
    xrot=0;
    yrot=0;
    zrot=0;
    textureEnabled = false;
    stairNum = 1;
    this->halfSize=sf::Vector3f(1,1,1);        
}


void Stairs::initBoxes()
{
    Box * box;
    
    sf::Vector3f thisSize;
    sf::Vector3f thisCord;
    
    thisSize.x=halfSize.x;
    thisSize.y=halfSize.y;
    thisSize.z=halfSize.z;    
    
    thisCord.x=position.x;
    thisCord.y=position.y;
    thisCord.z=position.z;
    
    thisSize.z = stairNum*halfSize.z*2;
    
    for(int i=0;i<stairNum;i++)
    {              
        thisSize.z-=2*halfSize.z;
        
        thisCord.y+=2*halfSize.y;
        thisCord.z+=2*halfSize.z;
        
        box=new Box(thisCord,thisSize);        
        boxList.push_back(box);
    }
}

void Stairs::Update(const sf::Input& input ){
    
}

void Stairs::draw(){
   
    if (textureEnabled) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[filter]);
    }
    else {
        glDisable(GL_TEXTURE_2D);
    }

    GLfloat d = halfSize.z ;
    GLfloat h = halfSize.y ;
    GLfloat w = halfSize.x ;
    
    sf::Vector3f thisSize;
    sf::Vector3f thisCord;
    
    thisSize.x=halfSize.x;
    thisSize.y=halfSize.y;
    thisSize.z=halfSize.z;    
    
    thisCord.x=position.x;
    thisCord.y=position.y;
    thisCord.z=position.z;
    
   
    list<Box*>::iterator i; 
    for (i=boxList.begin();i!=boxList.end();i++){
        ((Box*)(*i))->Draw();
        thisCord.y+=2*halfSize.y;
        thisCord.z+=2*halfSize.z;        
        glTranslatef(-thisCord.x,-thisCord.y,-thisCord.z);
    }
    
}

bool Stairs::LoadContent() {
    list<Box*>::iterator i; 
    for (i=boxList.begin();i!=boxList.end();i++){
        ((Box*)(*i))->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");        
    }
    
    return true;
}

void Stairs::SetComponents() {
}
