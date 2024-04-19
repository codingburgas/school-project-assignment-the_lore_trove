#include <iostream>
#include "raylib.h"
#include "../Library/MathGeneral.h"
#include "../Library/MathLesson.h"
#include "../Library/MathTest.h"

using namespace std;

int CenterPosition(int Offset = 0, char Axis = 'Y', int OffsetModifier = 0) {
	if (Axis == 'X') return (GetScreenWidth() / 2) - (Offset / 2) - OffsetModifier;
	return ((GetScreenHeight() / 2) - (Offset / 2)) - OffsetModifier;
}

void BoardEraser(int& Slide, Color ReplacementColor) {
	Color BoardEraserColor = Color{ 0, 49, 122, 255 };
	Color BoardEraserShade = Color{ 1, 35, 87, 255 };
	Color White = Color{ 255, 255, 255, 255 };

	Rectangle BoardEraserExit = { CenterPosition(83, 'X'), CenterPosition(42, 'Y', -379), 83, 42 };

	DrawRectangle(CenterPosition(83, 'X'), CenterPosition(45, 'Y', -400), 83, 45, BoardEraserShade);
	DrawRectangle(CenterPosition(80, 'X'), CenterPosition(42, 'Y', -400), 80, 42, BoardEraserColor);

	if (CheckCollisionPointRec(GetMousePosition(), BoardEraserExit)) {

		DrawRectangle(CenterPosition(85, 'X'), CenterPosition(45, 'Y', -400), 85, 45, ReplacementColor);
		DrawRectangle(CenterPosition(83, 'X'), CenterPosition(55, 'Y', -400), 83, 45, BoardEraserShade);
		DrawRectangle(CenterPosition(80, 'X'), CenterPosition(52, 'Y', -400), 80, 42, BoardEraserColor);

		if (IsMouseButtonPressed(0)) {
			Slide++;
		}
	}
}

void LoadWhiteBoardSlides(int Order) {
	Color WhiteBoardEdgesColor = Color{ 0, 0, 0, 255 };
	Color WhiteBoardColor = Color{ 255, 255, 255, 255 };
	Color WhiteBoardTextColor = Color{ 0, 0, 0, 255 };

	DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
	DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
}

void StartMathLesson() {
	int CurrentSlide = 0;

	LoadWhiteBoardSLides(CurrentSlide);
	BoardEraser(CurrentSlide);
}