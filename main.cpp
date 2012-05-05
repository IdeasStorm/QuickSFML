/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing The Base Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */
#define TRUE true
#define FALSE false

#include <SFML/Graphics.hpp>
#include <Drawable.h>
#include "Box.h"
#include "Ground.h"
#include <list>
#include "glframe.h"
using namespace std;

list<Drawable*> components;


GLFrame camera ;
bool fullscreen = FALSE; // Fullscreen Flag Set To Fullscreen Mode By Default
bool vsync = TRUE; // Turn VSYNC on/off
bool light; // Lighting ON/OFF ( NEW )

GLfloat xrot; // X Rotation
GLfloat yrot; // Y Rotation
GLfloat xspeed; // X Rotation Speed
GLfloat yspeed; // Y Rotation Speed
GLfloat z = -5.0f; // Depth Into The Screen

GLfloat LightAmbient[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat LightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat LightPosition[] = {0.0f, 0.0f, 2.0f, 1.0f};

GLuint filter; // Which Filter To Use
GLuint texture[3]; // Storage For 3 Textures




void LoadComponents(){   
    Box* box = new Box(Vector3(0,0,-5), Vector3(1,1,1),elements::OpenBox);
    box->setTexture("./Data/NeHe.bmp");
    components.push_back(box);
    //components.push_back(new Ground);

}

int LoadGLTextures() // Load Bitmaps And Convert To Textures
{
    bool Status=true;									// Status Indicator
    list<Drawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        Status = Status && (*i)->LoadContent();
    }
    return Status;

}

GLvoid ReSizeGLScene(GLsizei width, GLsizei height) // Resize And Initialize The GL Window
{
    if (height == 0) // Prevent A Divide By Zero By
    {
        height = 1; // Making Height Equal One
    }

    glViewport(0, 0, width, height); // Reset The Current Viewport

   
    glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
    glLoadIdentity(); // Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window    
    gluPerspective(45.0f,(GLfloat) 800 / (GLfloat) 600, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity(); // Reset The Modelview Matrix
}

int InitGL() // All Setup For OpenGL Goes Here
{
    LoadComponents();
    if (!LoadGLTextures()) // Jump To Texture Loading Routine
    {
        return FALSE; // If Texture Didn't Load Return FALSE
    }
   
    glEnable(GL_TEXTURE_2D); // Enable Texture Mapping
    glShadeModel(GL_SMOOTH); // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
    glClearDepth(1.0f); // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    // setup lighting for each component
    list<Drawable*>::iterator i;
    for (i=components.begin();i!=components.end();i++){
        (*i)->SetupLighting();
    }
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient); // Setup The Ambient Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse); // Setup The Diffuse Light
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition); // Position The Light
    glEnable(GL_LIGHT1); // Enable Light One
    return TRUE; // Initialization Went OK
}

int DrawGLScene() // Here's Where We Do All The Drawing
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
        
    glLoadIdentity(); // Reset The View

        
    list<Drawable*>::iterator i;
    
    glLoadIdentity(); // Reset The View
    camera.ApplyCamera();
    for (i=components.begin();i!=components.end();i++){
        (*i)->Draw();
    }

    xrot += xspeed;
    yrot += yspeed;
    return TRUE; // Keep Going
}

int main() {
    // Create the main window
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML/NeHe OpenGL");
    InitGL();
    
    ReSizeGLScene(800, 600);

    // Start game loop
    while (App.IsOpened()) {
        // Process events
        
        sf::Event Event;
        while (App.GetEvent(Event)) {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        
            // Resize event : adjust viewport
            if (Event.Type == sf::Event::Resized)
                ReSizeGLScene(Event.Size.Width, Event.Size.Height);

            // Handle Keyboard Events
            if (Event.Type == sf::Event::KeyPressed) {

                switch (Event.Key.Code) {
                    case sf::Key::Escape:
                        App.Close();
                        break;
                    case sf::Key::F1:
                        fullscreen = !fullscreen;
                        App.Create(fullscreen ? sf::VideoMode::GetDesktopMode() : sf::VideoMode(800, 600, 32), "SFML/NeHe OpenGL",
                                (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize | sf::Style::Close));
                        ReSizeGLScene(App.GetWidth(), App.GetHeight());
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
        float a = App.GetWidth()/2;
        float b = App.GetHeight()/2; 
        App.SetCursorPosition(a,b);
        //Handle movement keys
        const sf::Input& Input = App.GetInput();
        list<Drawable*>::iterator i;
        
        camera.UpdateCamera(Input,a,b);
        for (i=components.begin();i!=components.end();i++){            
            (*i)->Update(Input);
            (*i)->filter = filter;
        }


        // Turn VSYNC on so that animations run at a more reasonable speed on new CPU's/GPU's.
        App.UseVerticalSync(vsync);

        // Set the active window before using OpenGL commands
        // It's useless here because active window is always the same,
        // but don't forget it if you use multiple windows or controls
        App.SetActive();

        //Draw some pretty stuff
        
        DrawGLScene();

        // Finally, display rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}