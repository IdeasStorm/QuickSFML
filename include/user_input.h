//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/asphalt.jpg");
box0->position = Vector3f(23.600054,-17.960037,-5.099939); 
box0->halfSize = Vector3f(48.899826,-15.800024,484.998688); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
//========================box1=====================================
Cylinder *box1 = new Cylinder();
box1->position = Vector3f(23.190052,-4.000001,250.906616); 
box1->halfSize = Vector3f(46.499863,118.099724,21.100044); 
box1->setRotation(0.000000,0.000000,0.000000); 
box1->tag = "cave"; 
components.push_back(box1); 
//==================================================================
//========================box2=====================================
Train *box2 = new Train();
box2->position = Vector3f(37.100006,0.200000,-38.321430); 
box2->halfSize = Vector3f(0.200000,0.200000,0.200000); 
box2->setRotation(0.000000,0.000000,0.000000); 
box2->tag = "moveable"; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Box *box3 = new Box();
box3->position = Vector3f(133.700241,6.899996,-22.300045); 
box3->halfSize = Vector3f(63.999985,5.899997,156.799835); 
box3->setRotation(0.000000,0.000000,0.000000); 
box3->tag = "flagstone"; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Box *box4 = new Box();
box4->position = Vector3f(-42.059914,6.899996,-23.900068); 
box4->halfSize = Vector3f(18.739985,5.899997,156.900085); 
box4->setRotation(0.000000,0.000000,0.000000); 
box4->tag = "flagstone"; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Cylinder *box5 = new Cylinder();
box5->position = Vector3f(23.190052,-3.900001,-293.893555); 
box5->halfSize = Vector3f(46.499863,118.099724,21.100044); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = "cave"; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Railway *box6 = new Railway();
box6->position = Vector3f(29.800076,-0.600000,-5.499997); 
box6->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box6->setRotation(0.000000,0.000000,0.000000); 
box6->tag = ""; 
components.push_back(box6); 
//==================================================================
//========================box7=====================================
Model3d *box7 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box7->position = Vector3f(56.199715,-8.400000,-21.930046); 
box7->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box7->setRotation(-90.000000,-0.000000,-0.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Model3d *box8 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box8->position = Vector3f(-11.200372,-8.199999,-123.728683); 
box8->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box8->setRotation(90.000000,-0.000000,-0.000000); 
box8->tag = ""; 
components.push_back(box8); 
//==================================================================
//========================box9=====================================
Box *box9 = new Box();
box9->position = Vector3f(-60.000000,41.689926,-23.499990); 
box9->halfSize = Vector3f(1.000000,28.590017,156.300140); 
box9->setRotation(0.000000,0.000000,0.000000); 
box9->tag = ""; 
components.push_back(box9); 
//==================================================================
//========================box10=====================================
Box *box10 = new Box();
box10->position = Vector3f(174.839996,41.909920,-24.040047); 
box10->halfSize = Vector3f(1.000000,29.210020,157.620331); 
box10->setRotation(0.000000,0.000000,0.000000); 
box10->tag = ""; 
components.push_back(box10); 
//==================================================================
//========================box11=====================================
Box *box11 = new Box();
box11->position = Vector3f(-41.239777,27.710033,-176.930466); 
box11->halfSize = Vector3f(17.859962,14.910000,1.370000); 
box11->setRotation(0.000000,0.000000,0.000000); 
box11->tag = ""; 
components.push_back(box11); 
//==================================================================
//========================box12=====================================
Box *box12 = new Box();
box12->position = Vector3f(121.760223,27.610050,133.799744); 
box12->halfSize = Vector3f(52.059875,14.809966,-0.900000); 
box12->setRotation(0.000000,0.000000,0.000000); 
box12->tag = ""; 
components.push_back(box12); 
//==================================================================
//========================box13=====================================
Box *box13 = new Box();
box13->position = Vector3f(-42.139709,27.600052,133.599548); 
box13->halfSize = Vector3f(18.859966,14.799969,-0.800000); 
box13->setRotation(0.000000,0.000000,0.000000); 
box13->tag = ""; 
components.push_back(box13); 
//==================================================================
//========================box14=====================================
Box *box14 = new Box();
box14->position = Vector3f(56.460262,56.479958,133.649582); 
box14->halfSize = Vector3f(117.459808,14.079969,-0.850000); 
box14->setRotation(0.000000,0.000000,0.000000); 
box14->tag = ""; 
components.push_back(box14); 
//==================================================================
//========================box15=====================================
Box *box15 = new Box();
box15->position = Vector3f(22.110172,56.860073,-177.110001); 
box15->halfSize = Vector3f(81.119926,14.259984,1.460000); 
box15->setRotation(0.000000,0.000000,0.000000); 
box15->tag = ""; 
components.push_back(box15); 
//==================================================================
//========================box16=====================================
Stairs *box16 = new Stairs(Vector3f(-27.620180,41.359913,-205.700821),Vector3f(1.000000,1.000000,1.000000),10);
box16->setTexture("./Data/Wall/marble.jpg");
box16->position = Vector3f(-27.620180,41.359913,-205.700821); 
box16->halfSize = Vector3f(4.080000,1.200000,0.900000); 
box16->setRotation(-359.000000,-1.000000,-181.000000); 
box16->tag = ""; 
components.push_back(box16); 
//==================================================================
//========================box17=====================================
Railway *box17 = new Railway();
box17->position = Vector3f(-2.799953,-0.700000,-5.499997); 
box17->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box17->setRotation(0.000000,0.000000,0.000000); 
box17->tag = ""; 
components.push_back(box17); 
//==================================================================
//========================box18=====================================
Box *box18 = new Box();
box18->position = Vector3f(68.830200,27.689983,-191.581085); 
box18->halfSize = Vector3f(0.800000,14.990017,15.780027); 
box18->setRotation(0.000000,0.000000,0.000000); 
box18->tag = ""; 
components.push_back(box18); 
//==================================================================
//========================box19=====================================
Box *box19 = new Box();
box19->position = Vector3f(102.299080,27.700060,-193.101288); 
box19->halfSize = Vector3f(1.000000,14.700020,14.700020); 
box19->setRotation(0.000000,0.000000,0.000000); 
box19->tag = ""; 
components.push_back(box19); 
//==================================================================
//========================box20=====================================
Box *box20 = new Box();
box20->position = Vector3f(138.670288,41.809963,-177.201355); 
box20->halfSize = Vector3f(35.449936,29.310024,1.470000); 
box20->setRotation(0.000000,0.000000,0.000000); 
box20->tag = ""; 
components.push_back(box20); 
//==================================================================
//========================box21=====================================
Box *box21 = new Box();
box21->position = Vector3f(86.800003,28.400045,0.000000); 
box21->halfSize = Vector3f(1.000000,13.000013,1.000000); 
box21->setRotation(0.000000,0.000000,0.000000); 
box21->tag = ""; 
components.push_back(box21); 
//==================================================================
//========================box22=====================================
Box *box22 = new Box();
box22->position = Vector3f(86.879990,43.799980,-98.300026); 
box22->halfSize = Vector3f(2.799999,2.400000,1.000000); 
box22->setRotation(0.000000,0.000000,0.000000); 
box22->tag = "clock"; 
components.push_back(box22); 
//==================================================================
//========================box23=====================================
Box *box23 = new Box();
box23->position = Vector3f(86.800003,28.400045,-98.299988); 
box23->halfSize = Vector3f(1.000000,13.000013,1.000000); 
box23->setRotation(0.000000,0.000000,0.000000); 
box23->tag = ""; 
components.push_back(box23); 
//==================================================================
//========================box24=====================================
Box *box24 = new Box();
box24->position = Vector3f(86.779991,43.799980,0.199960); 
box24->halfSize = Vector3f(2.799999,2.400000,1.000000); 
box24->setRotation(0.000000,0.000000,0.000000); 
box24->tag = "clock"; 
components.push_back(box24); 
//==================================================================
//========================box31=====================================
Model3d *box31 = new Model3d("./Data/Model/new/6614b7cd4ab0bf54830bfccc9ca3e670/Bus stop N290112.3DS","./");
box31->position = Vector3f(83.000000,13.000000,-30.000000); 
box31->halfSize = Vector3f(0.010000,0.010000,0.010000); 
box31->setRotation(39.000000,0.000000,0.000000); 
box31->tag = ""; 
components.push_back(box31); 
//==================================================================
}