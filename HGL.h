#include "cstdlib"
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Color{
  float r, g, b;
  Color(float R, float G, float B):r(R/255), g(G/255), b(B/255){}
};

const Color WHITE(255, 255, 255);
const Color GREEN(0, 255, 0);
const Color RED(255, 0, 0);
const Color BLUE(0, 0, 255);

void init();
void point(float x, float y, Color color=WHITE);
void lineDDA(float x1,float y1,float x2,float y2,Color color=WHITE);
void line (float x1,float y1,float x2,float y2, Color color=WHITE);
void circle(float xc,float yc,float r, Color color=WHITE);
void ellipse(float xc,float yc,float rx,float ry, Color color=WHITE);





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

void line(float x1,float y1,float x2,float y2, Color color)
{
  float dx=x2-x1;
  float dy=y2-y1;
  float steps,xinr,yinr;
  if (dx==0)
  {
    steps=fabs(dy);
    yinr=dy/steps;
    for (size_t i = 0; i < steps; i++)
      {
        point (x1,y1);
        y1+=yinr;
        /* code */
      }
  }
  else if (dy==0)
  {
    steps=fabs(dx);
    xinr=dx/steps;
    for (size_t i = 0; i < steps; i++)
      {
        point (x1,y1);
        x1+=xinr;
        /* code */
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

    glFlush();

}

/*
void line (float x1,float y1,float x2,float y2, Color color)
{
  float dx=x2-x1;
  float dy=y2-y1;
  float p,xinr,yinr;
  float steps;

if(x1>x2)
  {
    float c;
    c=x1;
    x1=x2;
    x2=c;
  }

if(y1>y2)
  {
    float c;
    c=y1;
    y1=y2;
    y2=c;

  }
  float dx1=dx/fabs(dx);
  float dy1=dy/fabs(dy);

  if (fabs(dx)>fabs(dy))
  {
    dx=x2-x1;
    dy=y2-y1;
    float c;
  //  if (x1>x2)
  //    {
//        c=x1;
  //      x1=x2;
    //    x2=c;

      //  c=y1;
      //  y1=y2;
      //  y2=c;
    //    dx=x2-x1;
    //    dy=y2-y1;
    //  }

    steps=fabs(dx);
    yinr=dy/fabs(dy);
     p=2*(dy)-(dx);
    xinr=dx/steps;
    while (x1<=x2)
  //  for (size_t ; i < steps; i++)
      {

         point(x1*dx1,y1*dy1,color);
         x1=x1+xinr;
         if (p>0)
           {
             y1=y1+yinr;
             p=p+2*(dy)-2*(dx);
           }
         else
            {
              //y1++;
             p=p+2*(dy);
           }
     }
  }
  else
  {
    dx=x2-x1;
    dy=y2-y1;
  //  if (y1>y2)
  //    {
    //    float c;
  //      c=x1;
    //    x1=x2;
      //  x2=c;

  //      c=y1;
    //    y1=y2;
    //    y2=c;
      //  dx=x2-x1;
      //  dy=y2-y1;
      }
      steps=(dy);
      xinr=dx/(dx);
       p=2*(dx)-(dy);
      // y1=dy/steps;
       yinr=dy/steps;

      for (size_t i = 0; i < steps; i++)
         {
               point(x1*dx,y1*dy,color);

               y1=y1+yinr;
              // y1=y1+yinr*20;
              // point(x1,y1,color);
              // break;
               if (p>0)
                 {
                   x1=x1+xinr;
                   p=p+2*(dx)-2*(dy);
                 }
               else
                 {
                   //x1=x1+1;
                   p=p+2*(dx);
                 }
        }

  }

} */

void circle(float xc,float yc,float r,Color color)
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

void ellipse(float xc,float yc,float rx,float ry, Color color)
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
