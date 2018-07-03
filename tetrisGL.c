//gcc tetrisGL.c -lglut -lGL -lGLU -lm -o tetrisGL

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "keyboardFuncs.h"
#include <string.h>

void init (void) {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10, 10, -10, 10);
  glMatrixMode(GL_MODELVIEW);

  // init the board
  initBoard();

  // init pTypes
  pTypes = createPieceTypes();

  // init the active piece
  nextPiece = rand()%7;
  activePiece = createPiece();
}

void drawOnTheScreen(void) {
    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT);

    drawHud();

    drawBoard();

    char bla[50];
    char str1[12];
    strcpy(bla, "SCORE: ");
    sprintf(str1, "%d", score);
    strcat(bla, str1);

    drawScore(bla ,strlen(bla),525,250);

    char bla2[50];
    char str2[12];
    strcpy(bla2, "LINES: ");
    sprintf(str2, "%d", lines);
    strcat(bla2, str2);

    drawScore(bla2 ,strlen(bla2),525,190);

    drawScore("NEXT PIECE: " ,12, 525, 460);

    if(gameOver == 0) {
        updatePiece();
        fullLineVerification();
    }else{
        drawScore("GAME OVER!!!", 12, 535, 310);
    }

    drawActivePiece();

    drawNextPiece();

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
