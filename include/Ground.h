/* 
 * File:   Ground.h
 * Author: mhdsyrwan
 *
 * Created on May 2, 2012, 8:17 PM
 */

#ifndef GROUND_H
#define	GROUND_H

#include "Drawable.h"

class Ground : public Drawable{
public:
    Ground();
    Ground(const Ground& orig);
    void Draw();
    bool LoadContent();
    void Update(const sf::Input&);
    virtual ~Ground();
private:
    GLfloat rot;

};

#endif	/* GROUND_H */

