/* 
 * File:   Studio.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 5, 2012, 7:44 PM
 */

#include "Studio.h"

Studio::Studio() {
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
    
    if (input.IsKeyDown(sf::Key::N) )  {
        N_was_down = true;
    } else if (N_was_down) {
        N_was_down = false;
        Box *box = new Box();
        box->setTexture("Data/NeHe.bmp");
        box->DisableTexture();
        box->setTexture("Data/NeHe.bmp");
        components.push_back(box);
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
}