#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET_FPS 60
#define FRAME_TIME (1000 / TARGET_FPS) // in milliseconds

void init_battle(student* player, npc* enemy, npc* Enemy1, npc* Enemy2, npc* Enemy3) {
    clear_console("cls");
    srand(time(0));
    char input;
    int chooser = rand() % 3; // for random enemy
    if (chooser == 0) *enemy = *Enemy1;
    else if (chooser == 1) *enemy = *Enemy2;
    else if (chooser == 2) *enemy = *Enemy3;

    clock_t last_time = clock();
    while (1) {
        // Calculate the elapsed time
        clock_t current_time = clock();
        double elapsed_time = (double)(current_time - last_time) * 1000.0 / CLOCKS_PER_SEC;

        // Update the game state if enough time has passed
        if (elapsed_time >= FRAME_TIME) {
            last_time = current_time; // Reset the timer

            // Clear the screen and redraw everything
            clear_console("cls");
            printf("%s", enemy->img.img);
            printf("%s", player->img.img);
            draw_gui();

            // Here you can add input handling and other game logic
            // For example:
            // scanf(" %c", &input);
            // handle_input(input, player, enemy);
        }
    }
}