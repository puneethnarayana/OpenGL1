// Include section
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>

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

void otherCode()

{
	// Your other code here
}

// Generate the Graphics
void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);
	// Set  graphic objects color to Red or change for your choice
	//glColor3f(0.0, 0.0, 1.0);

	/*
	// Your graphics code here
	// Add First Rectangle (red)
	//Not Working
	glRecti(-20, -20, -15, 10);*/

	double vertex3[] = { 0, 0 };
	double vertex4[] = { -100, -100 };
	// Change color to green
	glColor3f(0.0, 0.0, 1.0);
	// Draw second Rectangle (green)
	glRectdv(vertex3, vertex4);

	// Define to Arrays to hold vertex points
	int vertex1[] = { 0, 0 };
	int vertex2[] = { 1, 1 };
	// Change color to green
	glColor3f(0.0, 1.0, 0.0);
	// Draw second Rectangle (green)
	glRectiv(vertex1, vertex2);

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
	glutCreateWindow("Graphics Rectangles");
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
}