#include "pch.h"
#include "framework.h"
#include "MathLesson.h"

Math* Math::instance = nullptr;
Button lessonButton;
Button switchSlidesButton;

void Math::LoadTextures() {
	buttons = LoadTexture("../assets/mathLessonIcons.png");
	boardEraser = LoadTexture("../assets/boardEraser.png");
	boardSharpie = LoadTexture("../assets/boardSharpie.png");
}

void Math::BoardEraser(Color ReplacementColor) {
	Rectangle boardSlideForward = { Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -379), 83, 42 };

	DrawTexture(boardEraser, Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -400), WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), boardSlideForward)) {

		DrawRectangle(Renderer::GetInstance()->CenterPosition(85, 'X'), Renderer::GetInstance()->CenterPosition(45, 'Y', -400), 85, 46, ReplacementColor);
		DrawTexture(boardEraser, Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -390), WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentSlide++;
	}
}

void Math::BoardSharpie(Color ReplacementColor) {
	Rectangle boardSlideBack = { Renderer::GetInstance()->CenterPosition(40, 'X', 200), Renderer::GetInstance()->CenterPosition(40, 'Y', -380), 40, 40 };

	DrawTexture(boardSharpie, Renderer::GetInstance()->CenterPosition(40, 'X', 200), Renderer::GetInstance()->CenterPosition(40, 'Y', -400), WHITE);
	
	if (CheckCollisionPointRec(GetMousePosition(), boardSlideBack)) {

		DrawRectangle(Renderer::GetInstance()->CenterPosition(50, 'X', 200), Renderer::GetInstance()->CenterPosition(50, 'Y', -400), 50, 50, ReplacementColor);
		DrawTexture(boardSharpie, Renderer::GetInstance()->CenterPosition(40, 'X', 200), Renderer::GetInstance()->CenterPosition(40, 'Y', -390), WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && currentSlide > 0) currentSlide--;
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
			DrawText("Triangles are shapes that consist of three angles.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("They are divided into acute-angled, right-angled and obtuse-angled triangles:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			break;

		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

			DrawText("Triangles", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("First sign of equality of triangles: AB = A1B1, AC = A1C1", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Second sign of equality of two triangles:If a side and two angles of one triangle", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("are respectively equal to a side and two angles of another triangle, then the ", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			DrawText("two triangles are congruent.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(230, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Third sign of equality of two triangles: If the sides of one triangle are", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(145, 'Y'), 25, WhiteBoardTextColor);
			DrawText("respectively equal to the sides of another triangle, then the two triangles", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(60, 'Y'), 25, WhiteBoardTextColor);
			DrawText("are congruent.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-25, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Fourth sign of congruence of right triangles:If the leg and hypotenuse of a", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(-110, 'Y'), 25, WhiteBoardTextColor);
			DrawText("rectangle triangle are respectively equal to leg and hypotenuse of another", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-195, 'Y'), 25, WhiteBoardTextColor);
			DrawText("right triangle, it the two triangles are congruent.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-280, 'Y'), 25, WhiteBoardTextColor);
			break;

		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

			DrawText("Triangles", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Formulas for the perimeter of a triangle: P = a+b+c", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Formulas for the face of a triangle:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Formulas for the volume of a triangle:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			break;

		default :
			DrawText("Lesson finished!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -300), 50, WhiteBoardTextColor);
			DrawText("Congratulations!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -400), 50, WhiteBoardTextColor);
			if (currentSlide > 3) currentSlide--;
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
		default:
			DrawText("Lesson finished!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -275), 50, WhiteBoardTextColor);
			DrawText("Congratulations!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -375), 50, WhiteBoardTextColor);
			if (currentSlide > 1) currentSlide--;
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
			DrawText("Radius – a segment whose one endpoint is at the center of a circular line and", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(400, 'Y'), 25, WhiteBoardTextColor);
			DrawText("the second endpoint is on the circle itself.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(315, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Chord – a segment whose endpoints lie on a circular line.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(230, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Diameter – a chord that passes through the center of a circular line.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(145, 'Y'), 25, WhiteBoardTextColor);
			break;
		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);
			DrawText("Circle", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Formulas for the Diameter = 2.radius (d = 2r)", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(485, 'Y'), 25, WhiteBoardTextColor);
			break;
		default:
			DrawText("Lesson finished!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -300), 50, WhiteBoardTextColor);
			DrawText("Congratulations!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -400), 50, WhiteBoardTextColor);
			if (currentSlide > 2) currentSlide--;
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
		lesson = "Circles";
		activeLesson = true;
	}
	else if (lessonButton.IsClicked(lessonButton.mathButtons[2])) {
		lesson = "Rectangles";
		activeLesson = true;
	}
}

void Math::StartMathLesson() {
	LoadWhiteBoardSlides(lesson);
	BoardEraser(Renderer::GetInstance()->Renderer::ongoingLessonBackgroundColor);
	BoardSharpie(Renderer::GetInstance()->Renderer::ongoingLessonBackgroundColor);
}