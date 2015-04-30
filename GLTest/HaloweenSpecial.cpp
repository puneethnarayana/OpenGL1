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

// Generate the Graphics
void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);

	// Set  graphic objects color to Red or change for your choice
	glColor3f(0.0, 1.0, 0.0);

	//Empty bitmap 
	GLubyte bitShape[72] = {};

	glColor3f(0.0, 0.0, 1.0);
	//Unique Bitmap 1 created. General block structure used to create Clint Eastwood
	GLubyte bitShape3[72] = { 0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF, };

	glColor3f(1.0, 0.0, 0.0);
	//The Unique Bitmap 2 created: Eyes, Mouth
	GLubyte bitShape4[72] = { 0xFF, 0x7F, 0xFF,
		0xFF, 0x7F, 0xFF,
		0xFF, 0x7F, 0xFF,
		0xFF, 0x7F, 0xFF,
		0x00, 0x7F, 0x00,
		0xFF, 0x00, 0xFF,
		0xFF, 0x00, 0xFF,
		0x00, 0x00, 0x00,
		0xFF, 0x00, 0xFF,
		0xFF, 0x00, 0xFF,
		0x00, 0x00, 0x00,
		0xFF, 0x00, 0xFF,
		0xFF, 0x00, 0xFF,
		0x00, 0x00, 0x00,
		0xFF, 0x00, 0xFF,
		0xFF, 0x00, 0xFF,
		0x00, 0x00, 0x00,
		0xFF, 0x00, 0xFF,
		0xFF, 0x63, 0xFF,
		0x00, 0x63, 0x00,
		0xFF, 0x63, 0xFF,
		0xFF, 0x63, 0xFF,
		0x00, 0x63, 0x00,
		0xFF, 0x63, 0xFF, };

	// Needed for reading from memory. 1 indicates byte alignment
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Center the bitmap image
	glRasterPos2i(0, 0);

	/*--------------------------RECTANGLES--------------------------------*/
	//3rd Quadrant the Ugly Rectangle
	float vertex3[] = { -1.0f, -0.67f };
	float vertex4[] = { 0, 0 };
	glColor3f(0.6, 0.0, 1.0);
	glRectf(-1.0f, -0.67f, 0, 0);

	//2nd Quadrant, the Bad Rectangle
	double vertex1[] = { 0, 0 };
	double vertex2[] = { -100, 100 };
	glColor3f(0.4, 0.4, 0.4);
	glRectdv(vertex1, vertex2);

	//Yellow Rectangle, 2st Quadrant
	double vertex5[] = { 0, 0 };
	double vertex6[] = { 100, 100 };
	glColor3f(1.4, 4.4, 0.4);
	glRectdv(vertex5, vertex6);

	//The Ground 
	glColor3f(0.85, 0.64, 0.52);
	glRectf(-1.0f, -0.67f, 1.0f, -1.0f);


	// Using the Bitmaps created

	glBitmap(24.0, 24.0, 0.0, 0.0, 20, 120.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -60.0, 0.0, bitShape4);
	glBitmap(24.0, 24.0, 0.0, 0.0, 10.0, -120.0, bitShape4);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -25.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -25.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -25.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 150.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -25.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -25.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 100.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -100.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 60.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, -180.0, -40.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 0.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 35.0, -100.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);

	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, -20.0, bitShape3);
	glBitmap(24.0, 24.0, 0.0, 0.0, 60.0, -80.0, bitShape3);

	/*----------------POLYGONS: Traingles, Quads-------------------*/

	//Machete 1 - Traingle
	glColor3f(0.9, 0.55, 0.12);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2f, -0.45f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.6f, -0.2f, 0.0f);
	glEnd();

	//Machete 2 - Quadilateral
	glColor3f(0.4, 0.2, 0.18);
	glBegin(GL_QUADS);
	glVertex3f(-0.20f, -0.45f, 0.0f);
	glVertex3f(-0.2f, -0.4f, 0.0f);
	glVertex3f(-0.30f, 0.15f, 0.0f);
	glVertex3f(-0.40f, 0.05f, 0.0f);
	glEnd();

	//The Moustache
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-0.30f, 0.23f, 0.0f);
	glVertex3f(-0.30f, 0.35f, 0.0f);
	glVertex3f(0.30f, 0.23f, 0.0f);
	glVertex3f(0.30f, 0.35f, 0.0f);
	glEnd();

	//The Cactus 1
	glColor3f(0.08, 0.56, 0.002);
	glBegin(GL_QUADS);
	glVertex3f(-0.60f, -0.67f, 0.0f);
	glVertex3f(-0.50f, -0.67f, 0.0f);
	glVertex3f(-0.60f, -0.23f, 0.0f);
	glVertex3f(-0.50f, -0.285f, 0.0f);
	glEnd();

	//The Cactus 2
	glColor3f(0.08, 0.56, 0.002);
	glBegin(GL_QUADS);
	glVertex3f(0.83f, -0.67f, 0.0f);
	glVertex3f(0.96f, -0.67f, 0.0f);
	glVertex3f(0.93, 0.43f, 0.0f);
	glVertex3f(0.85f, 0.485f, 0.0f);
	glEnd();

	//The Cactus 3
	glColor3f(0.08, 0.56, 0.002);
	glBegin(GL_QUADS);
	glVertex3f(0.33f, -0.67f, 0.0f);
	glVertex3f(0.46f, -0.67f, 0.0f);
	glVertex3f(0.33, -0.43f, 0.0f);
	glVertex3f(0.45f, -0.485f, 0.0f);
	glEnd();

	/*-----------------------------TEXTS------------------------------------*/

	//"Happy Halloween" Message
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'P');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'y');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'W');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');

	glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 300.0, bitShape);
	// glBitmap(24.0, 24.0, 0.0, 0.0, 30.0, 80.0, bitShape3);

	//"The Good" Text
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'G');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'o');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'D');

	//"The Bad" Text
	glBitmap(24.0, 24.0, 0.0, 0.0, -660.0, 0.0, bitShape);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'a');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');

	// "The Ugly" Message
	glBitmap(24.0, 24.0, 0.0, 0.0, -100.0, -200.0, bitShape);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'g');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'y');

	glBitmap(24.0, 24.0, 0.0, 0.0, 230.0, 240.0, bitShape);
	glBitmap(24.0, 24.0, 0.0, 0.0, -80.0, -350.0, bitShape4);

	//The "2014" Text
	glBitmap(24.0, 24.0, 0.0, 0.0, 20.0, 20.0, bitShape);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');

	/*--------------THE LINES-------------------------*/
	glBegin(GL_LINES);

	//3rd Quadrant
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.0f, -0.67f);
	glVertex2f(-1.0f, -1.0f);

	//4th Quadrant
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.0f, -0.67f);
	glVertex2f(1.0f, -1.0f);

	//Ground Line
	glColor3f(0.4256, 0.207, 0.101);
	glVertex2f(-1.0f, -0.67f);
	glVertex2f(1.0f, -0.67f);

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
	glutInitWindowPosition(1000, 100);
	// Set Window Size
	glutInitWindowSize(winWidth, winHeight);
	// Set Window Title

	glutCreateWindow("Halloween Special");
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
}