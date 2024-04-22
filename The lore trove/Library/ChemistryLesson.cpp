#include "pch.h"
#include "framework.h"
#include "ChemistryLesson.h"

Chemistry* Chemistry::instance = nullptr;
Button chemistryButton;

//Load chemistry's sprites
void Chemistry::LoadTextures() {
	electrolysisBefore = LoadTexture("../assets/electrolysisBefore.png");
	electrolysisAfter = LoadTexture("../assets/electrolysisAfter.png");
	afterTime = LoadTexture("../assets/afterTime.png");

	infoBox = LoadTexture("../assets/chemistryInfoBox.png");

	litmusLemon1 = LoadTexture("../assets/litmusLemon1.png");
	litmusLemon2 = LoadTexture("../assets/litmusLemon2.png");
	litmusLemon3 = LoadTexture("../assets/litmusLemon3.png");

	endBackground = LoadTexture("../assets/ongoingLessonBackground.png");

	litmusNaOH1 = LoadTexture("../assets/litmusNaOH1.png");
	litmusNaOH2 = LoadTexture("../assets/litmusNaOH2.png");
	litmusNaOH3 = LoadTexture("../assets/litmusNaOH3.png");
}

//Make the chemistry scenes change
void Chemistry::SwitchScenes(std::string chemistryTheme) {
	if (chemistryTheme == "Electrolysis") {
		if (currentScene != 4) {
			if (chemistryButton.IsClicked({ 0,0,1980,1080 })) {
				currentScene++;
			}
		}

		//Change electrolysis' scenes
		switch (currentScene) {

		case 1:
			DrawTexture(electrolysisBefore, 0, 0, WHITE);
			DrawTexture(infoBox, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "In this stage of the electrolysis", { 65,700 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "we put two electrolytes in", { 65, 750 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "water", { 65, 800 }, 50, 2, BLACK);
			break;
		case 2:
			DrawTexture(afterTime, 0, 0, WHITE);
			break;

		case 3:
			DrawTexture(electrolysisAfter, 0, 0, WHITE);
			DrawTexture(infoBox, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "After a while, owing to the ", { 65,700 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "electric current helping to ", { 65, 750 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "cause an chemical reaction", { 65,800 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "(electrolysis), the anode", { 65, 850 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "oxidizes, while the cathode ", { 65,900 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "reduces ", { 65,950 }, 50, 2, BLACK);
			break;

		case 4:
			DrawTexture(endBackground, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "Lesson finished!", { 700,500 }, 80, 5, BLACK);

			//Return to the chemistry menu to choose an other lesson
			chemistryButton.DrawButton(chemistryButton.backToLessons);

			DrawTextEx(Renderer::GetInstance()->font, "Choose another lesson", { chemistryButton.backToLessons.x, chemistryButton.backToLessons.y }, 80, 5, BLACK);
			if (chemistryButton.IsClicked(chemistryButton.backToLessons)) {
				activeChemistryLesson = false;
				PickChemistryLesson();
			}
		}
	}
	//Change litmus' scenes
	else if (chemistryTheme == "Litmus") {

		if (currentScene != 7) {
			if (chemistryButton.IsClicked({ 0,0,1980,1080 })) {
				currentScene++;
			}
		}

		switch (currentScene) {

			if (chemistryButton.IsClicked({ 0,0,1980,1080 })) {
				currentScene++;
			}

		case 1:
			DrawTexture(litmusLemon1, 0, 0, WHITE);
			DrawTexture(infoBox, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "Here we have lemon", { 65,700 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "juice", { 65, 750 }, 50, 2, BLACK);
			break;

		case 2:
			DrawTexture(litmusLemon2, 0, 0, WHITE);
			DrawTexture(infoBox, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "In this experiment", { 65,700 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "we will be using", { 65, 750 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "standard litmus paper", { 65,800 }, 50, 2, BLACK);
			break;

		case 3:
			DrawTexture(litmusLemon3, 0, 0, WHITE);
			DrawTexture(infoBox, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "As we can see because of its", { 65,700 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "acidic nature it colors", { 65, 750 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "the litmus an orangish", { 65,800 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "red color", { 65,850 }, 50, 2, BLACK);
			break;

		case 4:
			DrawTexture(litmusNaOH1, 0, 0, WHITE);
			DrawTexture(infoBox, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "In the next experiment we", { 65,700 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "have a 1% NaOH solution", { 65, 750 }, 50, 2, BLACK);
			break;

		case 5:
			DrawTexture(litmusNaOH2, 0, 0, WHITE);
			break;

		case 6:
			DrawTexture(litmusNaOH3, 0, 0, WHITE);
			DrawTexture(infoBox, 0, 0, WHITE);
			DrawTextEx(Renderer::GetInstance()->font, "Owing to its basic nature", { 65,700 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "the NaOH colors the litmus", { 65, 750 }, 50, 2, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "a dark blue color", { 65,800 }, 50, 2, BLACK);
			break;
		case 7:
			DrawTexture(endBackground, 0, 0, WHITE);
			//Return to the chemistry menu to choose an other lesson
			chemistryButton.DrawButton(chemistryButton.backToLessons);
			
			DrawTextEx(Renderer::GetInstance()->font, "Lesson finished!", { 700,500 }, 80, 5, BLACK);
			DrawTextEx(Renderer::GetInstance()->font, "Choose another lesson", { chemistryButton.backToLessons.x, chemistryButton.backToLessons.y }, 80, 5, BLACK);
			if (chemistryButton.IsClicked(chemistryButton.backToLessons)) {
				activeChemistryLesson = false;
				PickChemistryLesson();
			}
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