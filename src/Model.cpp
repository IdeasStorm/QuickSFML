/* 
 * File:   Model.cpp
 * Author: adn
 * 
 * Created on May 5, 2012, 11:07 AM
 */


#include "Model.h"


Model::Model(std::string filename)
{
    this->filename = filename;
    m_VertexVBO = 0;
    m_TotalFaces = 0;
    m_model=lib3ds_file_load(filename.data());
        //m_model = lib3ds_file_load(filename.c_str());
        // If loading the model failed, we throw an exception
    if(!m_model)
    {
            throw strcat("Unable to load ", filename.c_str());
    }
    position.x = position.y = position.z = rotation = 0 ;
}


void Model::GetFaces()
{
        assert(m_model != NULL);

        m_TotalFaces = 0;
        Lib3dsMesh * mesh;
        // Loop through every mesh
        for(mesh = m_model->meshes;mesh != NULL;mesh = mesh->next)
        {
                // Add the number of faces this mesh has to the total faces
                m_TotalFaces += mesh->faces;
        }
}


//void Model::SetupLighting()


bool Model::LoadContent() {
    // Calculate the number of faces we have in total
    GetFaces();
    if (m_TotalFaces > 0)
        return true;
    else
        return false;
}

void Model::GLInit()

{
         assert(m_model != NULL);
       
       
        // Allocate memory for our vertices and normals
        Lib3dsVector * vertices = new Lib3dsVector[m_TotalFaces * 3];
        Lib3dsVector * normals = new Lib3dsVector[m_TotalFaces * 3];
       
        Lib3dsMesh * mesh;
        unsigned int FinishedFaces = 0;
        // Loop through all the meshes
        for(mesh = m_model->meshes;mesh != NULL;mesh = mesh->next)
        {
                lib3ds_mesh_calculate_normals(mesh, &normals[FinishedFaces*3]);
                // Loop through every face
                for(unsigned int cur_face = 0; cur_face < mesh->faces;cur_face++)
                {
                        Lib3dsFace * face = &mesh->faceL[cur_face];
                        for(unsigned int i = 0;i < 3;i++)
                        {
                                memcpy(&vertices[FinishedFaces*3 + i], mesh->pointL[face->points[ i ]].pos, sizeof(Lib3dsVector));
                        }
                        FinishedFaces++;
                }
        }
       
        // Generate a Vertex Buffer Object and store it with our vertices
        glGenBuffers(1, &m_VertexVBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Lib3dsVector) * 3 * m_TotalFaces, vertices, GL_STATIC_DRAW);
       
        // Generate another Vertex Buffer Object and store the normals in it
        glGenBuffers(1, &m_NormalVBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_NormalVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Lib3dsVector) * 3 * m_TotalFaces, normals, GL_STATIC_DRAW);
       
        // Clean up our allocated memory
        delete vertices;
        delete normals;              
        
        // We no longer need lib3ds
        lib3ds_file_free(m_model);
        m_model = NULL;
        // :)
        //return true;
}

void Model::draw()
{
        assert(m_TotalFaces != 0);
        
        //TODO make better mechanism
        if (textureEnabled) {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, texture[filter]);
        }
        else {
            glDisable(GL_TEXTURE_2D);
        }
        
        // Enable vertex and normal arrays
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
       
        // Bind the vbo with the normals
        glBindBuffer(GL_ARRAY_BUFFER, m_NormalVBO);
        // The pointer for the normals is NULL which means that OpenGL will use the currently bound vbo
        glNormalPointer(GL_FLOAT, 0, NULL);
       
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexVBO);
        glVertexPointer(3, GL_FLOAT, 0, NULL);
       
        // Render the triangles
        glDrawArrays(GL_TRIANGLES, 0, m_TotalFaces * 3);
       
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        
        glTranslatef(-5,0,0)      ;
}

void Model::Update(const sf::Input& input)
{
    
}

GLDrawable* Model::Clone() {
    Model* cloned = new Model(filename);
    cloned->LoadContent();
    cloned->GLInit();
    cloned->position = position;
    cloned->halfSize = halfSize;
    if (axis_angle)
        cloned->setRotation(rotationAxis,rotation);
    else
        cloned->setRotation(yrot,xrot,zrot);
    cloned->textureEnabled = textureEnabled;
    return cloned;
}

void Model::WriteInstanceCreation(FILE* outfile, string name) {
    fprintf(outfile,"%s *%s = new %s(\"%s\");\n",
            this->getClass().data(),
            name.data(),this->getClass().data(),
            this->filename.data()
    );
}