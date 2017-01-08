#pragma once
#include <gl/glew.h>
#include <gl/freeglut.h>
#include "../../Managers/ShaderManager/ShaderManager.h"

namespace Core
{
	namespace Primitive
	{
		class Triangle
		{
		public:
			Triangle();
			~Triangle();
			void Init();
			void Render();

		private:
			ShaderManager shader;
			GLuint VBO, VAO;
		};
	}
}
