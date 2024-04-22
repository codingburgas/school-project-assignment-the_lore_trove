#pragma once
#include "../raylib-master/src/raylib.h" 
#include "Button.h"
#include "window.h"
#include <vector>

class Renderer {
public:

    static Renderer* GetInstance() {
        if (instance == nullptr) {
            instance = new Renderer;
        }
        return instance;
    }

    int CenterPosition(int offset, char axis, int offsetModifier = 0); // Calculate center position 

    void LoadTextures(); // Load textures for rendering
    void UnloadTextures();  // Unload loaded textures 
    void Update(); // Update rendering and also handle user input

    Texture2D chooseChemistry;

    Font font;

private:

    static Renderer* instance;

    

    Texture2D menuBackground, subjectChoosingBackground, backButton, chooseLesson;

    std::vector<Texture2D> biologyTextures; // Vector to store biology lesson textures

    bool shouldWindowClose = false, menu = true, chooseSubject = false, play = false, main = true, info = false, credits = false;

    //0-biology, 1-math, 2-chemistry
    int subject;

};