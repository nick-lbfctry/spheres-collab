#pragma once
#include <vector>
#include <memory>
#include "Model\ModelBase.h"

namespace Core
{
	class GameState
	{
	public:
		GameState();
		~GameState();
		void Init();
		void Render();
		//void AddModel(std::unique_ptr<Model::ModelBase> model);
	private:
		std::vector<std::unique_ptr<Model::ModelBase>> m_models;
	};
}