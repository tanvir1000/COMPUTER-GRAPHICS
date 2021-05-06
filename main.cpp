#include<cstdio>
#include <windows.h>
#include<math.h>
#include <vector>
#include <cstdlib>
# define PI 3.14159265358979323846
#include <GL/gl.h>
#include <GL/glut.h>
#include<MMSystem.h>

GLfloat position = 0.0f;
GLfloat speed = -0.1f;

GLfloat position1 = 0.0f;
GLfloat speed1 = 0.05f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.04f;

GLfloat position3 = 0.0f;
GLfloat speed3 = -0.1f;


void update2(int value) {

    if(position >8.0)
        position =-8.0f;

    position -= speed;

	glutPostRedisplay();

	if(position1 <-1.0)
        position1 = 0.2f;
        position1 -= speed1;
        glutPostRedisplay();

    if(position2 >1.0)
        position2 = -1.0f;
        position2 += speed2;
        glutPostRedisplay();


	glutTimerFunc(30, update2, 0);
}


//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    //glEnable(GL_LIGHT2); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
	//gluLookAt(.2, 0, 10, 5, 2, 0, 0, 1, -1); // eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz
}

bool flag=false;
float _revwheel = 0.0;
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float _wheel = -6.0;
bool movement = false;
float _zoom_x_y = 0.0;
float _zoom_up_down = 0.0;
float _zoom_in = -7.0;
//float _revwheel = 16.0;
void revclouds();
void update1();
void goalBar();
void movesun();
void aircraft();

void draw_cylinder(GLfloat radius,GLfloat height,float R,float G,float B)
{
    //glDisable(GL_LIGHTING);
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(R,G,B);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;

        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);

    glEnd();




    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
    //glEnable(GL_LIGHTING);
}


void clouds();
void dim();
void building();
void buildingShading();
void window();
void nightmode();

