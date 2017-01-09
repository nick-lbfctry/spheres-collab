#pragma once

namespace Core
{
	namespace Model
	{
		class ModelBase
		{
		public:
			ModelBase();
			virtual void Render() = 0;
		};
	}
}