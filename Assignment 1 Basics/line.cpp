#include<iostream>
#include<GL/freeglut.h>

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(0.25, 0.25);
	glVertex2f(0.75, 0.75);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Line display");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
