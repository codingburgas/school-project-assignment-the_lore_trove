#include "pch.h"
#include "framework.h"
#include "MathLesson.h"

Math* Math::instance = nullptr;
Button lessonButton;
Button switchSlidesButton;

void Math::LoadTextures() {
	//Loads textures
	buttons = LoadTexture("../assets/mathLessonIcons.png");
	boardEraser = LoadTexture("../assets/boardEraser.png");
	boardSharpie = LoadTexture("../assets/boardSharpie.png");

	triangleExamples = LoadTexture("../assets/triangleExamples.png");
	firstCongruency = LoadTexture("../assets/firstCongruency.png");
	secondCongruency = LoadTexture("../assets/secondCongruency.png");
	thirdCongruency = LoadTexture("../assets/thirdCongruency.png");
	fourthCongruency = LoadTexture("../assets/fourthCongruency.png");
}

void Math::BoardEraser(Color ReplacementColor) {
	//Draws a board eraser, used for going forwards in lesson slides
	
	Rectangle boardSlideForward = { Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -400), 83, 42 };

	DrawTexture(boardEraser, Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -400), WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), boardSlideForward)) {

		DrawRectangle(Renderer::GetInstance()->CenterPosition(85, 'X'), Renderer::GetInstance()->CenterPosition(45, 'Y', -400), 85, 46, ReplacementColor);
		DrawTexture(boardEraser, Renderer::GetInstance()->CenterPosition(83, 'X'), Renderer::GetInstance()->CenterPosition(42, 'Y', -390), WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentSlide++;
	}
}

void Math::BoardSharpie(Color ReplacementColor) {
	//Draws a board sharpie, used for going backwards in lesson slides

	Rectangle boardSlideBack = { Renderer::GetInstance()->CenterPosition(40, 'X', 200), Renderer::GetInstance()->CenterPosition(40, 'Y', -400), 40, 40 };

	DrawTexture(boardSharpie, Renderer::GetInstance()->CenterPosition(40, 'X', 200), Renderer::GetInstance()->CenterPosition(40, 'Y', -400), WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), boardSlideBack)) {

		DrawRectangle(Renderer::GetInstance()->CenterPosition(50, 'X', 200), Renderer::GetInstance()->CenterPosition(50, 'Y', -400), 50, 50, ReplacementColor);
		DrawTexture(boardSharpie, Renderer::GetInstance()->CenterPosition(40, 'X', 200), Renderer::GetInstance()->CenterPosition(40, 'Y', -390), WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && currentSlide > 0) currentSlide--;
	}
}

