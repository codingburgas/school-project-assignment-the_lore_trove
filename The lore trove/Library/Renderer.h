#pragma once
#include "../raylib-master/src/raylib.h" 
#include "Button.h"
#include "window.h"

class Renderer {
public:

    static Renderer* GetInstance() {
        if (instance == nullptr) {
            instance = new Renderer;
        }
        return instance;
    }

    void LoadTextures();

    void Update();

private:

    static Renderer* instance;

    Font font;

    Texture2D menuBackground, subjectChoosingBackground, backButton, chooseLesson;

    bool shouldWindowClose = false, menu = true, chooseSubject = false, play = false,main = true,info = false, credits = false;

    //0-biology, 1-math, 2-chemistry
    int subject;

};