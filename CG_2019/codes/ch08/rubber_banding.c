/* This program illustrates the use of the glut library for
interfacing with a Window System */

/* The program opens a window, clears it to black,
then draws a box at the location of the mouse each time the
left button is clicked. The right button exits the program

The program also reacts correctly when the window is
moved or resized by clearing the new window to black*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/* globals */

GLsizei wh = 500, ww = 500; /* initial window size */
float xm, ym, xmm, ymm;
int first = 0;

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		xm = x;
		ym = wh-y;
		glColor3f(0.0, 0.0, 1.0);
		glLogicOp(GL_XOR);
		first = 0;
	}
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
		glRectf(xm, ym, xmm, ymm);
		glFlush();
		glColor3f(0.0, 1.0, 0.0);
		glLogicOp(GL_COPY);
		xmm = x;
		ymm = wh-y;
		glLogicOp(GL_COPY);
		glRectf(xm, ym, xmm, ymm);
		glFlush();
	}
}

void move(int x, int y)
{
	if(first == 1)
	{
		glRectf(xm, ym, xmm, ymm);
		glFlush();
	}
	xmm = x;
	ymm = wh-y;
	glRectf(xm, ym, xmm, ymm);
	glFlush();
	first = 1;
}

void myReshape(GLsizei w, GLsizei h)
{
	
	/* adjust clipping box */
	
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity(); 
   	glOrtho(0.0,(GLdouble)w, 0.0,(GLdouble)h, -1.0, 1.0);
	
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity(); 
	
	/* adjust viewport and clear */
	
	glViewport(0,0,w,h);
    glClearColor(1.0, 1.0, 1.0, 1.0);
   	glClear(GL_COLOR_BUFFER_BIT);
   	glFlush();
	
	/* set global size for use by drawing routine */
	
	ww = w;
   	wh = h; 
}

void myinit(void)
{
   	glViewport(0,0,ww,wh);
	
	/* Pick 2D clipping window to match size of screen window 
	This choice avoids having to scale object coordinates
	each time window is resized */
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity(); 
   	glOrtho(0.0,(GLdouble) ww , 0.0,(GLdouble) wh , -1.0, 1.0);
	
	/* set clear color to black and clear window */
   	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	
	/* callback routine for reshape event */
   	glutReshapeFunc(myReshape);
	
}


/* display callback required by GLUT 3.0 */
void display(void)
{}

int main(int argc, char** argv)
{
   	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("square");
   	myinit();
   	glutReshapeFunc(myReshape);
   	glutMouseFunc(mouse);
   	glutMotionFunc(move);
	glutDisplayFunc(display);
	
   	glutMainLoop();
}
