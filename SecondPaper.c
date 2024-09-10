#include <conio.h>
#include <windows.h>

const int FRAME_RATE = 30; // Target frame rate
const int FRAME_TIME = 1000 / FRAME_RATE; // Time per frame in milliseconds

while (isRunning) {
    // Start timing for frame rate control
    DWORD start_time = GetTickCount();

    // Render the map (from map.c)
    render_view();

    // Check for player input without blocking
    if (_kbhit()) {
        input = _getch();  // Use _getch() to get single keypress without enter
        if (input == 'q') {
            // Quit the map
            isRunning = 0;
        } else {
            move_player(input);
        }
    }

    // Clear screen for the next frame
    system("cls");

    // Frame rate control
    DWORD end_time = GetTickCount();
    DWORD elapsed_time = end_time - start_time;
    if (elapsed_time < FRAME_TIME) {
        Sleep(FRAME_TIME - elapsed_time); // Sleep to maintain frame rate
    }
}