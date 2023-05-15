#pragma once
#include "GL/glut.h"
#include "shape.h"
#include <iostream>
#include <list>
#include <ctime>

using namespace std;

class game {

public:
    game();
    static void draw();
    static void keyboard(unsigned char key, int x, int y);
    static void update();
    static void initApp();
    static void board();
    static void  draw_pieces();
    static void check_collision();
    static void check_rows();
    static void drawScore();

private:

    static int height;
    static int width;
    static int score;
    static float fps;
    static float update_time;
    static shape tetromino;
    static list<square>squares;
};