// Include section
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#define _USE_MATH_DEFINES 
#include<cmath>

// Global Variable Section
// List all of your global variables, stuctures and other definition here
// Window display size
GLsizei winWidth = 800, winHeight = 600;

// Initialize method
void init(void)
{
	// Get and display your OpenGL version
	const GLubyte *Vstr;
	Vstr = glGetString(GL_VERSION);
	fprintf(stderr, "Your OpenGL version is %s\n", Vstr);

	// White color window
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Projection on World Coordinates 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight / 2, (GLdouble)winHeight / 2);

}

// Generate the Graphics
void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);
	// Set  graphic objects color to Red or change for your choice 
	glColor3f(0.0, 0.0, 1.0);
	// Your graphics code here  

	/*
	GLuint regHex;
	GLdouble theta;
	GLdouble x, y, k;

	// Sets up a hexagon starting at 10,10 with a size of "60"
	regHex = glGenLists(1);  //  Get an identifier for the display list.
	glNewList(regHex, GL_COMPILE);
	glBegin(GL_POLYGON);

	for (k = 0; k < 6; k++)
	{
	// M_PI is C++ Constant for PI
	theta = 2*M_PI * k / 6.0;
	x = 10 + 60 * cos(theta);
	y = 10 + 60 * sin(theta);
	//glVertex2i(x, y);
	glVertex2d(x,y);}

	glEnd();
	glEndList();

	// Must call this to display the Hex graphic
	glCallList(regHex);
	*/

	glBegin(GL_TRIANGLES);
	// first tri
	glVertex2d(0.1, 0.1);
	glVertex2d(1, 1);
	glVertex2d(2, 3);
	// second tri
	glVertex2d(-0.1, 0.1);
	glVertex2d(-1, 1);
	glVertex2d(-2, 3);
	// third tri
	glVertex2d(0, 0.1);
	glVertex2d(0.15, 1);
	glVertex2d(-0.15, 1);

	glEnd();
	// Execute OpenGL functions
	glFlush();
}


// Windows redraw function
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight / 2, (GLdouble)winHeight / 2);
	glClear(GL_COLOR_BUFFER_BIT);
}

// Main function
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set initial Window position
	glutInitWindowPosition(100, 100);
	// Set Window Size
	glutInitWindowSize(winWidth, winHeight);
	// Set Window Title
	glutCreateWindow("Graphics SunRays");
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
}