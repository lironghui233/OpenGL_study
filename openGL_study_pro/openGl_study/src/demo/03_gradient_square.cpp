/*
	Describe: draw a gradient color square
	Author: Leoh
	Data: 2024/6/5
*/

/* ������Ӧ�Ŀ� */
#include <iostream>
using namespace std;
#define GLEW_STATIC	
#include"GL/glew.h"	
#include"GLFW/glfw3.h""
#include"Shader.h"

/* ��д������λ�� */
GLfloat vertices_1[] =
{
	//position					
	0.5f, 0.5f, 0.0f,			// top right		0
	0.5f, -0.5f, 0.0f,			// bottom right		1
	-0.5f, -0.5f, 0.0f,			// bottom left		2
	-0.5f, 0.5f, 0.0f,			// top left			3
};

/* �ĸ������������Ϣ������ */
GLuint indices_1[] =
{
	0, 1, 3,		// ���Ϊ 0��1��3 �Ķ�����ϳ�һ��������
	1, 2, 3			// ���Ϊ 1��2��3 �Ķ�����ϳ�һ��������
};

const GLint WIDTH = 600, HEIGHT = 600;		// �����δ���

int main()
{
	glfwInit();
	GLFWwindow* window_1 = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL Triangle test", nullptr, nullptr);
	int screenWidth_1, screenHeight_1;
	glfwGetFramebufferSize(window_1, &screenWidth_1, &screenHeight_1);
	glfwMakeContextCurrent(window_1);
	glewInit();

	/* �������Լ����õ���ɫ���ı������� */
	Shader ourShader = Shader("shaders/shader_v_2.txt", "shaders/shader_f_2.txt");		// ���·��

	/* ���ö��㻺�����(VBO) + ���ö����������(VAO)  */
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);

	/* �������Ӷ������� */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);	// ͨ�� 0 ��

	/* ���������������	*/
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_1), indices_1, GL_STATIC_DRAW);

	// draw loop ��ͼѭ��
	while (!glfwWindowShouldClose(window_1))
	{
		// �ӿ� + ʱ�� 
		glViewport(0, 0, screenWidth_1, screenHeight_1);
		glfwPollEvents();

		// ��Ⱦ + �����ɫ����
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*  ����ͼ�� */
		ourShader.Use();
		float time = glfwGetTime();						// ��ȡʱ��
		float redValue = sin(time) / 2.0f + 0.5f;		// ��ɫ��ֵ���㣬��Χ[0,1]
		float greenValue = 1 - redValue;				// ��ɫ��ֵ���㣬��Χ[0.1]�������� ��redValue + greenValue = 1��
		int vertexColorLocation = glGetUniformLocation(ourShader.Program, "time");
		glUniform4f(vertexColorLocation, redValue, greenValue, 0.0f, 1.0f);

		glBindVertexArray(VAO);									// �� VAO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);				// �� EBO
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);	// ������������ �ӵ�0�����㿪ʼ һ����6��
		glBindVertexArray(0);									// ��� VAO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);				// ��� EBO

		// ��������
		glfwSwapBuffers(window_1);
	}

	glDeleteVertexArrays(1, &VAO);	// �ͷ���Դ
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();				// ����
	return 0;
}
