#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
float dx,dy,x1,y1,x2,y2,res,i,Xin,Yin;
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(5.0);



dx=x2-x1;
dy=y2-y1;

if(dx>dy)
{
    res=dx;
}
else
    res=dy;

Xin=dx/res;
Yin=dy/res;
glBegin(GL_POINTS);
glVertex2i(x1,y1);
glEnd();

for(i=1;i<=res;i++)
{
    x1=x1+Xin;
    y1=y1+Yin;

    glBegin(GL_POINTS);
    glVertex2i(x1,y1);
    glEnd();
}
glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}





int main(int argc, char** argv)
{
    printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
