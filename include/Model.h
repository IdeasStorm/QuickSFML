/* 
 * File:   Model.h
 * Author: adn
 *
 * Created on May 5, 2012, 11:07 AM
 */

#ifndef MODEL_H
#define	MODEL_H
#include <GL/glew.h>
#include <lib3ds/file.h>
#include <lib3ds/mesh.h>

#include "Drawable.h"

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <string>



class Model : public GLDrawable
{
    public :
        Model(std::string filename);  
        bool LoadContent();
        void Update(const sf::Input &input);
        void GLInit();
        
    protected:
        inline void draw();
    private:
        void GetFaces();
        unsigned int m_TotalFaces;
        Lib3dsFile * m_model;
        GLuint m_VertexVBO, m_NormalVBO;
};

#endif	/* MODEL_H */

