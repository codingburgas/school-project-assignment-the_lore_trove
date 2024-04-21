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

	renderer->LoadTextures();
}

void Manager::Update() {

	renderer->Update();
}
bool Manager::ShouldWindowClose() {

	return WindowShouldClose() || shouldWindowClose;
}

void Manager::Close() {

	shouldWindowClose = true;
}