void Math::LoadWhiteBoardSlides(std::string Theme) {
	//Loads the contents of different lesson slides, depending on theme and order 
	
	Color WhiteBoardEdgesColor = Color{ 0, 0, 0, 255 };
	Color WhiteBoardColor = Color{ 255, 255, 255, 255 };
	Color WhiteBoardTextColor = Color{ 0, 0, 0, 255 };

	DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(635, 'Y'), 1070, 635, WhiteBoardEdgesColor);
	DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(615, 'Y'), 1050, 615, WhiteBoardColor);

	DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
	DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

	//Draws lesson for triangles
	if (Theme == "Triangles") { 
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Triangles-Definition", { float(Renderer::GetInstance()->Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Triangles are shapes that consist of three angles.", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "They are divided into acute-angled, right-angled and obtuse-angled:", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTexture(triangleExamples, Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(560, 'Y', -75), WHITE);
			break;

		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Triangles-Signs of Congruency", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "First sign of congruency of triangles: If two sides of a triangle and an angle", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "between them are respectively equal to two sides and an angle between them of", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "another triangle, then the triangles are congruent.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Second sign of equality of triangles: If a side and two angles of one triangle", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "are respectively equal to a side and two angles of another triangle, then the ", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "two triangles are congruent.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(30, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Third sign of equality of triangles: If the sides of one triangle are", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(-55, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "respectively equal to the sides of another triangle, then the two triangles", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-140, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "are congruent.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-225, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Fourth sign of congruence (right triangles specific): If a leg and", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(-310, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "hypotenuse of a right triangle are respectively equal to a leg and", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-395, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "hypotenuse of another right triangle, it the two triangles", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-480, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "are congruent.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-565, 'Y')) }, 25, 2, WhiteBoardTextColor);

			break;

		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Signs of Congruency: Examples", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);

			DrawTextEx(Renderer::GetInstance()->font, "The First sign of Congruency in action:", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y', -115)) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Second sign of Congruency in action:", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y', -230)) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Third sign of Congruency in action:", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y', -345)) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Fourth sign of Congruency in action:", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y', -460)) }, 25, 2, WhiteBoardTextColor);
			
			DrawTexture(firstCongruency, Renderer::GetInstance()->CenterPosition(470, 'X', -275), Renderer::GetInstance()->CenterPosition(112, 'Y', 200), WHITE);
			DrawTexture(secondCongruency, Renderer::GetInstance()->CenterPosition(470, 'X', -275), Renderer::GetInstance()->CenterPosition(125, 'Y', 85), WHITE);
			DrawTexture(thirdCongruency, Renderer::GetInstance()->CenterPosition(470, 'X', -275), (GetScreenHeight() / 2 - 125 / 2 + 30), WHITE);
			DrawTexture(fourthCongruency, Renderer::GetInstance()->CenterPosition(470, 'X', -275), (GetScreenHeight() / 2 - 125 / 2 + 145), WHITE);
			break;

		case 3:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Triangles-Signs of Similarity", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);

			DrawTextEx(Renderer::GetInstance()->font, "First sign of similarity of triangles: if two angles of a triangle", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "are respectively equal to two angles of another triangle.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Second sign of similarity of triangles: if two sides of a triangle", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "are respectively proportional to two sides of another triangle", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "and the angles locked between them are equal.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Third sign of similarity of triangles: if all sides of a", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(30, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "triangle are respectively proprotional to all sides of another", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-55, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "triangle.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-140, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Fourth sign of similarity of triangles: if two sides of a", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(-225, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "triangle are respectively proportional to two sides of another", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-310, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "triangle and the angles situated oppositely of the greater", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-395, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "of the two sides are respecitvely equal.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')) , float(Renderer::GetInstance()->CenterPosition(-480, 'Y')) }, 25, 2, WhiteBoardTextColor);
			break;

		default:
			DrawTextEx(Renderer::GetInstance()->font, "Lesson finished!", { float(Renderer::GetInstance()->CenterPosition(1070, 'X', -300)), float(Renderer::GetInstance()->CenterPosition(635, 'Y', -300)) }, 50, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Congratulations!", { float(Renderer::GetInstance()->CenterPosition(1070, 'X', -300)), float(Renderer::GetInstance()->CenterPosition(635, 'Y', -400)) }, 50, 2, WhiteBoardTextColor);
			if (currentSlide > 4) currentSlide--;
			break;
		}
	}
	//Draws lesson for rectangles
	else if (Theme == "Rectangles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Rectangles-Definition", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);

			DrawTextEx(Renderer::GetInstance()->font, "Rectangles are shapes that consist of two pairs of", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "equal sides.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "A rectangle has only right angles.", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Squares are rectangles whose sides are all equal to eachother.", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Remember, every square is a rectangle, but not every rectangle is a square!", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, " is a square!", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(30, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Examples:", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(-55, 'Y')) }, 25, 2, WhiteBoardTextColor);

			break;

		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Rectangles-General Characteristics", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "In a rectangle, the diagonals (that connect oppsitely-sided angles) are", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "equal to eachother.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The meeting point of the diagonals divides them into two equal parts.", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The meeting point of the diagonlas is also the center of the Circle", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "surrouding said rectangle.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);

			break;
		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Rectangles-Formulae", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Following the Pythagoras' theorem, the diagonal of a rectangle", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "is respectively: d^2 = a^2 + b^2;", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Volume of a rectangle: S = a.b;", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Perimeter of a triangle: P = 2.(a+b);", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "If the rule of a:b = b:(a-b) applies to a rectangle, then", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "it is called a 'Golden rectangle'.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);
			
			break;
		default:
			DrawTextEx(Renderer::GetInstance()->font, "Lesson finished!", { float(Renderer::GetInstance()->CenterPosition(1070, 'X', -300)), float(Renderer::GetInstance()->CenterPosition(635, 'Y', -275)) }, 50, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Congratulations!", { float(Renderer::GetInstance()->CenterPosition(1070, 'X', -300)), float(Renderer::GetInstance()->CenterPosition(635, 'Y', -375)) }, 50, 2, WhiteBoardTextColor);
			if (currentSlide > 3) currentSlide--;
			break;
		}
	}
	//Draws lessons for circles
	else if (Theme == "Circles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Circles-Definition", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The circle is a shape, composed of all the meeting points", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "that are situated at a specific distance from the center.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "That distance is called a Radius, and the elongation of a", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "radius that goes in a straight line and connects both ends of", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "a circle is called a Diameter.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The three-dimensional version of the circle is called a", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(30, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "sphere.", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-55, 'Y')) }, 25, 2, WhiteBoardTextColor);

			break;
		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Circles-Formulae", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Volume of a circle: S = Pi.r^2 or S = (Pi.d^2) : 4;", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Circumference of a circle: P = 2.Pi.r or P = Pi.d;", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Volume of a sphere: V = 4:3.Pi.r^3;", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "The Area of a sphere: S = 4.Pi.r^2", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);

			break;

		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawTextEx(Renderer::GetInstance()->font, "Circles-Components", { float(Renderer::GetInstance()->CenterPosition(1000, 'X')), float(Renderer::GetInstance()->CenterPosition(575, 'Y')) }, 30, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Tangent-A line that has only a single meeting point with a circle;", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(455, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Chord-A line segment whose endpoints lie on the circle, thus", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(370, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "dividing a circle into two segments;", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(285, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Secant-An extended chord, a coplanar straight line, intersecting", { float(Renderer::GetInstance()->CenterPosition(975, 'X')), float(Renderer::GetInstance()->CenterPosition(200, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "a circle in two points;", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(115, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Sector: a region bounded by two radii of equal length with a", { float(Renderer::GetInstance()->CenterPosition(975, 'X')) , float(Renderer::GetInstance()->CenterPosition(30, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "common centre and either of the two possible arcs, determined", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-55, 'Y')) }, 25, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "by this centre and the endpoints of the radii;", { float(Renderer::GetInstance()->CenterPosition(925, 'X')), float(Renderer::GetInstance()->CenterPosition(-140, 'Y')) }, 25, 2, WhiteBoardTextColor);
			break;
		default:
			DrawTextEx(Renderer::GetInstance()->font, "Lesson finished!", { float(Renderer::GetInstance()->CenterPosition(1070, 'X', -300)), float(Renderer::GetInstance()->CenterPosition(635, 'Y', -300)) }, 50, 2, WhiteBoardTextColor);
			DrawTextEx(Renderer::GetInstance()->font, "Congratulations!", { float(Renderer::GetInstance()->CenterPosition(1070, 'X', -300)), float(Renderer::GetInstance()->CenterPosition(635, 'Y', -400)) }, 50, 2, WhiteBoardTextColor);
			if (currentSlide > 3) currentSlide--;
			break;
		}
	}
}

//Enables the user to pick a math lesson of their liking
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

//Starts the math lesson
void Math::StartMathLesson() {
	LoadWhiteBoardSlides(lesson);
	BoardEraser(Renderer::GetInstance()->Renderer::ongoingLessonBackgroundColor);
	BoardSharpie(Renderer::GetInstance()->Renderer::ongoingLessonBackgroundColor);
}