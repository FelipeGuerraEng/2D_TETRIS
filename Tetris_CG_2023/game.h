#pragma once
#include "GL/glut.h"
#include "shape.h"
#include <iostream>

using namespace std;

class game {

public:
    game();
    static void draw();
    static void keyboard(unsigned char key, int x, int y);
    static void update();
    static void initApp();
    static void board();

private:

    static int height;
    static int width;
    static float fps;
    static shape tetromino;
};