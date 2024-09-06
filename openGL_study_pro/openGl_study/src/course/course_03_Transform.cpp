/*
	Describe: transofrom with matrix
	Author: Leoh
	Data: 2024/9/5
*/

#include <glut.h>

void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0);	// set view display range of(x:-5.0, 5.0, y:-5.0, 5.0)
	glMatrixMode(GL_MODELVIEW);
}

void drawSquare(void)
{
	glBegin(GL_POLYGON);			// vertex specification needs to follow the counterclockwise direction
	glVertex2i(-1.0f, -1.0f);		// lower left point
	glVertex2i(1.0f, -1.0f);		// lower right point
	glVertex2i(1.0f, 1.0f);			// upper right point
	glVertex2i(-1.0f, 1.0f);		// upper left point
	glEnd();
}

void myDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();				// set the current matrix to the identity matrix

	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	glScalef(3.0, 0.5, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	drawSquare();					// this shape is a red rectangle
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-3.0, 0.0, 0.0);

	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	drawSquare();					// this shape is top diamond
	glPopMatrix();

	glTranslatef(3.0, 0.0, 0.0);

	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.7, 0.0);
	drawSquare();					// this shape is left diamond
	glPopMatrix();

	glTranslatef(3.0, 0.0, 0.0);

	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.4, 0.0);
	drawSquare();					// this shape is right diamond
	glPopMatrix();

	glPopMatrix();

	glTranslatef(0.0, -3.0, 0.0);
	glScalef(4.0, 1.5, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	drawSquare();					// this shape is bottom blue rectangle
	
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);	// init GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// set show mode
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("几何变换示例");
	Init();
	glutDisplayFunc(&myDraw);
	glutMainLoop();	// message loop
	return 0;
}