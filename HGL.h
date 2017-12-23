#include "Color.h"
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

//class line;
void init();
void point(float x, float y, Color color=WHITE);
void HGL_init(int argc, char **argv);
void HGL_End();

class line
{
  float x1,y1,x2,y2;
  Color color;
  public:
    line(float x1z,float y1z,float x2z,float y2z, Color colorz=WHITE);
};

class circle
{
  float xc,yc,r;
  Color color;
  public:
    circle(float xc,float yc,float r, Color color=WHITE);
};

class ellipse
{
  float xc,yc,rx,ry;
  Color color;
  public:
    ellipse(float xc,float yc,float rx,float ry, Color color=WHITE);
};
