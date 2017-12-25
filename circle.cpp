extern "C"
#include <cmath>
#include "HGL.h"

circle::circle(float xc,float yc,float r,Color color,string str):xc(xc),yc(yc),r(r),color(color)
{
  if (str=="nodraw")
  return;
  draw();
}

void circle::draw()
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

circle circle::translate(float xt,float yt,string str)
{
  //return circle(xc+xt,yc+yt,r,color);
  return circle(xc+xt,yc+yt,r,color,str);

}

circle circle::scale(float s,string str)
{
  //return circle(xc+xt,yc+yt,r,color);
  return circle(xc,yc,r*sqrt(s),color,str);

}

circle circle::remove()
{
  return circle(xc,yc,r,NONE);
}
