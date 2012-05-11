/* 
 * File:   GLScene.cpp
 * Author: mhdsyrwan
 * 
 * Created on May 5, 2012, 2:08 PM
 */

#include <GL/glew.h>

#include "GLScene.h"

GLScene::GLScene(char* title) : window(sf::VideoMode(800, 600, 32), title) {    
    GLfloat LightAmbient[] ={0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat LightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat LightPosition[] = {0.0f, 0.0f, 2.0f, 1.0f};
    //GLfloat LightPosition[] = {20.0f, 20.0f, -40.0f, 1.0f};
    memcpy(this->LightAmbient, LightAmbient, sizeof LightAmbient);
    memcpy(this->LightDiffuse, LightDiffuse, sizeof LightDiffuse);
    memcpy(this->LightPosition, LightPosition, sizeof LightPosition);
    light = true;
    filter = 0;
    fullscreen = FALSE; // Fullscreen Flag Set To Fullscreen Mode By Default
    vsync = TRUE; // Turn VSYNC on/off
    update_child_controls = false;
}

GLScene::GLScene(const GLScene& orig) {
}

GLScene::~GLScene() {
}

int GLScene::Run() {
    // Create the main window
 
    if (!InitGL())
        printf("Warning : Content not Loaded ");
    
    ReSizeGLScene(800, 600);

    // Start game loop
    while (window.IsOpened()) {
        // Process events
        
        sf::Event Event;
        while (window.GetEvent(Event)) {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                window.Close();
        
            // Resize event : adjust viewport
            if (Event.Type == sf::Event::Resized)
                ReSizeGLScene(Event.Size.Width, Event.Size.Height);

            // Handle Keyboard Events
            if (Event.Type == sf::Event::KeyPressed) {

                switch (Event.Key.Code) {
                    case sf::Key::Escape:
                        window.Close();
                        break;
                    case sf::Key::F1:
                        fullscreen = !fullscreen;
                        window.Create(fullscreen ? sf::VideoMode::GetDesktopMode() : sf::VideoMode(800, 600, 32), "SFML/NeHe OpenGL",
                                (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize | sf::Style::Close));
                        ReSizeGLScene(window.GetWidth(), window.GetHeight());
                        break;
                    case sf::Key::F5:
                        vsync = !vsync;
                        break;
                    case sf::Key::L:
                        light = !light;
                        if (!light) {
                            glDisable(GL_LIGHTING);
                        } else {
                            glEnable(GL_LIGHTING);
                        }
                        break;
                    case sf::Key::F:
                        filter += 1;
                        if (filter > 2) {
                            filter = 0;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        
        
        window.SetCursorPosition(window.GetWidth()/2,window.GetHeight()/2);
        //Handle movement keys
        const sf::Input& Input = window.GetInput();

        
        if (cameraEnable == 1 )
                camera.UpdateCamera(Input,window.GetWidth()/2,window.GetHeight()/2);
        else if (cameraEnable == 2)
                camera2.UpdateCamera(Input,window.GetWidth()/2,window.GetHeight()/2);
        else if (cameraEnable == 3)
                camera3.UpdateCamera(Input,window.GetWidth()/2,window.GetHeight()/2);
        Update(Input);
        

        // Turn VSYNC on so that animations run at a more reasonable speed on new CPU's/GPU's.
        window.UseVerticalSync(vsync);

        // Set the active window before using OpenGL commands
        // It's useless here because active window is always the same,
        // but don't forget it if you use multiple windows or controls
        window.SetActive();

        //Draw some pretty stuff
        
        Draw();

        // Finally, display rendered frame on screen
        window.Display();
    }

    return EXIT_SUCCESS;
}

int GLScene::InitGL() // All Setup For OpenGL Goes Here
{
    LoadComponents();
    if (!LoadContent()) // Jump To Texture Loading Routine
    {
        return FALSE; // If Texture Didn't Load Return FALSE
    }
    cameraEnable = 1 ;
    glewInit();
    glEnable(GL_TEXTURE_2D); // Enable Texture Mapping
    glShadeModel(GL_SMOOTH); // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
    glClearDepth(1.0f); // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    // setup lighting for each component
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((GLDrawable*)(*i))->GLInit();
    }
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient); // Setup The Ambient Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse); // Setup The Diffuse Light
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition); // Position The Light
    glEnable(GL_LIGHT1); // Enable Light One
    glEnable(GL_LIGHTING);
//    model->CreateVBO();
    
    return TRUE; // Initialization Went OK
}


GLvoid GLScene::ReSizeGLScene(GLsizei width, GLsizei height) // Resize And Initialize The GL Window
{
    if (height == 0) // Prevent A Divide By Zero By
    {
        height = 1; // Making Height Equal One
    }

    glViewport(0, 0, width, height); // Reset The Current Viewport

   
    glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
    glLoadIdentity(); // Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window    
    gluPerspective(45.0f,(GLfloat) 800 / (GLfloat) 600, 0.1f, 500.0f);

    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity(); // Reset The Modelview Matrix
}

void GLScene::Draw() // Here's Where We Do All The Drawing
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
        
    glLoadIdentity(); // Reset The View
        
    list<GLDrawable*>::iterator i;
    
    glLoadIdentity(); // Reset The View
    if (cameraEnable == 1)
        camera.ApplyCamera();
    else if (cameraEnable ==2)
        camera2.ApplyCamera();
    else if (cameraEnable ==3)
        camera3.ApplyCamera();
    
    for (i=components.begin();i!=components.end();i++){
        glPushMatrix();
        ((GLDrawable*)(*i))->Draw();
        glPopMatrix();
    }
    
    
    xrot += xspeed;
    yrot += yspeed;
    //return TRUE; // Keep Going
}
bool GLScene::LoadContent() {   
    bool Status=true;									// Status Indicator
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        Status = Status && ((GLDrawable*)(*i))->LoadContent();
    }
    return Status;
}

void GLScene::LoadComponents() {
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        ((GLDrawable*)(*i))->LoadComponents();
    }
}

void GLScene::Update(const sf::Input& input) {
    list<GLDrawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){            
        if (update_child_controls && ((GLDrawable*)(*i))->self_control )
                ((GLDrawable*)(*i))->Update(input);
        ((GLDrawable*)(*i))->filter = filter;
    }
}