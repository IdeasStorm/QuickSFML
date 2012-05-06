/* 
 * File:   Studio.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 5, 2012, 7:44 PM
 */


#include "Studio.h"

Studio::Studio() {
    currentComponent = components.end();
}

Studio::Studio(const Studio& orig) {
}

Studio::~Studio() {
}

void Studio::LoadComponents(){
    
}

void Studio::Update(const sf::Input& input){
    static bool N_was_down = false;
    static bool T_was_down = false;
    static bool eq_was_down = false;
    static bool minus_was_down = false;
    static bool F5_was_down = false;
    
    if (input.IsKeyDown(sf::Key::N) )  {
        N_was_down = true;
    } else if (N_was_down) {
        N_was_down = false;
        Box *box = new Box();
        box->setTexture("Data/NeHe.bmp");
        components.push_back(box);
        // setting this element as current
        list<GLDrawable*>::iterator end = components.end();
        end--;
        SetCurrentComponent(end);
    }
    
    if (input.IsKeyDown(sf::Key::T) )  {
        T_was_down = true;
    } else if (T_was_down) {
        T_was_down = false;
        Box *box = new Box();
        box->setTexture("Data/NeHe.bmp");
        box->DisableTexture();
        components.push_back(box);
    }
    
    if (input.IsKeyDown(sf::Key::Dash) )  {
        minus_was_down = true;
    } else if (minus_was_down) {
        minus_was_down = false;
        PrevComponent();
    }
    
    if (input.IsKeyDown(sf::Key::Equal) )  {
        eq_was_down = true;
    } else if (eq_was_down) {
        eq_was_down = false;
        NextComponent();
    }
    
    float s = 0.1f;
    if (input.IsKeyDown(sf::Key::LControl)) {
        s *=0.1f;
    }
    
    sf::Vector3f *field;
    bool scale = false;
    bool rotation = false;
    if (input.IsKeyDown(sf::Key::LShift)) {
        scale = true;
        field = &(((*currentComponent))->halfSize);
    }else if (input.IsKeyDown(sf::Key::LAlt)){
        field = new sf::Vector3f();
        rotation = true;
        s = 1;
    }else {
        field = &(((*currentComponent))->position);
    }
    if (input.IsKeyDown(sf::Key::Right)) {
        *field += sf::Vector3f(s,0,0);
        if (scale)
            (((Box*)(*currentComponent))->position) += sf::Vector3f(s,0,0);
    }
    if (input.IsKeyDown(sf::Key::Left)) {
        *field += sf::Vector3f(-s,0,0);
        if (scale)
            (((Box*)(*currentComponent))->position) += sf::Vector3f(-s,0,0);
    }
    if (input.IsKeyDown(sf::Key::Up)) {
        *field += sf::Vector3f(0,0,s);
        if (scale)
            (((Box*)(*currentComponent))->position) += sf::Vector3f(0,0,s);
    }
    if (input.IsKeyDown(sf::Key::Down)) {
        *field += sf::Vector3f(0,0,-s);
        if (scale)
            (((Box*)(*currentComponent))->position) += sf::Vector3f(0,0,-s);
    }
    if (input.IsKeyDown(sf::Key::PageUp)) {
        *field += sf::Vector3f(0,s,0);
        if (scale)
            (((Box*)(*currentComponent))->position) += sf::Vector3f(0,s,0);
    }
    if (input.IsKeyDown(sf::Key::PageDown)) {
        *field += sf::Vector3f(0,-s,0);
        if (scale)
            (((Box*)(*currentComponent))->position) += sf::Vector3f(0,-s,0);
    }
    if (rotation) {
        (*currentComponent)->xrot += field->x;
        (*currentComponent)->yrot += field->y;
        (*currentComponent)->zrot += field->z;
    }
    
    
    if (input.IsKeyDown(sf::Key::F5))  {
        F5_was_down = true;
    } else if (F5_was_down) {
        F5_was_down = false;
        WriteCode();
    }
    GLScene::Update(input);
}

void Studio::SetCurrentComponent(list<GLDrawable*>::iterator comp) {
    if (currentComponent != components.end())
        (*currentComponent)->textureEnabled = true;
    currentComponent = comp;
    (*currentComponent)->textureEnabled = false;
}

void Studio::NextComponent(){
   
    list<GLDrawable*>::iterator prev = currentComponent;
    currentComponent++;
    if (currentComponent == components.end())
        currentComponent = components.begin();
    (*prev)->textureEnabled = true;
    (*currentComponent)->textureEnabled = false;
}
void Studio::PrevComponent() {
    (*currentComponent)->textureEnabled = true;
    if (currentComponent == components.begin())
        currentComponent = components.end();
    currentComponent--;
    (*currentComponent)->textureEnabled = false;
}

void Studio::WriteCode(){
    list<GLDrawable*>::iterator i;
    int c = 0;
    printf("//=====================GENERATED CODE========================\n");
    for (i=components.begin();i!=components.end();i++){
        GLDrawable *e = *i;
        printf("//========================box%d=====================================\n",c);
        printf("Box *box%d = new Box(); \n",c);
        printf("box%d->position = Vector3f(%f,%f,%f); \n",c,e->position.x,e->position.y,e->position.z);
        printf("box%d->halfSize = Vector3f(%f,%f,%f); \n",c,e->halfSize.x,e->halfSize.y,e->halfSize.z);
        printf("box%d->setRotation(%f,%f,%f); \n",c,e->xrot,e->yrot,e->zrot);
        printf("components.push_back(box%d); \n",c);
        printf("//==================================================================\n");
        c++;
    }
}