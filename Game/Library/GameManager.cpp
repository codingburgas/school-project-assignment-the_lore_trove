#include "pch.h"
#include "framework.h"

#include "GameManager.h"

GameManager* GameManager::instance = nullptr;
Button button;
void GameManager::Initizalize() {
	InitWindow(screenWidth, screenHeight, "game");
	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawRectangleGradientH(0, 0, screenWidth, screenHeight, BLUE, PURPLE);
		DrawText("The lore trove", 30, 150, 70, WHITE);
		DrawText("Play", button.mainMenuButtons[0].x + 60, button.mainMenuButtons[0].y - 4, 70, WHITE);
		DrawText("Info", button.mainMenuButtons[1].x + 60, button.mainMenuButtons[1].y - 4, 70, WHITE);
		DrawText("Credits", button.mainMenuButtons[2].x + 60, button.mainMenuButtons[2].y - 4, 70, WHITE);
		DrawText("Exit", button.mainMenuButtons[3].x + 60, button.mainMenuButtons[3].y - 4, 70, WHITE);
		EndDrawing();
	}
	CloseWindow();
}