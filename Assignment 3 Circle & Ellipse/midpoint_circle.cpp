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

    int Xcentre=100, Ycentre=100;
    int r=10;
    int x=0, y=r;
    int p=1-r;

    while(x<y)
    {
        glVertex2d(x+Xcentre, y+Ycentre);
        glVertex2d(-x+Xcentre, y+Ycentre);
        glVertex2d(x+Xcentre, -y+Ycentre);
        glVertex2d(-x+Xcentre, -y+Ycentre);
        glVertex2d(y+Xcentre, x+Ycentre);
        glVertex2d(-y+Xcentre, x+Ycentre);
        glVertex2d(y+Xcentre, -x+Ycentre);
        glVertex2d(-y+Xcentre, -x+Ycentre);
        if(p<0)
        {
            x=x+1;
            p=p+2*x+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            p=p-2*y+2*x+1;
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
	glutCreateWindow("Circle Midpoint");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();   
}