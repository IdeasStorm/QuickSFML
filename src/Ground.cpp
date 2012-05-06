/* 
 * File:   Ground.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 2, 2012, 8:17 PM
 */

#include "Ground.h"
#include "Box.h"

Ground::Ground() {
    rot=0;
}

Ground::Ground(const Ground& orig) {
}

Ground::~Ground() {
}

void Ground::Update(const sf::Input& input) {
    //Update2(input);
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){            
            ((GLDrawable*)(*i))->Update(input);
            ((GLDrawable*)(*i))->filter = filter;
    }
    if (input.IsKeyDown(sf::Key::Z))
        rot++;
}

void Ground::LoadComponents() {
    Box *side1 = new Box(sf::Vector3f(0,0,-5), 
            sf::Vector3f(1,10,2), 
            elements::FlippedOpenBox
    );
    side1->setTexture(box_texture);
    components.push_back(side1);
}