#include<iostream>
#include<GL/freeglut.h>

void myInit()
{
	}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	
	gluOrtho2D(0, 100, 0, 10);
	glMatrixMode(GL_QUADS); 
	
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Rectangle");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
