#pragma once

#include "../raylib-master/src/raylib.h"
#include "Renderer.h"
#include <string>

class Chemistry {

public:

	static Chemistry* GetInstance() {
		if (instance == nullptr) {
			instance = new Chemistry;
		}
		return instance;
	}

	void DetectClick();

	void SwitchScenes(std::string chemistryTheme);

	void PickChemistryLesson();

	void StartChemistryLesson();

	bool activeChemistryLesson = false;

private:

	static Chemistry* instance;

	int currentScene = 1;

	std::string lessonChemistry;
};