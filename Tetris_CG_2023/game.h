#pragma once
#include "GL/glut.h"

class game {

public:
    game();
    static void draw();
    static void keyboard(unsigned char key, int x, int y);
    static void update();
    static void initApp();

private:

    static int height;
    static int width;
    

};