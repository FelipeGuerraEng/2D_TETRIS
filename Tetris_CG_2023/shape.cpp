#include "shape.h"

shape::shape(unsigned short num){

    id = num;
    rotation = 1;
    pos_x = 15;
    pos_y = 345;
    willCollide = false;

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
    case 6:
        tile[1].set_x(-30);
        tile[2].set_y(30);
        tile[3].set_x(30);
        tile[3].set_y(30);
      break;
    }

}

bool shape::update(){
    bool collision = false;

    for (int i=0; i<4; i++){
        if((int)calculate_pos_y(i) <= -280){
            collision = true;
        }
    }

    if(!collision){
       pos_y-=30;
    }
    return collision;
}

void shape::draw(){


    switch(id){

        case 1:
            glColor3f(1, 0, 1);//magenta
          break;
        case 2:
            glColor3f(0, 1, 1);//cian
          break;
        case 3:
            glColor3f(0, 0, 1);//azul
          break;
        case 4:
            glColor3f(1, 0, 0);//rojo
          break;
        case 5:
            glColor3f(0, 1, 0);//verde
          break;
        case 6:
            glColor3f(1, 1, 0);//amarillo
          break;

    }

    glPushMatrix();
    glTranslatef(pos_x,pos_y,0);
    for (int i=0; i<4; i++){

        tile[i].draw();

    }
    glPopMatrix();
}

void shape::set_x(double x){
    bool collision = false;

    for (int i=0; i<4; i++){
        if(x > 0){
            if(abs((int)calculate_pos_x(i)-130) < 15){
                collision = true;
            }
        } else {
            if(abs((int)calculate_pos_x(i)+130) < 15){
                collision = true;
            }
        }
    }

    if (!collision && !willCollide){
        pos_x+=x;
    }
}

void shape::set_y(double y){

    if(pos_y>-285){
      pos_y+=y;
    }

    
}

void shape::rotate(){
    // Save current rotation state
    int oldRotation = rotation;

    rotation++;
    if(rotation>4) rotation =1;
    for (int i=0; i<4; i++){
        tile[i].set_rotation(rotation);
    }

    // Check for wall collision after rotation
    bool collision = false;
    for (int i=0; i<4; i++){
        if(abs((int)calculate_pos_x(i)-130) < 15 || abs((int)calculate_pos_x(i)+130) < 15){
            collision = true;
        }
    }

    // If collision detected, revert to previous rotation state
    if(collision){
        rotation = oldRotation;
        for (int i=0; i<4; i++){
            tile[i].set_rotation(rotation);
        }
    }
}

double shape::get_angle_tetromino(unsigned short num){

      double square_angle = atan2f(tile[num].get_y(), tile[num].get_x());
      double local_rotation = (rotation -1)*90;

      return (square_angle)+ degtorad(local_rotation);

}

double shape::calculate_pos_x(unsigned short num){

    double hypotenuse;

    hypotenuse = sqrt(pow((tile[num].get_x()),2) + pow((tile[num].get_y()),2));

    return cos(get_angle_tetromino(num)) * hypotenuse + pos_x;
}

double shape::calculate_pos_y(unsigned short num){

    double hypotenuse;

    hypotenuse = sqrt(pow((tile[num].get_x()),2) + pow((tile[num].get_y()),2));

    return sin(get_angle_tetromino(num)) * hypotenuse + pos_y;
}