/* 
 * File:   Ground.h
 * Author: mhdsyrwan
 *
 * Created on May 2, 2012, 8:17 PM
 */

#ifndef GROUND_H
#define	GROUND_H

#include "Drawable.h"

using namespace std;

class Ground : public DrawableGL{
public:
    Ground();
    Ground(const Ground& orig);
    void LoadComponents();
    void Update(const sf::Input&);
    virtual ~Ground();
    
    string box_texture;
private:
    GLfloat rot;

};

#endif	/* GROUND_H */

