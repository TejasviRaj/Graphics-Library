main: main.o HGL_init.o line.o circle.o ellipse.o triangle.o rectangle.o
	g++ -g -o main main.o HGL_init.o line.o circle.o ellipse.o triangle.o rectangle.o -lGL -lGLU -lglut

main.o: main.cpp
	g++ -g -c main.cpp

HGL_init.o: HGL_init.cpp HGL.h
	g++ -g -c HGL_init.cpp

line.o:line.cpp HGL.h
	g++ -g -c line.cpp

circle.o:circle.cpp HGL.h
	g++ -g -c circle.cpp

ellipse.o:ellipse.cpp HGL.h
	g++ -g -c ellipse.cpp

triangle.o:triangle.cpp HGL.h
	g++ -g -c triangle.cpp

rectangle.o:rectangle.cpp HGL.h
	g++ -g -c rectangle.cpp
