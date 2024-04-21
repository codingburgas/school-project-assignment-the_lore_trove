#pragma once

#include "../raylib-master/src/raylib.h" 
#include <string>
#include <vector>

using namespace std;

class Biology {
public:
	static Biology* GetInstance() { // GetInstance function to get a single instance
		if (instance == nullptr) {
			instance = new Biology; // Create a new instance if none exists
		}
		return instance; // Return the existing instance or the newly created one
	}

	void StartLesson();
	void LoadSlide();
	bool CheckButtonClicked(Rectangle buttonRect);
	void setTextures(vector<Texture2D> textures); // Function to set the textures for rendering

private:
	static Biology* instance; // Static variable to hold the singleton instance
	int currentSlide = 0;
	int lesson;
	vector<Texture2D> _textures; // Vector to store textures for rendering
};