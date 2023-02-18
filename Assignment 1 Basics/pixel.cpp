#include<iostream>
#include<GL/freeglut.h>

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glColor3f(0.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 300.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i(150, 100);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Point display");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
