#include<iostream>
#include<cmath>
#include<GL/freeglut.h>
using namespace std;
GLdouble xa, ya, xb, yb;

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 300.0);
}

void display()
{
	glPointSize(2.0);
	glBegin(GL_POINTS);
	//Step 1
	glVertex2d(xa, ya);	

	//Step 2
	int dx=xb-xa;
	int dy=yb-ya;

	//Step 3
	int steps;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	
	//Step 4 & 5
	float xincr, yincr;
	float x=xa, y=ya;
	int xround, yround;
	for(int i=0; i<steps; i++)
	{
		xincr=float(dx)/float(steps);
		yincr=float(dy)/float(steps);
		x=x+xincr;
		y=y+yincr;
		xround=round(x);
		yround=round(y);
		glVertex2d(xround, yround);
	}
	
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{	
	cout<<"Enter xa, ya, xb, yb\n";
	cin>>xa>>ya>>xb>>yb;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Line DDA");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
