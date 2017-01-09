#pragma once
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <vector>
#include "ModelBase.h"
#include "../../Managers/ShaderManager/ShaderManager.h"

namespace Core
{
	namespace Model
	{
		class SimpleModel: public ModelBase
		{
		public:
			SimpleModel(std::vector<GLfloat> vertices, const GLchar* vertexPath, const GLchar* fragmentPath);
			void Render() override;
		private:
			ShaderManager shader;
			GLuint VBO, VAO;
		};
	}
}