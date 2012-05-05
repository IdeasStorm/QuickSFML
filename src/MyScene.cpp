/* 
 * File:   MyScene.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 5, 2012, 5:06 PM
 */

#include "Model.h"
#include "MyScene.h"
#include "Drawable.h"
#include "Ground.h"


MyScene::MyScene(const MyScene& orig) {
}

MyScene::~MyScene() {
}

void MyScene::LoadComponents(){
    Ground *g = new Ground();
    g->box_texture = "./Data/NeHe.bmp";
    Model * model=new Model("monkey.3ds");
    
    components.push_back(g);
    components.push_back(model);
    //model = new Model("monkey.3ds");
    GLScene::LoadComponents();
}

void MyScene::Update(const sf::Input& input) {
    
}