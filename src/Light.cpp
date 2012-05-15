/* 
 * File:   Light.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 4, 2012, 3:44 PM
 */


#include "Light.h"

GLfloat* vec4(sf::Color color){
    GLfloat* res = new GLfloat[4];
    res[0] = color.r;
    res[1] = color.g;
    res[2] = color.b;
    res[3] = color.a;
    return res;
}
Light::Light():GLDrawable(){
    ligthEnable = true ;
    angle = 45;
}

Light::Light(sf::Vector3f pos, float ang): GLDrawable(){

    EnableSphere = true ;
    sphere = new Sphere(position,20);
    position = pos ;
    ligthEnable = true ;
    angle = ang ;
}

Light::Light(const Light& orig) {
}

Light::~Light() {
}

void Light::init()
{
}
void Light::Update(const sf::Input& input)
{
    
    spot_direction[0] = 0.0 ;
    spot_direction[1] = 1.0 ;
    spot_direction[2] = 0.0 ;
    
}
bool Light::LoadContent()
{
    
}
void Light::draw() 
{
    GLInit();
    if (EnableSphere)
        sphere->Draw();
}

GLDrawable* Light::Clone() {
    /*Light* cloned = new Light();
    cloned->position = position;
    cloned->halfSize = halfSize;
    if (axis_angle)
        cloned->setRotation(rotationAxis, rotation);
    else
        cloned->setRotation(yrot, xrot, zrot);
    if (textureEnabled) {
        cloned->setTexture(texture_path);
    } else {
        cloned->texture_path = texture_path;
    }
    return cloned;
     */
}

void Light::GLInit() {
    
    if (ligthEnable)
    {
        GLfloat temp[]={position.x,position.y,position.z,w};
        glLightfv(GL_LIGHT0,GL_POSITION,temp);
    //    glLightfv(GL_LIGHT0,GL_AMBIENT,vec4(ambient));
//        glLightfv(GL_LIGHT0,GL_DIFFUSE,vec4(diffuse));
//        glLightfv(GL_LIGHT0,GL_SPECULAR,vec4(specular));

        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, angle);
        //glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
        glEnable(GL_LIGHT0); 
        
        GLfloat colours [] = { 1.0, 1.0, 0.0, 0.0 };
//        glEnable ( GL_COLOR_MATERIAL ) ; 
        glColorMaterial ( GL_FRONT_AND_BACK, GL_SPECULAR ) ; 
        //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,colours ) ;
        
//        glColor3f(1.0, 1.0, 1.0);
//        glDisable(GL_COLOR_MATERIAL);

    }else
        glDisable(GL_LIGHT0);
    
}

