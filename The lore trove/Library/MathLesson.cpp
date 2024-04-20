#include "pch.h"
#include "framework.h"

#include "MathLesson.h"
#include <string>

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

void Math::LoadWhiteBoardSlides(std::string Theme) {
	Color WhiteBoardEdgesColor = Color{ 0, 0, 0, 255 };
	Color WhiteBoardColor = Color{ 255, 255, 255, 255 };
	Color WhiteBoardTextColor = Color{ 0, 0, 0, 255 };

	DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
	DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

	if (Theme == "Triangles") {
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
	else if (Theme == "Rectangles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
			DrawText("Rectangles", CenterPosition(1000, 'X'), CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Circumference of a rectangle:P = 2.(a + b)", CenterPosition(975, 'X'), CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Face of a rectangle: S = a.b", CenterPosition(975, 'X'), CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			break;
		}
	}
	else if (Theme == "Circles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
			DrawText("Circle", CenterPosition(1000, 'X'), CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("What makes the circle:", CenterPosition(975, 'X'), CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Radius – a segment whose one endpoint is at the center of a circular line and the second endpoint is on the circle itself.", CenterPosition(975, 'X'), CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Chord – a segment whose endpoints lie on a circular line.", CenterPosition(975, 'X'), CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Diameter – a chord that passes through the center of a circular line.", CenterPosition(975, 'X'), CenterPosition(230, 'Y'), 25, WhiteBoardTextColor);
			break;
		case 1:
			DrawRectangle(CenterPosition(1070, 'X'), CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(CenterPosition(1050, 'X'), CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
			DrawText("Circle", CenterPosition(1000, 'X'), CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Formulas for the Diameter = 2.radius (d = 2r)", CenterPosition(975, 'X'), CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			break;
		}
	}
}

void Math::PickMathLesson() {
	DrawRectangle(CenterPosition(250, 'X', 300), CenterPosition(-125, 'Y'), 250, 125, BLACK);
	Rectangle TriButton = { CenterPosition(200, 'X', 300), CenterPosition(-100, 'Y'), 200, 100 };
	DrawRectangleRec(TriButton, RED);
	DrawText("Triangles", CenterPosition(200, 'X', 275), CenterPosition(-100, 'Y', - 25), 30, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), TriButton)) {
		DrawRectangle(CenterPosition(250, 'X', 300), CenterPosition(-125, 'Y'), 250, 125, MAROON);
		DrawRectangleRec(TriButton, RED);
		DrawText("Triangles", CenterPosition(200, 'X', 275), CenterPosition(-100, 'Y', -25), 30, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			lesson = "Triangles";
			activeLesson = true;
		}
	}

	DrawRectangle(CenterPosition(250, 'X'), CenterPosition(-125, 'Y'), 250, 125, BLACK);
	Rectangle CirButton = { CenterPosition(200, 'X'), CenterPosition(-100, 'Y'), 200, 100 };
	DrawRectangleRec(CirButton, GREEN);
	DrawText("Circles", CenterPosition(200, 'X', -25), CenterPosition(-100, 'Y', -25), 30, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), CirButton)) {
		DrawRectangle(CenterPosition(250, 'X'), CenterPosition(-125, 'Y'), 250, 125, DARKGREEN);
		DrawRectangleRec(CirButton, GREEN);
		DrawText("Circles", CenterPosition(200, 'X', -25), CenterPosition(-100, 'Y', -25), 30, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			lesson = "Circles";
			activeLesson = true;
		}
	}
	
	DrawRectangle(CenterPosition(250, 'X', -300), CenterPosition(-125, 'Y'), 250, 125, BLACK);
	Rectangle RecButton = { CenterPosition(200, 'X', -300), CenterPosition(-100, 'Y'), 200, 100 };
	DrawRectangleRec(RecButton, BLUE);
	DrawText("Rectangles", CenterPosition(200, 'X', -325), CenterPosition(-100, 'Y', -25), 30, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), RecButton)) {
		DrawRectangle(CenterPosition(250, 'X', -300), CenterPosition(-125, 'Y'), 250, 125, DARKBLUE);
		DrawRectangleRec(RecButton, BLUE);
		DrawText("Rectangles", CenterPosition(200, 'X', -325), CenterPosition(-100, 'Y', -25), 30, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			lesson = "Rectangles";
			activeLesson = true;
		}
	}
}

void Math::StartMathLesson() {
	
	LoadWhiteBoardSlides(lesson);
	BoardEraser(BLACK);
}