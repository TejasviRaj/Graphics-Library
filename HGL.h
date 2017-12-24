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
void clear(Color color=NONE);

class line
{
  float x1,y1,x2,y2;
  Color color;
  float lineCentreX,lineCentreY;
  public:
    line(float x1,float y1,float x2,float y2, Color color=WHITE,string str="Draw");
    void draw();

  line translate(float xt,float yt,string str="Draw");
  line scale(float xs,float ys,string str="Draw",float csx=-10000,float csy=-10000);
  line remove();
};

class circle
{
  float xc,yc,r;
  Color color;
  public:
    circle(float xc,float yc,float r, Color color=WHITE,string str="Draw");
    void draw();
    circle translate(float xt,float yt,string str="Draw");
    circle scale(float s,string str="Draw");
    circle remove();

};

class ellipse
{
  float xc,yc,rx,ry;
  Color color;
  public:
    ellipse(float xc,float yc,float rx,float ry, Color color=WHITE,string str="Draw");
    void draw();
    ellipse translate(float xt,float yt,string str="Draw");
    ellipse scale(float xs,float ys,string str="Draw");

    ellipse remove();

};

class triangle
{
  float x1,y1,x2,y2,x3,y3;
  Color color;
public:
  triangle(float x1,float y1,float x2,float y2,float x3,float y3, Color color=WHITE,string str="Draw");
  void draw();
  triangle translate(float xt,float yt,string str="Draw");
  triangle scale(float xs,float ys,string str="Draw",float csx=-10000,float csy=-10000);
  triangle remove();


};

class rectangle
{
  float x1,y1,x2,y2;
  Color color;
public:
  rectangle(float x1,float y1,float x2,float y2,Color color=WHITE,string str="Draw");
  void draw();
  rectangle translate(float xt,float yt,string str="Draw");
  rectangle scale(float xs,float ys,string str="Draw",float csx=-10000,float csy=-10000);
  rectangle remove();


};
