//gcc tetrisGL.c -lglut -lGL -lGLU -lm -o tetrisGL

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "keyboardFuncs.h"
#include "drawFuncs.h"
#include "pieceFuncs.h"

void init (void) {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10, 10, -10, 10);
  glMatrixMode(GL_MODELVIEW);

  // init the board
  initBoard();
}

void drawOnTheScreen(void) {
    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT);

    drawHud();

    drawBoard();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800,800); 
    glutInitWindowPosition(100,100);
    glutCreateWindow("TetrisGL");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(drawOnTheScreen);
    glutIdleFunc(drawOnTheScreen);
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(keyboardS);
    glutSpecialUpFunc(keyboardSUp);
    init();
    glutMainLoop();
} 
