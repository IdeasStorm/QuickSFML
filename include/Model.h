/* 
 * File:   Model.h
 * Author: adn
 *
 * Created on May 5, 2012, 11:07 AM
 */

#ifndef MODEL_H
#define	MODEL_H

#include <string>
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <lib3ds/file.h>
#include "Drawable.h"

class Model : public GLDrawable
{
    public :
        Model(std::string filename);  
        void Draw() const;
        bool LoadContent();
        void Update(const sf::Input &input);
    private:
        void GetFaces();
        unsigned int m_TotalFaces;
        Lib3dsFile * m_model;
        GLuint m_VertexVBO, m_NormalVBO;
};

#endif	/* MODEL_H */

