#include "shape.h"

shape::shape(unsigned short num){

    id = num;
    rotation = 1;

    switch (id)
    {
    case 1:
        tile[1].set_x(30);
        tile[2].set_x(-30);
        tile[3].set_x(-30);
        tile[3].set_y(30);
      break;
    case 2:
        tile[1].set_x(30);
        tile[2].set_x(-30);
        tile[3].set_x(30);
        tile[3].set_y(30);
      break;
    case 3:
        tile[1].set_x(30);
        tile[2].set_x(-30);
        tile[3].set_x(0);
        tile[3].set_y(30);
      break;
    case 4:
        tile[1].set_x(30);
        tile[2].set_x(30);
        tile[2].set_y(30);
        tile[3].set_x(0);
        tile[3].set_y(30);
      break;
    case 5:
        tile[1].set_x(30);
        tile[2].set_x(-30);
        tile[3].set_x(-60);
      break;
    }

}

void shape::update(){

    for (int i=0; i<4; i++){

        tile[i].update();

    }

}

void shape::draw(){


    switch(id){

        case 1:
            glColor3f(1, 0, 1);
          break;
        case 2:
            glColor3f(0, 1, 1);
          break;
        case 3:
            glColor3f(0, 0, 1);
          break;
        case 4:
            glColor3f(1, 0, 0);
          break;
        case 5:
            glColor3f(0, 1, 0);
          break;

    }

    glPushMatrix();
    switch(rotation){

        case 2:
            glRotatef(90,0,0,1);
          break;
        case 3:
            glRotatef(180,0,0,1);
          break;
        case 4:
            glRotatef(270,0,0,1);
          break;

    }

    for (int i=0; i<4; i++){

        tile[i].draw();

    }
    glPopMatrix();
}

void shape::set_x(double x){

    for (int i=0; i<4; i++){

        tile[i].set_x(x);

    }
}

void shape::set_y(double y){

    for (int i=0; i<4; i++){

        tile[i].set_y(y);

    }
}

void shape::rotate(){

    rotation++;

    if(rotation>4) rotation =1;

}