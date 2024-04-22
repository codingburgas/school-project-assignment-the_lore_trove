#include "pch.h"
#include "framework.h"

#include "Button.h"

// Check if the leff button of the mouse if pressed
bool Button::IsClicked(Rectangle rect) {

	return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rect);
}

// Draw buttons
void Button::DrawButton(Rectangle rect) {
	DrawRectangleRec(rect, ORANGE);
}