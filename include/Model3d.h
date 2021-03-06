/* 
 * File:   Model3d.h
 * Author: adn
 *
 * Created on May 6, 2012, 11:41 PM
 */

#ifndef MODEL3D_H
#define	MODEL3D_H

#include "Light.h"
#include <SFML/Graphics.hpp>
#include <fstream>
//to map image filenames to textureIds
#include <string.h>
#include <map>
#include <iostream>


// assimp include files. These three are usually needed.

#include <assimp/assimp.hpp>
#include <assimp/aiScene.h>
#include <assimp/aiPostProcess.h>
#include <assimp/aiPostProcess.h>
#include <assimp/DefaultLogger.h>
#include <assimp/LogStream.h>
//#include <GL/glut.h>
#include <string>
#include "Drawable.h"

#define TRUE true
#define FALSE false

using namespace std;

class Model3d : public GLDrawable {
public:
    Model3d(const std::string& pFile, const std::string& path = "./");    
    ~Model3d();
    int LoadGLTextures(const aiScene* scene);
    void LoadComponents()const;

    void draw() {

        drawAiScene(scene);
        //recursive_render(scene, scene->mRootNode, 0.5);

    }
    virtual void WriteInstanceCreation(FILE* outfile, string name);

    virtual string getClass() {
        return "Model3d";
    }
    bool LoadContent();
    void GLInit();
    void Update(const sf::Input &input);
    
     void setTexture(const string& path) {
        textureEnabled = true;
        texture_path = path;
        Texture tex(path);
        textures.push_back(tex);
    }
    
    void  setTexture(Texture* tex){
        textureEnabled = true;
        textures.push_back(*tex);
    }
protected:
    //void Draw();

    void DisableTexture() {
    }

    GLDrawable* Clone() {
        Model3d *cloned = new Model3d(modelname,basepath);
        if (!texture_path.empty()){
            cloned->texture_path = texture_path;
            cloned->textureEnabled = true;
        }
        cloned->position = position;
        cloned->halfSize = halfSize;
        cloned->setRotation(yrot,xrot,zrot);
        return cloned;
    }
private:
    const aiScene* scene;
    GLuint scene_list;
    aiVector3D scene_min, scene_max, scene_center;
    list<Texture> textures;
    // images / texture
    std::map<std::string, GLuint*> textureIdMap; // map image filenames to textureIds
    GLuint* textureIds; // pointer to texture Array

    string basepath;
    string modelname;
    string texture_path;
    // Create an instance of the Importer class
    Assimp::Importer importer;

   
    
