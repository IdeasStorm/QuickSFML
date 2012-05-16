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
    basepath = "./Data/Train/1/";
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
                //filename = "SpiderTex.jpg";
                
                // removing backward slash
                if (filename.empty()) continue;
                std::replace( filename.begin(), filename.end(), '\\', '/');
                
                std::string fileloc = basepath + filename;	/* Loading of image */
                
                sf::Image image;
                
		//success = ilLoadImage(fileloc.c_str());
                ILenum error = ilGetError();
		if (image.LoadFromFile(fileloc)) /* If no error occured: */
		{
			//glGenTextures(numTextures, &textureIds[i]); /* Texture name generation */
			glBindTexture(GL_TEXTURE_2D, textureIds[i]); /* Binding of texture name */
			//redefine standard texture values
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear
			interpolation for magnification filter */
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear
			interpolation for minifying filter */
                        glTexImage2D(GL_TEXTURE_2D, 0, 3, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetPixelsPtr());
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


	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);		 // Enables Smooth Shading
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClearDepth(1.0f);				// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);		// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);			// The Type Of Depth Test To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculation


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);    // Uses default lighting parameters
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);

//	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
//	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT1);

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



void Model3d::WriteInstanceCreation(FILE* outfile, string name) {
    fprintf(outfile,"%s *%s = new %s(\"%s\");\n",
            this->getClass().data(),
            name.data(),this->getClass().data(),
            this->modelname.data()
    );
}
        