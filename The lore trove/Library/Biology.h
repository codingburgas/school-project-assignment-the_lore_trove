#pragma once

#include "../raylib-master/src/raylib.h" 
#include <string>
#include <vector>

using namespace std;

class Biology {
public:
	static Biology* GetInstance() {
		if (instance == nullptr) {
			instance = new Biology;
		}
		return instance;
	}

	void StartLesson();
	void LoadSlide();
	bool CheckButtonClicked(Rectangle buttonRect);
	void setTextures(vector<Texture2D> textures);

private:
	static Biology* instance;
	int currentSlide = 0;
	int lesson;
	vector<Texture2D> _textures;
};