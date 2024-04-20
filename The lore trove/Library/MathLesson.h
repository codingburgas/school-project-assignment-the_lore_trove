#pragma once

#include "../raylib-master/src/raylib.h" 
#include <string>

class Math {

public:

	static Math* GetInstance() {
		if (instance == nullptr) {
			instance = new Math;
		}
		return instance;
	}

	int CenterPosition(int offset, char axis, int offsetModifier);

	void BoardEraser(Color replacementColor);

	void LoadWhiteBoardSlides(std::string theme);

	void PickMathLesson();

	void StartMathLesson();

	bool activeLesson = false;

private:

	static Math* instance;

	int currentSlide = 0;

	std::string lesson;
};
