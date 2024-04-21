#include "pch.h"
#include "framework.h"

#include "Renderer.h"
#include "MathLesson.h"
#include "Manager.h"


Renderer* Renderer::instance = nullptr;
Button button;

void Renderer::LoadTextures() {
	menuBackground = LoadTexture("../assets/mainMenuBackground.png");
	subjectChoosingBackground = LoadTexture("../assets/chooseSubjectBackground.png");
	backButton = LoadTexture("../assets/arrow.png");
}

void Renderer::Update() {

	BeginDrawing();
		if (menu) {
			if (main) {
				DrawTexture(menuBackground, 0, 0, WHITE);
				DrawText("The lore trove", 30, 150, 70, WHITE);
				DrawText("Play", button.mainMenuButtons[0].x + 60, button.mainMenuButtons[0].y - 4, 70, WHITE);
				DrawText("Info", button.mainMenuButtons[1].x + 60, button.mainMenuButtons[1].y - 4, 70, WHITE);
				DrawText("Credits", button.mainMenuButtons[2].x + 60, button.mainMenuButtons[2].y - 4, 70, WHITE);
				DrawText("Exit", button.mainMenuButtons[3].x + 60, button.mainMenuButtons[3].y - 4, 70, WHITE);

				if (button.IsClicked(button.mainMenuButtons[0])) {
					menu = false;
					chooseSubject = true;
				}
				else if (button.IsClicked(button.mainMenuButtons[1])) {
					info = true;
					main = false;
				}
				else if (button.IsClicked(button.mainMenuButtons[2])) {
					credits = true;
					main = false;
				}
				else if (button.IsClicked(button.mainMenuButtons[3])) {
					Manager::GetInstance()->Close();
				}
			}
			else if (info) {
				ClearBackground(BLACK);
				DrawRectangleRec({ 10,10,1900,1060 }, BEIGE);
				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					info = false;
					main = true;
				}
			}
			else if (credits) {
				ClearBackground(BLACK);
				DrawRectangleRec({ 10,10,1900,1060 }, BEIGE);
				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					credits = false;
					main = true;
				}
			}
			
		}
		else {
			if (chooseSubject) {
				ClearBackground(WHITE);
				DrawTexture(subjectChoosingBackground, 0, 0, WHITE);
				if (button.IsClicked(button.subjects[0])) {
					subject = 0;
					chooseSubject = false;
				}
				else if (button.IsClicked(button.subjects[1])) {
					subject = 1;
					chooseSubject = false;
				}
				else if (button.IsClicked(button.subjects[2])) {
					subject = 2;
					chooseSubject = false;
				}
			}
			else {
				ClearBackground(WHITE);
				if (subject == 1) {
					if (!Math::GetInstance()->activeLesson) {
						Math::GetInstance()->PickMathLesson();
					}
					else {
						Math::GetInstance()->StartMathLesson();
					}
				}
			}
		}

	EndDrawing();
}