#include "pch.h"
#include "framework.h"

#include "MathLesson.h"

Math* Math::instance = nullptr;

int Math::CenterPosition(int Offset = 0, char Axis = 'Y', int OffsetModifier = 0) {
	if (Axis == 'X') return (GetScreenWidth() / 2) - (Offset / 2) - OffsetModifier;
	return ((GetScreenHeight() / 2) - (Offset / 2)) - OffsetModifier;
}

void Math::BoardEraser(Color ReplacementColor) {
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

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			currentSlide++;
		}
	}
}

void Math::LoadWhiteBoardSlides() {
	Color WhiteBoardEdgesColor = Color{ 0, 0, 0, 255 };
	Color WhiteBoardColor = Color{ 255, 255, 255, 255 };
	Color WhiteBoardTextColor = Color{ 0, 0, 0, 255 };

	DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
	DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

	switch (currentSlide) {
	case 0:
		DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
		DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

		DrawText("Triangles", CenterPosition(1000, 'X'), CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
		DrawText("They have three angles.", CenterPosition(975, 'X'), CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
		DrawText("Triangles are shapes that consist of three angles.", CenterPosition(975, 'X'), CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
		DrawText("They have three angles.", CenterPosition(975, 'X'), CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
		DrawText("They are divided into acute-angled, right-angled and obtuse-angled triangles:", CenterPosition(975, 'X'), CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
		break;

	case 1:
		DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
		DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
		DrawText("Triangles", CenterPosition(1000, 'X'), CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
		DrawText("First sign of equality of triangles: AB = A1B1, AC = A1C1", CenterPosition(975, 'X'), CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
		DrawText("Second sign of equality of two triangles:If a side and two angles of one triangle are respectively equal to a side and two angles of another triangle, then the two triangles are congruent.", CenterPosition(975, 'X'), CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
		DrawText("Third sign of equality of two triangles:If the sides of one triangle are correspondingly equal to the sides of another triangle, then the two triangles are congruent.", CenterPosition(975, 'X'), CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
		DrawText("Fourth sign of congruence of right triangles:If the leg and hypotenuse of a rectangle triangle are respectively equal to leg and hypotenuse of another right triangle, it the two triangles are congruent.", CenterPosition(975, 'X'), CenterPosition(230, 'Y'), 25, WhiteBoardTextColor);
		break;

	case 2:
		DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
		DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
		DrawText("Triangles", CenterPosition(1000, 'X'), CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
		DrawText("Formulas for the perimeter of a triangle: P = a+b+c", CenterPosition(975, 'X'), CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
		DrawText("Formulas for the face of a triangle:", CenterPosition(975, 'X'), CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
		DrawText("Formulas for the volume of a triangle:", CenterPosition(975, 'X'), CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
		break;
	}
}

void Math::StartMathLesson() {
	
	LoadWhiteBoardSlides();
	BoardEraser(BLACK);
}