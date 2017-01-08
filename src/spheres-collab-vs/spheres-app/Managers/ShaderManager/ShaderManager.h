#pragma once

#include <gl/glew.h>
#include <gl/freeglut.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShaderManager {
public:
	ShaderManager();
	void Load(const GLchar* vertexPath, const GLchar* fragmentPath);
	void Use();
private:
	GLuint Program;
};