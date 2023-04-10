#pragma once
#include "GL/glut.h"

class square{

    public:
        square();
        void draw();
        void set_x(double x){pos_x += x;}
        void set_y(double y){pos_y += y;}
        void update();
        double get_x() {return pos_x;}
        double get_y() {return pos_y;}


    private:
        double pos_x;
        double pos_y;

};