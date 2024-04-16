#include "pch.h"
#include "framework.h"

#include "Button.h"

bool Button::IsClicked(Rectangle rect) {

	return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rect);
}