extern "C"
#include <cmath>
#include "HGL.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
SDL_Event event;
 SDL_Window *window;
 SDL_Renderer *renderer;
void OPENGL_INIT(int argc,char **argv);
void OPENGL_end();
void SDL_initialize();
void SDL_close();

void HGL_run(int argc, char **argv,void (*func)(void))
{
/*   OPENGL_INIT(argc,argv);
    glutDisplayFunc(func);
    OPENGL_end();*/

   SDL_initialize();
   func();
    while (1) {
      if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }

  	//Free resources and close SDL
  	SDL_close();
}

void point(float x, float y, Color color, float b,string rotate,float angle,float xc,float yc) {
/*	glBegin(GL_POINTS);
  glColor3f(color.r*b, color.g*b, color.b*b);
  angle=(PI/180)*angle;
  if(rotate=="TRUE")
  {
    x=(x-xc)*cos(angle)-(y-yc)*sin(angle)+xc;
    y=(x-xc)*sin(angle)+(y-yc)*cos(angle)+yc;
  }
	glVertex2f(x, y);
	glEnd(); */
  SDL_SetRenderDrawColor(renderer, color.r*255, color.g*255, color.b*255, 255);
  SDL_RenderDrawPoint(renderer, x, y);

}

void clear(Color color)
{
  glClearColor(color.r, color.g, color.b, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

void OPENGL_INIT(int argc,char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(WINDOW_WIDTH,WINDOW_WIDTH);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Graphics Project");
  //glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(NONE.r, NONE.g, NONE.b, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 500, 0, 500);
}

void OPENGL_end()
{
  glFlush();
  glutMainLoop();
}

void SDL_initialize()
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	}



void SDL_close()
{
  while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();;
}
