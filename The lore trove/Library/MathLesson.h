#pragma once

#include "../raylib-master/src/raylib.h"
#include "Renderer.h"
#include <string>

class Math {

public:

	static Math* GetInstance() {
		if (instance == nullptr) {
			instance = new Math;
		}
		return instance;
	}

	void LoadTextures();

	void BoardEraser(Color replacementColor);

	void BoardSharpie(Color replacementColor);

	void LoadWhiteBoardSlides(std::string theme);

	void PickMathLesson();

	void StartMathLesson();

	bool activeLesson = false;

private:

	static Math* instance;

	int currentSlide = 0;

	std::string lesson;

	Texture2D buttons, boardEraser, boardSharpie, triangleExamples, firstCongruency, secondCongruency, thirdCongruency, fourthCongruency;
};
