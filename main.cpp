/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing The Base Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */
#define TRUE true
#define FALSE false
#include <GL/glew.h>
#include "Model.h"
#include "MyScene.h"
#include "Studio.h"

using namespace std;

int main() {
    // Create the main window
    GLScene *scene;
    //scene = new MyScene("Metro Simulation");
    scene = new Studio();
    return scene->Run();
}