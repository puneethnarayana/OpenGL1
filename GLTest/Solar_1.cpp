	// Include section
	#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#else
	#include <GL/glut.h>
	#endif
	#include <stdio.h>
#include <iostream>


GLsizei winWidth = 600, winHeight = 400;

// Used for Circle and Ellipse points
class screenPt
{
private:
	GLint x, y;

public:
	/*  Default Constructor: initializes coordinate position to (0, 0).  */
	screenPt()  {
		x = y = 0;
	}
	void setCoords(GLint xCoordValue, GLint yCoordValue)  {
		x = xCoordValue;
		y = yCoordValue;
	}

	GLint getx() const  {
		return x;
	}

	GLint gety() const  {
		return y;
	}
	void incrementx()  {
		x++;
	}
	void decrementy()  {
		y--;
	}
};


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

// Set the Pixels for the current x,y position
void setPixel(GLint xPos, GLint yPos)
{
	glBegin(GL_POINTS);
	glVertex2i(xPos, yPos);
	glEnd();
}


void helpCode(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Set  graphic objects color to Red or change for your choice
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2i(0, 0);
	//glBitmap(20.0, 20.0, 0.0, 0.0, -920.0, -405.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
	// Execute OpenGL functions
	glutSwapBuffers();

}


void circlePlotPoints(GLint xc, GLint yc, screenPt circPt)
{
	setPixel(xc + circPt.getx(), yc + circPt.gety());
	setPixel(xc - circPt.getx(), yc + circPt.gety());
	setPixel(xc + circPt.getx(), yc - circPt.gety());
	setPixel(xc - circPt.getx(), yc - circPt.gety());
	setPixel(xc + circPt.gety(), yc + circPt.getx());
	setPixel(xc - circPt.gety(), yc + circPt.getx());
	setPixel(xc + circPt.gety(), yc - circPt.getx());
	setPixel(xc - circPt.gety(), yc - circPt.getx());
}

void circleMidpoint(GLint xc, GLint yc, GLint radius)
{
	screenPt circPt;

	GLint p = 1 - radius;         // Initial value for midpoint parameter.

	circPt.setCoords(0, radius); //  Set coordinates for top point of circle.

	/*  Plot the initial point in each circle quadrant.  */
	circlePlotPoints(xc, yc, circPt);
	/*  Calculate next point and plot in each octant.  */
	while (circPt.getx() < circPt.gety()) {
		circPt.incrementx();
		if (p < 0)
			p += 2 * circPt.getx() + 1;
		else {
			circPt.decrementy();
			p += 2 * (circPt.getx() - circPt.gety()) + 1;
		}
		circlePlotPoints(xc, yc, circPt);
	}
}

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
	setPixel(xCenter + x, yCenter + y);
	setPixel(xCenter - x, yCenter + y);
	setPixel(xCenter + x, yCenter - y);
	setPixel(xCenter - x, yCenter - y);
}

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry)
{
	int Rx2 = Rx * Rx;
	int Ry2 = Ry * Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2 * y;

	/* Plot the initial point in each quadrant. */
	ellipsePlotPoints(xCenter, yCenter, x, y);

	/* Region 1 */
	p = ceil(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
	while (px < py) {
		x++;
		px += twoRy2;
		if (p < 0)
			p += Ry2 + px;
		else {
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}

	/* Region 2 */
	p = ceil(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
	while (y > 0) {
		y--;
		py -= twoRx2;
		if (p > 0)
			p += Rx2 - py;
		else {
			x++;
			px += twoRy2;
			p += Rx2 - py + px;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
}

void objectCode(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.4, 0.85, 0.97);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, 120.0, 80.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');

	glutSwapBuffers();
}
 
void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);
	// Ellipse
	GLint xc = 0, yc = 0, radius = 50;
	circleMidpoint(xc, yc, radius);
	glColor3f(1.0, 0.0, 1.0);
	ellipseMidpoint(xc, yc, 155, 50);
	glFlush();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set initial Window position
	glutInitWindowPosition(300, 300);
	// Set Window Size
	glutInitWindowSize(winWidth, winHeight);
	// Set Window Title
	glutCreateWindow("Graphics Solar System Stats");
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(reshape);
	glutMainLoop();
}

