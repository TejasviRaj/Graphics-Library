extern "C"
#include <cmath>
#include "HGL.h"

void OPENGL_INIT(int argc,char **argv);
void OPENGL_end();

void HGL_run(int argc, char **argv,void (*func)(void))
{
    OPENGL_INIT(argc,argv);
    glutDisplayFunc(func);
    OPENGL_end();
}

void point(float x, float y, Color color, float b,string rotate,float angle,float xc,float yc) {
	glBegin(GL_POINTS);
  glColor3f(color.r*b, color.g*b, color.b*b);
  angle=(PI/180)*angle;
  if(rotate=="TRUE")
  {
    x=(x-xc)*cos(angle)-(y-yc)*sin(angle)+xc;
    y=(x-xc)*sin(angle)+(y-yc)*cos(angle)+yc;
  }
	glVertex2f(x, y);
	glEnd();
}

void clear(Color color)
{
  glClearColor(color.r, color.g, color.b, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

void OPENGL_INIT(int argc,char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Graphics Project");
  //glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(NONE.r, NONE.g, NONE.b, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 500, 0, 500);
}

void OPENGL_end()
{
  glFlush();
  glutMainLoop();
}
