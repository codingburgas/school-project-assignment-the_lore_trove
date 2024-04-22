#include "pch.h"
#include "framework.h"
#include "MathLesson.h"

Math* Math::instance = nullptr;
Button lessonButton;

void Math::LoadTextures() {
	buttons = LoadTexture("../assets/mathLessonIcons.png");
}
void Math::BoardEraser(Color ReplacementColor) {
	Color BoardEraserColor = Color{ 0, 49, 122, 255 };
	Color BoardEraserShade = Color{ 1, 35, 87, 255 };
	Color White = Color{ 255, 255, 255, 255 };

	Rectangle BoardEraserExit = { Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -379), 83, 42 };

	DrawRectangle(Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(45, 'Y', -400), 83, 45, BoardEraserShade);
	DrawRectangle(Renderer::GetInstance()->CenterPosition(80, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -400), 80, 42, BoardEraserColor);

	if (CheckCollisionPointRec(GetMousePosition(), BoardEraserExit)) {

		DrawRectangle(Renderer::GetInstance()->CenterPosition(85, 'X'), Renderer::GetInstance()->CenterPosition(45, 'Y', -400), 85, 45, ReplacementColor);
		DrawRectangle(Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(55, 'Y', -400), 83, 45, BoardEraserShade);
		DrawRectangle(Renderer::GetInstance()->CenterPosition(80, 'X'), Renderer::GetInstance()->CenterPosition(52, 'Y', -400), 80, 42, BoardEraserColor);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			currentSlide++;
		}
	}
}

void Math::LoadWhiteBoardSlides(std::string Theme) {
	Color WhiteBoardEdgesColor = Color{ 0, 0, 0, 255 };
	Color WhiteBoardColor = Color{ 255, 255, 255, 255 };
	Color WhiteBoardTextColor = Color{ 0, 0, 0, 255 };

	DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
	DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

	if (Theme == "Triangles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

			DrawText("Triangles", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("They have three angles.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Triangles are shapes that consist of three angles.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("They have three angles.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("They are divided into acute-angled, right-angled and obtuse-angled triangles:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			break;

		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

			DrawText("Triangles", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("First sign of equality of triangles: AB = A1B1, AC = A1C1", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Second sign of equality of two triangles:If a side and two angles of one triangle are respectively equal to a side and two angles of another triangle, then the two triangles are congruent.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Third sign of equality of two triangles:If the sides of one triangle are correspondingly equal to the sides of another triangle, then the two triangles are congruent.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Fourth sign of congruence of right triangles:If the leg and hypotenuse of a rectangle triangle are respectively equal to leg and hypotenuse of another right triangle, it the two triangles are congruent.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(230, 'Y'), 25, WhiteBoardTextColor);
			break;

		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

			DrawText("Triangles", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Formulas for the perimeter of a triangle: P = a+b+c", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Formulas for the face of a triangle:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Formulas for the volume of a triangle:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			break;

		}
	}
	else if (Theme == "Rectangles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
			DrawText("Rectangles", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("A rectangle has two equal sides.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Circumference of a rectangle:P = 2.(a + b)", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Face of a rectangle: S = a.b", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			break;
		}
	}
	else if (Theme == "Circles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
			DrawText("Circle", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("What makes the circle:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Radius – a segment whose one endpoint is at the center of a circular line and the second endpoint is on the circle itself.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Chord – a segment whose endpoints lie on a circular line.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Diameter – a chord that passes through the center of a circular line.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(230, 'Y'), 25, WhiteBoardTextColor);
			break;
		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
			DrawText("Circle", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Formulas for the Diameter = 2.radius (d = 2r)", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			break;
		}
	}
}

void Math::PickMathLesson() {
	currentSlide = 0;
	DrawTexture(buttons, 0, 0, WHITE);
	if (lessonButton.IsClicked(lessonButton.mathButtons[0])) {
		lesson = "Triangles";
		activeLesson = true;
	}
	else if (lessonButton.IsClicked(lessonButton.mathButtons[1])) {
		lesson = "Rectangles";
		activeLesson = true;
	}
	else if (lessonButton.IsClicked(lessonButton.mathButtons[2])) {
		lesson = "Circles";
		activeLesson = true;
	}
}

void Math::StartMathLesson() {
	LoadWhiteBoardSlides(lesson);
	BoardEraser(BLACK);
}