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

  //score grid
  drawParallelepiped(3.0f, 8.0f, 6.0f, 2.0f, 0.0f, 1.0f, 0.47f, 0.47f, 0.47f);

  //next piece grid
  drawParallelepiped(3.0f, 8.0f, -1.0f, -5.0f, 0.0f, 1.0f, 0.47f, 0.47f, 0.47f); 
  
  glEnd();
}