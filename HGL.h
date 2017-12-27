#ifndef HGL_H
#define HGL_H

#include "Color.h"
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <stdio.h>

#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433


extern SDL_Renderer *renderer;
extern SDL_Event event;
 extern SDL_Window *window;


//class line;
void init();
void point(float x, float y, Color color=WHITE, float b=1,string rotate="FALSE",float angle=0,float xc=0,float yc=0);//void HGL_init(int argc, char **argv);
//void HGL_End(void (*func)(void));
void clear(Color color=NONE);
void HGL_run(int argc, char **argv,void (*func)(void (*)()))
;
//void OPENGL_init();
//void OPENGL_end();

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
  line rotate(float angle,string str="Draw",float csx=-10000,float csy=-10000);

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
    circle move(float xt,float yt,int time=100,string str="Draw");
    circle scale(float s,string str="Draw");
    circle remove();

};

class ellipse
{
  float xc,yc,rx,ry;
  Color color;
  public:
    ellipse(float xc,float yc,float rx,float ry, Color color=WHITE,string str="Draw");
    void draw(string rotate="FALSE",float angle=0,float xc=0,float yc=0);
    ellipse translate(float xt,float yt,string str="Draw");
    ellipse scale(float xs,float ys,string str="Draw");
    ellipse rotate(float angle,string str="Draw",float csx=-10000,float csy=-10000);
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
  triangle rotate(float angle,string str="Draw",float csx=-10000,float csy=-10000);
  triangle remove();


};

class rectangle
{
  float x1,y1,x2,y2,angle;
  Color color;
public:
  rectangle(float x1,float y1,float x2,float y2,float angle=0,Color color=WHITE,string str="Draw");
  void draw();
  rectangle translate(float xt,float yt,string str="Draw");
  rectangle scale(float xs,float ys,string str="Draw",float csx=-10000,float csy=-10000);
  rectangle rotate(float angle,string str="Draw",float csx=-10000,float csy=-10000);
  rectangle remove();


};

#endif
