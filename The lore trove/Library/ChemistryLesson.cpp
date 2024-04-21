#include "pch.h"
#include "framework.h"
#include "ChemistryLesson.h"

Chemistry* Chemistry::instance = nullptr;
Button chemistryButton;

void Chemistry::DetectClick() {

}

void Chemistry::SwitchScenes(std::string chemistryTheme) {
	if (chemistryTheme == "Electrolysis") {
		switch (currentScene) {
		case 1:
			DrawText("This is the first scene of electrolysis (Placeholder text, used for debugging)", 1000, 700, 40, BLACK);
		}
	}
	else if (chemistryTheme == "Litmus") {
		switch (currentScene) {
		case 1:
			DrawText("This is the first scene of latimus (Placeholder text, used for debugging)", 1000, 700, 40, BLACK);
		}
	}
}

void Chemistry::PickChemistryLesson() {
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