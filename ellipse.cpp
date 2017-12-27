extern "C"
#include <cmath>
#include "HGL.h"

ellipse::ellipse(float xc,float yc,float rx,float ry, Color color,string str):xc(xc),yc(yc),rx(rx),ry(ry),color(color)
{
  if (str=="nodraw")
  return;
  draw();
}

void ellipse::draw(string rotate,float angle,float xcp,float ycp)
{
  //region 1
  float x=0, y=ry;
  float p=ry*ry-rx*rx*ry+(1/4.0)*rx*rx;

  while (2*ry*ry*x<=2*rx*rx*y)
  {
    point(x+xc,y+yc,color,1,rotate,angle,xcp,ycp);
    point(-x+xc,-y+yc,color,1,rotate,angle,xcp,ycp);
    point(-x+xc,y+yc,color,1,rotate,angle,xcp,ycp);
    point(x+xc,-y+yc,color,1,rotate,angle,xcp,ycp);
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
  SDL_RenderPresent(renderer);

}

ellipse ellipse::translate(float xt,float yt,string str)
{
  return ellipse(xc+xt,yc+yt,rx,ry,color,str);
}

ellipse ellipse::scale(float xs,float ys,string str)
{
  return ellipse(xc,yc,rx/xs,ry/ys,color,str);
}

ellipse ellipse::remove()
{
  return ellipse(xc,yc,rx,ry,NONE);
}

ellipse ellipse::rotate(float angle,string str,float csx,float csy)
{
  angle=(PI/180)*angle;
  if (csx==-10000 || csy==-10000)
  {
    csx=xc;
    csy=yc;
  }
   ellipse(xc,yc,rx,ry,color,"nodraw").draw("TRUE",PI/2,20,20);
}
