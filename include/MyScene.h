/* 
 * File:   MyScene.h
 * Author: mhdsyrwan
 *
 * Created on May 5, 2012, 5:06 PM
 */

#ifndef MYSCENE_H
#define	MYSCENE_H
#include "GLScene.h"

class MyScene : public GLScene {
public:
    MyScene(char* title = "SFML/OpenGL") : GLScene(title) {};
    MyScene(const MyScene& orig);
    void Update(const sf::Input& input);
    void LoadComponents();
    virtual ~MyScene();

private:

};

#endif	/* MYSCENE_H */

