//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
box0->position = Vector3f(14.300018,-0.900000,0.300002); 
box0->halfSize = Vector3f(37.599998,1.000000,200.498825); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
//========================box2=====================================
Model *box2 = new Model("./Data/Train/1/train1.3ds");
box2->position = Vector3f(0.000000,0.200000,0.000000); 
box2->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box2->setRotation(0.000000,0.000000,0.000000); 
box2->tag = ""; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Model *box3 = new Model("./Data/Train/1/train1.3ds");
box3->position = Vector3f(31.700085,0.200000,0.000000); 
box3->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box3->setRotation(0.000000,0.000000,0.000000); 
box3->tag = ""; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Cylinder *box4 = new Cylinder();
box4->position = Vector3f(16.700027,3.889975,0.000000); 
box4->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box4->setRotation(0.000000,90.000000,0.000000); 
box4->tag = ""; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Cylinder *box5 = new Cylinder();
box5->position = Vector3f(16.700027,3.889975,40.000000); 
box5->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box5->setRotation(0.000000,90.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box6=====================================
Box *box6 = new Box();
box6->setTexture("Data/NeHe.bmp");
box6->position = Vector3f(16.800028,5.799997,20.000040); 
box6->halfSize = Vector3f(0.500000,0.900000,16.800043); 
box6->setRotation(0.000000,0.000000,0.000000); 
box6->tag = ""; 
components.push_back(box6); 
//==================================================================
}