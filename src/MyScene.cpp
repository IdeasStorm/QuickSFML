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

MyScene::MyScene(const MyScene& orig) {
    

}

MyScene::~MyScene() {
}

Train * train_1;
Train * train_2;
Light * light2 ,*test;
bool lightTest ;
list<Light *> lights; 
void MyScene::LoadComponents(){
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
    stair = new Stairs(sf::Vector3f (10,-2,50),sf::Vector3f (3.5,1,1),10);
    //stair->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");    
    stair->yrot = 90;
    
    //g->box_texture = "./Data/Wall/images.jpg";
    Box *leftWall = new Box(sf::Vector3f (-20,6,-50),sf::Vector3f (1,10,150));
    Box *Edge = new Box(sf::Vector3f (40,-3,-50),sf::Vector3f (20,1,150));
    Box *ground = new Box(sf::Vector3f (0,-4,-50),sf::Vector3f (20,0.1,150));
    
    leftWall->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
    Edge->setTexture("./Data/Wall/wall-texture-high-resolution.jpg");
    ground->setTexture("./Data/Wall/brown_wall_texture_by_fantasystock-d34un9s.jpg");
    
    train_1=new Train("./Data/Model/straba_m_mod_02.3ds");
    train_1-> position = sf::Vector3f(-10,3,-15);
    train_1->halfSize  = sf::Vector3f(2,2,2);
    train_1-> setRotation(sf::Vector3f(1,0,0),-90);
    train_1->self_control = true ;
    train_1->self_control = true ;
    
    train_2= new Train("./Data/Model/straba_m_mod_02.3ds");
    train_2->position= sf::Vector3f(10,3,-15);
    train_2->halfSize  = sf::Vector3f(2,2,2);
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
    
    //Fence->setRotation(0,1,0);


    for (int i=-5 ;i<10 ;i++)
    {
    }
    
  /*  Model * ligth1 = new Model("./Data/Model/Lamppost N090508.3ds");
    ligth1->position = sf::Vector3f(25,6,-20);
    ligth1->halfSize = sf::Vector3f(0.2,0.2,0.2);
    ligth1->setRotation(sf::Vector3f(1,0,0),-90);
    //ligth1->setRotation(sf::Vector3f(0,0,1),-180);
    //components.push_back(ligth1);*/
    
    Box *box3 = new Box(sf::Vector3f (25,6,-20),sf::Vector3f(0.5,8.1,0.5));
    box3->setTexture("Data/NeHe.bmp");

        
    light2  = new Light();
    light2->position = sf::Vector3f(25,30,-15);
    light2->ambient = sf::Color(1,1,1);
    light2->diffuse = sf::Color(1,1,1);
    light2->specular = sf::Color(1,1,1);
    light2->w = 1 ;
    lights.push_front(light2);
    //light2->SetupLighting();
     


    
    SkyBox * skyBox = new SkyBox();    
    skyBox->setTextures("./Data/city/");

    //components.push_back(skyBox);
    components.push_back(stair); 
    components.push_back(leftWall);
    //components.push_back(box3); 
    components.push_back(Edge);
    components.push_back(train_1);
    //components.push_back(train_2);
    components.push_back(ground);
      
   // components.push_back(skyBox);

    GLScene::LoadComponents();
}

void MyScene::Update(const sf::Input& input) {
    if (input.IsKeyDown(sf::Key::Z)){
        train_1->MoveForward -=0.5;
        camera.MoveForward(+0.5);
    }
        list<Light*>::iterator i;
    if (input.IsKeyDown(sf::Key::Y)){
        light2->position.y += 1 ;
                for (i=lights.begin();i!=lights.end();i++){
            ((Light*)(*i))->ligthEnable != ((Light*)(*i))->ligthEnable;
            ((Light*)(*i))->SetupLighting();
        }
    }
    if (input.IsKeyDown(sf::Key::H)){
        light2->position.y -= 1 ;
                for (i=lights.begin();i!=lights.end();i++){
            ((Light*)(*i))->ligthEnable != ((Light*)(*i))->ligthEnable;
            ((Light*)(*i))->SetupLighting();
        }
    }
    if (input.IsKeyDown(sf::Key::J)){
        light2->position.x += 1 ;
                for (i=lights.begin();i!=lights.end();i++){
            ((Light*)(*i))->ligthEnable != ((Light*)(*i))->ligthEnable;
            ((Light*)(*i))->SetupLighting();
        }
    }
    if (input.IsKeyDown(sf::Key::G)){
        light2->position.x -= 1 ;
                for (i=lights.begin();i!=lights.end();i++){
            ((Light*)(*i))->ligthEnable != ((Light*)(*i))->ligthEnable;
            ((Light*)(*i))->SetupLighting();
        }
    }
    if (input.IsKeyDown(sf::Key::U)){
        light2->position.z += 1 ;
                for (i=lights.begin();i!=lights.end();i++){
            ((Light*)(*i))->ligthEnable != ((Light*)(*i))->ligthEnable;
            ((Light*)(*i))->SetupLighting();
        }
    }

    if (input.IsKeyDown(sf::Key::I)){
        light2->position.z -= 1 ;
                for (i=lights.begin();i!=lights.end();i++){
            ((Light*)(*i))->ligthEnable != ((Light*)(*i))->ligthEnable;
            ((Light*)(*i))->SetupLighting();
        }
    }
    if (input.IsKeyDown(sf::Key::X)){
        train_1->MoveForward +=0.5;
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

    for (i=lights.begin();i!=lights.end();i++){
        ((Light*)(*i))->SetupLighting();
    }
    GLScene::Update(input);

}