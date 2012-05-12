/* 
 * File:   Studio.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 5, 2012, 7:44 PM
 */

#include "user_input.h"
#include "Model.h"
#include "Studio.h"
#include "Stairs.h"

Studio::Studio() {
    currentComponent = components.end();
}

Studio::Studio(const Studio& orig) {
}

Studio::~Studio() {
}

void Studio::LoadComponents(){
    cameraEnable = 1;
    loadUserComponents(components);
    currentComponent = components.begin();
}

void Studio::Update(const sf::Input& input){
    static bool N_was_down = false;
    static bool M_was_down = false;    
    static bool eq_was_down = false;
    static bool minus_was_down = false;
    static bool F5_was_down = false;
    static bool del_was_down = false;
    static bool V_was_down = false;
    static bool T_was_down = false;
    
    camera.EnableMouse = true ;
    
    if (input.IsKeyDown(sf::Key::T) )  {
        T_was_down = true;
    } else if (T_was_down) {
        T_was_down = false;
        cout << "Enter a tag for the current Element: ";
        cin >> (*currentComponent)->tag;
    }
    
    if (input.IsKeyDown(sf::Key::V) )  {
        V_was_down = true;
    } else if (V_was_down) {
        V_was_down = false;
        GLDrawable* drawable = (*currentComponent)->Clone();
        components.push_back(drawable);    
        // setting this element as current
        list<GLDrawable*>::iterator end = components.end();
        end--;
        SetCurrentComponent(end);
    }
    
    if (input.IsKeyDown(sf::Key::Delete) )  {
        del_was_down = true;
    } else if (del_was_down) {
        del_was_down = false;
        components.remove(*currentComponent);
        // setting this element as current
        if (!components.empty()) {
                list<GLDrawable*>::iterator end = components.end();
                end--;
                SetCurrentComponent(end);
        }else {
            *currentComponent = NULL;
        }
    }
    
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
    
    if (input.IsKeyDown(sf::Key::M) )  {
        M_was_down = true;
    } else if (M_was_down) {
        M_was_down = false;
        Model *model = new Model("./Data/Model/straba_m_mod_02.3ds");
        model->LoadContent();
        model->GLInit();
        components.push_back(model);
        // setting this element as current
        list<GLDrawable*>::iterator end = components.end();
        end--;
        SetCurrentComponent(end);
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
            (((*currentComponent))->position) += sf::Vector3f(s,0,0);
    }
    if (input.IsKeyDown(sf::Key::Left)) {
        *field += sf::Vector3f(-s,0,0);
        if (scale)
            (((*currentComponent))->position) += sf::Vector3f(-s,0,0);
    }
    if (input.IsKeyDown(sf::Key::Up)) {
        *field += sf::Vector3f(0,0,s);
        if (scale)
            (((*currentComponent))->position) += sf::Vector3f(0,0,s);
    }
    if (input.IsKeyDown(sf::Key::Down)) {
        *field += sf::Vector3f(0,0,-s);
        if (scale)
            (((*currentComponent))->position) += sf::Vector3f(0,0,-s);
    }
    if (input.IsKeyDown(sf::Key::PageUp)) {
        *field += sf::Vector3f(0,s,0);
        if (scale)
            (((*currentComponent))->position) += sf::Vector3f(0,s,0);
    }
    if (input.IsKeyDown(sf::Key::PageDown)) {
        *field += sf::Vector3f(0,-s,0);
        if (scale)
            (((*currentComponent))->position) += sf::Vector3f(0,-s,0);
    }
    if (rotation) {
        (*currentComponent)->xrot += field->z;
        (*currentComponent)->yrot += field->y;
        (*currentComponent)->zrot += field->x;
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
    if (components.empty())
        return;
    if (currentComponent != components.end() && (*currentComponent)!=NULL)
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
    FILE *outfile;
    
    char *mode = "w";
    char outputFilename[] = "include/user_input.h";
    outfile = fopen(outputFilename, mode);
    
    int c = 0;
    fprintf(outfile,"//============THIS FILE IS GENERATED FROM USER INPUT================\n");
    fprintf(outfile,"#include \"gen_init.h\" \n");
    fprintf(outfile,"//=====================GENERATED CODE===============================\n");
    fprintf(outfile,"void loadUserComponents(list<GLDrawable*>& components) {\n");
    for (i=components.begin();i!=components.end();i++){
        GLDrawable *e = *i;
        fprintf(outfile,"//========================box%d=====================================\n",c);

        std::string str = "box";
        str += (char)('0' + c);
        e->WriteInstanceCreation(outfile, str);
        fprintf(outfile,"box%d->position = Vector3f(%f,%f,%f); \n",c,e->position.x,e->position.y,e->position.z);
        fprintf(outfile,"box%d->halfSize = Vector3f(%f,%f,%f); \n",c,e->halfSize.x,e->halfSize.y,e->halfSize.z);
        fprintf(outfile,"box%d->setRotation(%f,%f,%f); \n",c,e->yrot,e->xrot,e->zrot);
        fprintf(outfile,"components.push_back(box%d); \n",c);
        fprintf(outfile,"//==================================================================\n");
        c++;
    }
    fprintf(outfile,"}");
    fclose(outfile);
}