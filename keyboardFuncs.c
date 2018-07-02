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
         gameSpeed = DEFAULTGAMESPEED / 3;
         break;
      case GLUT_KEY_UP:
         //rotate
         break;
      case GLUT_KEY_RIGHT:
         if(collisionVerification(2) == 0) {
            activePiece->x += 1;
         }
         break;
      case GLUT_KEY_LEFT:
         if(collisionVerification(4) == 0) {
            activePiece->x -= 1;
         }
         break;
   }
}

void keyboardSUp (int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_DOWN:
         gameSpeed = DEFAULTGAMESPEED;
         break;
      case GLUT_KEY_UP:
         break;
      case GLUT_KEY_RIGHT:
         break;
      case GLUT_KEY_LEFT:
         break;
   }
}