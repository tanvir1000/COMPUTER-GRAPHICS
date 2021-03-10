#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(22.0);
glBegin(GL_LINE_LOOP);
glVertex2i(435,270);
glVertex2i(340,270);
glVertex2i(310,370);
glVertex2i(280,270);
glVertex2i(185,270);
glVertex2i(260,218);
glVertex2i(230,120);
glVertex2i(310,190);
glVertex2i(390,120);
glVertex2i(360,218);
glEnd();
glFlush ();
}
void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(640.0, 0.0, 480.0, 0.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Lab Task");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
