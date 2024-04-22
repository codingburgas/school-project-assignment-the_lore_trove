#pragma once

#include "../raylib-master/src/raylib.h" 

class Button {

public:

	bool IsClicked(Rectangle rect);

	void DrawButton(Rectangle rect);

	// Define Buttons
	Rectangle mainMenuButtons[4] = {
		{ 30,350,300,100 },
		{ 30,450,300,100 },
		{ 30,550,300,100 },
		{ 30,850,300,100 }
	};

	Rectangle subjects[3]{
		{30,150,480,700},
		{730,150,480,700},
		{1430,150,480,700},
	};

	Rectangle back = { 10,10,200,106 };

	Rectangle chooseChemistryLessonIcons = { 0, 0, 0, 0 };

	Rectangle backToLessons = { 600,800,740,90 };

	Rectangle mathButtons[3]{
		{200,380,400,420},
		{725,380,430,420},
		{1280,380,450,400}
	};

private:
	
};