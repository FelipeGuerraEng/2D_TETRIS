#include "game.h"


int game::height;
int game:: width;

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
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glOrtho(width, 0, height, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}


void game::draw(){
  


  glutSwapBuffers();

}

void game::keyboard(unsigned char key, int x, int y){




}

void game::update(){


  
    glutPostRedisplay();


}

