//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("Data/NeHe.bmp");
box0->position = Vector3f(14.100018,4.699997,5.999997); 
box0->halfSize = Vector3f(4.599998,5.999997,3.599999); 
box0->setRotation(5.000000,0.000000,-2.000000); 
components.push_back(box0); 
//==================================================================
//========================box1=====================================
Box *box1 = new Box();
box1->setTexture("Data/NeHe.bmp");
box1->position = Vector3f(-4.399998,4.299998,0.800000); 
box1->halfSize = Vector3f(4.399998,5.299997,4.399998); 
box1->setRotation(0.000000,0.000000,0.000000); 
components.push_back(box1); 
//==================================================================
//========================box2=====================================
Box *box2 = new Box();
box2->setTexture("Data/NeHe.bmp");
box2->position = Vector3f(5.099998,-2.800000,-1.900001); 
box2->halfSize = Vector3f(14.600019,1.000000,14.800020); 
box2->setRotation(0.000000,0.000000,0.000000); 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Model *box3 = new Model("./Data/Model/straba_m_mod_02.3ds");
box3->position = Vector3f(4.299998,2.200000,-15.900023); 
box3->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box3->setRotation(0.000000,-93.000000,-2.000000); 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Box *box4 = new Box();
box4->setTexture("Data/NeHe.bmp");
box4->position = Vector3f(2.760000,8.269995,-7.889995); 
box4->halfSize = Vector3f(0.150000,0.100000,33.800056); 
box4->setRotation(0.000000,0.000000,0.000000); 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Box *box5 = new Box();
box5->setTexture("Data/NeHe.bmp");
box5->position = Vector3f(5.359996,8.320004,-1.300030); 
box5->halfSize = Vector3f(0.120000,0.100000,33.600060); 
box5->setRotation(0.000000,0.000000,0.000000); 
components.push_back(box5); 
//==================================================================
}