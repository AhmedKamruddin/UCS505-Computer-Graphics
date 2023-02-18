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


    int p=100, q=100;
    int r=10;
    int d=3-2*r;
    int x=0, y=r;

    while(x<y)
    {
        glVertex2d(x+p, y+q);
        glVertex2d(y+p, x+q);
        glVertex2d(-y+p, x+q);
        glVertex2d(-x+p, y+q);
        glVertex2d(-x+p, -y+q);
        glVertex2d(-y+p, -x+q);
        glVertex2d(y+p, -x+q);
        glVertex2d(x+p, -y+q);

        if(d<0)
        {
            d=d+4*x+6;
            x=x+1;
        }
        else
        {
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
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
	glutCreateWindow("Circle Bresenham");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}