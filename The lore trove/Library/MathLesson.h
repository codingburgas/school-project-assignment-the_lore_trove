#pragma once

#include "../raylib-master/src/raylib.h" 

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

	void LoadWhiteBoardSlides();

	void StartMathLesson();

private:

	static Math* instance;

	int currentSlide = 0;
};
