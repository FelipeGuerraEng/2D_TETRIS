#include "game.h"


int game::height = 600;
int game:: width = 800;
float game::fps = 60.f;
shape game::tetromino(2);

game::game(){

    
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
  
  glClearColor(0,0,0,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, 0, height, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}


void game::draw(){
  
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  glTranslatef(400, 300, 0);

  board();
  tetromino.draw();
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
        tetromino.set_y(-30);
      break;
    case ' ':
        tetromino.rotate();
      break;
    }


}

void game::update(){

    static float time_passed = 0;
    static float update_square = 0;

    if(glutGet(GLUT_ELAPSED_TIME) > (time_passed + 1.f/fps)){

        if(glutGet(GLUT_ELAPSED_TIME) > update_square + 1000.f){

            update_square = glutGet(GLUT_ELAPSED_TIME);
            tetromino.update();
        }

        time_passed = glutGet(GLUT_ELAPSED_TIME);
        glutPostRedisplay();
    }
  
    //glutPostRedisplay();


}

void game::board(){

    glPushMatrix();

    glTranslatef(-150, 300, 0);

    glColor3f(1, 1, 1);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0, 0);
    glVertex2f(300,0);
    glVertex2f(0,-600);
    glVertex2f(300,-600);
    glEnd();
    
    glPopMatrix();
    
    

}