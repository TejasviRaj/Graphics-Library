extern "C"
#include <cmath>
#include "HGL.h"

rectangle::rectangle(float x1,float y1,float x2,float y2,float angle,Color color,string str):x1(x1),y1(y1),x2(x2),y2(y2),color(color),angle(angle)
{
  if (str=="nodraw")
  return;
  draw();

}

void rectangle::draw()
{
  float xk=(x1+x2)/2;
  float yk=(y1+y2)/2;
  line(x1,y1,x1,y2,color,"nodraw").rotate(angle,"Draw",xk,yk);
  line(x1,y1,x2,y1,color,"nodraw").rotate(angle,"Draw",xk,yk);
  line(x2,y2,x1,y2,color,"nodraw").rotate(angle,"Draw",xk,yk);
  line(x2,y2,x2,y1,color,"nodraw").rotate(angle,"Draw",xk,yk);
}

rectangle rectangle::translate(float xt,float yt,string str)
{
  return rectangle(x1+xt,y1+yt,x2+xt,y2+yt,angle,color,str);

}

rectangle rectangle::scale(float xs,float ys,string str,float csx,float csy)
{
  if (csx==-10000 || csy==-10000)
  {
    csx=(x1+x2)/2;
    csy=(y1+y2)/2;
  }
  rectangle r=translate(-csx,-csy,"nodraw");
  return rectangle(r.x1*xs,r.y1*ys,r.x2*xs,r.y2*ys,angle,color,"nodraw").translate(csx,csy,str);

}

rectangle rectangle::remove()
{
  return rectangle(x1,y1,x2,y2,angle,NONE);
}

rectangle rectangle::rotate(float angle,string str,float csx,float csy)
{

  return rectangle(x1,y1,x2,y2,angle,color,str);

}

rectangle rectangle::move(float xt,float yt,int time,string str)
{
//  remove();
  remove();
  *this=translate(xt,yt,str);
  SDL_Delay(time);
  return *this;
}
