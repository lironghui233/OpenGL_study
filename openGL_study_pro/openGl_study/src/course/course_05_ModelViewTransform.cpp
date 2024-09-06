/*
	Describe: ModelView Transform
	Author: Leoh
	Data: 2024/9/5
*/

#include <glut.h>
#include <stdlib.h>

static int year = 0, day = 0;

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	glPushMatrix();
	glutWireSphere(1.0, 20, 16);		// draw sun
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8);		// draw smaller planet
	glPopMatrix();
	glutSwapBuffers();

}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();											// set the current matrix to the identity matrix
	gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		day = (day + 10) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);	// init GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_SINGLE);	// set show mode
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("模型视图变换示例");
	Init();
	glutDisplayFunc(&myDisplay);
	glutReshapeFunc(&Reshape);
	glutKeyboardFunc(&Keyboard);
	glutMainLoop();	// message loop
	return 0;
}