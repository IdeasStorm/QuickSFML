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
    if (input.IsKeyDown(sf::Key::N)) {
        Box *box = new Box();
        box->LoadContent();
        components.push_back(box);
    }
}