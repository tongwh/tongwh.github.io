/*
*  double.c
*  This program demonstrates double buffering for 
*  flicker-free animation.  The left and middle mouse
*  buttons start and stop the spinning motion of the square.
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

#define DEGREES_TO_RADIANS 3.14159/180.0

#define NULL 0

static GLfloat t = 0.0;
GLfloat x1[9][2]={{0,35},{-25,20},{-25,-25},{-10,-25},{-10,-10},{10,-10},{10,-25},{25,-25},{25,20}},
	x2[9][2]={{0,30},{-25,30},{-25,10},{-8,10},{-8,-20},{8,-20},{8,10},{25,10},{25,30}};
//GLfloat x1[9][2]={{-17.5, 32.5}, {0, 47.5}, {17.5, 32.5}, {17.5, 0}, {5, 0}, {5, 1}, {-5, 1}, {-5, 0}, {-17.5, 0}},
//	x2[9][2]={{-17.5, 37.5}, {0, 37.5}, {17.5, 37.5}, {17.5, 25}, {7.5, 25}, {7.5, 0}, {-7.5, 0}, {-7.5, 25}, {-17.5, 25}};

int doubleb, key=1;

void my_shape(void)
{
	int i;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
	   for(i=0; i<9; ++i)
		  glVertex2f((1-t)*x1[i][0]+t*x2[i][0],(1-t)*x1[i][1]+t*x2[i][1]);
	glEnd();
}


void displayd(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	
	my_shape();
    
    glutSwapBuffers ();
}

void tranDisplay(void)
{
    if(key) 
		if(t<1.0)
			t = t + 0.005;
		else key = 0;
	else 
		if(t>0.0)
			t = t - 0.005;
		else key = 1;
	
	glutSetWindow(doubleb);
    glutPostRedisplay();
}

void myinit()
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glColor3f (1.0, 1.0, 1.0);
    glShadeModel (GL_FLAT);
}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  glutIdleFunc(tranDisplay);
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)   glutIdleFunc(NULL);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) 
		glOrtho (-50.0, 50.0, -50.0*(GLfloat)h/(GLfloat)w, 
		50.0*(GLfloat)h/(GLfloat)w, -1.0, 1.0);
    else 
		glOrtho (-50.0*(GLfloat)w/(GLfloat)h, 
		50.0*(GLfloat)w/(GLfloat)h, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
	
}

/*  Main Loop
*  Open window with initial window size, title bar, 
*  RGBA display mode, and handle input events.
*/
int main(int argc, char** argv)
{
	
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    
	glutInitWindowPosition(500,0);
	doubleb=glutCreateWindow("double buffered");
    myinit();
	glutDisplayFunc(displayd);
    glutReshapeFunc (myReshape);
    glutIdleFunc (tranDisplay);
    glutMouseFunc (mouse);
	
	
	glutMainLoop();
	return(0);	
}

