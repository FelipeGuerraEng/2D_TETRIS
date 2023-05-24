#include "game.h"


int game::height = 600;
int game:: width = 800;
int game::score = 0;
float game::fps = 60.f;
float game::update_time = 1000.f;
shape game::tetromino(rand()%6+1);
//bool game::canMoveSideways = true;  
//shape game::tetromino(6);
list<square>game::squares;

game::game(){

    srand(time(NULL));
    tetromino = shape(rand()%6+1);
    //Selecciona modo de display: RGB y double buffering
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

    //Fija tamaño y posición inicial de las ventanas
    glutInitWindowSize(width,height);
    glutInitWindowPosition(50,50);
    glutCreateWindow("TETRIS");

   
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(update);
    initApp();


}

void game::initApp(){
  
  glClearColor(0.0f,0.5f,0.0f,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, 0, height, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}

void game::drawScore() {

    glColor3f(1.0f, 0.0f, 0.0f);  // Set text color (red)
    glRasterPos2i(220, 220);  // Set text position
    //cout << "It's working!!"<<endl;
    std::string scoreStr = "Score: " + std::to_string(score);
    for (char c : scoreStr) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

void game::drawGameOver() {
  glColor3f(1.0f, 0.0f, 0.0f);  // Set text color (red)
  glRasterPos2i(220, 220);  // Set text position
  std::string gameOverStr = "Perdiste";
  for (char c : gameOverStr) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
  }
}


void game::draw(){
  
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  glTranslatef(400, 300, 0);

  board();
  tetromino.draw();
  draw_pieces();
  drawScore();
  //tile.update();
  //cout << "It's working!!"<<endl;
  glPopMatrix();
  glutSwapBuffers();

}

void game::keyboard(unsigned char key, int x, int y){

    switch (key)
    {
    case 'A': case 'a':
        tetromino.set_x(-30);
      break;
    case 'D': case 'd':
        tetromino.set_x(30);
      break;
    case 'S': case 's':
        //tetromino.set_y(-30);
        update_time = 50;
      break;
    case ' ':
        tetromino.rotate();
      break;
    }


}

void game::update(){

    static float time_passed = 0;
    static float update_square = 0;
    //static float update_time = 1000.f;

    if(glutGet(GLUT_ELAPSED_TIME) > (time_passed + 1.f/fps)){

        if(glutGet(GLUT_ELAPSED_TIME) > update_square + update_time){

            check_collision();
            update_square = glutGet(GLUT_ELAPSED_TIME);
            if(tetromino.update()){
             
              for (int i=0; i<4; i++){

                  squares.push_back(square(tetromino.calculate_pos_x(i),tetromino.calculate_pos_y(i)));

              }
              check_rows();
              //tetromino.hasLanded = true;
              tetromino = shape(rand()%6+1);

            }
        }

        time_passed = glutGet(GLUT_ELAPSED_TIME);
        update_time = 1000;
        glutPostRedisplay();
    }
  
    //glutPostRedisplay();


}

void game::board(){

    glPushMatrix();

    glTranslatef(-150, 300, 0);

    glColor3f(0, 0, 0);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0, 0);
    glVertex2f(300,0);
    glVertex2f(0,-600);
    glVertex2f(300,-600);
    glEnd();
    
    glPopMatrix();

}

void game::draw_pieces(){

    glColor3f(0.6f, 0.3f, 0.0f);

    list<square>::iterator p =squares.begin();
    while(p!= squares.end()){

          p->draw();
          p++;

    }


}

void game::check_collision(){

    bool gameover=false;

    list<square>::iterator p =squares.begin();
    while(p!= squares.end()){

      bool collision = false;

      for (int i=0; i<4; i++){

          if(abs(p->get_y()-((int)tetromino.calculate_pos_y(i)-30)) < 15){

            if(abs(p->get_x()-(int)tetromino.calculate_pos_x(i)) < 5){

              collision = true;

            }

          }
         
      }
      if (collision){
        
        for (int i=0; i<4; i++){

            squares.push_back(square(tetromino.calculate_pos_x(i),tetromino.calculate_pos_y(i)));

            if((int)tetromino.calculate_pos_y(i) > 300){

              gameover = true;

            }

        }
        check_rows();
        tetromino = shape(rand()%6+1);

      }

       p++;
    }

    if(gameover){

      exit(1);

    }

}

void game::check_rows(){

    for (int i=0; i<4; i++){

        int square_counter=0;
        list<square>::iterator p =squares.begin();
        while(p!= squares.end()){

              if(abs((int)tetromino.calculate_pos_y(i)- p->get_y())< 15){

                  square_counter++;
              }
              p++;
        }

        if(square_counter==10){

            p =squares.begin();
            while(p!= squares.end()){

              if(abs((int)tetromino.calculate_pos_y(i)- p->get_y())< 15){

                  p = squares.erase(p);
              }else{

                  if( p->get_y() > ((int)tetromino.calculate_pos_y(i))){

                      p->set_y(-30);

                  }                  
                  p++;
              }
              
            }
            score += 100;
        }
    }

}