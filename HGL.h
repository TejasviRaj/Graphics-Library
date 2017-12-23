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
    line(float x1,float y1,float x2,float y2, Color color=WHITE);

  line translate(float xt,float yt);
};

class circle
{
  float xc,yc,r;
  Color color;
  public:
    circle(float xc,float yc,float r, Color color=WHITE);
    circle translate(float xt,float yt);
};

class ellipse
{
  float xc,yc,rx,ry;
  Color color;
  public:
    ellipse(float xc,float yc,float rx,float ry, Color color=WHITE);
    ellipse translate(float xt,float yt);

};

class triangle
{
  float x1,y1,x2,y2,x3,y3;
  Color color;
public:
  triangle(float x1,float y1,float x2,float y2,float x3,float y3, Color color=WHITE);
  triangle translate(float xt,float yt);

};

class rectangle
{
  float x1,y1,x2,y2;
  Color color;
public:
  rectangle(float x1,float y1,float x2,float y2,Color color=WHITE);
  rectangle translate(float xt,float yt);

};
