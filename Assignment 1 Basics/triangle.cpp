#include<iostream>
#include<GL/freeglut.h>

void myInit()
{
	}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	
	gluOrtho2D(0, 100, 0, 10);
	glMatrixMode(GL_PROJECTION); 
	
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 1, 0);

	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Triangle");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
