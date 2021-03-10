#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 80.0);
}


void myDisplay(void)
{


    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (8.0, 5.0, 0.0);
    glPointSize(4.0);

    glBegin(GL_QUADS);
    glColor3ub ( 46, 64, 83 );
    glVertex2i(25,60);
    glVertex2i(25,50);
    glVertex2i(30,50);
    glVertex2i(30,60);

    glBegin(GL_QUADS);
    glColor3ub ( 46, 64, 83 );
    glVertex2i(35,60);
    glVertex2i(35,55);
    glVertex2i(40,55);
    glVertex2i(40,60);

    glBegin(GL_QUADS);
    glColor3ub ( 23, 32, 42);
    glVertex2i(25,55);
    glVertex2i(25,50);
    glVertex2i(40,50);
    glVertex2i(40,55);

     glBegin(GL_QUADS);
    glColor3ub ( 243, 156, 18);
    glVertex2i(25,50);
    glVertex2i(25,45);
    glVertex2i(40,45);
    glVertex2i(40,50);

    glBegin(GL_QUADS);
    glColor3ub ( 42, 41, 36 );
    glVertex2i(20,45);
    glVertex2i(20,30);
    glVertex2i(45,30);
    glVertex2i(45,45);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3ub ( 25, 25, 24  );
    glVertex2i(25,40);
    glVertex2i(25,35);
    glVertex2i(40,35);
    glVertex2i(40,40);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3ub ( 252, 223, 6  );
    glVertex2i(20,30);
    glVertex2i(20,25);
    glVertex2i(45,25);
    glVertex2i(45,30);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3ub ( 42, 41, 36  );
    glVertex2i(15,40);
    glVertex2i(15,35);
    glVertex2i(20,35);
    glVertex2i(20,40);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3ub ( 42, 41, 36 );
    glVertex2i(45,40);
    glVertex2i(45,35);
    glVertex2i(50,35);
    glVertex2i(50,40);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3ub ( 243, 156, 18  );
    glVertex2i(15,35);
    glVertex2i(15,30);
    glVertex2i(20,30);
    glVertex2i(20,35);

    glEnd();
    glFlush ();

     glBegin(GL_QUADS);
    glColor3ub ( 214, 137, 16 );
    glVertex2i(15,30);
    glVertex2i(15,20);
    glVertex2i(20,20);
    glVertex2i(20,30);

    glEnd();
    glFlush ();

     glBegin(GL_QUADS);
    glColor3ub ( 243, 156, 18 );
    glVertex2i(45,35);
    glVertex2i(45,30);
    glVertex2i(50,30);
    glVertex2i(50,35);

    glEnd();
    glFlush ();



     glBegin(GL_QUADS);
    glColor3ub ( 214, 137, 16 );
    glVertex2i(45,30);
    glVertex2i(45,20);
    glVertex2i(50,20);
    glVertex2i(50,30);

    glEnd();
    glFlush ();


     glBegin(GL_QUADS);
    glColor3ub ( 19, 13, 2);
    glVertex2i(20,20);
    glVertex2i(20,5);
    glVertex2i(30,5);
    glVertex2i(30,20);

    glEnd();
    glFlush ();

     glBegin(GL_QUADS);
    glColor3ub ( 28, 40, 51  );
    glVertex2i(15,20);
    glVertex2i(15,15);
    glVertex2i(20,15);
    glVertex2i(20,20);

    glEnd();
    glFlush ();

     glBegin(GL_QUADS);
    glColor3ub ( 28, 40, 51  );
    glVertex2i(45,20);
    glVertex2i(45,15);
    glVertex2i(50,15);
    glVertex2i(50,20);

    glEnd();
    glFlush ();

      glBegin(GL_QUADS);
    glColor3ub ( 19, 13, 2);
    glVertex2i(35,20);
    glVertex2i(35,5);
    glVertex2i(45,5);
    glVertex2i(45,20);

      glBegin(GL_QUADS);
    glColor3ub ( 26, 25, 25);
    glVertex2i(30,20);
    glVertex2i(30,15);
    glVertex2i(35,15);
    glVertex2i(35,20);

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1024, 768);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Batman");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
