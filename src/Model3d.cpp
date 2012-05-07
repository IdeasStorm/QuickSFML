/* 
 * File:   Model3d.cpp
 * Author: adn
 * 
 * Created on May 6, 2012, 11:41 PM
 */

#include "Model3d.h"
#include <fstream>
Model3d::Model3d(const std::string& pFile) 
{
    basepath = "./Data/OBJ/";
    modelname= pFile;
    std::string temp(basepath+modelname);
    std::ifstream fin(temp.c_str());
	if(!fin.fail())
	{
		fin.close();
	}
	else
	{		
		abort();
	}

	scene = importer.ReadFile( temp, aiProcessPreset_TargetRealtime_Quality);

	// If the import failed, report it
	if( !scene)
	{		
		abort();
	}

	// We're done. Everything will be cleaned up by the importer destructor        
}


int Model3d::LoadGLTextures(const aiScene* scene)
{
	
	ILboolean success;

	/* Before calling ilInit() version should be checked. */
	if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
	{
		ILint test = ilGetInteger(IL_VERSION_NUM);
		/// wrong DevIL version ///
		std::string err_msg = "Wrong DevIL version. Old devil.dll in system32/SysWow64?";
		char* cErr_msg = (char *) err_msg.c_str();
		//abortGLInit(cErr_msg);
		return -1;
	}

	ilInit(); /* Initialization of DevIL */

	if (scene->HasTextures()) 
            return false;
            //abortGLInit("Support for meshes with embedded textures is not implemented");

	/* getTexture Filenames and Numb of Textures */
	for (unsigned int m=0; m<scene->mNumMaterials; m++)
	{
		int texIndex = 0;
		aiReturn texFound = AI_SUCCESS;

		aiString path;	// filename

		while (texFound == AI_SUCCESS)
		{
			texFound = scene->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
			
                        textureIdMap[path.data] = NULL; //fill map with textures, pointers still NULL yet
			texIndex++;
		}
	}

	int numTextures = textureIdMap.size();

	/* array with DevIL image IDs */
	ILuint* imageIds = NULL;
	imageIds = new ILuint[numTextures];

	/* generate DevIL Image IDs */
	ilGenImages(numTextures, imageIds); /* Generation of numTextures image names */

	/* create and fill array with GL texture ids */
	textureIds = new GLuint[numTextures];
	glGenTextures(numTextures, textureIds); /* Texture name generation */

	/* define texture path */
	//std::string texturepath = "../../../test/models/Obj/";

	/* get iterator */
	std::map<std::string, GLuint*>::iterator itr = textureIdMap.begin();

	for (int i=0; i<numTextures; i++)
	{

		//save IL image ID
		std::string filename = (*itr).first;  // get filename
		(*itr).second =  &textureIds[i];	  // save texture id for filename in map
		itr++;								  // next texture


		ilBindImage(imageIds[i]); /* Binding of DevIL image name */
                filename = "SpiderTex.jpg";
                std::string fileloc = basepath + filename;	/* Loading of image */
		success = ilLoadImage(fileloc.c_str());

		if (success) /* If no error occured: */
		{
			success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE); /* Convert every colour component into
			unsigned byte. If your image contains alpha channel you can replace IL_RGB with IL_RGBA */
			if (!success)
			{
				/* Error occured */
				//abortGLInit("Couldn't convert image");
				return -1;
			}
			//glGenTextures(numTextures, &textureIds[i]); /* Texture name generation */
			glBindTexture(GL_TEXTURE_2D, textureIds[i]); /* Binding of texture name */
			//redefine standard texture values
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear
			interpolation for magnification filter */
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear
			interpolation for minifying filter */
			glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
				ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
				ilGetData()); /* Texture specification */
		}
		else
		{
			/* Error occured */
			//MessageBox(NULL, ("Couldn't load Image: " + fileloc).c_str() , "ERROR", MB_OK | MB_ICONEXCLAMATION);
		}


	}

	ilDeleteImages(numTextures, imageIds); /* Because we have already copied image data into texture data
	we can release memory used by image. */

	//Cleanup
	delete [] imageIds;
	imageIds = NULL;

	//return success;
	return TRUE;									// Return The Status
}



void Model3d::GLInit()
{
if (!LoadGLTextures(scene))
	{
		return;
	}


//	glEnable(GL_TEXTURE_2D);
//	glShadeModel(GL_SMOOTH);		 // Enables Smooth Shading
//	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//	glClearDepth(1.0f);				// Depth Buffer Setup
//	glEnable(GL_DEPTH_TEST);		// Enables Depth Testing
//	glDepthFunc(GL_LEQUAL);			// The Type Of Depth Test To Do
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculation
//
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);    // Uses default lighting parameters
//	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
//	glEnable(GL_NORMALIZE);
//
////	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
////	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
////	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
//	glEnable(GL_LIGHT1);

	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);


	return ;					// Initialization Went OK
}

void Model3d::Update(const sf::Input& input)
{    
}

bool Model3d::LoadContent() {
    return true;
}

Model3d::~Model3d() {
}

void Model3d::Draw()
{
    recursive_render(scene, scene->mRootNode, 0.5);

//    xrot+=xspeed;
//    yrot+=yspeed;
}
