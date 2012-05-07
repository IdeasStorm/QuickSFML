/* 
 * File:   Train.cpp
 * Author: yaman
 * 
 * Created on May 5, 2012, 9:44 PM
 */

#include "Train.h"


Train::Train(std::string filename): Model(filename)
{
    
}

void Train::Update(const sf::Input &input)
{
    position.x = MoveForward;
}
        
Train::~Train() {
}

