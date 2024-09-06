/*
	Describe: Draw a rectangle, a triangle, and three points in the center of a black window
	Author: Leoh
	Data: 2024/9/5
*/
 
 
#include <glut.h>


void myDisplay(void)
{
	glClearColor(0.0, 0.0, 0.01, 0.0); //color to black
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	glVertex2f(0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);	glVertex2f(0.8f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);	glVertex2f(-0.8f, -0.5f);
	glEnd();

	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);	glVertex2f(-0.4f, -0.4f);
	glColor3f(0.0f, 1.0f, 0.0f);	glVertex2f(0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);	glVertex2f(0.4f, 0.4f);
	glEnd();

	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);	// init GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// set show mode
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World!");
	glutDisplayFunc(&myDisplay);
	glutMainLoop();	// message loop
	return 0;
}