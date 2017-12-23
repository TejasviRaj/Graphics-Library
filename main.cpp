#include"HGL.h"

int main(int argc, char **argv) {
  // float x1, y1, x2, y2;
	// cout << "Enter x1, y1, x2 ,y2: ";
	// cin >> x1 >> y1 >> x2 >> y2;

  HGL_init(argc,argv);

 line(300,300,400,400,WHITE);
  line(300,300,400,200,BLUE);
  line(300,300,200,400,GREEN);
  line(300,300,200,200,RED);
  line(300,300,300,400,WHITE);
  line(300,300,300,200,BLUE);
  line(300,300,200,300,GREEN);
  line(300,300,400,300,RED);
  circle(100,100,50);
  ellipse(100,100,50,100);
  ellipse(100,100,100,50);
  HGL_End();
}
