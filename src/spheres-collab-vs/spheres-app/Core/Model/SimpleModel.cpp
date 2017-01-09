#include "SimpleModel.h"

Core::Model::SimpleModel::SimpleModel(std::vector<GLfloat> vertices, const GLchar* vertexPath, const GLchar* fragmentPath)
	: ModelBase()
{
	std::cout << "SimpleModel::()" << std::endl;
	// build and compile our shaders
	this->shader.Load(vertexPath, fragmentPath);

	// create buffers
	glGenBuffers(1, &this->VBO); // generate a single buffer object
	glGenVertexArrays(1, &this->VAO); // generate a single vertex array object

	//=== bind buffers
	glBindVertexArray(this->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO); // vertex buffer uses array buffer type
		//=== load data
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
		//=== tell VAO how to read buffer
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
	//=== unbind
	glBindVertexArray(0);
}

void Core::Model::SimpleModel::Render()
{
	std::cout << "SimpleModel::Render()" << std::endl;
	this->shader.Use();
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}