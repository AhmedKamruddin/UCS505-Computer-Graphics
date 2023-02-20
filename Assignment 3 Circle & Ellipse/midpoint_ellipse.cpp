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

    int rx=10, ry=15;
	int xc=50, yc=50;
	float dx, dy, p1, p2, x, y;
	x=0;
	y=ry;

	p1=ry*ry + 0.25*rx*rx - rx*rx*ry;
	dx=2*ry*ry*x;
	dy=2*rx*rx*y;

	while(dx<dy)
	{
		glVertex2d(x+xc, y+yc);
		glVertex2d(-x+xc, y+yc);
		glVertex2d(x+xc, -y+yc);
		glVertex2d(-x+xc, -y+yc);

		// cout<<x+xc<<", "<<y+yc<<endl;
		// cout<<-x+xc<<", "<<y+yc<<endl;
		// cout<<x+xc<<", "<<-y+yc<<endl;
		// cout<<-x+xc<<", "<<-y+yc<<endl;

		if(p1<0)
		{
			x++;
			dx=dx + (2*ry*ry);
			p1=p1 + dx + ry*ry;
		}
		else
		{
			x++;
			y--;
			dx=dx + (2*ry*ry);
			dy=dy - (2*rx*rx);
			p1=p1 + dx - dy + ry*ry;
		}
	}

	p2=(ry*ry*(x+0.5)*(x+0.5)) + rx*rx*(y-1)*(y-1) - rx*rx*ry*ry;
	while(y>=0)
	{
		glVertex2d(x+xc, y+yc);
		glVertex2d(-x+xc, y+yc);
		glVertex2d(x+xc, -y+yc);
		glVertex2d(-x+xc, -y+yc);

		// cout<<x+xc<<", "<<y+yc<<endl;
		// cout<<-x+xc<<", "<<y+yc<<endl;
		// cout<<x+xc<<", "<<-y+yc<<endl;
		// cout<<-x+xc<<", "<<-y+yc<<endl;

		if(p2>0)
		{
			y--;
			dy=dy-(2*rx*rx);
			p2=p2+(rx*rx)-dy;
		}
		else
		{
			y--;
			x++;
			dx=dx+(2*ry*ry);
			dy=dy-(2*rx*rx);
			p2=p2+dx-dy+rx*rx;
		}
	}


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
	// display();   
}
