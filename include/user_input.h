//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/asphalt.jpg");
box0->position = Vector3f(23.100052,-17.960037,-5.199939); 
box0->halfSize = Vector3f(49.399818,-15.800024,484.998688); 
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
Box *box2 = new Box();
box2->position = Vector3f(133.700241,5.199997,-22.300045); 
box2->halfSize = Vector3f(63.999985,7.499996,156.799835); 
box2->setRotation(0.000000,0.000000,0.000000); 
box2->tag = "flagstone"; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Box *box3 = new Box();
box3->position = Vector3f(-42.059914,5.399997,-24.200069); 
box3->halfSize = Vector3f(18.739985,7.899995,156.700073); 
box3->setRotation(0.000000,0.000000,0.000000); 
box3->tag = "flagstone"; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Cylinder *box4 = new Cylinder();
box4->position = Vector3f(23.190052,-3.900001,-293.893555); 
box4->halfSize = Vector3f(46.499863,118.099724,21.100044); 
box4->setRotation(0.000000,0.000000,0.000000); 
box4->tag = "cave"; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Railway *box5 = new Railway();
box5->position = Vector3f(29.800076,-0.600000,-5.499997); 
box5->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Model3d *box6 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box6->position = Vector3f(56.199715,-8.400000,-21.930046); 
box6->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box6->setRotation(-90.000000,-0.000000,-0.000000); 
box6->tag = ""; 
components.push_back(box6); 
//==================================================================
//========================box7=====================================
Model3d *box7 = new Model3d("2track_lighting-2.3DS","./Data/Train/2/");
box7->position = Vector3f(-11.200372,-8.199999,-123.728683); 
box7->halfSize = Vector3f(0.300000,0.300000,0.300000); 
box7->setRotation(90.000000,-0.000000,-0.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Box *box8 = new Box();
box8->position = Vector3f(-60.000000,41.689926,-23.499990); 
box8->halfSize = Vector3f(1.000000,28.590017,156.300140); 
box8->setRotation(0.000000,0.000000,0.000000); 
box8->tag = ""; 
components.push_back(box8); 
//==================================================================
//========================box9=====================================
Box *box9 = new Box();
box9->position = Vector3f(174.839996,41.909920,-24.040047); 
box9->halfSize = Vector3f(1.000000,29.210020,157.620331); 
box9->setRotation(0.000000,0.000000,0.000000); 
box9->tag = ""; 
components.push_back(box9); 
//==================================================================
//========================box10=====================================
Box *box10 = new Box();
box10->position = Vector3f(-41.239777,27.710033,-176.930466); 
box10->halfSize = Vector3f(17.859962,14.910000,1.370000); 
box10->setRotation(0.000000,0.000000,0.000000); 
box10->tag = ""; 
components.push_back(box10); 
//==================================================================
//========================box11=====================================
Box *box11 = new Box();
box11->position = Vector3f(121.760223,27.610050,133.799744); 
box11->halfSize = Vector3f(52.059875,14.809966,-0.900000); 
box11->setRotation(0.000000,0.000000,0.000000); 
box11->tag = ""; 
components.push_back(box11); 
//==================================================================
//========================box12=====================================
Box *box12 = new Box();
box12->position = Vector3f(-42.139709,27.600052,133.599548); 
box12->halfSize = Vector3f(18.859966,14.799969,-0.800000); 
box12->setRotation(0.000000,0.000000,0.000000); 
box12->tag = ""; 
components.push_back(box12); 
//==================================================================
//========================box13=====================================
Box *box13 = new Box();
box13->position = Vector3f(56.460262,56.479958,133.649582); 
box13->halfSize = Vector3f(117.459808,14.079969,-0.850000); 
box13->setRotation(0.000000,0.000000,0.000000); 
box13->tag = ""; 
components.push_back(box13); 
//==================================================================
//========================box14=====================================
Box *box14 = new Box();
box14->position = Vector3f(22.110172,56.860073,-177.110001); 
box14->halfSize = Vector3f(81.119926,14.259984,1.460000); 
box14->setRotation(0.000000,0.000000,0.000000); 
box14->tag = ""; 
components.push_back(box14); 
//==================================================================
//========================box15=====================================
Stairs *box15 = new Stairs(Vector3f(-27.620180,41.359913,-205.700821),Vector3f(1.000000,1.000000,1.000000),10);
box15->setTexture("./Data/Wall/marble.jpg");
box15->position = Vector3f(-27.620180,41.359913,-205.700821); 
box15->halfSize = Vector3f(4.080000,1.200000,0.900000); 
box15->setRotation(-359.000000,-1.000000,-181.000000); 
box15->tag = ""; 
components.push_back(box15); 
//==================================================================
//========================box16=====================================
Railway *box16 = new Railway();
box16->position = Vector3f(-2.799953,-0.700000,-5.499997); 
box16->halfSize = Vector3f(2.800002,0.600000,94.900078); 
box16->setRotation(0.000000,0.000000,0.000000); 
box16->tag = ""; 
components.push_back(box16); 
//==================================================================
//========================box17=====================================
Box *box17 = new Box();
box17->position = Vector3f(68.830200,27.689983,-192.381134); 
box17->halfSize = Vector3f(0.800000,14.990017,15.780027); 
box17->setRotation(0.000000,0.000000,0.000000); 
box17->tag = ""; 
components.push_back(box17); 
//==================================================================
//========================box18=====================================
Box *box18 = new Box();
box18->position = Vector3f(102.299080,27.700060,-193.101288); 
box18->halfSize = Vector3f(1.000000,14.700020,14.700020); 
box18->setRotation(0.000000,0.000000,0.000000); 
box18->tag = ""; 
components.push_back(box18); 
//==================================================================
//========================box19=====================================
Box *box19 = new Box();
box19->position = Vector3f(138.670288,41.809963,-177.201355); 
box19->halfSize = Vector3f(35.449936,29.310024,1.470000); 
box19->setRotation(0.000000,0.000000,0.000000); 
box19->tag = ""; 
components.push_back(box19); 
//==================================================================
//========================box20=====================================
Box *box20 = new Box();
box20->position = Vector3f(97.399086,45.899796,-26.250048); 
box20->halfSize = Vector3f(15.800024,7.699995,0.500000); 
box20->setRotation(0.000000,11.000000,0.000000); 
box20->tag = "LCD"; 
components.push_back(box20); 
//==================================================================
//========================box21=====================================
Box *box21 = new Box();
box21->position = Vector3f(97.199089,45.899796,-30.150063); 
box21->halfSize = Vector3f(15.500023,7.699995,0.500000); 
box21->setRotation(0.000000,171.000000,180.000000); 
box21->tag = "LCD"; 
components.push_back(box21); 
//==================================================================
//========================box22=====================================
Box *box22 = new Box();
box22->setTexture("./Data/Textures/Ceramic_texture.jpg");
box22->position = Vector3f(67.999535,71.399635,-27.750053); 
box22->halfSize = Vector3f(129.795502,1.300000,166.201736); 
box22->setRotation(0.000000,0.000000,0.000000); 
box22->tag = ""; 
components.push_back(box22); 
//==================================================================
//========================box23=====================================
Cylinder *box23 = new Cylinder();
box23->position = Vector3f(97.300003,56.599911,-28.200005); 
box23->halfSize = Vector3f(0.500000,16.200026,-0.700000); 
box23->setRotation(1.000000,90.000000,-13.000000); 
box23->tag = ""; 
components.push_back(box23); 
//==================================================================
//========================box24=====================================
Model3d *box24 = new Model3d("./Data/Model/Call box N071211.3DS","./");
box24->position = Vector3f(112.100006,37.000000,-174.099960); 
box24->halfSize = Vector3f(0.010000,0.010000,0.010000); 
box24->setRotation(0.000000,0.000000,0.000000); 
box24->tag = ""; 
components.push_back(box24); 
//==================================================================
//========================box25=====================================
Box *box25 = new Box();
box25->position = Vector3f(-56.499825,44.799889,8.999998); 
box25->halfSize = Vector3f(-0.900000,12.600012,19.700037); 
box25->setRotation(0.000000,0.000000,0.000000); 
box25->tag = "Ad1"; 
components.push_back(box25); 
//==================================================================
//========================box26=====================================
Model3d *box26 = new Model3d("./Data/Model/bench_conc.3DS","./");
box26->position = Vector3f(163.000061,12.400000,84.099998); 
box26->halfSize = Vector3f(0.310000,0.410000,-0.290000); 
box26->setRotation(0.000000,0.000000,0.000000); 
box26->tag = "bench"; 
components.push_back(box26); 
//==================================================================
//========================box27=====================================
Box *box27 = new Box();
box27->position = Vector3f(-56.499825,44.799889,8.999998); 
box27->halfSize = Vector3f(-0.900000,12.600012,19.700037); 
box27->setRotation(0.000000,0.000000,0.000000); 
box27->tag = "Ad1"; 
components.push_back(box27); 
//==================================================================
//========================box28=====================================
Box *box28 = new Box();
box28->position = Vector3f(173.782730,47.099903,11.800009); 
box28->halfSize = Vector3f(1.400000,10.100002,26.700026); 
box28->setRotation(0.000000,0.000000,0.000000); 
box28->tag = "Ad2"; 
components.push_back(box28); 
//==================================================================
//========================box29=====================================
Model3d *box29 = new Model3d("./Data/Model/bench_conc.3DS","./");
box29->position = Vector3f(163.000061,12.400000,15.099998); 
box29->halfSize = Vector3f(0.310000,0.410000,-0.290000); 
box29->setRotation(0.000000,0.000000,0.000000); 
box29->tag = "bench"; 
components.push_back(box29); 
//==================================================================
//========================box30=====================================
Model3d *box30 = new Model3d("./Data/Model/bench_conc.3DS","./");
box30->position = Vector3f(163.000061,12.400000,-55.399986); 
box30->halfSize = Vector3f(0.310000,0.410000,-0.290000); 
box30->setRotation(0.000000,0.000000,0.000000); 
box30->tag = "bench"; 
components.push_back(box30); 
//==================================================================
//========================box31=====================================
Model3d *box31 = new Model3d("./Data/Model/bench_conc.3DS","./");
box31->position = Vector3f(163.000061,12.400000,-117.300003); 
box31->halfSize = Vector3f(0.310000,0.410000,-0.290000); 
box31->setRotation(0.000000,0.000000,0.000000); 
box31->tag = "bench"; 
components.push_back(box31); 
//==================================================================
//========================box32=====================================
Box *box32 = new Box();
box32->position = Vector3f(174.082748,47.399899,-92.099808); 
box32->halfSize = Vector3f(1.400000,19.800039,18.299994); 
box32->setRotation(0.000000,0.000000,0.000000); 
box32->tag = "Ad3"; 
components.push_back(box32); 
//==================================================================
}