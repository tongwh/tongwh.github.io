/*
 *  simple.c
 *  This program draws a white rectangle on a black background.
 */


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>         /* glut.h includes gl.h and glu.h*/
#endif

void display(void)

{
    // render scenes
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2d(-0.5, -0.5);
        glVertex2d(-0.5, 0.5);
        glVertex2d(0.5, 0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
    glFlush();
}


void init()
{
    // set the background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// set up standard orthogonal view with clipping 
    // box as cube of side 2 centered at origin
    //This is default view and these statement could be removed
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{

    // Initialize mode and open a window in upper left corner of screen
    // Window title is name of program (arg[0])
 	glutInit(&argc,argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0); 
	glutCreateWindow("simple"); 
	glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
	init();
	glutMainLoop();

}
