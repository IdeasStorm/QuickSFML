/* 
 * File:   Stairs.cpp
 * Author: adn
 * 
 * Created on May 8, 2012, 12:34 AM
 */

#include <GL/glew.h>

#include "Stairs.h"
#include "Box.h"
#include "glframe.h"

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
    self_control=true;
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
    
    thisCord.y = stairNum*halfSize.y*2;
    thisCord.z = stairNum*halfSize.z*2;
    int j=0;
    for(int i=0;i<stairNum;i++)
    {       
        thisSize.z-=2*halfSize.z;
        if(i<stairNum/2)
        {            
            thisCord.y-=2*halfSize.y;
            thisCord.z-=2*halfSize.z;
        }
        else
        {
            thisCord.y-=2*halfSize.y;
            thisCord.z-=2*halfSize.z;
        }
        
        box=new Box(thisCord,thisSize);        
        
        boxList.push_back(box);
    }
}

void Stairs::Update(const sf::Input& input ){
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
    
    thisCord.y = stairNum*halfSize.y*2;
    thisCord.z = stairNum*halfSize.z*2;
    int j=0;
    
    list<Box*>::iterator i;
    for (i=boxList.begin();i!=boxList.end();i++){
        GLDrawable *e = *i;
        thisSize.z-=2*halfSize.z;
                  
        thisCord.y-=2*halfSize.y;
        thisCord.z-=2*halfSize.z;
       
        //box=new Box(thisCord,thisSize);        
        e->position = thisCord;
        e->halfSize = thisSize;
        //boxList.push_back(box);
    }
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
    //glPushMatrix();
    //glRotatef(90,0,1,0);
   
    //rotate();
    list<Box*>::iterator i; 
     
    for (i=boxList.begin();i!=boxList.end();i++){        
        
        glPushMatrix();
        
        //glRotatef(90,position.x,thisCord,position.z);
        ((Box*)(*i))->Draw();
        glPopMatrix();
        //thisCord.y+=2*halfSize.y;
//        thisCord.z+=2*halfSize.z;        
//        glTranslatef(-thisCord.x,-thisCord.y,-thisCord.z);
    }
    
    //glPopMatrix();
    
}

bool Stairs::LoadContent() {            
    
    if(textureEnabled)
    {   
        Texture *tex=new Texture(texture_path);
        tex->id = elements::All;
        list<Box*>::iterator i; 
        for (i=boxList.begin();i!=boxList.end();i++){
            ((Box*)(*i))->setTexture(tex);        
        }
    }
    return true;
}

void Stairs::SetComponents() {
}


GLDrawable* Stairs::Clone() {
    Stairs* cloned = new Stairs(position,halfSize,stairNum);
    if (axis_angle)
        cloned->setRotation(rotationAxis,rotation);
    else
        cloned->setRotation(yrot,xrot,zrot);
    return cloned;
}

void Stairs::WriteInstanceCreation(FILE *outfile,string name) {
    fprintf(outfile,"Stairs *%s = new Stairs(Vector3f(%f,%f,%f),Vector3f(%f,%f,%f),%d);\n",name.data(),
            position.x,position.y,position.z,
            1.0,1.0,1.0,stairNum);
    fprintf(outfile, "%s->setTexture(\"%s\");\n", name.data(), texture_path.data());
    //halfSize.x,halfSize.y,halfSize.z
}