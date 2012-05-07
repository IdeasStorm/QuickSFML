/* 
 * File:   Train.h
 * Author: mhdsyrwan
 *
 * Created on May 5, 2012, 9:44 PM
 */

#ifndef TRAIN_H
#define	TRAIN_H
#include "Model.h"
#include "Drawable.h"

class Train : public Model {
public:
    Train(std::string filename);
     void Update(const sf::Input &input);
    virtual ~Train();
    GLfloat MoveForward ;
private:


};

#endif	/* TRAIN_H */

