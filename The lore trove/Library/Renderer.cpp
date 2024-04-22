#include "pch.h"
#include "framework.h"
#include "Renderer.h"
#include "MathLesson.h"
#include "ChemistryLesson.h"
#include "Manager.h"
#include "Biology.h"


Renderer* Renderer::instance = nullptr;
Button button;

// Load all the textures from files
void Renderer::LoadTextures() { 

	menuBackground = LoadTexture("../assets/mainMenuBackground.png");
	subjectChoosingBackground = LoadTexture("../assets/chooseSubjectBackground.png");
	backButton = LoadTexture("../assets/arrow.png");
	chooseLesson = LoadTexture("../assets/chooseLessonBoard.png");
	ongoingLesson = LoadTexture("../assets/ongoingLessonBackground.png");
	font = LoadFont("../assets/font/Itim-Regular.ttf");

	ongoingLessonImage = LoadImage("../assets/ongoingLessonBackground.png");
	ongoingLessonBackgroundColor = GetImageColor(ongoingLessonImage, 300, 200);

	ongoingLessonBackgroundColor;

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

		// Unload textures
		UnloadTexture(texture); 
	}
}

// Calculate center position based on screen size and object size
int Renderer::CenterPosition(int offset, char axis, int offsetModifier) {
	if (axis == 'X') return (GetScreenWidth() / 2) - (offset / 2) - offsetModifier;
	return ((GetScreenHeight() / 2) - (offset / 2)) - offsetModifier;
} 

void Renderer::Update() {

	BeginDrawing();
	if (menu) {
		// Render main menu options
		if (main) {  
			DrawTexture(menuBackground, 0, 0, WHITE);
			DrawTextEx(font, "The lore trove", { 30, 150 }, 90, 5, WHITE);
			DrawTextEx(font, "Play", { button.mainMenuButtons[0].x + 60, button.mainMenuButtons[0].y - 4 }, 70, 5, WHITE);
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
				// Close application
				Manager::GetInstance()->Close();
			} 
		}
		else if (info) {
			// Render information screen content
			ClearBackground(BLACK);  
			DrawTexture(ongoingLesson, 0, 0, WHITE);
			DrawTexture(backButton, button.back.x, button.back.y, WHITE);
			DrawTextEx(font, "The Lore Trove", { 700, 150 }, 80, 5, BLACK);
			DrawTextEx(font, "Welcome to The_Lore_Trove, an interesting and", { 350, 300 }, 50, 5, BLACK);
			DrawTextEx(font, "interactive educational game designed to make", { 350, 375 }, 50, 5, BLACK);
			DrawTextEx(font, "learning Biology, Math, and Chemistry both enjoyable", { 350, 450 }, 50, 5, BLACK);
			DrawTextEx(font, "and informative. Dive into a virtual online school where ", { 350, 525 }, 50, 5, BLACK);
			DrawTextEx(font, "you can explore various topics in these subjects such as:", { 350, 600 }, 50, 5, BLACK);
			DrawTextEx(font, "Electrosys, Cell, Triangles and more! Through its to", { 350, 675 }, 50, 5, BLACK);
			DrawTextEx(font, "innovative  approach to education, the game aims ", { 350, 750 }, 50, 5, BLACK);
			DrawTextEx(font, "to motivate people of all ages to explore the wonders", { 350, 825 }, 50, 5, BLACK);
			DrawTextEx(font, "of science and mathematics in a fun and dynamic way!", { 350, 900 }, 50, 5, BLACK);
			if (button.IsClicked(button.back)) {
				info = false;
				main = true;
			} 
		}
		else if (credits) {
			// Shows the credits page
			ClearBackground(BLACK);
			DrawTexture(ongoingLesson, 0, 0, WHITE);
			DrawTexture(backButton, button.back.x, button.back.y, WHITE);
			DrawTextEx(font, "Hello, we are The Lore Trove and this is our team:", { 150, 180 }, 80, 5, BLACK);
			DrawTextEx(font, "Nadezhda Ivanova - 10th grade - Scrum Trainer", { 400, 300 }, 50, 5, BLACK);
			DrawTextEx(font, "Antonia Taneva - 10th grade - Front-end Developer and Designer", { 250, 375 }, 50, 5, BLACK);
			DrawTextEx(font, "Valeria Chavdarova - 10th grade - Back-end Developer", { 300, 450 }, 50, 5, BLACK);
			DrawTextEx(font, "Ivan-Michail Ivanov  - 9th grade - Back-end Developer", { 320, 525 }, 50, 5, BLACK);
			DrawTextEx(font, "Pavlin Peev - 9th grade - Quality Assurance", { 420, 675 }, 50, 5, BLACK);
			DrawTextEx(font, "Nikolay Kulov - 9th grade - Back-end Developer", { 400, 600 }, 50, 5, BLACK);

			// Makes to go back in the main menu
			if (button.IsClicked(button.back)) {
				credits = false;
				main = true; 
			}
		}

	}
	else {

		// Shows different options of different subject chosen
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
			// Runs if subject == 0
			if (subject == 0) { 
				Biology::GetInstance()->setTextures(biologyTextures);
				DrawTexture(chooseLesson, 0, 0, WHITE);
				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					chooseSubject = true;
				}
				Biology::GetInstance()->LoadSlide();

			}
			// Runs if subject == 1
			else if (subject == 1) { 
				DrawTexture(chooseLesson, 0, 0, WHITE);
				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					chooseSubject = true;
					Math::GetInstance()->activeLesson = false;
				}

				if (!Math::GetInstance()->activeLesson) {
					Math::GetInstance()->PickMathLesson();
				}
				else {
					DrawTexture(ongoingLesson, 0, 0, WHITE);
					DrawTexture(backButton, button.back.x, button.back.y, WHITE);
					Math::GetInstance()->StartMathLesson();
				}
			}
			// Runs if subject == 2
			else if (subject == 2) { 



				if (!Chemistry::GetInstance()->activeChemistryLesson) {
					DrawTexture(chooseLesson, 0, 0, WHITE);
					Chemistry::GetInstance()->PickChemistryLesson();
				}
				else {
					Chemistry::GetInstance()->StartChemistryLesson();
				}

				DrawTexture(backButton, button.back.x, button.back.y, WHITE);

				if (button.IsClicked(button.back)) {
					chooseSubject = true;
					Chemistry::GetInstance()->activeChemistryLesson = false;
				}

			}
		}
	}

	EndDrawing();

}