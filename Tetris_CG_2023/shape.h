#pragma once
#include "square.h"

class shape{

  public:
      shape(unsigned short num);// 1--> L; 2--> inverted L; 3--> cube; 4--> T; 5 --> stick;
      void update();
      void draw();
      void set_x(double x);
      void set_y(double y);
      void rotate();

  private: 
      square tile[4];
      unsigned short id;
      unsigned short rotation;

};