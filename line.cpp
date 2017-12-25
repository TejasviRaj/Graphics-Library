extern "C"
#include <cmath>
#include "HGL.h"

line::line(float x1,float y1,float x2,float y2,Color color,string str):x1(x1),y1(y1),x2(x2),y2(y2),color(color)
{
  if (str=="nodraw")
  return;
draw();
}

void line::draw()
{
  //color=colorz;
  float dx=x2-x1;
  float dy=y2-y1;
  float steps,xinr,yinr;
  float x=x1;
  float y=y1;
  if (dx==0)
  {
    steps=fabs(dy);
    yinr=dy/steps;
    for (size_t i = 0; i < steps; i++)
      {
        point (x,y,color);
        y+=yinr;
      }
  }
  else if (dy==0)
  {
    steps=fabs(dx);
    xinr=dx/steps;
    for (size_t i = 0; i < steps; i++)
      {
        point (x,y,color);
        x+=xinr;
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
          point (x,y,color);
          x=x+xinr;
          y=y+yinr;
        }
  }
}

line line::translate(float xt,float yt,string str)
{
  //line(x1+xt,50,x2+xt,y2+yt,color,str);
  return line(x1+xt,y1+yt,x2+xt,y2+yt,color,str);

}

line line::scale(float xs,float ys,string str,float csx,float csy)
{
  if (csx==-10000 || csy==-10000)
  {
    csx=(x1+x2)/2;
    csy=(x1+x2)/2;
  }
  line l =translate(-csx,-csy,"nodraw");
  return line(l.x1*xs,l.y1*ys,l.x2*xs,l.y2*ys,color,"nodraw").translate(csx,csy,str);

}

line line::remove()
{
  return line(x1,y1,x2,y2,NONE);
}

line line::rotate(float angle,string str,float csx,float csy)
{
  angle=(PI/180)*angle;
  if (csx==-10000 || csy==-10000)
  {
    csx=(x1+x2)/2;
    csy=(y1+y2)/2;
  }
  line l =translate(-csx,-csy,"nodraw");
  return line(l.x1*cos(angle)-l.y1*sin(angle),l.x1*sin(angle)+l.y1*cos(angle),l.x2*cos(angle)-l.y2*sin(angle),l.x2*sin(angle)+l.y2*cos(angle),color,"nodraw").translate(csx,csy,str);

}
