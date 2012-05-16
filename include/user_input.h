//============THIS FILE IS GENERATED FROM USER INPUT================
#include "gen_init.h" 
//=====================GENERATED CODE===============================
void loadUserComponents(list<GLDrawable*>& components) {
//========================box0=====================================
Box *box0 = new Box();
box0->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
box0->position = Vector3f(14.300018,-0.900000,0.000000); 
box0->halfSize = Vector3f(37.599998,1.000000,200.498825); 
box0->setRotation(0.000000,0.000000,0.000000); 
box0->tag = ""; 
components.push_back(box0); 
//==================================================================
//========================box1=====================================
Model *box1 = new Model("./Data/Train/1/train1.3ds");
box1->position = Vector3f(0.000000,0.200000,0.000000); 
box1->halfSize = Vector3f(0.100000,0.300000,0.100000); 
box1->setRotation(0.000000,-90.000000,0.000000); 
box1->tag = ""; 
components.push_back(box1); 
//==================================================================
//========================box2=====================================
Cylinder *box2 = new Cylinder();
box2->position = Vector3f(41.300018,3.889975,0.000000); 
box2->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box2->setRotation(0.000000,90.000000,0.000000); 
box2->tag = ""; 
components.push_back(box2); 
//==================================================================
//========================box3=====================================
Cylinder *box3 = new Cylinder();
box3->position = Vector3f(41.300018,3.889975,40.000000); 
box3->halfSize = Vector3f(3.399999,3.999999,1.000000); 
box3->setRotation(0.000000,90.000000,0.000000); 
box3->tag = ""; 
components.push_back(box3); 
//==================================================================
//========================box4=====================================
Box *box4 = new Box();
box4->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
box4->position = Vector3f(41.300022,5.799997,20.000040); 
box4->halfSize = Vector3f(0.700000,0.900000,16.800043); 
box4->setRotation(0.000000,0.000000,0.000000); 
box4->tag = ""; 
components.push_back(box4); 
//==================================================================
//========================box5=====================================
Cylinder *box5 = new Cylinder();
box5->position = Vector3f(0.500000,12.700010,70); 
box5->halfSize = Vector3f(16.400026,100,2.799999); 
box5->setRotation(0.000000,0.000000,0.000000); 
box5->tag = ""; 
components.push_back(box5); 
//==================================================================
//========================box7=====================================
Box *box7 = new Box();
box7->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
box7->position = Vector3f(-12.600012,11.100004,70); 
box7->halfSize = Vector3f(2.799999,10.900005,100);  
box7->setRotation(0.000000,0.000000,0.000000); 
box7->tag = ""; 
components.push_back(box7); 
//==================================================================
//========================box8=====================================
Box *box8 = new Box();
box8->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
box8->position = Vector3f(14.099949,11.100004,70); 
box8->halfSize = Vector3f(2.799999,10.900005,100); 
box8->setRotation(0.000000,0.000000,0.000000); 
box8->tag = ""; 
components.push_back(box8); 
//==================================================================
}