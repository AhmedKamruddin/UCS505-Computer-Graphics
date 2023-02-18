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
	
	//Step 2
	int x=xa;
	int y=ya;
	glVertex2d(xa, ya);	

	//Step 3
	int dx=xb-xa;
	int dy=yb-ya;
	int pinitial=2*dy-dx;

	//Step 4
	int p=pinitial;
	for(int k=0; k<abs(dx); k++)
	{
		if(p<0)
		{
			x=x+1;
			y=y;
			glVertex2d(x, y);
			
			p=p+2*dy;
		}
		else 
		{
			x=x+1;
			y=y+1;
			glVertex2d(x, y);
			
			p=p+2*dy-2*dx;
		}
	}
			
		
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{	
	//Step 1
	cout<<"Enter x0, y0, xf, yf\n";
	cin>>xa>>ya>>xb>>yb;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Line Bresenham");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
