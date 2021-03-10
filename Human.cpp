#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


int x=20;
int y=800;
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (255, 0, 0);
glPointSize(5.0);

glBegin(GL_QUADS);

//boots
glVertex2i(x*13, x*2);
glVertex2i(x*13, x*0);

glVertex2i(x*18.7, x*0);
glVertex2i(x*18.7, x*2);

glVertex2i(x*15.7, x*2);
glVertex2i(x*18.7, x*2);
glVertex2i(x*18.7, x*4);
glVertex2i(x*15.7, x*4);



glVertex2i(y-x*13, x*2);
glVertex2i(y-x*13, x*0);

glVertex2i(y-x*18.7, x*0);
glVertex2i(y-x*18.7, x*2);

glVertex2i(y-x*15.7, x*2);
glVertex2i(y-x*18.7, x*2);
glVertex2i(y-x*18.7, x*4);
glVertex2i(y-x*15.7, x*4);
// show up
glColor3ub (0, 255, 0);

glVertex2i(x*15.7, x*4);
glVertex2i(x*18.7, x*4);
glVertex2i(x*18.7, x*6);
glVertex2i(x*15.7, x*6);

glVertex2i(y-x*15.7, x*4);
glVertex2i(y-x*18.7, x*4);
glVertex2i(y-x*18.7, x*6);
glVertex2i(y-x*15.7, x*6);


//leg
glColor3ub (0, 200, 0);

glVertex2i(y-x*15.7, x*6);
glVertex2i(y-x*18.7, x*6);
glVertex2i(y-x*18.7, x*22);
glVertex2i(y-x*15.7, x*22);


glVertex2i(x*15.7, x*6);
glVertex2i(x*18.7, x*6);
glVertex2i(x*18.7, x*22);
glVertex2i(x*15.7, x*22);

//black body
glColor3ub (0, 0, 255);

glVertex2i(x*13.7, x*20);
glVertex2i(y-x*13.7, x*20);
glVertex2i(y-x*13.7, x*35.5);
glVertex2i(x*13.7, x*35.5);



//bottom
glColor3ub (0, 200, 0);
glVertex2i(x*15.7, x*18);
glVertex2i(y-x*15.7, x*18);
glVertex2i(y-x*15.7, x*22);
glVertex2i(x*15.7, x*22);


//dawn T shap
glColor3ub (245, 176, 65);
glVertex2i(x*15.7, x*22);
glVertex2i(y-x*15.7, x*22);
glVertex2i(y-x*15.7, x*22.9);
glVertex2i(x*15.7, x*22.9);

glVertex2i(x*19.5, x*22.9);
glVertex2i(y-x*19.5, x*22.9);
glVertex2i(y-x*19.5, x*28.5);
glVertex2i(x*19.5, x*28.5);




//hand
glColor3ub (255,255 , 255);

glVertex2i(x*13.7, x*17);
glVertex2i(x*15.7, x*17);
glVertex2i(x*15.7, x*20);
glVertex2i(x*13.7, x*20);

glVertex2i(x*13.7, x*19);
glVertex2i(x*16.7, x*19);
glVertex2i(x*16.7, x*20);
glVertex2i(x*13.7, x*20);



glVertex2i(y-x*13.7, x*17);
glVertex2i(y-x*15.7, x*17);
glVertex2i(y-x*15.7, x*20);
glVertex2i(y-x*13.7, x*20);
glVertex2i(y-x*13.7, x*19);
glVertex2i(y-x*16.7, x*19);
glVertex2i(y-x*16.7, x*20);
glVertex2i(y-x*13.7, x*20);


// jacket coller


glColor3ub (0,0 , 255);

glVertex2i(x*15.7, x*35.5);
glVertex2i(y-x*15.7, x*35.5);
glVertex2i(y-x*15.7, x*37.5);
glVertex2i(x*15.7, x*37.5);

glVertex2i(x*16.7, x*37.5);
glVertex2i(y-x*16.7, x*37.5);
glVertex2i(y-x*16.7, x*38.5);
glVertex2i(x*16.7, x*38.5);

// head

glColor3ub (255,255 , 255);
glVertex2i(x*14.7, x*36.5);
glVertex2i(y-x*17.7, x*36.5);
glVertex2i(y-x*17.7, x*43.5);
glVertex2i(x*14.7, x*43.5);



// hair

glColor3ub (135, 54, 0 );
glVertex2i(x*12.7, x*43.5);
glVertex2i(y-x*16.7, x*43.5);
glVertex2i(y-x*16.7, x*46.5);
glVertex2i(x*12.7, x*46.5);

glVertex2i(x*12.7, x*46.5);
glVertex2i(x*17.7, x*46.5);
glVertex2i(x*17.7, x*48.4);
glVertex2i(x*12.7, x*48.4);


glVertex2i(y-x*18.7, x*41.5);
glVertex2i(y-x*16.7, x*41.5);
glVertex2i(y-x*16.7, x*43.5);
glVertex2i(y-x*18.7, x*43.5);

glVertex2i(x*19.3, x*39.5);
glVertex2i(x*20.3, x*39.5);
glVertex2i(x*20.3, x*43.5);
glVertex2i(x*19.3, x*43.5);

glVertex2i(x*12.7, x*40.5);
glVertex2i(x*18.3, x*40.5);
glVertex2i(x*18.3, x*42.5);
glVertex2i(x*12.7, x*42.5);

//nose
glColor3ub (255,255 , 255);
glVertex2i(x*14.7, x*40.5);
glVertex2i(x*15.7, x*40.5);
glVertex2i(x*15.7, x*41.5);
glVertex2i(x*14.7, x*41.5);


// nek

glColor3ub (20, 143, 119);
glVertex2i(x*17.7, x*32.5);
glVertex2i(y-x*17.7, x*32.5);
glVertex2i(y-x*17.7, x*36.5);
glVertex2i(x*17.7, x*36.5);


glVertex2i(x*18.5, x*30.5);
glVertex2i(y-x*18.5, x*30.5);
glVertex2i(y-x*18.5, x*32.5);
glVertex2i(x*18.5, x*32.5);

glVertex2i(x*19.5, x*28.5);
glVertex2i(y-x*19.5, x*28.5);
glVertex2i(y-x*19.5, x*30.5);
glVertex2i(x*19.5, x*30.5);

glEnd();



glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 800.0, 0.0, 1000.0);
}



int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800, 1000);
glutInitWindowPosition (0, 0);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();

}
