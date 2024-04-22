#include "pch.h"
#include "framework.h"
#include "window.h"
#include "Biology.h"
#include <string>

Biology* Biology::instance = nullptr;

void DrawButton(Rectangle rect, const char* text, Color idleColor, Color hoverColor, Color textColor) {

    // Check if the mouse cursor is hovering over the button
    bool isHovered = CheckCollisionPointRec(GetMousePosition(), rect); 

    // Draw button according to hover state
    if (isHovered) {
        DrawRectangleRec(rect, hoverColor);
    }
    else {
        DrawRectangleRec(rect, idleColor);
    }

    // Draw button text
    DrawTextEx(Renderer::GetInstance()->font, text, { rect.x + 40, rect.y + 20 }, 30, 5, textColor); 
}

// Function to start a biology lesson
void Biology::StartLesson(){

    // Draw common board elements
    DrawTexture(_textures[3], 0, 0, WHITE);
    DrawRectangle(BOARDX, BOARDY, BOARD_WIDTH, BOARD_HEIGHT, WHITE_BOARD_MARGIN_COLOR);
    DrawRectangle(BOARDX + BORDER, BOARDY + BORDER, BOARD_WIDTH - (BORDER * 2), BOARD_HEIGHT - (BORDER * 2), WHITE_BOARD_COLOR);

    // Draw lesson specific content for the first icon
    if (lesson == 1) {
        switch (currentSlide) {
        case 1:
            DrawTexture(_textures[4], BOARDX + 255, BOARDY + 15, WHITE);
            DrawTextEx(Renderer::GetInstance()->font, "The cell is the smallest unit that can live on its own and that makes up all ", { BOARDX + (BOARD_WIDTH / 2) - 470, BOARDY + 400 }, 25, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "living organisms and the issues of the body. A cell has three main parts: ", { BOARDX + (BOARD_WIDTH / 2) - 470, BOARDY + 440 }, 25, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "The cell membrane, The nucleus, and The cytoplasm. The powerhouse of", { BOARDX + (BOARD_WIDTH / 2) - 470, BOARDY + 480 }, 25, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "the cell is Mitohondria.", { BOARDX + (BOARD_WIDTH / 2) - 125, BOARDY + 525 }, 25, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(NEXT_BUTTON, "Next", BLUE, SKYBLUE, WHITE);
            break;

        case 2:
            DrawTextEx(Renderer::GetInstance()->font, "Question 1:", { BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105 }, 40, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Which of the following is from the main part of the cell?", { BOARDX + (BOARD_WIDTH / 2) - 460 - 10, BOARDY + 195 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A. Mitohandria", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. The Nucleus", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Membrane Receptor ", BLUE, SKYBLUE, WHITE);
            break;
        case 3:
            DrawTextEx(Renderer::GetInstance()->font, "Question 2:", { BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105 }, 40, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "What is the powerhouse of the cell?", { BOARDX + (BOARD_WIDTH / 2) - 460 - 10, BOARDY + 195 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A. Mitochondria", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. Nucleus", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Golgi Apparatus", BLUE, SKYBLUE, WHITE);
            break;
        default:
            DrawTextEx(Renderer::GetInstance()->font, "Lesson finished!", { BOARDX + (BOARD_WIDTH / 2) - 160, BOARDY + 250 }, 45, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(RETURN_BUTTON, "Choose another lesson", BLUE, SKYBLUE, WHITE);
            break;
        }
    }
    // Draw lesson specific content for the second icon
    else if (lesson == 2) {  
        switch (currentSlide) {
        case 1: {

            DrawTexture(_textures[5], BOARDX + 5, BOARDY + 25, WHITE);
            DrawTextEx(Renderer::GetInstance()->font, "Eukaryotic Cell", { BOARDX + (BOARD_WIDTH / 2) - 460 + 545, BOARDY + 25 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Eukaryote, any cell or", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 90 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "organism that possesses a", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 125 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "clearly defined nucleus.", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 160 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "The eukaryotic cell has a ", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 205 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "nuclear membrane that  ", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 245 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "surrounds the nucleus,  ", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 280 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "in which the well-defined   ", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 315 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "chromosomes are located.  ", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 355 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Eukaryotic cells also,", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 395 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "contain mitochondria, a", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 435 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Golgi apparatus,lysosomes ", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 475 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "etc. ", { BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 505 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(NEXT_BUTTON, "Next", BLUE, SKYBLUE, WHITE);

            break;
        }
        case 2: {
            DrawTextEx(Renderer::GetInstance()->font, "Question 1:", { BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105 }, 40, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Which of the these surrounds the nucleur?", { BOARDX + (BOARD_WIDTH / 2) - 460 - 10, BOARDY + 195 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A. Golgi apparatus", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. Lysosomes", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Nucleur Membrane ", BLUE, SKYBLUE, WHITE);
            break;
        }
        case 3:
            DrawTexture(_textures[6], BOARDX + 5, BOARDY + 205, WHITE);
            DrawTextEx(Renderer::GetInstance()->font, "Prokaryotic Cell", { BOARDX + (BOARD_WIDTH / 2) - 365, BOARDY + 55 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Prokaryotic cells are", { BOARDX + (BOARD_WIDTH / 2) + 10, BOARDY + 50 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "single-celled microorganisms", { BOARDX + (BOARD_WIDTH / 2) + 10, BOARDY + 85 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "that include Bacteria and", { BOARDX + (BOARD_WIDTH / 2) + 10, BOARDY + 125 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Archaea. A prokaryotic cell ", { BOARDX + (BOARD_WIDTH / 2) + 10, BOARDY + 170 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "does not have a", { BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 205 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "nuclear membrane. ", { BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 240 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "A prokaryotic cell", { BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 280 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "lacks, organelles", { BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 320 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "like: mitochondria, ", { BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 360 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "endoplasmic, and ", { BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 400 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "Golgi apparatus", { BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 440 }, 35, 5, WHITE_BOARD_TEXT_COLOR);

            DrawButton(NEXT_BUTTON, "Next", BLUE, SKYBLUE, WHITE);
            break;
        case 4:
            DrawTextEx(Renderer::GetInstance()->font, "Question 2:", { BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105 }, 40, 5, WHITE_BOARD_TEXT_COLOR);
            DrawTextEx(Renderer::GetInstance()->font, "What does not have a prokaryotic cell?", { BOARDX + (BOARD_WIDTH / 2) - 470, BOARDY + 195 }, 35, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A.  Nucleur Membrane", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. Mitochondria", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Lysosomes", BLUE, SKYBLUE, WHITE);
            break;
        default:
            DrawTextEx(Renderer::GetInstance()->font, "Lesson finished!", { BOARDX + (BOARD_WIDTH / 2) - 160, BOARDY + 250 }, 45, 5, WHITE_BOARD_TEXT_COLOR);
            DrawButton(RETURN_BUTTON, "Choose another lesson", BLUE, SKYBLUE, WHITE);
            break;
        }
    }
}

// Function to load a specific slide
void Biology::LoadSlide(){

    Rectangle lessonButton1 = { 300, screenHeight / 5, 613, 790 };
    Rectangle lessonButton2 = { screenWidth / 2, screenHeight / 5, 611, 812 };
    if (!lesson) {

        // Draw buttons for selecting lessons
        DrawTexture(_textures[1], 300, screenHeight / 5, WHITE);
        DrawTexture(_textures[2], screenWidth / 2, screenHeight / 5, WHITE); 

        // Check if lesson buttons are clicked
        if (CheckButtonClicked(lessonButton1)) {  
            lesson = 1;
            currentSlide = 1;
        }
        else if (CheckButtonClicked(lessonButton2)) {
            lesson = 2;
            currentSlide = 1;
        }
    }
    else {
        // Check which button should be displayed based on lesson and slide
        Rectangle nextButton = NEXT_BUTTON; 

        // Update next button for lesson 1
        if (lesson == 1) { 
            switch (currentSlide)
            {
            case 1:
                nextButton = NEXT_BUTTON;
                break;
            case 2:
                nextButton = BUTTON_B;
                break;
            case 3:
                nextButton = BUTTON_A;
                break;
            default:
                nextButton = RETURN_BUTTON;
                break;
            }
        }
        // Update next button for lesson 2
        if (lesson == 2) { 
            switch (currentSlide)
            {
            case 1:
                nextButton = NEXT_BUTTON;
                break;
            case 2:
                nextButton = BUTTON_C;
                break;
            case 3:
                nextButton = NEXT_BUTTON;
                break;
            case 4:
                nextButton = BUTTON_A;
                break;
            default:
                nextButton = RETURN_BUTTON;
                break;
            }
        }

        // Check if nextButton is clicked
        if (CheckButtonClicked(nextButton)) {

            // Check if last slide of lesson is reached
            if ((lesson == 1 && currentSlide == 4) || (lesson == 2 && currentSlide == 5)) 
            {
                currentSlide = 1;
                lesson = 0;
            }
            currentSlide++; 
        }
        StartLesson();
    }
}

bool Biology::CheckButtonClicked(Rectangle buttonRect)
{
    return CheckCollisionPointRec(GetMousePosition(), buttonRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Biology::setTextures(vector<Texture2D> textures)
{
    _textures = textures;
}
