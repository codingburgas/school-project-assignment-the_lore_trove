#include "pch.h"
#include "framework.h"

#include "Manager.h"

Manager* Manager::instance = nullptr;


void Manager::Initizalize() {

	//Initialize window
	InitWindow(screenWidth, screenHeight, "game");
	SetTargetFPS(60);
	Start();
}

void Manager::Start() {

	// Get instance for renderer, chemistry and math
	renderer = Renderer::GetInstance();
	chemistry = Chemistry::GetInstance();
	math = Math::GetInstance();

	renderer->LoadTextures();
	chemistry->LoadTextures();
	math->LoadTextures();
}

void Manager::Update() {
	// Call Update function
	renderer->Update();
}
bool Manager::ShouldWindowClose() {

	return WindowShouldClose() || shouldWindowClose;
}

void Manager::Close() {

	shouldWindowClose = true;
	// Unload textures
	renderer->UnloadTextures();
}
