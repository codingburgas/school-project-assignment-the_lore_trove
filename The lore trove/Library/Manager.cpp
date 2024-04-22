#include "pch.h"
#include "framework.h"

#include "Manager.h"

Manager* Manager::instance = nullptr;


void Manager::Initizalize() {

	InitWindow(screenWidth, screenHeight, "game");
	SetTargetFPS(60);
	Start();
}

void Manager::Start() {
	renderer = Renderer::GetInstance();
	chemistry = Chemistry::GetInstance();

	renderer->LoadTextures();
	chemistry->LoadTextures();
}

void Manager::Update() {

	renderer->Update();
}
bool Manager::ShouldWindowClose() {

	return WindowShouldClose() || shouldWindowClose;
}

void Manager::Close() {

	shouldWindowClose = true;
	renderer->UnloadTextures();
}
