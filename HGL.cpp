extern "C"
#include <cmath>
#include "HGL.h"
//#include"Color.h"

line::line(float x1,float y1,float x2,float y2,Color color):x1(x1),y1(y1),x2(x2),y2(y2),color(color)
{

  //color=colorz;
  float dx=x2-x1;
  float dy=y2-y1;
  float steps,xinr,yinr;
  if (dx==0)
  {
    steps=fabs(dy);
    yinr=dy/steps;
    for (size_t i = 0; i < steps; i++)
      {
        point (x1,y1,color);
        y1+=yinr;
      }
  }
  else if (dy==0)
  {
    steps=fabs(dx);
    xinr=dx/steps;
    for (size_t i = 0; i < steps; i++)
      {
        point (x1,y1,color);
        x1+=xinr;
      }
  }
  else
  {
    if (fabs(dx)>fabs(dy))
        steps=fabs(dx);
      else
        steps=fabs(dy);

      xinr=dx/steps;
      yinr=dy/steps;

      for (size_t i = 0; i < steps; i++)
        {
          point (x1,y1,color);
          x1=x1+xinr;
          y1=y1+yinr;
        }
  }

    //glFlush();

}

void HGL_init(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics Project");
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void HGL_End()
{
  glFlush();
	glutMainLoop();
}

void point(float x, float y, Color color) {
	glBegin(GL_POINTS);
  glColor3f(color.r, color.g, color.b);
	glVertex2f(x, y);

	glEnd();
}





circle::circle(float xc,float yc,float r,Color color):xc(xc),yc(yc),color(color)
{
  float x=0, y=r;
  float p=1-r;
  while (x<=y)
  {
    point(x+xc,y+yc,color);
    point(-x+xc,-y+yc,color);
    point(-x+xc,y+yc,color);
    point(x+xc,-y+yc,color);
    point(y+xc,x+yc,color);
    point(-y+xc,-x+yc,color);
    point(-y+xc,x+yc,color);
    point(y+xc,-x+yc,color);
    x++;
    if (p<0)
    p+=2*x+1;
    else
    {
      y-=1;
      p+=2*x+1-2*y;
    }
  }
}

ellipse::ellipse(float xc,float yc,float rx,float ry, Color color):xc(xc),yc(yc),rx(rx),ry(ry),color(color)
{
  //region 1
  float x=0, y=ry;
  float p=ry*ry-rx*rx*ry+(1/4.0)*rx*rx;

  while (2*ry*ry*x<=2*rx*rx*y)
  {
    point(x+xc,y+yc,color);
    point(-x+xc,-y+yc,color);
    point(-x+xc,y+yc,color);
    point(x+xc,-y+yc,color);
    x++;
    if (p<0)
    p+=2*ry*ry*x+ry*ry;
    else
    {
      y-=1;
      p+=2*ry*ry*x-2*rx*rx*y+ry*ry;
    }
  }
  //region 2
  p=ry*ry*(x+1/2.0)*(x+1/2.0)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
  while (y>=0)
  {
    point(x+xc,y+yc,color);
    point(-x+xc,-y+yc,color);
    point(-x+xc,y+yc,color);
    point(x+xc,-y+yc,color);
    y--;
    if (p<=0)
    {
      x++;

      p+=2*ry*ry*x-2*rx*rx*y+rx*rx;
    }
    else
    {
      y-=1;
      p-=2*rx*rx*y+rx*rx;
    }
  }

}

triangle::triangle(float x1,float y1,float x2,float y2,float x3,float y3, Color colorz):x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3),color(color)
{
  line(x1,y1,x2,y2);
  line(x2,y2,x3,y3);
  line(x3,y3,x1,y1);

}
