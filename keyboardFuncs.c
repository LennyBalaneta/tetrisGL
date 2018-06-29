void keyboard (unsigned char key, int x, int y) {
   switch (key) {
      case 'w':
      case 'W':
      	 printf("w");
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
         break;
      case GLUT_KEY_UP:
         break;
      case GLUT_KEY_RIGHT:
         break;
      case GLUT_KEY_LEFT:
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