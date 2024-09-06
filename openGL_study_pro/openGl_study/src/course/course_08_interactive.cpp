/*
	Describe: OpenGL interactive
	Author: Leoh
	Data: 2024/9/5
*/

#include <glut.h>
#include <stdlib.h>

GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat size = 50.0;
GLsizei wh = 500, ww = 500;

void drawSquare(GLint x, GLint y)
{
	y = wh - y;
	glBegin(GL_POLYGON);
	glVertex3f(x + size, y + size, 0);
	glVertex3f(x - size, y + size, 0);
	glVertex3f(x - size, y - size, 0);
	glVertex3f(x + size, y - size, 0);
	glEnd();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawSquare(x, y);
	glutSwapBuffers();
	glutPostRedisplay();
}

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	ww = w;
	wh = h;
}

void myMouse(GLint button, GLint state, GLint wx, GLint wy)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x = wx;
		y = wy;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);	// init GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);	// set show mode
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL½»»¥");
	Init();
	glutDisplayFunc(&myDisplay);
	glutReshapeFunc(&Reshape);
	glutMouseFunc(&myMouse);
	glutMainLoop();	// message loop
	return 0;
}