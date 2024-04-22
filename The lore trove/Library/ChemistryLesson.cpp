#include "pch.h"
#include "framework.h"
#include "ChemistryLesson.h"

Chemistry* Chemistry::instance = nullptr;
Button chemistryButton;

void Chemistry::LoadTextures() {
	electrolysisBefore = LoadTexture("../assets/electrolysisBefore.png");
	electrolysisAfter = LoadTexture("../assets/electrolysisAfter.png");

	litmusLemon1 = LoadTexture("../assets/litmusLemon1.png");
	litmusLemon2 = LoadTexture("../assets/litmusLemon2.png");
	litmusLemon3 = LoadTexture("../assets/litmusLemon3.png");

	litmusNaOH1 = LoadTexture("../assets/litmusNaOH1.png");
	litmusNaOH2 = LoadTexture("../assets/litmusNaOH2.png");
	litmusNaOH3 = LoadTexture("../assets/litmusNaOH.png");
}

void Chemistry::SwitchScenes(std::string chemistryTheme) {
	if (chemistryTheme == "Electrolysis") {

		
		if (currentScene == 3) {
			DrawTextEx(Renderer::GetInstance()->font, "Hello, we are The Lore Trove and this is our team:", { 150, 180 }, 80, 5, BLACK);
		}
		else {
			if (chemistryButton.IsClicked({ 0,0,1980,1080 })) {
				currentScene++;
			}
		}
		switch (currentScene) {

		case 1:
			DrawTexture(electrolysisBefore, 0, 0, WHITE);
			
			break;
		case 2:
			DrawTexture(electrolysisAfter, 0, 0, WHITE);
		}
	}
	else if (chemistryTheme == "Litmus") {

		if (chemistryButton.IsClicked({ 0,0,1980,1080 })) {
			currentScene++;
		}

		switch (currentScene) {

			if (chemistryButton.IsClicked({ 0,0,1980,1080 })) {
				currentScene++;
			}

		case 1:
			DrawTexture(litmusLemon1, 0, 0, WHITE);
			break;

		case 2:
			DrawTexture(litmusLemon2, 0, 0, WHITE);
			break;

		case 3:
			DrawTexture(litmusLemon3, 0, 0, WHITE);
			break;

		case 4:
			DrawTexture(litmusNaOH1, 0, 0, WHITE);
			break;

		case 5:
			DrawTexture(litmusNaOH2, 0, 0, WHITE);
			break;

		case 6:
			DrawTexture(litmusNaOH3, 0, 0, WHITE);

		}

	}
}

void Chemistry::PickChemistryLesson() {
	currentScene = 1;
	Rectangle ElecButton = { 255, 400, 350, 600 };
	Rectangle LatiButton = { 1200, 400, 350, 600 };

	DrawTexture(Renderer::GetInstance()->Renderer::chooseChemistry, chemistryButton.chooseChemistryLessonIcons.x + 50, chemistryButton.chooseChemistryLessonIcons.y, WHITE);

	if (chemistryButton.IsClicked(ElecButton)) {
		lessonChemistry = "Electrolysis";
		activeChemistryLesson = true;
	}

	if (chemistryButton.IsClicked(LatiButton)) {
		lessonChemistry = "Litmus";
		activeChemistryLesson = true;
	}
}

void Chemistry::StartChemistryLesson() {
	SwitchScenes(lessonChemistry);
}