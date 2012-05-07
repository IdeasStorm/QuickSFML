/* 
 * File:   ModelHelper.h
 * Author: adn
 *
 * Created on May 6, 2012, 11:00 PM
 */

#ifndef MODELHELPER_H
#define	MODELHELPER_H





#include <fstream>

//to map image filenames to textureIds
#include <string.h>
#include <map>
#include <iostream>


// assimp include files. These three are usually needed.


#define TRUE true
#define FALSE false
bool	fullscreen=FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default
bool    vsync=TRUE;         // Turn VSYNC on/off
bool	light;				// Lighting ON/OFF ( NEW )

GLfloat	xrot;				// X Rotation
GLfloat	yrot;				// Y Rotation
GLfloat xspeed;				// X Rotation Speed
GLfloat yspeed;				// Y Rotation Speed
GLfloat	z=-5.0f;			// Depth Into The Screen

GLfloat LightAmbient[]=		{ 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]=		{ 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]=	{ 0.0f, 0.0f, 2.0f, 1.0f };

GLuint	filter;				// Which Filter To Use
GLuint	texture[3];			// Storage For 3 Textures

// the global Assimp scene object





GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int InitGL()										    // All Setup For OpenGL Goes Here
{
    if (!LoadGLTextures(scene))
	{
		return FALSE;
	}


	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);		 // Enables Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClearDepth(1.0f);				// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);		// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);			// The Type Of Depth Test To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculation


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);    // Uses default lighting parameters
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT1);

	//glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);


	return TRUE;					// Initialization Went OK
}


void Color4f(const aiColor4D *color)
{
	glColor4f(color->r, color->g, color->b, color->a);
}

void set_float4(float f[4], float a, float b, float c, float d)
{
	f[0] = a;
	f[1] = b;
	f[2] = c;
	f[3] = d;
}

void color4_to_float4(const aiColor4D *c, float f[4])
{
	f[0] = c->r;
	f[1] = c->g;
	f[2] = c->b;
	f[3] = c->a;
}

void apply_material(const aiMaterial *mtl)
{
	float c[4];

	GLenum fill_mode;
	int ret1, ret2;
	aiColor4D diffuse;
	aiColor4D specular;
	aiColor4D ambient;
	aiColor4D emission;
	float shininess, strength;
	int two_sided;
	int wireframe;
	unsigned int max;	// changed: to unsigned

	int texIndex = 0;
	aiString texPath;	//contains filename of texture

	if(AI_SUCCESS == mtl->GetTexture(aiTextureType_DIFFUSE, texIndex, &texPath))
	{
		//bind texture
		unsigned int texId = *textureIdMap[texPath.data];
		glBindTexture(GL_TEXTURE_2D, texId);
	}

	set_float4(c, 0.8f, 0.8f, 0.8f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
		color4_to_float4(&diffuse, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c);

	set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &specular))
		color4_to_float4(&specular, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);

	set_float4(c, 0.2f, 0.2f, 0.2f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &ambient))
		color4_to_float4(&ambient, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c);

	set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_EMISSIVE, &emission))
		color4_to_float4(&emission, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c);

	max = 1;
	ret1 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS, &shininess, &max);
	max = 1;
	ret2 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS_STRENGTH, &strength, &max);
	if((ret1 == AI_SUCCESS) && (ret2 == AI_SUCCESS))
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess * strength);
	else {
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);
		set_float4(c, 0.0f, 0.0f, 0.0f, 0.0f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);
	}

	max = 1;
	if(AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_ENABLE_WIREFRAME, &wireframe, &max))
		fill_mode = wireframe ? GL_LINE : GL_FILL;
	else
		fill_mode = GL_FILL;
	glPolygonMode(GL_FRONT_AND_BACK, fill_mode);

	max = 1;
	if((AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_TWOSIDED, &two_sided, &max)) && two_sided)
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);
}



