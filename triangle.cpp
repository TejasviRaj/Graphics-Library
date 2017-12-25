extern "C"
#include <cmath>
#include "HGL.h"

triangle::triangle(float x1,float y1,float x2,float y2,float x3,float y3, Color color,string str):x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3),color(color)
{
  if (str=="nodraw")
  return;
  draw();
}

void triangle::draw()
{
  line(x1,y1,x2,y2,color);
  line(x2,y2,x3,y3,color);
  line(x3,y3,x1,y1,color);
}

triangle triangle::translate(float xt,float yt,string str)
{
  return triangle(x1+xt,y1+yt,x2+xt,y2+yt,x3+xt,y3+yt,color,str);
}

triangle triangle::scale(float xs,float ys,string str,float csx,float csy)
{
  if (csx==-10000 || csy==-10000)
  {
    csx=(x1+x2+x3)/3;
    csy=(y1+y2+y3)/3;
  }
    triangle t=translate(-csx,-csy,"nodraw");
  return triangle(t.x1*xs,t.y1*ys,t.x2*xs,t.y2*ys,t.x3*xs,t.y3*ys,color,"nodraw").translate(csx,csy,str);
}

triangle triangle::remove()
{
  return triangle(x1,y1,x2,y2,x3,y3,NONE);
}

triangle triangle::rotate(float angle,string str,float csx,float csy)
{
  angle=(PI/180)*angle;
  if (csx==-10000 || csy==-10000)
  {
    csx=(x1+x2+x3)/3;
    csy=(y1+y2+y3)/3;
  }
    triangle l=translate(-csx,-csy,"nodraw");
  return triangle(l.x1*cos(angle)-l.y1*sin(angle),l.x1*sin(angle)+l.y1*cos(angle),l.x2*cos(angle)-l.y2*sin(angle),l.x2*sin(angle)+l.y2*cos(angle),l.x3*cos(angle)-l.y3*sin(angle),l.x3*sin(angle)+l.y3*cos(angle),color,"nodraw").translate(csx,csy,str);
}
