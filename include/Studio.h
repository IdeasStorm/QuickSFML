/* 
 * File:   Studio.h
 * Author: mhdsyrwan
 *
 * Created on May 5, 2012, 7:44 PM
 */

#ifndef STUDIO_H
#define	STUDIO_H
#include <SFML/Graphics.hpp>
#include "GLScene.h"
#include <list>
#include "Box.h"

using namespace std;

class Studio : public GLScene {
public:
    Studio();
    Studio(const Studio& orig);
    void Update(const sf::Input& input);
    void LoadComponents();
    
    virtual ~Studio();
private:
    

};

#endif	/* STUDIO_H */

