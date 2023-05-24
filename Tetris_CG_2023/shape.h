#pragma once
#include "square.h"
#include <cmath>

class shape{

  public:
      shape(unsigned short num);// 1--> L; 2--> inverted L; 3--> cube; 4--> T; 5 --> stick;
      bool update();
      void draw();
      void set_x(double x);
      void set_y(double y);
      double get_x(unsigned short num){return tile[num].get_x() + pos_x;}
      double get_y(unsigned short num){return tile[num].get_y() + pos_y;}
      void rotate();
      double get_angle_tetromino(unsigned short int);
      double calculate_pos_x(unsigned short num);
      double calculate_pos_y(unsigned short num);
      float radtodeg(float radians){return radians*180/3.14;}
      float degtorad(float degrees){return degrees*3.14/180;}
      bool willCollide;

  private: 
      square tile[4];
      unsigned short id;
      unsigned short rotation;
      double pos_x;
      double pos_y;
      

};