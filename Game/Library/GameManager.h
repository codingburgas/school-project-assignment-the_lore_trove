#pragma once
#include "../raylib-master/src/raylib.h" 
#include "Button.h"
#include "window.h"

class GameManager {
public:

    static GameManager* GetInstance() {
        if (instance == nullptr) {
            instance = new GameManager;
        }
        return instance;
    }

	void Initizalize();

private:
    static GameManager* instance;
};