void drawScene() {
    GLfloat twicePi = 2.0f * PI;
	int triangleAmount = 100;
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);// color red 0.74902 green 0.847059 blue 0.847059(0.74902,0.847059,0.847059)
    //glClearColor(r,g,b,1);// color red 0.74902 green 0.847059 blue 0.847059




	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity(); //Reset the drawing perspective
	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(_zoom_x_y, _zoom_up_down, _zoom_in); //Move forward 5 units
	/*----------------------sun--------------------------------------*/
	glDisable(GL_LIGHTING);
	glPushMatrix();


    glRotatef(0,0,1,0);
	glTranslatef(-3.8,2.4, -.77);
	                glColor3ub(255, 255, 100);
                    GLfloat sx=.0f; GLfloat sy=.0f; GLfloat sr =.5f;
                    glBegin(GL_TRIANGLE_FAN);

                    glVertex2f(sx, sy);
                    for(i = 0; i <= triangleAmount;i++) {
                        glVertex2f(
                                sx + (sr * cos(i *  twicePi / triangleAmount)),
                            sy + (sr * sin(i * twicePi / triangleAmount))
                        );
                    }
                glEnd();
	glPopMatrix();


	glColor3f(0.74902,0.847059,0.847059);
	glBegin(GL_POLYGON);
	glVertex3d(-650,325,-1);
	glVertex3d(-650,-325,-1);
	glVertex3d(650,-325,-1);
	glVertex3d(650,325,-1);
	glEnd();
	glPopMatrix();



	///rain


	glPushMatrix();
    glTranslatef(position2,position1, 0.0f);

    // Rain line1
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

 glTranslatef(-.2,0.1,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.2,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-2.2,0.2,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-1.4,0.7,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-1.2,0.2,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.02,-0.6,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.01,-0.6,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

     glTranslatef(1.02,0.6,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(0.5,0.6,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(0.4,-0.3,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(0.8,-0.3,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-0.8,-0.3,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(1.8,0.6,0);

    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(2.8,0.6,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.8,0.6,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.8,0.1,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.6,0.1,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(1.8,-0.3,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.7,-.7,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.3,-.7,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(-.5,-.7,0);
    glColor3ub(4, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();






    glPopMatrix();


























    glPushMatrix();
    glEnable(GL_LIGHTING);


	/*Dim*/
	dim();
    /*Building*/
	building();
    buildingShading();



	glPushMatrix();
    glTranslatef(-2.3,-1.1,1.2);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.05, 0.5, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.85,-1.1,1.2);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.05, 0.5, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glDisable(GL_LIGHTING);
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-.85,-.53,1.2);
    //glRotatef(90, -1.0, 0.0, 0.0);
    glutSolidSphere(.1,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.3,-.53,1.2);
    //glRotatef(90, -1.0, 0.0, 0.0);
    glutSolidSphere(.1,20,20);
    glPopMatrix();
    glEnable(GL_LIGHTING);

    aircraft();
    revclouds();
    glutSwapBuffers();




}
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);// color red 0.74902 green 0.847059 blue 0.847059(0.74902,0.847059,0.847059)
    //glClearColor(r,g,b,1);// color red 0.74902 green 0.847059 blue 0.847059

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity(); //Reset the drawing perspective
	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(_zoom_x_y, _zoom_up_down, _zoom_in); //Move forward 5 units
	//glRotatef(20.0,1.0,1.0,0.0);
	glDisable(GL_LIGHTING);
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex3d(-650,325,-1);
	glVertex3d(-650,-325,-1);
	glVertex3d(650,-325,-1);
	glVertex3d(650,325,-1);
	glEnd();
	glPopMatrix();
	nightmode();

    glPushMatrix();
    glEnable(GL_LIGHTING);

	/*Dim*/
	dim();
    /*Building*/
	building();
    buildingShading();
    glPushMatrix();
    glTranslatef(-2.3,-1.1,1.2);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.05, 0.5, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.85,-1.1,1.2);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.05, 0.5, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glDisable(GL_LIGHTING);
    glColor3f(1,1,0);
    glPushMatrix();
    glTranslatef(-.85,-.53,1.2);
    //glRotatef(90, -1.0, 0.0, 0.0);
    glutSolidSphere(.1,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.3,-.53,1.2);
    //glRotatef(90, -1.0, 0.0, 0.0);
    glutSolidSphere(.1,20,20);
    glPopMatrix();
    glEnable(GL_LIGHTING);

	glutSwapBuffers();
}


void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	_wheel +=0.05;
    if(_wheel>15.0){
        _wheel=-15.5;
    }
    _revwheel -=0.05;
    if(_revwheel<-15.0){
        _revwheel=15.5;
    }

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}
void Special_Keys (int key, int x, int y)
{
    switch (key) {

       case GLUT_KEY_LEFT :
           _zoom_x_y++;
           break;
       case GLUT_KEY_RIGHT:
           _zoom_x_y--;
           break;
       case GLUT_KEY_UP:
            _zoom_up_down--;
            glutPostRedisplay();
            break;
       case GLUT_KEY_DOWN :
           _zoom_up_down++;
           break;
       /*case 27:
        glutDestroyWindow(Win.id);
        exit(0);
        break;
*/
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
    if(!flag){
        switch(key){
        case 's':
            movement = true;
            glutPostRedisplay();
            break;
        case 'S':
            movement = true;
            glutPostRedisplay();
            break;
        case 'f':
            movement = false;
            glutPostRedisplay();
            break;
        case 'F':
            movement = false;
            glutPostRedisplay();
            break;
        case '+':
            _zoom_in++;
            glutPostRedisplay();
            break;
        case '-':
            _zoom_in--;
            glutPostRedisplay();
            break;
        case 'n':
            glutDisplayFunc(draw);
            movement = false;
            flag=true;
            PlaySound(TEXT("crickets-1787.wav"), NULL, SND_ASYNC);

            glutPostRedisplay();
            break;
            case 'e':
             glutDestroyWindow(1);
             movement = false;
            flag=true;

            PlaySound(TEXT("crickets-1787.wav"), NULL, SND_ASYNC);
            glutPostRedisplay();
            break;




        case 'd':
            glutDisplayFunc(drawScene);
            flag=false;
            movement = true;
            PlaySound(TEXT("rain-07.wav"), NULL, SND_ASYNC);
            glutPostRedisplay();
            break;
            case 'D':
            glutDestroyWindow(1);
            flag=false;
            movement = true;
            PlaySound(TEXT("rain-07.wav"), NULL, SND_ASYNC);
            glutPostRedisplay();
            break;
    }
    }
    else{
        movement = false;
        glutPostRedisplay();
        switch(key){
case '+':
    _zoom_in++;
    glutPostRedisplay();
    break;
case '-':
    _zoom_in--;
    glutPostRedisplay();
    break;
case 'n':
    glutDisplayFunc(draw);
    flag=true;
    movement = false;
    //glutKeyboardFunc(handleKeypress);

    PlaySound(TEXT("crickets-1787.wav"), NULL, SND_ASYNC);
    glutPostRedisplay();
    break;
     case 'e':
             glutDestroyWindow(1);
             movement = true;
            flag= false;

            PlaySound(TEXT("crickets-1787.wav"), NULL, SND_ASYNC);
            glutPostRedisplay();
            break;


case 'd':
    glutDisplayFunc(drawScene);
    flag=false;
    movement = true;
    PlaySound(TEXT("rain-07.wav"), NULL, SND_ASYNC);
    glutPostRedisplay();
    break;

    case 'D':
    glutDestroyWindow(1);
    flag=false;
    movement = true;
    PlaySound(TEXT("rain-07.wav"), NULL, SND_ASYNC);
    glutPostRedisplay();
    break;


    }

    }
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1368, 650);
    //glClearColor(1,1,1,1);
	//Create the window
	glutCreateWindow("Transformations");
	//glutFullScreen();

	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Special_Keys);



	glutTimerFunc(25, update, 0);
	glutTimerFunc(100, update2, 0); //Add a timer

//	glutTimerFunc(25, update1, 0); //Add a timer
	glutMainLoop();
	return 0;
}
void dim()
{
	/*-----------------------Sphere------------------------*/
	glPushMatrix();
    glTranslatef(5.30,-.96,.5);
    glRotatef(90, 0, -1.0, 0.0);
    draw_cylinder(0.05, 11, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    /*-----Field-----*/
    goalBar();
	glPushMatrix();
	//glRotatef(20.0,1.0,1.0,0.0);
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3d(-650,-.97,0);
	glVertex3d(-650,-100,0);
	glVertex3d(650,-100,0);
	glVertex3d(650,-.97,0);
	glEnd();
	glPopMatrix();
	/*-----------------cloud-----------------------------------------*/
	if(movement){
            glPushMatrix();
            glColor3f(0.902, 0.902, 0.980);
        clouds();
    glPopMatrix();
    }
	/*---------------------------------------------------------------*/
    /*-----The DIM-----*/
	//glPopMatrix(); //Undo the move to the center of the pentagon
	glPushMatrix(); //Save the current state of transformations
	glColor3f(0,0,0);
	glRotatef(-100,1.0,1.0,0.0);
	glTranslatef(.17, 2.3, -.77); //Move to the center of the triangle
	glRotatef(53, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
	//glColor3f(0,0,0);
    glutWireSphere(1.45,20,20);
    glPopMatrix();

	/*------------------------------------------------------------------------*/
	//glPopMatrix(); //Undo the move to the center of the pentagon
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.658824,0.658824,0.658824);
	glRotatef(-100,1.0,1.0,0.0);
	glTranslatef(.17, 2.3, -.77); //Move to the center of the triangle
	glRotatef(53, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
	//glColor3f(0,0,0);
    glutSolidSphere(1.44,20,20);
    glPopMatrix();
    /*----------------------------------------------------------------------------------------------------*/
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.658824,0.658824,0.658824);
	glRotatef(-90,1,0,0);
	glTranslatef(1.8,0.7,-1.1); //Move to the center of the triangle
	//glRotatef(40, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	//glColor3f(0,0,0);
    glutSolidTorus(.28,.28,20,20);
    glPopMatrix();
}

void building()
{
    /*======================3D Building=====================================*/
	/*----------------------------------------------------------------------*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-5.4, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-5.4, -.55, 0.0);//Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-5.4, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(-5.4, -.55, 0.0);//Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();
    /*---------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-4.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	/*-----tree-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(-4.6, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-4.6, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.6,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();


	/*--------------*/

	glColor3f(0,0,0);
	glTranslatef(-4.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-4.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(-4.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();
    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-3.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-3.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-3.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(-3.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree1-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(-3.85, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.85, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.85,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/


    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-3, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-3, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-3, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(-3, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree2-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(-3.1, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.1, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.1,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/


    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(-.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(-.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree3-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(-.2, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-.2, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.2,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/
    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0.0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();


    /*----------------------------------------------------------------------------------*/
     /*---------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(1, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(1, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(1, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(1, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree4-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(.5, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(.5, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(.5,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/
    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(1.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(1.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(1.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(1.8, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree5-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(1.25, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(1.25, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.25,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/
    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(2.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(2.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(2.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(2.6, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree6-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(2, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(2, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/
    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(3.4, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(3.4, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(3.4, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(3.4, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree6-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(2.75, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.75, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.75,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/
    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(4.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(4.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(4.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(4.2, -.55, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();

    /*-----tree7-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(3.5, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(3.5, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/
    /*----------------------------------------------------------------------------------*/
    /*---------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(5, -.55, 0.0); //Move to the center of the triangle
	glRotatef(.2, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.8);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(5, -.55, 0.0); //Move to the center of the triangle
	glRotatef(.2, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.71);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0,0,0);
	glTranslatef(5, -.55, 0.0); //Move to the center of the triangle
	glRotatef(.2, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutWireCube(.79);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glColor3f(0.545, 0.000, 0.000);
	glTranslatef(5, -.55, 0.0); //Move to the center of the triangle
	glRotatef(.2, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.78);
    glPopMatrix();
    /*-----tree5-----*/
	glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(4.25, -.5, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.45,20,20);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.25, -.6, 1.0); //Move to the center of the triangle
	glRotatef(90, -1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCone(.10,.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.25,-.9,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, 0.3, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    glPopMatrix();
	/*--------------*/
}
void buildingShading()
{

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-2.5,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-2.3,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-2.1,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-1.9,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-1.7,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-1.5,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-1.3,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-1.1,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-.9,.12, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.2);
    glPopMatrix();

    /*=========================bars=======================================================*/
    //glColor3f(0.753, 0.753, 0.753);
    glPushMatrix();
    glTranslatef(-2.22,-.85,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.05,-.85,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.88,-.85,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,-.85,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,-.85,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.4,-.85,1.0);
    glRotatef(90, -1.0, 0.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.05,0,1.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.05,-.2,1.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    draw_cylinder(0.03, .87, 0.627, 0.322, 0.176);
    glFlush();
    glPopMatrix();
    /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/
    //glDisable(GL_DEPTH_TEST);
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(1,1,1);
	glTranslatef(-6.02,-.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();
    //glEnable(GL_DEPTH_TEST);
    /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.95, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.88, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.81, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    /*----------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.74, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.67, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.60, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.1);glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.35, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();
    glPopMatrix();

 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.53, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.46, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.39, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.32, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.25, -0.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.18, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.11, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-5.04, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.97, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();



 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.90, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.83, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.76, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.69, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.61, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.54, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.47, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/



    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.40, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/



     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.33, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.26, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.19, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.12, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-4.05, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.98, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.91, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.84, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.77, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.70, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.63, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.56, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.49, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.42, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.35, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.28, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.21, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.14, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.07, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-3.0, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();



 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-2.93, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();



 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-2.86, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();



 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-2.79, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();



 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-2.72, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-2.65, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();



 /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/
     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-2.58, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     /*----------------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------------*/

 glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.98, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


 glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.91, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


 glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.84, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.1);
    glPopMatrix();


     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.77, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

     glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.70, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.63, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.56, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.49, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.42, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.35, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.28, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.21, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.14, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(-0.07, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(0, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.07, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.14, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	//color red 0.658824 green 0.658824 blue 0.658824
	glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.21, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.28, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.35, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.42, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.49, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.56, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.63, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.70, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.77, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.84, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.91, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(.98, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.05, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.12, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.19, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.26, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.33, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.4, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.47, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.54, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.61, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.68, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.75, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.82, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.89, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(1.96, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.03, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.1, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.17, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.24, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.31, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.38, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.45, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.52, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.59, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.66, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.73, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.80, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.87, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(2.94, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.01, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.08, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.15, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.22, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.29, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.36, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.43, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.5, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.57, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.64, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.71, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.78, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.85, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.92, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(3.99, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.06, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.13, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.2, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.27, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.34, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.41, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.48, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.55, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.62, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.69, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.76, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.83, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.9, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(4.97, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.04, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.11, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.18, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.25, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.32, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.39, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.46, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.53, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.6, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
	glTranslatef(5.67, -.1, 0.0); //Move to the center of the triangle
	glRotatef(0, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
    glutSolidCube(.13);
    glPopMatrix();
    //glColor3f(1,1,1);
    window();

}

void window()
{
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glColor3f(0.753, 0.753, 0.753);
	glTranslatef(-5.65,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);


    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/
    glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(-4.92,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);



    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/


     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(-4.2,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);


     /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(-3.43,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);



    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(-1.30,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);



     /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(-0.57,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);



/*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(0.17,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);



    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(0.89,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);


    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(1.65,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);


    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(2.39,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);

    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(3.13,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);

    /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

     glDisable(GL_LIGHTING);
    glPushMatrix();
   // glColor3f(0.184, 0.310, 0.310);
	glTranslatef(3.85,-1.43, 1.0);
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(1,1,0);
	glVertex3d(1,1.23,0);
	glVertex3d(.75,1.23,0);
    glVertex3d(.75,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
	glVertex3d(.7,1,0);
	glVertex3d(.7,1.23,0);
	glVertex3d(.45,1.23,0);
    glVertex3d(.45,1,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.75,0);
    glVertex3d(.45,.75,0);
    glVertex3d(.45,.65,0);
    glVertex3d(1,.65,0);
	glEnd();
	glBegin(GL_QUADS); //Move to the center of the triangle
    glVertex3d(1,.9,0);
    glVertex3d(.45,.9,0);
    glVertex3d(.45,.8,0);
    glVertex3d(1,.8,0);
	glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);

}


void clouds(){
	glTranslatef(_wheel,0.0,0.0);
    /*=======================================cloud============================================================================*/
    glDisable(GL_LIGHTING);
    //glColor3f(0, 0, 0);
   // glColor3f(0.000, 1.000, 1.000);
    //glTranslatef(_wheel,0.0,0.0);
	//glPushMatrix();

	glPushMatrix();

//=======================================================
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.50,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.25,2.45,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.0,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.25,2.15,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();






	//=============================================================LEFTMOST side cloud================
	/*-----------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix();
	//Save the current state of transformations
	glTranslatef(-5.8,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();



	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.7,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.35,2.20,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.0,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.35,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	/*------------------------------------------------------------------------------------------------------------------------*/

//----------------------------------------------------------------------------------
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-4.0,2.3,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.7,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.6,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.25,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.1,2.1,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

//=============================================================right side cloud================

    glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.50,1.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.20,1.6,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.0,1.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.2,1.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();






//=============================================================================================
	//-------------------------------------------------------------------------------------------------------------------*/

    //glTranslatef(_wheel,0.0,0.0);
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.45;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-.5,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.4,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glLoadIdentity();
	glPopMatrix();



	glPopMatrix();


	/*------------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(.75,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(1.25,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.25,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.28;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	//glPopMatrix();
	glPopMatrix();

	/*-----------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.2,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.30,2.45,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.7,2.35,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(3.1,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.7,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	/*------------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.3,2.45,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.7,2.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.37;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(5.2,2.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.42;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	//glPopMatrix();
    glEnable(GL_LIGHTING);

    /*========================================================================================================================*/
}
void revclouds(){
//glPushMatrix();
	glTranslatef(_revwheel,0.0,0.0);

    /*=======================================cloud============================================================================*/
    glDisable(GL_LIGHTING);
    glColor3f(0.000, 1.000, 1.000);
   // glColor3f(0.000, 1.000, 1.000);
    //glTranslatef(_wheel,0.0,0.0);
	//glPushMatrix();

	glPushMatrix();

//=======================================================
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.50,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.25,2.45,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.0,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.25,2.15,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();






	//=============================================================LEFTMOST side cloud================
	/*-----------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix();
	//Save the current state of transformations
	glTranslatef(-5.8,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();



	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.7,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.35,2.20,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.0,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


glPushMatrix(); //Save the current state of transformations
	glTranslatef(-5.35,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	/*------------------------------------------------------------------------------------------------------------------------*/






//----------------------------------------------------------------------------------
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-4.0,2.3,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.7,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.6,2.0,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.25,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	  glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3.1,2.1,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

//=============================================================right side cloudcloud================

    glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.50,1.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.20,1.6,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.0,1.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.2,1.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();






//=============================================================================================
	//-------------------------------------------------------------------------------------------------------------------*/

    //glTranslatef(_wheel,0.0,0.0);
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.45;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-.5,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.4,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();



	glPopMatrix();


	/*------------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(.75,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(1.25,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.25,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.28;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	//glPopMatrix();
	glPopMatrix();

	/*-----------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.2,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.30,2.45,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.7,2.35,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(3.1,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.7,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	/*------------------------------------------------------------------------------------------------------------------------*/

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.3,2.45,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(4.7,2.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.37;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(5.2,2.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.42;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();
    glEnable(GL_LIGHTING);

    /*========================================================================================================================*/
}
void nightmode()
{
    glDisable(GL_LIGHTING);
    glColor3f(1,1,1);
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(5.2,2.4,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.01;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2,2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.5,2.5,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(1.75,1.75,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(1,1.75,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2,2,1); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2,2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.75,2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.6,1.9,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(3,1,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-3,1,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.75,0.8,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0,1,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-4,1,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-4.25,1.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0,1.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.013;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(3.75,2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glColor3f(0,0,0);
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(3.23,2,.5); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}
void goalBar()
{
   // ---------------------------------------
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glColor3f(0.753, 0.753, 0.753);
	glTranslatef(-5.50,-2.50,1);
	glBegin(GL_LINE_STRIP); //Move to the center of the triangle

	glVertex3f(1,1.30,0);
	glVertex3f(1.8,0.15,0);

	glVertex3f(10,0.15,0);
	glVertex3f(8.8,1.30,0);
	glVertex3f(1,1.30,0);

	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	//-----------------------------------
// ---------------------------------------
  glDisable(GL_LIGHTING);
    glPushMatrix();
    glColor3f(0.753, 0.753, 0.753);
	glTranslatef(-5.50,-2.50,1);
	glBegin(GL_LINE_STRIP); //Move to the center of the triangle

	glVertex3f(4.9,1.30,0);
	glVertex3f(5.9,0.15,0);

	//glVertex3f(10,0.15,0);
	//glVertex3f(8.8,1.30,0);
	//glVertex3f(1,1.30,0);

	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);

	//-----------------------------------

    glDisable(GL_LIGHTING);
       //Undo the move to the center of the pentagon
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-0.10, -1.80, 1.0); //Move to the center of the triangle
//	glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_LINE_STRIP);
	//glTranslatef(-0.10, 1.80, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
	glEnable(GL_LIGHTING);
	//---------------------------------------------------

//// ---------------------------------------
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glColor3f(0.753, 0.753, 0.753);
	glTranslatef(-5.50,-2.50,1);
	glBegin(GL_LINES); //Move to the center of the triangle

	glVertex3f(1.2,1.01,0);
	glVertex3f(2.50,1.01,0);

	glVertex3f(1.6,0.435,0);
	glVertex3f(3.05,0.435,0);
	glVertex3f(3.05,0.435,0);
	glVertex3f(2.50,1.01,0);
	//glVertex3f(1,1.30,0);

	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	//------------------
// ---------------------------------------
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glColor3f(0.753, 0.753, 0.753);
	glTranslatef(-5.50,-2.50,1);
	glBegin(GL_LINES); //Move to the center of the triangle

	glVertex3f(9.1,1.01,0);
	glVertex3f(7.40,1.01,0);

	glVertex3f(9.7,0.435,0);
	glVertex3f(8.0,0.435,0);
	glVertex3f(8.0,0.435,0);
	glVertex3f(7.40,1.01,0);
	//glVertex3f(7.95,0.435,0);
	//glVertex3f(7.50,1.01,0);
	//glVertex3f(1,1.30,0);



	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);

	//------------------

}
void aircraft(){







     glPushMatrix();

    glTranslatef(-0.5*position, 0.0, 4.0);
   glBegin(GL_POLYGON);//body
   glColor3ub(50, 78, 78);
   glColor3ub(0, 0, 0);
   glVertex2f(-0.65,1.08);
   glVertex2f(-0.6,0.97);
   glVertex2f(0.1,1.05);
   glVertex2f(0.1,1.1);
   glEnd();
   glBegin(GL_POLYGON);
   glColor3ub(102, 153, 153);//front
   glVertex2f(-1.0,1.0);
   glVertex2f(-0.6,1.12);
   glVertex2f(-0.4,1.1);
   glVertex2f(-0.3,1.05);
   glEnd();
   glBegin(GL_POLYGON);//cockpit
   glColor3ub(0,0,0);
   glVertex2f(-0.85,1.045);
   glVertex2f(-0.6,1.12);
   glVertex2f(-0.4,1.109);
   glVertex2f(-0.65,1.06);
   glEnd();
   glBegin(GL_POLYGON);//wing
   glColor3ub(102, 153, 153);
   glVertex2f(-0.5,1.04);
   glVertex2f(0.05,1.065);
   glVertex2f(-0.01,0.95);
   glVertex2f(-0.2,0.9);
   glEnd();
   glBegin(GL_POLYGON);//wing-tail
   glColor3ub(102, 153, 153);
   glVertex2f(0.07,1.1);
   glVertex2f(-0.15,1.09);
   glVertex2f(-0.05,1.17);
   glVertex2f(0.03,1.17);
   glEnd();
glPopMatrix();







glEnable(GL_LIGHTING);
}


