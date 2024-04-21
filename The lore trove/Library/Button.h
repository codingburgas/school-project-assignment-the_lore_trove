#pragma once

#include "../raylib-master/src/raylib.h" 

class Button {

public:

	bool IsClicked(Rectangle rect);

	void DrawButton(Rectangle rect);

	Rectangle mainMenuButtons[4] = {
		{ 30,350,300,100 },
		{ 30,450,300,100 },
		{ 30,550,300,100 },
		{ 30,850,300,100 }
	};

	Rectangle subjects[3]{
		{50,300,50,50},
		{50,300,50,50},
		{50,300,50,50}
	};

private:
	
};