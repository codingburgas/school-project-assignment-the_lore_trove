#pragma once
#include "../raylib-master/src/raylib.h" 
#include "Renderer.h"
#include "MathLesson.h"
#include "ChemistryLesson.h"
#include "window.h"

class Manager {
public:

    static Manager* GetInstance() {
        if (instance == nullptr) {
            instance = new Manager;
        }
        return instance;
    }

    void Initizalize();

    void Start();

    bool ShouldWindowClose();

    void Update();

    void Close();

private:

    static Manager* instance;

    bool shouldWindowClose = false;

    Renderer* renderer;

    Chemistry* chemistry;
};