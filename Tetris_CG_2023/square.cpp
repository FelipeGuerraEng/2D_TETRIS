#include "square.h"

square::square(){

  pos_y = 330;
  pos_x = 0;


}

void square::draw(){

  glPushMatrix();

  glTranslatef(pos_x, pos_y, 0);

  glColor3f(0, 0, 1);
  glBegin(GL_QUAD_STRIP);
  glVertex2f(0, 0);
  glVertex2f(30,0);
  glVertex2f(0,30);
  glVertex2f(30,30);
  glEnd();
  
  glPopMatrix();


}

void square::update(){

    pos_y-=30;


}