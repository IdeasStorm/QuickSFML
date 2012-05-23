///* 
// * File:   Material.cpp
// * Author: adn
// * 
// * Created on May 5, 2012, 11:57 AM
// */
//
//#include "Material.h"
//#include "lib3ds/material.h"
//#include <qt4/QtGui/QImage>
//#include <qt4/QtOpenGL/QGLWidget>
//#include <SFML/Graphics.hpp>
//
//myMats::~myMats()
//{
//}
//myMats::myMats(Lib3dsMaterial *libMat)
//{
//    this->id=libMat->name;   // give material name to this Object
//
//    if(strcmp(libMat->texture1_map.name,"")==0) // Does it have Img Texture?
//    {
//                            this->img=false;
//                    return;
//    }
//    else // If Yes
//    {
//        this->img=true;  // Set that its a Imaged Texture
//        this->mapName=libMat->texture1_map.name; // give File name
//        QImage tex, buf;
//        if ( !buf.load( libMat->texture1_map.name ) )
//        {
//                qWarning( "Could not read image file, using single-color instead." );
//        }
//        tex = QGLWidget::convertToGLFormat( buf );
//        glGenTextures(1,&tID[0]);  // this is Important texture ID genrated is Given to This myMat Object
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // If the u,v coordinates overflow the range 0,1 the image is repeated
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); //The minifying function
//        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND); 
//        glTexImage2D( GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
//        GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );
//        gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, tex.width(), tex.height(),
//        GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );
//        this->qtTex=tex;
//    }
//}
//char* myMats::tellID()
//{
//		printf("\n %s",id);
//		return id;
//}
//bool myMats::imaged()
//{
//    return img;
//}
//
//char* myMats::tellMapName()
//{
//    printf("\n%s",mapName);
//    return mapName;
//}
//void myMats::add(Lib3dsMaterial* libMat)
//{
//
//}