#include "pch.h"
#include "framework.h"
#include "Renderer.h"
#include "MathLesson.h"
#include "ChemistryLesson.h"
#include "Manager.h"
#include "Biology.h"


Renderer* Renderer::instance = nullptr;
Button button;

void Renderer::LoadTextures() { // Load all the textures from files

	menuBackground = LoadTexture("../assets/mainMenuBackground.png");
	subjectChoosingBackground = LoadTexture("../assets/chooseSubjectBackground.png");
	backButton = LoadTexture("../assets/arrow.png");
	chooseLesson = LoadTexture("../assets/chooseLessonBoard.png");
	font = LoadFont("../assets/font/Itim-Regular.ttf");
	
	biologyTextures.push_back(LoadTexture("../assets/chooseLessonBoard.png"));
	biologyTextures.push_back(LoadTexture("../assets/biologyLessonIcon1.png"));
	biologyTextures.push_back(LoadTexture("../assets/biologyLessonIcon2.png"));
	biologyTextures.push_back(LoadTexture("../assets/cell.png"));
	biologyTextures.push_back(LoadTexture("../assets/eucell.png"));
	biologyTextures.push_back(LoadTexture("../assets/eukaryoticCell.png"));
	biologyTextures.push_back(LoadTexture("../assets/prokaryote.png"));

	chooseChemistry = LoadTexture("../assets/chemistryLessonIcons.png");
}

void Renderer::UnloadTextures()
{
	for (Texture2D& texture : biologyTextures) {
		UnloadTexture(texture); // Unload textures
	}
}

int Renderer::CenterPosition(int offset, char axis, int offsetModifier) {
	if (axis == 'X') return (GetScreenWidth() / 2) - (offset / 2) - offsetModifier;
	return ((GetScreenHeight() / 2) - (offset / 2)) - offsetModifier;
} // Calculate center position based on screen size and object size

void Renderer::Update() {

	BeginDrawing();
	if (menu) {
		if (main) {  // Render main menu options
			DrawTexture(menuBackground, 0, 0, WHITE);
			DrawTextEx(font, "The lore trove", { 30, 150 }, 90,5, WHITE);
			DrawTextEx(font, "Play", { button.mainMenuButtons[0].x + 60, button.mainMenuButtons[0].y - 4 }, 70,5, WHITE);
			DrawTextEx(font, "Info", { button.mainMenuButtons[1].x + 60, button.mainMenuButtons[1].y - 4 }, 70, 5, WHITE);
			DrawTextEx(font, "Credits", { button.mainMenuButtons[2].x + 60, button.mainMenuButtons[2].y - 4 }, 70, 5, WHITE);
			DrawTextEx(font, "Quit", { button.mainMenuButtons[3].x + 60, button.mainMenuButtons[3].y - 4 }, 70, 5, WHITE);

			// Check for button clicks
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
			} // Close application
		}
		else if (info) {
			ClearBackground(BLACK);  // Render information screen content
			DrawRectangleRec({ 10,10,1900,1060 }, BEIGE);
			DrawTexture(backButton, button.back.x, button.back.y, WHITE);

			if (button.IsClicked(button.back)) {
				info = false;
				main = true;
			}
		}
		else if (credits) { // Shows the info page
			ClearBackground(BLACK);
			DrawRectangleRec({ 10,10,1900,1060 }, BEIGE);
			DrawTexture(backButton, button.back.x, button.back.y, WHITE);
			DrawTextEx(font, "Hello, we are The Lore Trove and this is our team:", { 150, 180 }, 80, 5, BLACK);
			DrawTextEx(font, "Nadezhda Ivanova - 10th grade - Scrum Trainer", { 400, 300 }, 50, 5, BLACK);
			DrawTextEx(font, "Antonia Taneva - 10th grade - Front-end Developer and Designer", { 250, 375 }, 50, 5, BLACK);
			DrawTextEx(font, "Valeria Chavdarova - 10th grade - Back-end Developer", { 300, 450 }, 50, 5, BLACK);
			DrawTextEx(font, "Ivan-Michail Ivanov  - 9th grade - Back-end Developer", { 320, 525 }, 50, 5, BLACK);
			DrawTextEx(font, "Pavlin Peev - 9th grade - Back-end Developer", { 420, 675 }, 50, 5, BLACK);
			DrawTextEx(font, "Nikolay Kulov - 9th grade - Back-end Developer", { 400, 600 }, 50, 5, BLACK);

			if (button.IsClicked(button.back)) {
				credits = false;
				main = true; // Makes to go back in the main menu
			}
		}

	}
	else {
		if (chooseSubject) { // Shows different options of different subject chosen
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
			if (subject == 0) { // Runs if subject == 0
				Biology::GetInstance()->setTextures(biologyTextures);
				DrawTexture(chooseLesson, 0, 0, WHITE);
				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					chooseSubject = true;
				}
				Biology::GetInstance()->LoadSlide();

			}
			else if (subject == 1) { // Runs if subject == 1
				DrawTexture(chooseLesson, 0, 0, WHITE);
				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					chooseSubject = true;
				}

				if (!Math::GetInstance()->activeLesson) {
					Math::GetInstance()->PickMathLesson();
				}
				else {
					Math::GetInstance()->StartMathLesson();
				}
			}
			else if (subject == 2) { // Runs if subject == 2
				DrawTexture(chooseLesson, 0, 0, WHITE);
				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					chooseSubject = true;
				}

				if (!Chemistry::GetInstance()->activeChemistryLesson) {
					Chemistry::GetInstance()->PickChemistryLesson();
				}
				else {
					Chemistry::GetInstance()->StartChemistryLesson();
				}
			}
		}
	}

	EndDrawing();

}