void recursive_render (const struct aiScene *sc, const struct aiNode* nd, float scale)
{
	unsigned int i;
	unsigned int n=0, t;
	aiMatrix4x4 m = nd->mTransformation;

	m.Scaling(aiVector3D(scale, scale, scale), m);

	// update transform
	m.Transpose();
	glPushMatrix();
	glMultMatrixf((float*)&m);

	// draw all meshes assigned to this node
	for (; n < nd->mNumMeshes; ++n)
	{
		const struct aiMesh* mesh = scene->mMeshes[nd->mMeshes[n]];

		apply_material(sc->mMaterials[mesh->mMaterialIndex]);


		if(mesh->mNormals == NULL)
		{
			glDisable(GL_LIGHTING);
		}
		else
		{
			glEnable(GL_LIGHTING);
		}

		if(mesh->mColors[0] != NULL)
		{
			glEnable(GL_COLOR_MATERIAL);
		}
		else
		{
			glDisable(GL_COLOR_MATERIAL);
		}



		for (t = 0; t < mesh->mNumFaces; ++t) {
			const struct aiFace* face = &mesh->mFaces[t];
			GLenum face_mode;

			switch(face->mNumIndices)
			{
				case 1: face_mode = GL_POINTS; break;
				case 2: face_mode = GL_LINES; break;
				case 3: face_mode = GL_TRIANGLES; break;
				default: face_mode = GL_POLYGON; break;
			}

			glBegin(face_mode);

			for(i = 0; i < face->mNumIndices; i++)		// go through all vertices in face
			{
				int vertexIndex = face->mIndices[i];	// get group index for current index
				if(mesh->mColors[0] != NULL)
					Color4f(&mesh->mColors[0][vertexIndex]);
				if(mesh->mNormals != NULL)

					if(mesh->HasTextureCoords(0))		//HasTextureCoords(texture_coordinates_set)
					{
						glTexCoord2f(mesh->mTextureCoords[0][vertexIndex].x, 1 - mesh->mTextureCoords[0][vertexIndex].y); //mTextureCoords[channel][vertex]
					}

					glNormal3fv(&mesh->mNormals[vertexIndex].x);
					glVertex3fv(&mesh->mVertices[vertexIndex].x);
			}

			glEnd();

		}

	}


	// draw all children
	for (n = 0; n < nd->mNumChildren; ++n)
	{
		recursive_render(sc, nd->mChildren[n], scale);
	}

	glPopMatrix();
}



void drawAiScene(const aiScene* scene)
{
//	logInfo("drawing objects");

	recursive_render(scene, scene->mRootNode, 0.5);

}

int DrawGLScene()									    // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View
       // box.Draw();
        
        drawAiScene(scene);

	xrot+=xspeed;
	yrot+=yspeed;
	return TRUE;										// Keep Going
}

//int main()
//{
//    // Create the main window
//    sf::Window App(sf::VideoMode(800, 600, 32), "SFML/NeHe OpenGL");
//
//    Import3DFromFile(basepath+modelname);
//            
//    InitGL();
//    ReSizeGLScene(800, 600);
//
//    // Start game loop
//    while (App.IsOpened())
//    {
//        // Process events
//        sf::Event Event;
//        while (App.GetEvent(Event))
//        {
//            // Close window : exit
//            if (Event.Type == sf::Event::Closed)
//                App.Close();
//
//            // Resize event : adjust viewport
//            if (Event.Type == sf::Event::Resized)
//                ReSizeGLScene(Event.Size.Width, Event.Size.Height);
//
//            // Handle Keyboard Events
//            if (Event.Type == sf::Event::KeyPressed) {
//                switch (Event.Key.Code) {
//                    case sf::Key::Escape:
//                        App.Close();
//                        break;
//                    case sf::Key::F1:
//                        fullscreen = !fullscreen;
//                        App.Create(fullscreen ? sf::VideoMode::GetDesktopMode() : sf::VideoMode(800, 600, 32) , "SFML/NeHe OpenGL",
//                        (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize | sf::Style::Close));
//                        ReSizeGLScene(App.GetWidth(),App.GetHeight());
//                        break;
//                    case sf::Key::F5:
//                        vsync = !vsync;
//                        break;
//                    case sf::Key::L:
//                        light=!light;
//                        if (!light) {
//                            glDisable(GL_LIGHTING);
//                        } else {
//                            glEnable(GL_LIGHTING);
//                        }
//                        break;
//                    case sf::Key::F:
//                        filter+=1;
//                        if (filter>2) {
//                            filter=0;
//                        }
//                        break;
//                    default:
//                        break;
//                }
//            }
//        }
//
//        //Handle movement keys
//        const sf::Input& Input = App.GetInput();
//
//        if (Input.IsKeyDown(sf::Key::PageUp)) {
//            z-=0.02f;
//        }
//        if (Input.IsKeyDown(sf::Key::PageDown)) {
//            z+=0.02f;
//        }
//        if (Input.IsKeyDown(sf::Key::Up)) {
//            xspeed-=0.01f;
//        }
//        if (Input.IsKeyDown(sf::Key::Down)) {
//            xspeed+=0.01f;
//        }
//        if (Input.IsKeyDown(sf::Key::Right)) {
//            yspeed+=0.01f;
//        }
//        if (Input.IsKeyDown(sf::Key::Left)) {
//            yspeed-=0.01f;
//        }
//
//        
//        // Turn VSYNC on so that animations run at a more reasonable speed on new CPU's/GPU's.
//        App.UseVerticalSync(vsync);
//
//        // Set the active window before using OpenGL commands
//        // It's useless here because active window is always the same,
//        // but don't forget it if you use multiple windows or controls
//        App.SetActive();
//
//        //Draw some pretty stuff
//        DrawGLScene();
//
//        // Finally, display rendered frame on screen
//        App.Display();
//    }
//
//    return EXIT_SUCCESS;
//}

#endif	/* MODELHELPER_H */

