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
    static bool was_down = false;
    
    if (input.IsKeyDown(sf::Key::N) )  {
        was_down = true;
    } else if (was_down) {
        was_down = false;
        Box *box = new Box();
        box->setTexture("Data/NeHe.bmp");
        box->DisableTexture();
        components.push_back(box);
    }
}