#include "pieceFuncs.h"
#include <string.h>

void initBoard() {
  int i, j;
  for(i=0 ; i<SIZEN ; i++){
    for(j=0 ; j<SIZEM ; j++){
      board[i][j].active = 0;
      board[i][j].r = 0.0;
      board[i][j].g = 0.0;
      board[i][j].b = 1.0;
    }
  }
}


void drawScore(const char *text, int lenght, int x, int y){
    glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    double matrix[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0; i<lenght; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}

void drawParallelepiped(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float r, float g, float b) {
  //draw a parallelepiped using the coordinates and the color passed by parameter
  glColor3f(r, g, b);
  glVertex3f(xMin, yMin, zMin);
  glVertex3f(xMin, yMax, zMin);
  glVertex3f(xMax, yMax, zMin);
  glVertex3f(xMax, yMin, zMin);

  glVertex3f(xMin, yMin, zMin);
  glVertex3f(xMin, yMax, zMin);
  glVertex3f(xMin, yMax, zMax);
  glVertex3f(xMin, yMin, zMax);

  glVertex3f(xMin, yMin, zMin);
  glVertex3f(xMax, yMin, zMin);
  glVertex3f(xMax, yMin, zMax);
  glVertex3f(xMin, yMin, zMax);

  glVertex3f(xMin, yMax, zMin);
  glVertex3f(xMax, yMax, zMin);
  glVertex3f(xMax, yMax, zMax);
  glVertex3f(xMin, yMax, zMax);

  glVertex3f(xMax, yMin, zMin);
  glVertex3f(xMax, yMax, zMin);
  glVertex3f(xMax, yMax, zMax);
  glVertex3f(xMax, yMin, zMax);

  glVertex3f(xMin, yMin, zMax);
  glVertex3f(xMin, yMax, zMax);
  glVertex3f(xMax, yMax, zMax);
  glVertex3f(xMax, yMin, zMax);

}

void drawHud() {
  glBegin(GL_QUADS);

  //main grid
  drawParallelepiped(-7.0f, 1.0f, -8.0f, 8.0f, 0.0f, 1.0f, 0.47f, 0.47f, 0.47f);

  //next piece grid
  drawParallelepiped(3.0f, 8.0f, 6.0f, 2.0f, 0.0f, 1.0f, 0.47f, 0.47f, 0.47f);

  //score grid
  drawParallelepiped(3.0f, 8.0f, -1.0f, -2.0f, 0.0f, 1.0f, 0.47f, 0.47f, 0.47f);

  //line grid
  drawParallelepiped(3.0f, 8.0f, -3.0f, -4.0f, 0.0f, 1.0f, 0.47f, 0.47f, 0.47f);

  glEnd();
}

void drawBoard() {
  int i, j;

  float slotSize = 8.0 / SIZEM;
  glBegin(GL_QUADS);
  for(i=0 ; i<SIZEN ; i++){
    for(j=0 ; j<SIZEM ; j++){
      if(board[i][j].active == 1) {
        drawParallelepiped(-7.0f+(slotSize*j), -7.0f+slotSize+(slotSize*j), 8.0f-(slotSize*i), 8.0f-slotSize-(slotSize*i), 0.0f, 1.0f,
                            board[i][j].r, board[i][j].g, board[i][j].b);
      }
    }
  }
  glEnd();
}

void drawActivePiece() {
  int i, j, x, y;

  float slotSize = 8.0 / SIZEM;
  y = activePiece->y;
  x = activePiece->x;

  float baseX = -7.0f+(slotSize*x);
  float baseY = 8.0f-(slotSize*y);
  glBegin(GL_QUADS);
  for(i = 0; i < 2; i++){
    for(j = 0; j < 4; j++){
      if(activePiece->type.layout[i][j] != 0) {
        drawParallelepiped(baseX+(slotSize*j), baseX+slotSize+(slotSize*j), baseY-(slotSize*i), baseY-slotSize-(slotSize*i), 0.0f, 1.0f,
                            activePiece->type.r, activePiece->type.g, activePiece->type.b);
      }
    }
  }
  glEnd();
}

void drawNextPiece() {
  int i, j;

  float slotSize = 8.0 / SIZEM;

  float baseX = 4.25f;
  float baseY = 5.0f;
  glBegin(GL_QUADS);
  for(i = 0; i < 2; i++){
    for(j = 0; j < 4; j++){
      if(pTypes[nextPiece].layout[i][j] != 0) {
        drawParallelepiped(baseX+(slotSize*j), baseX+slotSize+(slotSize*j), baseY-(slotSize*i), baseY-slotSize-(slotSize*i), 0.0f, 1.0f,
                            pTypes[nextPiece].r, pTypes[nextPiece].g, pTypes[nextPiece].b);
      }
    }
  }
  glEnd();
}
