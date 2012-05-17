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
#include "Light.h"
#include "Train.h"
#include "Stairs.h"
#include "SkyBox.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Railway.h"
#include "Model3d.h"



MyScene::MyScene(const MyScene& orig) {
}

MyScene::~MyScene() {
}


Model3d * train_1;
Train * train_2;
Light * light2 , *light1;
Sphere *sphere ;
bool lightTest ;
void MyScene::LoadComponents(){
    this->default_lighting = true;
    update_child_controls = true;
    
    camera.SetOrigin(30,15,150);
    camera.ApplyDefault();
    
    camera2.SetOrigin(25,25,25);
    camera2.RotateLocalX(0.5);
    camera2.RotateLocalY(0.3);
    camera2.ApplyDefault() ;
    camera2.EnableMove = false ;
    
    camera3.SetOrigin(10,25,120);
    camera3.RotateLocalX(0.3);
    camera3.RotateLocalY(0.1);
    camera3.ApplyDefault() ;
    camera3.EnableMove = true ;
    camera3.EnableMouse = false ;
    cameraEnable = &camera;
        
    Stairs * stair;
    stair = new Stairs(sf::Vector3f (10,-2,-20),sf::Vector3f (3.5,1,1),10);
    //stair->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");    
    stair->yrot = 90;

    
    //g->box_texture = "./Data/Wall/images.jpg";
    Box *leftWall = new Box(sf::Vector3f (-20,6,-50),sf::Vector3f (1,10,150));
    Box *Edge = new Box(sf::Vector3f (40,-3,-50),sf::Vector3f (20,1,150));
    Box *ground = new Box(sf::Vector3f (0,-4,-50),sf::Vector3f (20,0.1,150));
    
    leftWall->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
    Edge->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
    ground->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
    
    train_1=new Model3d("metro_all.DAE");
    train_1->position = sf::Vector3f(-5,3,-15);
    train_1->halfSize  = sf::Vector3f(0.1,0.1,0.1);
    //train_1->setRotation(sf::Vector3f(1,0,0),-90);
    train_1->self_control = true ;
    
    train_2= new Train("./Data/Train/1/train1.3ds");
    train_2->position= sf::Vector3f(15,3,-15);
    train_2->halfSize  = sf::Vector3f(0.1,0.1,0.1);
    train_2->setRotation(sf::Vector3f(1,0,0),-90);
    train_2->self_control = true ;
    
    Model * Tele = new Model("./Data/Model/Telephone 1 N300408.3ds");
    Tele->position = sf::Vector3f(40,6,50);
    Tele->halfSize = sf::Vector3f(0.3,0.3,0.3);
    Tele->setRotation(sf::Vector3f(1,0,0),-90);

    
    Model * Fence = new Model("./Data/Model/fence-K009.3DS");
    Fence->position = sf::Vector3f(2,0,50);
    Fence->halfSize = sf::Vector3f(0.1,0.1,0.1);
    //Fence->setRotation(sf::Vector3f(1,0,0),-90);
    Fence->setRotation(sf::Vector3f(0,1,0),-90);
    //Fence->setRotation(sf::Vector3f(0,0,1),0);

    light2  = new Light(sf::Vector3f(25,30,-200),90,true);
    light2->ambient = sf::Color(1,1,1);
    light2->diffuse = sf::Color(1,1,1);
    light2->specular = sf::Color(0,0,0);
    light2->setDirection(sf::Vector3f(0,0,1));
    light2->w = 1 ;
    light2->lightNum +=1 ;
    light2->EnableSphere = false ;
    
    
    light1  = new Light(sf::Vector3f(0,10,-33),45,true);
    light1->ambient = sf::Color(1,1,1);
    light1->diffuse = sf::Color(1,1,1);
    light1->specular = sf::Color(0,0,0);
    light1->w =1 ;
    
    SkyBox * skyBox = new SkyBox();    
    skyBox->setTextures("./Data/city/");
    
    Cylinder *cy=new Cylinder(sf::Vector3f(10,10,40),3,6);
    cy->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
    cy->xrot=90;
     
    Railway *ra=new Railway(sf::Vector3f(10,10,10),sf::Vector3f(5,2,100));
    components.push_back(ra);
    components.push_back(cy);
    components.push_back(light1);
    //components.push_back(light2);
    
    //components.push_back(stair); 
    components.push_back(leftWall);
    components.push_back(Edge);
    components.push_back(train_1);
    //components.push_back(train_2);
    components.push_back(ground);

    GLScene::LoadComponents();
}

void MyScene::Update(const sf::Input& input) {
    if (input.IsKeyDown(sf::Key::Z)){
//        train_1->MoveForward -=0.5;
        camera.MoveForward(+0.5);
    }
        list<Light*>::iterator i;
    if (input.IsKeyDown(sf::Key::Y)){
        light1->position.y += 1 ;
    }
    if (input.IsKeyDown(sf::Key::H)){
        light1->position.y -= 1 ;
    }
    if (input.IsKeyDown(sf::Key::J)){
        light1->position.x += 1 ;
    }
    if (input.IsKeyDown(sf::Key::G)){
        light1->position.x -= 1 ;
    }
    if (input.IsKeyDown(sf::Key::U)){
        light1->position.z += 1 ;
    }
    if (input.IsKeyDown(sf::Key::I)){
        light1->position.z -= 1 ;
    }
    if (input.IsKeyDown(sf::Key::X)){
 //       train_1->MoveForward +=0.5;
        camera.MoveForward(-0.5);
    }
    if (input.IsKeyDown(sf::Key::Num1)){
        cameraEnable = &camera;
        camera.Default();
    }
    if (input.IsKeyDown(sf::Key::Num2)){
        cameraEnable = &camera2 ;
        camera2.Default();
    }
    if (input.IsKeyDown(sf::Key::Num3)){
        cameraEnable = &camera3 ;
        camera3.Default();
    } 
    GLScene::Update(input);
}