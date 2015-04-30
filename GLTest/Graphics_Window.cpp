// Include section
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>


// Global Variable Section
// List global variables,stuctures and other definition here
// Window display size
// Modify winWidth/winHeight to experiment with World coordinates
GLsizei winWidth = 300, winHeight = 100;

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
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight / 2,
		(GLdouble)winHeight / 2);

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
	glColor3f(1.0, 0.0, 0.0);
	// Your graphics code here  
	// Modify the x,y positions below to experiment
	glRasterPos2i(0, 0);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'G');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'P');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'H');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'C');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'S');

	// Execute OpenGL functions
	glFlush();
}
// Windows redraw function
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight / 2,
		(GLdouble)winHeight / 2);



	glClear(GL_COLOR_BUFFER_BIT);
}
// Main function
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set initial Window position
	glutInitWindowPosition(300, 300);
	// Set Window Size
	glutInitWindowSize(winWidth, winHeight);
	// Set Window Title
	glutCreateWindow("Graphics Window (0,0)");
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
}


