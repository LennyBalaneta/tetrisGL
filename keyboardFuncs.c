#include "drawFuncs.h"

void keyboard (unsigned char key, int x, int y) {
   switch (key) {
      case 'w':
      case 'W':
      	pinThePieceOnTheBoard();
         break;
      case 'q':
      case 'Q':
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

void keyboardUp (unsigned char key, int x, int y) {
   switch (key) {
      case 'w':
      case 'W':
         break;
      case 's':
      case 'S':
         break;
      case 'a':
      case 'A':
         break;
      case 'd':
      case 'D':
         break;
      default:
         break;
   }
}

void keyboardS (int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_DOWN:
         activePiece->y += 1;
         break;
      case GLUT_KEY_UP:
         activePiece->y -= 1;
         break;
      case GLUT_KEY_RIGHT:
         activePiece->x += 1;
         break;
      case GLUT_KEY_LEFT:
         activePiece->x -= 1;
         break;
   }
}

void keyboardSUp (int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_DOWN:
         break;

      case GLUT_KEY_UP:
         break;
      case GLUT_KEY_RIGHT:
         break;
      case GLUT_KEY_LEFT:
         break;
   }
}