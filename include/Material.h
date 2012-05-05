/* 
 * File:   Material.h
 * Author: adn
 *
 * Created on May 5, 2012, 11:57 AM
 */

#ifndef MATERIAL_H
#define	MATERIAL_H

#include "lib3ds/material.h"
#include <qt4/QtGui/QImage>
#include <qt4/QtGui/qwidget.h>
#include <SFML/Graphics.hpp>

class myMats{

public:
	myMats(){} // Empty Constructor
	myMats(Lib3dsMaterial *); // this one is USed
//	myMats(const myMats& orig) // Copy Constructor  
//	{
//		id=orig.id;
//		img=orig.img;
//		if(!img)
//			return;
//		mapName=orig.mapName;
//		//texture=orig.texture;
//
//	}
	//myMats();
	~myMats();
	
	char* id;  //   Name of Material 
	bool img;  // Does this Material has Image??
	char* mapName; // name of the BMP FILE
	GLuint tID[1];  //   Id of texture once Loaded in OpenGL
	char* tellID();
	bool imaged();
	char* tellMapName();
	void add(Lib3dsMaterial*);
	QImage qtTex; // Saves Texture Object made by QT ( No need but just in case)
	private:
	int BuildTexture(char *szPathName, GLuint &texid);
	
};


#endif	/* MATERIAL_H */

