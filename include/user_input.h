//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("Data/NeHe.bmp");
box0->position = Vector3f(4.899998,0.000000,0.000000); 
box0->halfSize = Vector3f(1.000000,1.000000,1.000000); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
//========================box1=====================================
Box *box1 = new Box();
box1->setTexture("Data/NeHe.bmp");
box1->position = Vector3f(1.900000,-1.300000,11.700008); 
box1->halfSize = Vector3f(7.899995,5.599997,4.499998); 
box1->setRotation(0.000000,0.000000,0.000000); 
box1->tag = "building"; 
components.push_back(box1); 
//==================================================================
}