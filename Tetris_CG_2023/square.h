#pragma once
#include "GL/glut.h"

class square{

    public:
        square();
        square(double x, double y){pos_x=x, pos_y=y;}
        void draw();
        void set_x(double x){pos_x += x;}
        void set_y(double y){pos_y += y;}
        void set_rotation(unsigned short num);
        void update();

        double get_x() {return pos_x;}
        double get_y() {return pos_y;}


    private:
        double pos_x;
        double pos_y;
        unsigned short rotation;

};