/* 
 * File:   MyScene.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 5, 2012, 5:06 PM
 */

#include "Model.h"
#include "MyScene.h"
#include "Ground.h"
#include "Box.h"


MyScene::MyScene(const MyScene& orig) {
}

MyScene::~MyScene() {
}

void MyScene::LoadComponents(){
    update_child_controls = true;
    //Ground *g = new Ground();
//    b->box_texture = "./Data/NeHe.bmp";
    Box *b = new Box();
    Model * model=new Model("monkey.3ds");
    b->setTexture("./Data/NeHe.bmp");  
    components.push_back(b);
    components.push_back(model);
    //model = new Model("monkey.3ds");
    GLScene::LoadComponents();
}

void MyScene::Update(const sf::Input& input) {
    
}