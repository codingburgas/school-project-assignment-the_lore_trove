#include "pch.h"
#include "framework.h"
#include "window.h"
#include "Biology.h"
#include <string>


Biology* Biology::instance = nullptr;

void DrawButton(Rectangle rect, const char* text, Color idleColor, Color hoverColor, Color textColor) {
    bool isHovered = CheckCollisionPointRec(GetMousePosition(), rect);

    if (isHovered) {
        DrawRectangleRec(rect, hoverColor);
    }
    else {
        DrawRectangleRec(rect, idleColor);
    }

    DrawText(text, rect.x + 40, rect.y + 20, 30, textColor);
}


void Biology::StartLesson()
{

  
    DrawTexture(_textures[3], 0, 0, WHITE);
    DrawRectangle(BOARDX, BOARDY, BOARD_WIDTH, BOARD_HEIGHT, WHITE_BOARD_MARGIN_COLOR);
    DrawRectangle(BOARDX + BORDER, BOARDY + BORDER, BOARD_WIDTH - (BORDER * 2), BOARD_HEIGHT - (BORDER * 2), WHITE_BOARD_COLOR);

    if (lesson == 1) {
        switch (currentSlide) {
        case 1:
            DrawTexture(_textures[4], BOARDX + 255, BOARDY + 15, WHITE);
            DrawText("The cell is the smallest unit that can live on its own and that makes up all ", BOARDX + (BOARD_WIDTH / 2) - 470, BOARDY + 400, 25, WHITE_BOARD_TEXT_COLOR);
            DrawText("living organisms and the issues of the body. A cell has three main parts: ", BOARDX + (BOARD_WIDTH / 2) - 470, BOARDY + 440, 25, WHITE_BOARD_TEXT_COLOR);
            DrawText("The cell membrane, The nucleus, and The cytoplasm. The powerhouse of", BOARDX + (BOARD_WIDTH / 2) - 470, BOARDY + 480, 25, WHITE_BOARD_TEXT_COLOR);
            DrawText("the cell is Mitohondria.", BOARDX + (BOARD_WIDTH / 2) - 125, BOARDY + 525, 25, WHITE_BOARD_TEXT_COLOR);
            DrawButton(NEXT_BUTTON, "Next", BLUE, SKYBLUE, WHITE);
            break;

        case 2:
            DrawText("Question 1:", BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105, 40, WHITE_BOARD_TEXT_COLOR);
            DrawText("Which of the following is from the main part of the cell?", BOARDX + (BOARD_WIDTH / 2) - 460 - 10, BOARDY + 195, 35, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A. Mitohandria", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. The Nucleus", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Membrane Receptor ", BLUE, SKYBLUE, WHITE);
            break;
        case 3:
            DrawText("Question 2:", BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105, 40, WHITE_BOARD_TEXT_COLOR);
            DrawText("What is the powerhouse of the cell?", BOARDX + (BOARD_WIDTH / 2) - 460 - 10, BOARDY + 195, 35, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A. Mitochondria", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. Nucleus", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Golgi Apparatus", BLUE, SKYBLUE, WHITE);
            break;
        default:
            DrawText("Lesson finished!", BOARDX + (BOARD_WIDTH / 2) - 160, BOARDY + 250, 45, WHITE_BOARD_TEXT_COLOR);
            DrawButton(RETURN_BUTTON, "Choose another lesson", BLUE, SKYBLUE, WHITE);
            break;
        }
    }
    else if (lesson == 2) {
        switch (currentSlide) {
        case 1:
        {
            DrawTexture(_textures[5], BOARDX + 5, BOARDY + 25, WHITE);
            DrawText("Eukaryotic Cell", BOARDX + (BOARD_WIDTH / 2) - 460 + 545, BOARDY + 25, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("Eukaryote, any cell or", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 90, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("organism that possesses a", BOARDX + (BOARD_WIDTH / 2) - 460  + 470, BOARDY + 125, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("clearly defined nucleus.", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 160, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("The eukaryotic cell has a ", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 205, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("nuclear membrane that  ", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 245, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("surrounds the nucleus,  ", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 280, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("in which the well-defined   ", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 315, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("chromosomes are located.  ", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 355, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("Eukaryotic cells also,", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 395, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("contain mitochondria, a", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 435, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("Golgi apparatus,lysosomes ", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 475, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("etc. ", BOARDX + (BOARD_WIDTH / 2) - 460 + 470, BOARDY + 505, 35, WHITE_BOARD_TEXT_COLOR);
            DrawButton(NEXT_BUTTON, "Next", BLUE, SKYBLUE, WHITE);

            break;
        }
        case 2: {
            DrawText("Question 1:", BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105, 40, WHITE_BOARD_TEXT_COLOR);
            DrawText("Which of the these surrounds the nucleur?", BOARDX + (BOARD_WIDTH / 2) - 460 - 10, BOARDY + 195, 35, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A. Golgi apparatus", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. Lysosomes", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Nucleur Membrane ", BLUE, SKYBLUE, WHITE);
            break;
        }
        case 3:
            DrawTexture(_textures[6], BOARDX + 5, BOARDY + 205, WHITE);
            DrawText("Prokaryotic Cell", BOARDX + (BOARD_WIDTH / 2) - 365, BOARDY + 55, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("Prokaryotic cells are", BOARDX + (BOARD_WIDTH / 2) + 10, BOARDY + 50, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("single-celled microorganisms", BOARDX + (BOARD_WIDTH / 2) + 10, BOARDY + 85, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("that include Bacteria and", BOARDX + (BOARD_WIDTH / 2) +10, BOARDY + 125, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("Archaea. A prokaryotic cell ", BOARDX + (BOARD_WIDTH / 2) + 10, BOARDY + 170, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("does not have a", BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 205, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("nuclear membrane. ", BOARDX + (BOARD_WIDTH / 2) + 140 , BOARDY + 240, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("A prokaryotic cell", BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 280, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("lacks, organelles", BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 320, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("like: mitochondria, ", BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 360, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("endoplasmic, and ", BOARDX + (BOARD_WIDTH / 2)  + 140, BOARDY + 400, 35, WHITE_BOARD_TEXT_COLOR);
            DrawText("Golgi apparatus", BOARDX + (BOARD_WIDTH / 2) + 140, BOARDY + 440, 35, WHITE_BOARD_TEXT_COLOR);

            DrawButton(NEXT_BUTTON, "Next", BLUE, SKYBLUE, WHITE);
            break;
        case 4:
            DrawText("Question 2:", BOARDX + (BOARD_WIDTH / 2) - 460, BOARDY + 105, 40, WHITE_BOARD_TEXT_COLOR);
            DrawText("What does not have a prokaryotic cell?", BOARDX + (BOARD_WIDTH / 2) -  470, BOARDY + 195, 35, WHITE_BOARD_TEXT_COLOR);
            DrawButton(BUTTON_A, "A.  Nucleur Membrane", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_B, "B. Mitochondria", BLUE, SKYBLUE, WHITE);
            DrawButton(BUTTON_C, "C. Lysosomes", BLUE, SKYBLUE, WHITE);
            break;
        default:
            DrawText("Lesson finished!", BOARDX + (BOARD_WIDTH / 2) - 160, BOARDY + 250, 45, WHITE_BOARD_TEXT_COLOR);
            DrawButton(RETURN_BUTTON, "Choose another lesson", BLUE, SKYBLUE, WHITE);
            break;
        }
    }

}

void Biology::LoadSlide()
{
    Rectangle lessonButton1 = { 300, screenHeight / 5, 613, 790 };
    Rectangle lessonButton2 = { screenWidth / 2, screenHeight / 5, 611, 812 };
    if (!lesson) {
        
        DrawTexture(_textures[1], 300, screenHeight / 5, WHITE);
        DrawTexture(_textures[2], screenWidth / 2, screenHeight / 5, WHITE);

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
        Rectangle nextButton = NEXT_BUTTON;

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


        if (CheckButtonClicked(nextButton)) {

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
