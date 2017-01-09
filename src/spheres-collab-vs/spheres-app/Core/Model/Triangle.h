#pragma once
#include <gl/glew.h>
#include <gl/freeglut.h>
#include "ModelBase.h"
#include "../../Managers/ShaderManager/ShaderManager.h"

namespace Core
{
	namespace Model
	{
		class Triangle : public ModelBase
		{
		public:
			Triangle();
			~Triangle();
			void Init();
			void Render() override;

		private:
			ShaderManager shader;
			GLuint VBO, VAO;
		};
	}
}
