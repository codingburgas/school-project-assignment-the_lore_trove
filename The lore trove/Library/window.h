#pragma once

#define screenWidth 1920
#define screenHeight 1080
#define BOARD_WIDTH 1000
#define BOARD_HEIGHT 590
#define BORDER 5
#define BOARDX (screenWidth / 2) - BOARD_WIDTH / 2 // = 540 - 355 = 185
#define BOARDY (screenHeight / 2) - BOARD_HEIGHT / 2// 360 - 230 = 130
// Buttons
#define START_BUTTON {BOARDX + BOARD_WIDTH / 2 - 95, BOARDY + BOARD_HEIGHT - 225, 165, 80} // WIDHT 400
#define NEXT_BUTTON {BOARDX + 800 , BOARDY + BOARD_HEIGHT - 70, 165, 55}
#define BUTTON_A {280, 370, 420, 50}
#define BUTTON_B {280, 470, 420, 50}
#define BUTTON_C {280, 570, 420, 50}
// Colors
#define BLACK_BOARD_COLOR { 56, 68, 85, 255}
#define WHITE_BOARD_MARGIN_COLOR { 0, 0, 0, 255}
#define WHITE_BOARD_COLOR { 255, 255, 255, 255}
#define WHITE_BOARD_TEXT_COLOR {  0, 0, 0, 255 }




// Text

#define TITLE "Biology Lesson and a mini test about the Cell" 
