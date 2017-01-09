#include "GameState.h"
#include "Display\InitWindow.h"
#include "Model\Triangle.h"
#include "Model\SimpleModel.h"
#include <iostream>

Core::GameState::GameState()
{

}

Core::GameState::~GameState()
{

}

void Core::GameState::Init()
{
	Core::Display::InitWindow("OpenGL Testing App", 480, 480);

	//  Set OpenGL program initial state.
	//  Set the frame buffer clear color to black. 
	glClearColor(0.0, 0.0, 0.0, 0.0);

	std::cout << "GameState::Init()" << std::endl;
	auto triangle1 = std::unique_ptr<Core::Model::Triangle>(new Core::Model::Triangle);
	auto triangle2 = std::unique_ptr<Core::Model::SimpleModel>(new Core::Model::SimpleModel({
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
		}, "Shaders\\SimpleShader.vert", "Shaders\\SimpleShader.frag"));

	this->m_models.push_back(std::move(triangle1));
	this->m_models.push_back(std::move(triangle2));
}

void Core::GameState::Render()
{
	std::cout << "GameState::Render()" << std::endl;
	// http://stackoverflow.com/questions/24125669/abstract-classes-in-std-containers
	for (auto it(m_models.begin()), ite(m_models.end()); it != ite; ++it)
	{
		(*it)->Render();
	}
}