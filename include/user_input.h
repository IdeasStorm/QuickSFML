//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================

Box *box0 = new Box();
box0->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
box0->position = Vector3f(14.300018,-0.900000,0.300002); 
box0->halfSize = Vector3f(37.599998,1.000000,114.498825); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
Light *light2  = new Light(sf::Vector3f(25,30,-200),90,true);
light2->ambient = sf::Color(1,1,1);
light2->diffuse = sf::Color(1,1,1);
light2->specular = sf::Color(0,0,0);
light2->setDirection(sf::Vector3f(0,0,1));
light2->w = 1 ;
light2->lightNum = GL_LIGHT7 ;
light2->EnableSphere = false ;
components.push_back(light2); 
//========================box2=====================================
Model *box2 = new Model("./Data/Train/1/train1.3ds");
box2->position = Vector3f(0.000000,0.200000,0.000000); 
box2->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box2->setRotation(0.000000,0.000000,0.000000); 
box2->halfSize  = sf::Vector3f(0.1,0.3,0.1);
box2->setRotation(sf::Vector3f(1,0,0),-90);
box2->tag = ""; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Model *box3 = new Model("./Data/Train/1/train1.3ds");
box3->position = Vector3f(31.700085,0.200000,0.000000); 
box3->halfSize  = sf::Vector3f(0.1,0.3,0.1);
box3->setRotation(sf::Vector3f(1,0,0),-90);
box3->tag = ""; 
components.push_back(box3); 
//==================================================================
}