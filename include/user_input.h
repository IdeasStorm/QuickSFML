//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
box0->position = Vector3f(23.300053,-17.960037,1.200000); 
box0->halfSize = Vector3f(45.999870,-15.800024,199.298752); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
//========================box1=====================================
Cylinder *box1 = new Cylinder();
box1->position = Vector3f(23.190052,-3.900001,250.906616); 
box1->halfSize = Vector3f(46.499863,118.099724,21.100044); 
box1->setRotation(0.000000,0.000000,0.000000); 
box1->tag = "cave"; 
components.push_back(box1); 
//==================================================================
//========================box2=====================================
Light *box2  = new Light(sf::Vector3f(25.500002,30.000000,-56.800018),90,true);
box2->ambient = sf::Color(1,1,1);
box2->diffuse = sf::Color(1,1,1);
box2->specular = sf::Color(0,0,0);
box2->w = 1 ;
box2->position = Vector3f(25.500002,30.000000,-56.800018); 
box2->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box2->setRotation(0.000000,38.000000,0.000000); 
box2->tag = ""; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Model3d *box3 = new Model3d("train1.3ds","./Data/Train/1/");
box3->position = Vector3f(37.100006,0.200000,97.299088); 
box3->halfSize = Vector3f(0.200000,0.200000,0.200000); 
box3->setRotation(0.000000,0.000000,0.000000); 
box3->tag = ""; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Box *box4 = new Box();
box4->setTexture("Data/NeHe.bmp");
box4->position = Vector3f(4.359997,-0.200000,17.180029); 
box4->halfSize = Vector3f(0.200000,0.400000,500.600006); 
box4->setRotation(0.000000,0.000000,0.000000); 
box4->tag = ""; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Box *box5 = new Box();
box5->setTexture("Data/NeHe.bmp");
box5->position = Vector3f(10.660002,-0.200000,16.680027); 
box5->halfSize = Vector3f(0.200000,0.400000,500.600006); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Box *box6 = new Box();
box6->setTexture("Data/NeHe.bmp");
box6->position = Vector3f(82.300026,6.899996,-24.100052); 
box6->halfSize = Vector3f(23.700003,5.899997,157.699890); 
box6->setRotation(0.000000,0.000000,0.000000); 
box6->tag = ""; 
components.push_back(box6); 
//==================================================================
//========================box7=====================================
Box *box7 = new Box();
box7->setTexture("Data/NeHe.bmp");
box7->position = Vector3f(-37.699974,6.899996,-24.000051); 
box7->halfSize = Vector3f(23.700003,5.899997,157.699890); 
box7->setRotation(0.000000,0.000000,0.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Cylinder *box8 = new Cylinder();
box8->position = Vector3f(23.190052,-3.900001,-293.793488); 
box8->halfSize = Vector3f(46.499863,118.099724,21.100044); 
box8->setRotation(0.000000,0.000000,0.000000); 
box8->tag = "cave"; 
components.push_back(box8); 
//==================================================================
//========================box9=====================================
Railway *box9 = new Railway();
box9->position = Vector3f(29.800076,-0.700000,-5.199997); 
box9->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box9->setRotation(0.000000,0.000000,0.000000); 
box9->tag = ""; 
components.push_back(box9); 
//==================================================================
//========================box10=====================================
Model3d *box10 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box10->position = Vector3f(56.199715,-8.400000,-21.830046); 
box10->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box10->setRotation(-90.000000,-0.000000,-0.000000); 
box10->tag = ""; 
components.push_back(box10); 
//==================================================================
//========================box11=====================================
Model3d *box11 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box11->position = Vector3f(-11.200372,-8.199999,-123.428688); 
box11->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box11->setRotation(90.000000,-0.000000,-0.000000); 
box11->tag = ""; 
components.push_back(box11); 
//==================================================================
//========================box12=====================================
Model3d *box12 = new Model3d("spider.obj","./Data/OBJ/");
box12->position = Vector3f(20.299677,9.799997,-124.028679); 
box12->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box12->setRotation(90.000000,0.000000,0.000000); 
box12->tag = ""; 
components.push_back(box12); 
//==================================================================
}