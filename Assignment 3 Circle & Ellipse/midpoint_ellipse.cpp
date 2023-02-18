#include<iostream>
#include<GL/glut.h>
using namespace std;

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 300.0);
}

void display()
{
    glPointSize(2.0);
	glBegin(GL_POINTS);

    //To complete

    glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Ellipse Midpoint");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();   
}