   inline void applyFaceTexture() {
        if (!textureEnabled || textures.empty()) 
            return;
        list<Texture>::iterator i;
        for (i=textures.begin();i!=textures.end();i++){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, i->getPtr(filter));                
                break;
        }
   }
    
    void Color4f(const aiColor4D *color) {
        glColor4f(color->r, color->g, color->b, color->a);
    }

    void set_float4(float f[4], float a, float b, float c, float d) {
        f[0] = a;
        f[1] = b;
        f[2] = c;
        f[3] = d;
    }

    void color4_to_float4(const aiColor4D *c, float f[4]) {
        f[0] = c->r;
        f[1] = c->g;
        f[2] = c->b;
        f[3] = c->a;
    }

    void apply_material(const aiMaterial *mtl) {
        float c[4];
        glPushMatrix();
        GLenum fill_mode;
        int ret1, ret2;
        aiColor4D diffuse;
        aiColor4D specular;
        aiColor4D ambient;
        aiColor4D emission;
        float shininess, strength;
        int two_sided;
        int wireframe;
        unsigned int max; // changed: to unsigned

        int texIndex = 0;
        aiString texPath; //contains filename of texture

        if (AI_SUCCESS == mtl->GetTexture(aiTextureType_DIFFUSE, texIndex, &texPath)) {
            //bind texture
            if(!textureEnabled)
            {
                glEnable(GL_TEXTURE_2D);
                unsigned int texId = *textureIdMap[texPath.data];
                glBindTexture(GL_TEXTURE_2D, texId);
            }
        }

        set_float4(c, 0.8f, 0.8f, 0.8f, 1.0f);
        if (AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
            color4_to_float4(&diffuse, c);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c);

        set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
        if (AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &specular))
            color4_to_float4(&specular, c);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);

        set_float4(c, 0.2f, 0.2f, 0.2f, 1.0f);
        if (AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &ambient))
            color4_to_float4(&ambient, c);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c);

        set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
        if (AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_EMISSIVE, &emission))
            color4_to_float4(&emission, c);
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c);

        max = 1;
        ret1 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS, &shininess, &max);
        max = 1;
        ret2 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS_STRENGTH, &strength, &max);
        if ((ret1 == AI_SUCCESS) && (ret2 == AI_SUCCESS))
            glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess * strength);
        else {
            glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);
            set_float4(c, 0.0f, 0.0f, 0.0f, 0.0f);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);
        }

        max = 1;
        if (AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_ENABLE_WIREFRAME, &wireframe, &max))
            fill_mode = wireframe ? GL_LINE : GL_FILL;
        else
            fill_mode = GL_FILL;
        glPolygonMode(GL_FRONT_AND_BACK, fill_mode);

        max = 1;
        if ((AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_TWOSIDED, &two_sided, &max)) && two_sided)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);

        glPopMatrix();
    }

    void print_array(aiMatrix4x4 m) {
        printf("%f, %f, %f, %f \n%f, %f, %f, %f \n%f, %f, %f, %f \n%f, %f, %f, %f \n",
                m.a1, m.b1, m.c1, m.d1,
                m.a2, m.b2, m.c2, m.d2,
                m.a3, m.b3, m.c3, m.d3,
                m.a4, m.b4, m.c4, m.d4);

    }

    void recursive_render(const struct aiScene *sc, const struct aiNode* nd, float scale) {
        unsigned int i;
        unsigned int n = 0, t;
        aiMatrix4x4 m = nd->mTransformation;
        aiMatrix4x4 m2;
        aiMatrix4x4::Scaling(aiVector3D(scale, scale, scale), m2);
        m = m * m2;
        // update transform
        m.Transpose();
        glPushMatrix();

        glMultMatrixf((float*) &m);

        // draw all meshes assigned to this node
        for (; n < nd->mNumMeshes; ++n) {
            const struct aiMesh* mesh = scene->mMeshes[nd->mMeshes[n]];
            apply_material(sc->mMaterials[mesh->mMaterialIndex]);

            if (mesh->mNormals == NULL) {
                glDisable(GL_LIGHTING);
            } else {
                glEnable(GL_LIGHTING);
            }

            if (mesh->mColors[0] != NULL) {
                glEnable(GL_COLOR_MATERIAL);
            } else {
                glDisable(GL_COLOR_MATERIAL);
            }



            for (t = 0; t < mesh->mNumFaces; ++t) {
                const struct aiFace* face = &mesh->mFaces[t];
                GLenum face_mode;

                switch (face->mNumIndices) {
                    case 1: face_mode = GL_POINTS;
                        break;
                    case 2: face_mode = GL_LINES;
                        break;
                    case 3: face_mode = GL_TRIANGLES;
                        break;
                    default: face_mode = GL_POLYGON;
                        break;
                }

                glBegin(face_mode);

                for (i = 0; i < face->mNumIndices; i++) // go through all vertices in face
                {
                    int vertexIndex = face->mIndices[i]; // get group index for current index
                    if (mesh->mColors[0] != NULL)
                        Color4f(&mesh->mColors[0][vertexIndex]);
                    if (mesh->mNormals != NULL)

                        if (mesh->HasTextureCoords(0)) //HasTextureCoords(texture_coordinates_set)
                        {
                            glTexCoord2f(mesh->mTextureCoords[0][vertexIndex].x, 1 - mesh->mTextureCoords[0][vertexIndex].y); //mTextureCoords[channel][vertex]
                        }
                    glNormal3fv(&mesh->mNormals[vertexIndex].x);
                    glVertex3fv(&mesh->mVertices[vertexIndex].x);
                }

                glEnd();

            }
            if(!textureEnabled) {
                glDisable(GL_TEXTURE_2D);
            }
        }


        // draw all children
        for (n = 0; n < nd->mNumChildren; ++n) {
            recursive_render(sc, nd->mChildren[n], scale);
        }

        glPopMatrix();
    }

    void drawAiScene(const aiScene* scene) {
        //	logInfo("drawing objects");
        applyFaceTexture();
        recursive_render(scene, scene->mRootNode, 1);
        glEnable(GL_COLOR_MATERIAL);
        float specular[4] = {1,1,1,1};
        float emission[4] = {0,0,0,1};
        glColor4f(1,1,1,1);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
        glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glDisable(GL_TEXTURE_2D);
    }

};

#endif	/* MODEL3D_H */

