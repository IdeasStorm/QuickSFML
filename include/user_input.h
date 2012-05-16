//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
box0->position = Vector3f(18.600035,-0.900000,-0.400000); 
box0->halfSize = Vector3f(33.700058,1.000000,200.098801); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
//========================box1=====================================
Model *box1 = new Model("./Data/Train/1/train1.3ds");
box1->position = Vector3f(4.099997,0.200000,1.600000); 
box1->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box1->setRotation(0.000000,-90.000000,180.000000); 
box1->tag = ""; 
components.push_back(box1); 
//==================================================================
//========================box2=====================================
Cylinder *box2 = new Cylinder();
box2->position = Vector3f(21.800121,3.889975,3.999998); 
box2->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box2->setRotation(0.000000,90.000000,0.000000); 
box2->tag = ""; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Cylinder *box3 = new Cylinder();
box3->position = Vector3f(22.300123,3.889975,43.699944); 
box3->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box3->setRotation(0.000000,90.000000,0.000000); 
box3->tag = ""; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Box *box4 = new Box();
box4->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
box4->position = Vector3f(22.100126,5.799997,23.800055); 
box4->halfSize = Vector3f(0.700000,0.900000,16.800043); 
box4->setRotation(0.000000,0.000000,0.000000); 
box4->tag = ""; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Cylinder *box5 = new Cylinder();
box5->position = Vector3f(18.190033,12.700010,248.706482); 
box5->halfSize = Vector3f(33.800056,100.000000,2.999999); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Light *box6  = new Light(sf::Vector3f(25.300001,30.000000,-200.000000),90,true);
box6->ambient = sf::Color(1,1,1);
box6->diffuse = sf::Color(1,1,1);
box6->specular = sf::Color(0,0,0);
box6->w = 1 ;
box6->position = Vector3f(25.300001,30.000000,-200.000000); 
box6->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box6->setRotation(0.000000,0.000000,0.000000); 
box6->tag = ""; 
components.push_back(box6); 
//==================================================================
//========================box7=====================================
Model *box7 = new Model("./Data/Train/1/train1.3ds");
box7->position = Vector3f(36.200020,0.200000,1.200000); 
box7->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box7->setRotation(0.000000,-90.000000,0.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Light *box8  = new Light(sf::Vector3f(27.500010,30.000000,-200.500031),90,true);
box8->ambient = sf::Color(1,1,1);
box8->diffuse = sf::Color(1,1,1);
box8->specular = sf::Color(0,0,0);
box8->w = 1 ;
box8->position = Vector3f(27.500010,30.000000,-200.500031); 
box8->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box8->setRotation(0.000000,0.000000,0.000000); 
box8->tag = ""; 
components.push_back(box8); 
//==================================================================
//========================box9=====================================
Light *box9  = new Light(sf::Vector3f(26.600006,30.000000,-200.000000),90,true);
box9->ambient = sf::Color(1,1,1);
box9->diffuse = sf::Color(1,1,1);
box9->specular = sf::Color(0,0,0);
box9->w = 1 ;
box9->position = Vector3f(26.600006,30.000000,-200.000000); 
box9->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box9->setRotation(0.000000,0.000000,0.000000); 
box9->tag = ""; 
components.push_back(box9); 
//==================================================================
}