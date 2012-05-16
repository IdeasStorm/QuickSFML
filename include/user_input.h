//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
box0->position = Vector3f(14.300018,-0.900000,0.400002); 
box0->halfSize = Vector3f(37.599998,1.000000,200.498825); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
//========================box1=====================================
Model *box1 = new Model("./Data/Train/1/train1.3ds");
box1->position = Vector3f(-1.100000,0.200000,-0.200000); 
box1->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box1->setRotation(0.000000,-90.000000,0.000000); 
box1->tag = ""; 
components.push_back(box1); 
//==================================================================
//========================box2=====================================
Model *box2 = new Model("./Data/Train/1/train1.3ds");
box2->position = Vector3f(31.700085,0.200000,0.000000); 
box2->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box2->setRotation(0.000000,-90.000000,0.000000); 
box2->tag = ""; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Cylinder *box3 = new Cylinder();
box3->position = Vector3f(16.700027,3.889975,0.000000); 
box3->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box3->setRotation(0.000000,90.000000,0.000000); 
box3->tag = ""; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Cylinder *box4 = new Cylinder();
box4->position = Vector3f(16.700027,3.889975,40.000000); 
box4->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box4->setRotation(0.000000,90.000000,0.000000); 
box4->tag = ""; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Box *box5 = new Box();
box5->setTexture("Data/NeHe.bmp");
box5->position = Vector3f(16.800028,5.799997,20.000040); 
box5->halfSize = Vector3f(0.500000,0.900000,16.800043); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Light *box6  = new Light(sf::Vector3f(25.000000,30.000000,-200.000000),90,true);
box6->ambient = sf::Color(1,1,1);
box6->diffuse = sf::Color(1,1,1);
box6->specular = sf::Color(0,0,0);
box6->w = 1 ;
box6->position = Vector3f(25.000000,30.000000,-200.000000); 
box6->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box6->setRotation(0.000000,0.000000,0.000000); 
box6->tag = ""; 
components.push_back(box6); 
//==================================================================
//========================box7=====================================
Light *box7  = new Light(sf::Vector3f(-2.700000,87.899193,2.500000),90,true);
box7->ambient = sf::Color(1,1,1);
box7->diffuse = sf::Color(1,1,1);
box7->specular = sf::Color(0,0,0);
box7->w = 1 ;
box7->position = Vector3f(-2.700000,87.899193,2.500000); 
box7->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box7->setRotation(0.000000,0.000000,-63.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Light *box8  = new Light(sf::Vector3f(25.000000,30.000000,-200.000000),90,true);
box8->ambient = sf::Color(1,1,1);
box8->diffuse = sf::Color(1,1,1);
box8->specular = sf::Color(0,0,0);
box8->w = 1 ;
box8->position = Vector3f(25.000000,30.000000,-200.000000); 
box8->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box8->setRotation(0.000000,0.000000,0.000000); 
box8->tag = ""; 
components.push_back(box8); 
//==================================================================
//========================box9=====================================
Cylinder *box9 = new Cylinder();
box9->position = Vector3f(-0.700000,0.000000,-20.100040); 
box9->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box9->setRotation(0.000000,0.000000,0.000000); 
box9->tag = ""; 
components.push_back(box9); 
//==================================================================
//========================box10=====================================
Cylinder *box10 = new Cylinder();
box10->position = Vector3f(-20.080036,22.580055,2.370000); 
box10->halfSize = Vector3f(7.399995,14.400019,2.899999); 
box10->setRotation(0.000000,110.000000,0.000000); 
box10->tag = ""; 
components.push_back(box10); 
//==================================================================
}