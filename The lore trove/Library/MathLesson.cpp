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

	DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
	DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

	if (Theme == "Triangles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Triangles-Definition", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Triangles are shapes that consist of three angles.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("They are divided into acute-angled, right-angled and obtuse-angled:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);

			break;

		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Triangles-Signs of Congruency", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("First sign of congruency of triangles: If two sides of a triangle and an angle", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("between them are respectively equal to two sides and an angle between them of", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);
			DrawText("another triangle, then the triangles are congruent.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Second sign of equality of triangles: If a side and two angles of one triangle", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);
			DrawText("are respectively equal to a side and two angles of another triangle, then the ", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);
			DrawText("two triangles are congruent.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(30, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Third sign of equality of triangles: If the sides of one triangle are", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(-55, 'Y'), 25, WhiteBoardTextColor);
			DrawText("respectively equal to the sides of another triangle, then the two triangles", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-140, 'Y'), 25, WhiteBoardTextColor);
			DrawText("are congruent.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-225, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Fourth sign of congruence (right triangles specific): If a leg and", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(-310, 'Y'), 25, WhiteBoardTextColor);
			DrawText("hypotenuse of a right triangle are respectively equal to a leg and", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-395, 'Y'), 25, WhiteBoardTextColor);
			DrawText("hypotenuse of another right triangle, it the two triangles", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-480, 'Y'), 25, WhiteBoardTextColor);
			DrawText("are congruent.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-565, 'Y'), 25, WhiteBoardTextColor);

			break;

		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Signs of Congruency: Examples", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);

			break;

		case 3:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Triangles-Signs of Similarity", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);

			DrawText("First sign of similarity of triangles: if two angles of a triangle", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("are respectively equal to two angles of another triangle.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);

			DrawText("Second sign of similarity of triangles: if two sides of a triangle", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("are respectively proportional to two sides of another triangle", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);
			DrawText("and the angles locked between them are equal.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);

			DrawText("Third sign of similarity of triangles: if all sides of a", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(30, 'Y'), 25, WhiteBoardTextColor);
			DrawText("triangle are respectively proprotional to all sides of another", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-55, 'Y'), 25, WhiteBoardTextColor);
			DrawText("triangle.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-140, 'Y'), 25, WhiteBoardTextColor);

			DrawText("Fourth sign of similarity of triangles: if two sides of a", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(-225, 'Y'), 25, WhiteBoardTextColor);
			DrawText("triangle are respectively proportional to two sides of another", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-310, 'Y'), 25, WhiteBoardTextColor);
			DrawText("triangle and the angles situated oppositely of the greater", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-395, 'Y'), 25, WhiteBoardTextColor);
			DrawText("of the two sides are respecitvely equal.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-480, 'Y'), 25, WhiteBoardTextColor);
			break;

		default:
			DrawText("Lesson finished!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -300), 50, WhiteBoardTextColor);
			DrawText("Congratulations!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -400), 50, WhiteBoardTextColor);
			if (currentSlide > 4) currentSlide--;
			break;
		}
	}
	else if (Theme == "Rectangles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Rectangles-Definition", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);

			DrawText("Rectangles are shapes that consist of two pairs of", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("equal sides.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);
			DrawText("A rectangle has only right angles.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Squares are rectangles whose sides are all equal to eachother.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Remember, every square is a rectangle, but not every rectangle is a square!", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);
			DrawText(" is a square!", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(30, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Examples:", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(-55, 'Y'), 25, WhiteBoardTextColor);

			//Texture goes here

			break;

		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Rectangles-General Characteristics", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("In a rectangle, the diagonals (that connect oppsitely-sided angles) are", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("equal to eachother.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The meeting point of the diagonals divides them into two equal parts.", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The meeting point of the diagonlas is also the center of the Circle", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);
			DrawText("surrouding said rectangle.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);

			break;
		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Rectangles-Formulae", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Following the Pythagoras' theorem, the diagonal of a rectangle", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("is respectively: d^2 = a^2 + b^2;", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The Volume of a rectangle: S = a.b;", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The Perimeter of a triangle: P = 2.(a+b);", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);
			DrawText("If the rule of a:b = b:(a-b) applies to a rectangle, then", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);
			DrawText("it is called a 'Golden rectangle'.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);
			break;
		default:
			DrawText("Lesson finished!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -275), 50, WhiteBoardTextColor);
			DrawText("Congratulations!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -375), 50, WhiteBoardTextColor);
			if (currentSlide > 3) currentSlide--;
			break;
		}
	}
	else if (Theme == "Circles") {
		switch (currentSlide) {
		case 0:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Circles-Definition", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("The circle is a shape, composed of all the meeting points", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("that are situated at a specific distance from the center.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);
			DrawText("That distance is called a Radius, and the elongation of a", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("radius that goes in a straight line and connects both ends of", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);
			DrawText("a circle is called a Diameter.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The three-dimensional version of the circle is called a", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(30, 'Y'), 25, WhiteBoardTextColor);
			DrawText("sphere.", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-55, 'Y'), 25, WhiteBoardTextColor);

			//Texture goes here

			break;
		case 1:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Circles-Formulae", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("The Volume of a circle: S = Pi.r^2 or S = (Pi.d^2) : 4;", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The Circumference of a circle: P = 2.Pi.r or P = Pi.d;", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The Volume of a sphere: V = 4:3.Pi.r^3;", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("The Area of a sphere: S = 4.Pi.r^2", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);

			break;

		case 2:
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1070, 'X'), Renderer::GetInstance()->CenterPosition(665, 'Y'), 1070, 665, WhiteBoardEdgesColor);
			DrawRectangle(Renderer::GetInstance()->CenterPosition(1050, 'X'), Renderer::GetInstance()->CenterPosition(645, 'Y'), 1050, 645, WhiteBoardColor);

			DrawText("Circles-Components", Renderer::GetInstance()->CenterPosition(1000, 'X'), Renderer::GetInstance()->CenterPosition(575, 'Y'), 30, WhiteBoardTextColor);
			DrawText("Tangent-A line that has only a single meeting point with a circle;", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(455, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Chord-A line segment whose endpoints lie on the circle, thus", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(370, 'Y'), 25, WhiteBoardTextColor);
			DrawText("dividing a circle into two segments;", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(285, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Secant-An extended chord, a coplanar straight line, intersecting", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(200, 'Y'), 25, WhiteBoardTextColor);
			DrawText("a circle in two points;", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(115, 'Y'), 25, WhiteBoardTextColor);
			DrawText("Sector: a region bounded by two radii of equal length with a", Renderer::GetInstance()->CenterPosition(975, 'X'), Renderer::GetInstance()->CenterPosition(30, 'Y'), 25, WhiteBoardTextColor);
			DrawText("common centre and either of the two possible arcs, determined", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-55, 'Y'), 25, WhiteBoardTextColor);
			DrawText("by this centre and the endpoints of the radii;", Renderer::GetInstance()->CenterPosition(925, 'X'), Renderer::GetInstance()->CenterPosition(-140, 'Y'), 25, WhiteBoardTextColor);
			break;
		default:
			DrawText("Lesson finished!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -300), 50, WhiteBoardTextColor);
			DrawText("Congratulations!", Renderer::GetInstance()->CenterPosition(1070, 'X', -300), Renderer::GetInstance()->CenterPosition(635, 'Y', -400), 50, WhiteBoardTextColor);
			if (currentSlide > 3) currentSlide--;
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