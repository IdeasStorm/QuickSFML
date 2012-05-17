/* 
 * File:   Railway.cpp
 * Author: adn
 * 
 * Created on May 17, 2012, 5:57 PM
 */

#include "Railway.h"

Railway::Railway() {
    init();
    int n = this->halfSize.z;
    GLfloat x,y,z,sx,sy,sz;
    x=position.x;
    y=position.y;
    z=position.z;
    sx=this->halfSize.x;
    sy=this->halfSize.y;
    sz=this->halfSize.z;
    
    left = new Box(sf::Vector3f (x,y,z),sf::Vector3f (sx/10,sy,sz));
    left->setTexture("./Data/Wall/ironforrail.jpg");
    right = new Box(sf::Vector3f (x+sx,y,z),sf::Vector3f (sx/10,sy,sz));
    right->setTexture("./Data/Wall/ironforrail.jpg");
     int j=0;
    for(int i=0;i<n;i++)
    {
        Box *temp;
       
        if(i<(n/2))
            temp=new Box(sf::Vector3f (x+(sx/2),y-sy,z-i),sf::Vector3f (sx,sy,0.05));          
        else
        { 
            temp=new Box(sf::Vector3f (x+(sx/2),y-sy,z+i),sf::Vector3f (sx,sy,0.05));
            j++;
        }
       temp->setTexture("./Data/Wall/woodenForrail.jpg");
       cross.push_back(temp);
    }
}

Railway::Railway(sf::Vector3f position, sf::Vector3f halfsize) {
    init();
    this->position = position;
    this->halfSize = halfsize;
    int n = halfsize.z;
    
    GLfloat x,y,z,sx,sy,sz;
    x=position.x;
    y=position.y;
    z=position.z;
    sx=halfsize.x;
    sy=halfsize.y;
    sz=halfsize.z;
            
    left = new Box(sf::Vector3f (x,y,z),sf::Vector3f (sx/10,sy,sz));
    left->setTexture("./Data/Wall/ironforrail.jpg");
    right = new Box(sf::Vector3f (x+sx,y,z),sf::Vector3f (sx/10,sy,sz));
    right->setTexture("./Data/Wall/ironforrail.jpg");
     int j=0;
    for(int i=0;i<n;i++)
    {
        Box *temp;
       
        if(i<(n/2))
            temp=new Box(sf::Vector3f (x+(sx/2),y-sy,z-i),sf::Vector3f (sx,sy,0.05));          
        else
        { 
            temp=new Box(sf::Vector3f (x+(sx/2),y-sy,z+i),sf::Vector3f (sx,sy,0.05));
            j++;
        }
       temp->setTexture("./Data/Wall/woodenForrail.jpg");
       cross.push_back(temp);
    }
}

Railway::Railway(const Railway& orig) {
}

Railway::~Railway() {
}

void Railway::init(){    
    rotation = 0;    
    xrot = 0;
    yrot = 0;
    zrot = 0;    
    this->halfSize = sf::Vector3f(1, 1, 1);   
}

void Railway::Update(const sf::Input &input)
{
    if(thereIsEdit())
    {        
        int n = halfSize.z;

        GLfloat x,y,z,sx,sy,sz;
        x=position.x;
        y=position.y;
        z=position.z;
        sx=halfSize.x;
        sy=halfSize.y;
        sz=halfSize.z;

        left = new Box(sf::Vector3f (x,y,z),sf::Vector3f (sx/10,sy,sz));
        left->setTexture("./Data/Wall/ironforrail.jpg");
        right = new Box(sf::Vector3f (x+sx,y,z),sf::Vector3f (sx/10,sy,sz));
        right->setTexture("./Data/Wall/ironforrail.jpg");
        int j=0;
        
        list<GLDrawable*>::iterator i;
        for(i=cross.begin();i!=cross.end();i++){        
            delete *i;
        }    
        cross.clear();
        for(int i=0;i<n;i++)
        {
            Box *temp;

            if(i<(n/2))
                temp=new Box(sf::Vector3f (x+(sx/2),y-sy,z-i),sf::Vector3f (sx,sy,0.05));          
            else
            { 
                temp=new Box(sf::Vector3f (x+(sx/2),y-sy,z+i),sf::Vector3f (sx,sy,0.05));
                j++;
            }
            temp->setTexture("./Data/Wall/woodenForrail.jpg");
            cross.push_back(temp);
        }
    }    
}