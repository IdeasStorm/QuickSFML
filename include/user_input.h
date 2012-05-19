//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h"
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
box0->position = Vector3f(23.600054,-17.960037,-5.099939); 
box0->halfSize = Vector3f(48.899826,-15.800024,484.998688); 
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
Light *box2  = new Light(sf::Vector3f(25.500002,30.000000,-56.500023),90,true);
box2->ambient = sf::Color(1,1,1);
box2->diffuse = sf::Color(1,1,1);
box2->specular = sf::Color(0,0,0);
box2->w = 1 ;
box2->position = Vector3f(25.500002,30.000000,-56.500023); 
box2->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box2->setRotation(0.000000,38.000000,0.000000); 
box2->tag = ""; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Train *box3 = new Train;
box3->position = Vector3f(37.100006,0.200000,96.199089); 
box3->halfSize = Vector3f(0.200000,0.200000,0.200000); 
box3->setRotation(0.000000,0.000000,0.000000); 
box3->Gas();
box3->tag = "record"; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Box *box4 = new Box();
box4->setTexture("Data/NeHe.bmp");
box4->position = Vector3f(133.700241,6.899996,-22.300045); 
box4->halfSize = Vector3f(63.999985,5.899997,156.799835); 
box4->setRotation(0.000000,0.000000,0.000000); 
box4->tag = ""; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Box *box5 = new Box();
box5->setTexture("Data/NeHe.bmp");
box5->position = Vector3f(-42.299904,6.899996,-56.000046); 
box5->halfSize = Vector3f(18.499983,5.899997,124.800117); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Cylinder *box6 = new Cylinder();
box6->position = Vector3f(23.190052,-3.900001,-292.693481); 
box6->halfSize = Vector3f(46.499863,118.099724,21.100044); 
box6->setRotation(0.000000,0.000000,0.000000); 
box6->tag = "cave"; 
components.push_back(box6); 
//==================================================================
//========================box7=====================================
Railway *box7 = new Railway();
box7->position = Vector3f(29.800076,-0.700000,-5.499997); 
box7->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box7->setRotation(0.000000,0.000000,0.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Model3d *box8 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box8->position = Vector3f(56.199715,-8.400000,-21.930046); 
box8->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box8->setRotation(-90.000000,-0.000000,-0.000000); 
box8->tag = ""; 
components.push_back(box8); 
//==================================================================
//========================box9=====================================
Model3d *box9 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box9->position = Vector3f(-11.200372,-8.199999,-123.728683); 
box9->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box9->setRotation(90.000000,-0.000000,-0.000000); 
box9->tag = ""; 
components.push_back(box9); 
//==================================================================
//========================box10=====================================
Model3d *box10 = new Model3d("spider.obj","./Data/OBJ/");
box10->position = Vector3f(20.299677,9.799997,-124.428673); 
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
box12->position = Vector3f(174.839996,41.589943,-24.040047); 
box12->halfSize = Vector3f(1.000000,28.890017,157.620331); 
box12->setRotation(0.000000,0.000000,0.000000); 
box12->tag = ""; 
components.push_back(box12); 
//==================================================================
//========================box13=====================================
Box *box13 = new Box();
box13->setTexture("Data/NeHe.bmp");
box13->position = Vector3f(-41.239777,27.710033,-176.930466); 
box13->halfSize = Vector3f(17.859962,14.910000,1.370000); 
box13->setRotation(0.000000,0.000000,0.000000); 
box13->tag = ""; 
components.push_back(box13); 
//==================================================================
//========================box14=====================================
Box *box14 = new Box();
box14->setTexture("Data/NeHe.bmp");
box14->position = Vector3f(121.760223,27.610050,133.799744); 
box14->halfSize = Vector3f(52.059875,14.809966,-0.900000); 
box14->setRotation(0.000000,0.000000,0.000000); 
box14->tag = ""; 
components.push_back(box14); 
//==================================================================
//========================box15=====================================
Box *box15 = new Box();
box15->setTexture("Data/NeHe.bmp");
box15->position = Vector3f(-42.139709,27.600052,133.599548); 
box15->halfSize = Vector3f(18.859966,14.799969,-0.800000); 
box15->setRotation(0.000000,0.000000,0.000000); 
box15->tag = ""; 
components.push_back(box15); 
//==================================================================
//========================box16=====================================
Box *box16 = new Box();
box16->setTexture("Data/NeHe.bmp");
box16->position = Vector3f(56.460262,56.479958,133.649582); 
box16->halfSize = Vector3f(117.459808,14.079969,-0.850000); 
box16->setRotation(0.000000,0.000000,0.000000); 
box16->tag = ""; 
components.push_back(box16); 
//==================================================================
//========================box17=====================================
Box *box17 = new Box();
box17->setTexture("Data/NeHe.bmp");
box17->position = Vector3f(22.110172,56.860073,-177.110001); 
box17->halfSize = Vector3f(81.119926,14.259984,1.460000); 
box17->setRotation(0.000000,0.000000,0.000000); 
box17->tag = ""; 
components.push_back(box17); 
//==================================================================
//========================box18=====================================
Stairs *box18 = new Stairs(Vector3f(-27.620180,42.999897,-205.700821),Vector3f(1.000000,1.000000,1.000000),10);
box18->setTexture("Data/NeHe.bmp");
box18->position = Vector3f(-27.620180,42.999897,-205.700821); 
box18->halfSize = Vector3f(4.080000,1.200000,0.900000); 
box18->setRotation(-359.000000,-1.000000,-181.000000); 
box18->tag = ""; 
components.push_back(box18); 
//==================================================================
//========================box19=====================================
Railway *box19 = new Railway();
box19->position = Vector3f(-2.799953,-0.700000,-5.499997); 
box19->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box19->setRotation(0.000000,0.000000,0.000000); 
box19->tag = ""; 
components.push_back(box19); 
//==================================================================
//========================box20=====================================
Box *box20 = new Box();
box20->setTexture("Data/NeHe.bmp");
box20->position = Vector3f(68.800217,29.099993,-190.691025); 
box20->halfSize = Vector3f(0.800000,13.700016,14.110022); 
box20->setRotation(0.000000,0.000000,0.000000); 
box20->tag = ""; 
components.push_back(box20); 
//==================================================================
//========================box21=====================================
Box *box21 = new Box();
box21->setTexture("Data/NeHe.bmp");
box21->position = Vector3f(102.299080,27.700060,-193.101288); 
box21->halfSize = Vector3f(1.000000,14.700020,14.700020); 
box21->setRotation(0.000000,0.000000,0.000000); 
box21->tag = ""; 
components.push_back(box21); 
//==================================================================
//========================box22=====================================
Box *box22 = new Box();
box22->setTexture("Data/NeHe.bmp");
box22->position = Vector3f(138.750244,41.779968,-177.071304); 
box22->halfSize = Vector3f(35.459934,29.310024,1.400000); 
box22->setRotation(0.000000,0.000000,0.000000); 
box22->tag = ""; 
components.push_back(box22); 
//==================================================================
//========================box23=====================================
Box *box23 = new Box();
box23->setTexture("Data/NeHe.bmp");
box23->position = Vector3f(86.800003,28.400045,0.000000); 
box23->halfSize = Vector3f(1.000000,13.000013,1.000000); 
box23->setRotation(0.000000,0.000000,0.000000); 
box23->tag = ""; 
components.push_back(box23); 
//==================================================================
//========================box24=====================================
Box *box24 = new Box();
box24->setTexture("Data/NeHe.bmp");
box24->position = Vector3f(86.879990,43.799980,-98.300026); 
box24->halfSize = Vector3f(2.799999,2.400000,1.000000); 
box24->setRotation(0.000000,0.000000,0.000000); 
box24->tag = "clock"; 
components.push_back(box24); 
//==================================================================
//========================box25=====================================
Box *box25 = new Box();
box25->setTexture("Data/NeHe.bmp");
box25->position = Vector3f(86.800003,28.400045,-98.299988); 
box25->halfSize = Vector3f(1.000000,13.000013,1.000000); 
box25->setRotation(0.000000,0.000000,0.000000); 
box25->tag = ""; 
components.push_back(box25); 
//==================================================================
//========================box26=====================================
Box *box26 = new Box();
box26->setTexture("Data/NeHe.bmp");
box26->position = Vector3f(86.779991,43.799980,0.199960); 
box26->halfSize = Vector3f(2.799999,2.400000,1.000000); 
box26->setRotation(0.000000,0.000000,0.000000); 
box26->tag = "clock"; 
components.push_back(box26); 
//==================================================================
}