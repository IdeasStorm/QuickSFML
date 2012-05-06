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
    camera.SetOrigin(0,0,0);
   // Ground *g = new Ground();

    //g->box_texture = "./Data/Wall/images.jpg";
    Box *leftWall = new Box(sf::Vector3f (-20,5,-50),sf::Vector3f (1,10,50));
    Box *Edge = new Box(sf::Vector3f (20,-3,-50),sf::Vector3f (5,1,50));
    Box *ground = new Box(sf::Vector3f (0,-5,-50),sf::Vector3f (20,0.1,50));
    
    leftWall->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
    Edge->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");

    Model * train_1=new Model("straba_m_mod_02.3ds");
    //train_1->setTexture("./Data/NeHe.bmp");
    train_1-> position = sf::Vector3f(-5,0,-15);
    train_1-> setRotation(sf::Vector3f(1,0,0),-45);
    
    Model * train_2=new Model("straba_m_mod_02.3ds");
    //train_2->setTexture("./Data/NeHe.bmp");
    train_2->position= sf::Vector3f(5,0,-15);
    train_2->setRotation(sf::Vector3f(1,0,0),-45);
    
    
    //components.push_back(g);
    components.push_back(leftWall);
    components.push_back(Edge);
    components.push_back(train_1);
    components.push_back(train_2);
//   components.push_back(ground);
 
    GLScene::LoadComponents();
}

void MyScene::Update(const sf::Input& input) {

}