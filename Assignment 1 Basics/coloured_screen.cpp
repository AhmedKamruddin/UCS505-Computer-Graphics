#include<GL/freeglut.h>
#include<iostream>
using namespace std;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void myinit()
{
	glClearColor(0.45, 0.84, 0.2, 1.0);
		
	glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Blank Window");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}
