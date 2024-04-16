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

    bool shouldWindowClose = false, menu = true, play = false;

    Texture2D menuBackground;
};