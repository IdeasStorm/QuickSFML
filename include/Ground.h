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

class Ground : public GLDrawable{
public:
    Ground();
    Ground(const Ground& orig);
    void LoadComponents();
    void Update(const sf::Input&);
    inline string getClass(){
        return "Ground";
    }
    virtual ~Ground();
    
    string box_texture;
    
protected:
    inline void draw() {
        
    }
private:
    GLfloat rot;

};

#endif	/* GROUND_H */

