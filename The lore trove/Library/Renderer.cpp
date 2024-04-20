#include "pch.h"
#include "framework.h"

#include "Renderer.h"
#include "MathLesson.h"
#include "Manager.h"


Renderer* Renderer::instance = nullptr;
Button button;

void Renderer::LoadTextures() {
	menuBackground = LoadTexture("../assets/mainMenuBackground.png");
}

void Renderer::Update() {

	BeginDrawing();
		if (menu) {
			
			DrawTexture(menuBackground, 0, 0, WHITE);
			DrawText("The lore trove", 30, 150, 70, WHITE);
			DrawText("Play", button.mainMenuButtons[0].x + 60, button.mainMenuButtons[0].y - 4, 70, WHITE);
			DrawText("Info", button.mainMenuButtons[1].x + 60, button.mainMenuButtons[1].y - 4, 70, WHITE);
			DrawText("Credits", button.mainMenuButtons[2].x + 60, button.mainMenuButtons[2].y - 4, 70, WHITE);
			DrawText("Exit", button.mainMenuButtons[3].x + 60, button.mainMenuButtons[3].y - 4, 70, WHITE);

			if (button.IsClicked(button.mainMenuButtons[0])) {
				menu = false;
				play = true;
			}
			else if (button.IsClicked(button.mainMenuButtons[3])) {
				Manager::GetInstance()->Close();
			}
		}
		else if (play) {
			ClearBackground(BLACK);
			Math::GetInstance()->StartMathLesson();
			//DrawRectangleGradientH(0, 0, screenWidth, screenHeight, BLUE, PURPLE);
			//DrawText("CARS GO VROOM VROOM", button.mainMenuButtons[2].x + 60, button.mainMenuButtons[2].y - 4, 70, WHITE);
		}


		

	EndDrawing();
}