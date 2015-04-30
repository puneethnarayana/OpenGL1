#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif


void init(void)
{
	// Set display-window color to white.
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// Set projection parameters.
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);
	// Set line segment color to green.
	glColor3f(0.0, 0.4, 0.2);

	glBegin(GL_LINES);
	// Specify line-segment geometry. 

	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();

	//lBegin(GL_POLYGON);
	// Process all OpenGL routines as quickly as possible.
	glFlush();
}

void Rect(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(-0.75f, 0.75f, 0.75f, -0.75f);
	// glutSwapBuffers();

	glEnd();

	//lBegin(GL_POLYGON);
	// Process all OpenGL routines as quickly as possible.
	glFlush();
}

void main(int argc, char** argv)
{
	// Initialize GLUT.
	glutInit(&argc, argv);

	// Set display mode.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	// Set top-left display-window position.
	glutInitWindowPosition(50, 100);
	// Set display-window width and height.
	glutInitWindowSize(800, 600);
	// Create display window.

	glutCreateWindow("Graphics Line");

	// Execute initialization procedure.
	init();

	// Send graphics to display window.
	glutDisplayFunc(lineSegment);
	// glutDisplayFunc(Rect);


	// Display everything and wait.
	glutMainLoop();
}

