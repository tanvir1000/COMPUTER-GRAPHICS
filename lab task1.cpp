#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (0, 0, 0);
glPointSize(5.0);


glBegin(GL_TRIANGLES);
glVertex2i(80,60);
glVertex2i(55,50);
glVertex2i(70,50);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(500,100);
glVertex2i(50,100);
glVertex2i(70,50);
glVertex2i(490,50);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(510,140);
glVertex2i(30,140);
glVertex2i(50,110);
glVertex2i(500,110);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(90,150);
glVertex2i(20,150);
glVertex2i(30,140);
glVertex2i(100,140);
glEnd();

glBegin(GL_QUADS);
glVertex2i(500,160);
glVertex2i(480,160);
glVertex2i(480,150);
glVertex2i(500,150);
glEnd();

glBegin(GL_QUADS);
glVertex2i(500,175);
glVertex2i(480,175);
glVertex2i(480,165);
glVertex2i(500,165);
glEnd();

glBegin(GL_QUADS);
glVertex2i(500,190);
glVertex2i(480,190);
glVertex2i(480,180);
glVertex2i(500,180);
glEnd();

glBegin(GL_QUADS);
glVertex2i(500,205);
glVertex2i(480,205);
glVertex2i(480,195);
glVertex2i(500,195);
glEnd();

glBegin(GL_QUADS);
glVertex2i(430,210);
glVertex2i(410,210);
glVertex2i(410,150);
glVertex2i(430,150);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(420,210);
glVertex2i(415,190);
glVertex2i(415,150);
glVertex2i(420,150);
glEnd();


glBegin(GL_QUADS);
glVertex2i(390,160);
glVertex2i(370,160);
glVertex2i(370,150);
glVertex2i(390,150);
glEnd();

glBegin(GL_QUADS);
glVertex2i(390,175);
glVertex2i(370,175);
glVertex2i(370,165);
glVertex2i(390,165);
glEnd();

glBegin(GL_QUADS);
glVertex2i(390,190);
glVertex2i(370,190);
glVertex2i(370,180);
glVertex2i(390,180);
glEnd();

glBegin(GL_QUADS);
glVertex2i(390,205);
glVertex2i(370,205);
glVertex2i(370,195);
glVertex2i(390,195);
glEnd();

glBegin(GL_QUADS);
glVertex2i(330,210);
glVertex2i(280,210);
glVertex2i(280,150);
glVertex2i(330,150);
glEnd();

glBegin(GL_QUADS);
glVertex2i(340,190);
glVertex2i(330,210);
glVertex2i(330,150);
glVertex2i(340,150);
glEnd();

glBegin(GL_QUADS);  //first
glVertex2i(260,160);
glVertex2i(240,160);
glVertex2i(240,150);
glVertex2i(260,150);
glEnd();

glBegin(GL_QUADS);
glVertex2i(260,175);
glVertex2i(240,175);
glVertex2i(240,165);
glVertex2i(260,165);
glEnd();

glBegin(GL_QUADS);
glVertex2i(260,190);
glVertex2i(240,190);
glVertex2i(240,180);
glVertex2i(260,180);
glEnd();

glBegin(GL_QUADS);  //second
glVertex2i(230,160);
glVertex2i(210,160);
glVertex2i(210,150);
glVertex2i(230,150);
glEnd();

glBegin(GL_QUADS);
glVertex2i(230,175);
glVertex2i(210,175);
glVertex2i(210,165);
glVertex2i(230,165);
glEnd();

glBegin(GL_QUADS);
glVertex2i(230,190);
glVertex2i(210,190);
glVertex2i(210,180);
glVertex2i(230,180);
glEnd();



glBegin(GL_QUADS);  //third
glVertex2i(200,160);
glVertex2i(180,160);
glVertex2i(180,150);
glVertex2i(200,150);
glEnd();

glBegin(GL_QUADS);
glVertex2i(200,175);
glVertex2i(180,175);
glVertex2i(180,165);
glVertex2i(200,165);
glEnd();

glBegin(GL_QUADS);
glVertex2i(200,190);
glVertex2i(180,190);
glVertex2i(180,180);
glVertex2i(200,180);
glEnd();



glBegin(GL_QUADS);  //4
glVertex2i(160,160);
glVertex2i(140,160);
glVertex2i(140,150);
glVertex2i(160,150);
glEnd();

glBegin(GL_QUADS);  //4
glVertex2i(160,175);
glVertex2i(140,175);
glVertex2i(140,165);
glVertex2i(160,165);
glEnd();


glBegin(GL_QUADS);
glVertex2i(160,190);
glVertex2i(140,190);
glVertex2i(140,180);
glVertex2i(160,180);
glEnd();

glBegin(GL_QUADS);
glVertex2i(130,160);
glVertex2i(110,160);
glVertex2i(110,150);
glVertex2i(130,150);
glEnd();

glBegin(GL_QUADS);
glVertex2i(130,175);
glVertex2i(110,175);
glVertex2i(110,165);
glVertex2i(130,165);
glEnd();

glBegin(GL_QUADS);
glVertex2i(130,190);
glVertex2i(110,190);
glVertex2i(110,180);
glVertex2i(130,180);
glEnd();

glBegin(GL_QUADS);
glVertex2i(100,160);
glVertex2i(80,160);
glVertex2i(80,155);
glVertex2i(100,150);
glEnd();

glBegin(GL_QUADS);  //6
glVertex2i(100,175);
glVertex2i(80,175);
glVertex2i(80,165);
glVertex2i(100,165);
glEnd();

glBegin(GL_QUADS);  //6
glVertex2i(100,190);
glVertex2i(80,190);
glVertex2i(80,180);
glVertex2i(100,180);
glEnd();




glFlush ();
}

void myInit (void)
{
glClearColor(128, 128, 128, 128);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("1");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
