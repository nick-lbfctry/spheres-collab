#include "Triangle.h"

using namespace Core::Model;

Triangle::Triangle()
	: ModelBase()
{
	// build and compile our shaders
	shader.Load("Shaders\\basicShader.vert", "Shaders\\basicShader.frag");

	// vertex stuff
	GLfloat vertices[] = {
		// points			// colors
		-0.9f,-0.9f, 0.0f,	1.0f, 0.0f, 0.0f,
		0.1f,-0.9f, 0.0f,	0.0f, 1.0f, 0.0f,
		-0.4f, 0.1f, 0.0f,	0.0f, 0.0f, 1.0f
	};

	// buffers
	glGenBuffers(1, &VBO); // generate a single buffer object
	glGenVertexArrays(1, &VAO); // generate a single vertex array object

	//=== triangle
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // vertex buffer uses array buffer type
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy our vertices into the buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

Triangle::~Triangle()
{
	// properly deallocate buffers
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Triangle::Init()
{
	
}

void Triangle::Render()
{
	std::cout << "drawing triangle..." << std::endl;
	shader.Use();
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}