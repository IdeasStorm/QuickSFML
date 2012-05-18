//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
box0->position = Vector3f(23.300053,-17.960037,1.400000); 
box0->halfSize = Vector3f(45.999870,-15.800024,199.498764); 
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
box4->position = Vector3f(82.300026,6.899996,-24.100052); 
box4->halfSize = Vector3f(23.700003,5.899997,157.699890); 
box4->setRotation(0.000000,0.000000,0.000000); 
box4->tag = ""; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Box *box5 = new Box();
box5->setTexture("Data/NeHe.bmp");
box5->position = Vector3f(-37.699974,6.899996,-24.000051); 
box5->halfSize = Vector3f(23.700003,5.899997,157.699890); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Cylinder *box6 = new Cylinder();
box6->position = Vector3f(23.190052,-3.900001,-293.793488); 
box6->halfSize = Vector3f(46.499863,118.099724,21.100044); 
box6->setRotation(0.000000,0.000000,0.000000); 
box6->tag = "cave"; 
components.push_back(box6); 
//==================================================================
//========================box7=====================================
Railway *box7 = new Railway();
box7->position = Vector3f(29.800076,-0.700000,-5.199997); 
box7->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box7->setRotation(0.000000,0.000000,0.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Model3d *box8 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box8->position = Vector3f(56.199715,-8.400000,-21.830046); 
box8->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box8->setRotation(-90.000000,-0.000000,-0.000000); 
box8->tag = ""; 
components.push_back(box8); 
//==================================================================
//========================box9=====================================
Model3d *box9 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box9->position = Vector3f(-11.200372,-8.199999,-123.428688); 
box9->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box9->setRotation(90.000000,-0.000000,-0.000000); 
box9->tag = ""; 
components.push_back(box9); 
//==================================================================
//========================box10=====================================
Model3d *box10 = new Model3d("spider.obj","./Data/OBJ/");
box10->position = Vector3f(20.299677,9.799997,-124.028679); 
box10->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box10->setRotation(90.000000,0.000000,0.000000); 
box10->tag = ""; 
components.push_back(box10); 
//==================================================================
//========================box11=====================================
Box *box11 = new Box();
box11->setTexture("Data/NeHe.bmp");
box11->position = Vector3f(-60.000000,41.889923,-23.499990); 
box11->halfSize = Vector3f(1.000000,28.590017,156.300140); 
box11->setRotation(0.000000,0.000000,0.000000); 
box11->tag = ""; 
components.push_back(box11); 
//==================================================================
//========================box12=====================================
Box *box12 = new Box();
box12->setTexture("Data/NeHe.bmp");
box12->position = Vector3f(104.239998,42.189934,-22.040049); 
box12->halfSize = Vector3f(1.000000,28.890017,156.560242); 
box12->setRotation(0.000000,0.000000,0.000000); 
box12->tag = ""; 
components.push_back(box12); 
//==================================================================
//========================box13=====================================
Box *box13 = new Box();
box13->setTexture("Data/NeHe.bmp");
box13->position = Vector3f(-41.239777,27.710033,-177.130478); 
box13->halfSize = Vector3f(17.859962,14.910000,1.370000); 
box13->setRotation(0.000000,0.000000,0.000000); 
box13->tag = ""; 
components.push_back(box13); 
//==================================================================
//========================box14=====================================
Box *box14 = new Box();
box14->setTexture("Data/NeHe.bmp");
box14->position = Vector3f(87.060173,27.670036,-177.000000); 
box14->halfSize = Vector3f(18.559965,14.869987,1.300000); 
box14->setRotation(0.000000,0.000000,0.000000); 
box14->tag = ""; 
components.push_back(box14); 
//==================================================================
//========================box15=====================================
Box *box15 = new Box();
box15->setTexture("Data/NeHe.bmp");
box15->position = Vector3f(87.660164,27.800053,133.199585); 
box15->halfSize = Vector3f(18.259964,14.999969,-0.900000); 
box15->setRotation(0.000000,0.000000,0.000000); 
box15->tag = ""; 
components.push_back(box15); 
//==================================================================
//========================box16=====================================
Box *box16 = new Box();
box16->setTexture("Data/NeHe.bmp");
box16->position = Vector3f(-42.139709,27.600052,133.699554); 
box16->halfSize = Vector3f(18.859966,14.799969,-0.800000); 
box16->setRotation(0.000000,0.000000,0.000000); 
box16->tag = ""; 
components.push_back(box16); 
//==================================================================
//========================box17=====================================
Box *box17 = new Box();
box17->setTexture("Data/NeHe.bmp");
box17->position = Vector3f(22.030272,56.479958,133.649582); 
box17->halfSize = Vector3f(83.029861,14.079969,-0.850000); 
box17->setRotation(0.000000,0.000000,0.000000); 
box17->tag = ""; 
components.push_back(box17); 
//==================================================================
//========================box18=====================================
Box *box18 = new Box();
box18->setTexture("Data/NeHe.bmp");
box18->position = Vector3f(22.110172,56.860073,-177.100006); 
box18->halfSize = Vector3f(81.119926,14.259984,1.400000); 
box18->setRotation(0.000000,0.000000,0.000000); 
box18->tag = ""; 
components.push_back(box18); 
//==================================================================
//========================box19=====================================
Stairs *box19 = new Stairs(Vector3f(2.400000,2.899999,1.000000),Vector3f(1.000000,1.000000,1.000000),10);
box19->setTexture("Data/NeHe.bmp");
box19->position = Vector3f(2.400000,2.899999,1.000000); 
box19->halfSize = Vector3f(2.400000,1.000000,1.000000); 
box19->setRotation(-186.000000,0.000000,0.000000); 
box19->tag = ""; 
components.push_back(box19); 
//==================================================================
}