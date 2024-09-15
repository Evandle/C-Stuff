#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 
#include <windows.h>

#include "data.h"
#include "map.h"

#define TARGET_FPS 4
#define FRAME_TIME 250 // in milliseconds


int character_select(char* prompt, char* valid_inputs, student* DM_Evandle, student* BM_Evandle, student* K_Evandle, student* ME_Evandle, char* output, student* place_holder);
void prologue(student* player, npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, image* EF1);
int init_player(student* place_holder, student* student);

void clear_console() {
    // Use ANSI escape codes for clearing the console
    printf("\033[H\033[J");
}

int text(const char* text){
    printf("%s\n", text);
    while (getchar() != '\n');
    return 0;
}
int imgtext(const char* text, const char* img){
    printf("%s\n", img);
    while (getchar() != '\n');
    printf("%s\n", text);
    while (getchar() != '\n');
    return 0;
}

// battle loop, is in another loop
void init_battle(student* player, npc* enemy, npc* Enemy1, npc* Enemy2, npc* Enemy3) {
    clear_console("cls");
    srand(time(0));
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
            printf("%ld", current_time);
            // Here you can add input handling and other game logic
            // For example:
            // scanf(" %c", &input);
            // handle_input(input, player, enemy);
        }
    }
}


char check_tile(char check, student* player, npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime) {
    switch (check) {
        case 'X': init_battle(&*player, &*enemy, &*Nightmare, &*LostOne, &*Slime);
        case 'O': return 'O';
        default: return 'E';
    }
}

void handle_character_selection(char choice, student* selected_student, student* place_holder, char* output) {
    printf("%s%s\n", output, selected_student->name);
    init_player(place_holder, selected_student);
    printf("%s", place_holder->img.img);
}

int character_select(char* prompt, char* valid_inputs, student* DM_Evandle, student* BM_Evandle, student* K_Evandle, student* ME_Evandle, char* output, student* place_holder) {
    char user_input[3];
    do {
        printf("%s\n\n: ", prompt);
        if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
            user_input[strcspn(user_input, "\n")] = '\0'; // Remove newline
            // Convert user input to lowercase for case-insensitive matching.
            for (int i = 0; user_input[i] != '\0'; i++) {
                user_input[i] = tolower(user_input[i]);
            }
            // Check if the user input is valid
            if (user_input[0] == '\0' || strchr(valid_inputs, user_input[0]) == NULL) {
                printf("Invalid input. Please try again.\n");
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    } while (strchr(valid_inputs, user_input[0]) == NULL);
    switch (user_input[0]) {
        case 'a': handle_character_selection('a', DM_Evandle, place_holder, output); break;
        case 'b': handle_character_selection('b', BM_Evandle, place_holder, output); break;
        case 'c': handle_character_selection('c', K_Evandle, place_holder, output); break;
        case 'd': handle_character_selection('d', ME_Evandle, place_holder, output); break;
        default: return 1; // Handle unexpected input (shouldn't happen)
    }
    return 0;
}

int init_player(student* place_holder, student* student) {
    *place_holder = *student; // Copy all fields at once
    return 0;
}


// Start of the game, this game is supposed to be played on the code editor's terminal
void prologue(student* player, npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, image* EF1){
    clear_console();

    init_forest(400, 20);
    char input;

    // Game start
    text("\"Apathy\"");
    text("A game by Benedict\n");
    clear_console();

    imgtext("I jolted awake as I experienced the nauseating feeling of free falling.", EF1->img);
    // Prologue text
    char* prologueText1[] = {
        "I blankly stared at the starless night sky, it was pretty in an unnerving sort of way. I wonder how I got here, the last thing I remembered was...",
        "Going on a ship with my classmates to participate in a tournament... A pirate attack and the eventual ship wreck on an unknown island... There were somehow human-made structures there...",
        "A fight with a strange cult... And then an explosion...",
        "'Huh, who would have thought that the portal looking structure was actually a portal how silly of me.'",
        "'It's not like I was aiming for the damn thing, but that hooded asshole was just in front of it.'",
        "Now that I'm fully awake gravity of the situation finally kicked in my nausea-addled head.",
        "'Oh fuck!'"
    };
        for(int i = 0; i < sizeof(prologueText1) / sizeof(prologueText1[0]); i++) {
        text(prologueText1[i]);
        
    }
    clear_console();
    char* prologueText2[] = {
        "Pain rattled through my entire body as I crash through multiple leaves, branches, and finally a thick bush. Luckily I managed to cast a levitation spell in time to reduce the force of my fall.",
        "'What the heck. That hurt a lot, now where am I?'",
        "As I looked around all I see was darkness and dense trees, and a creeping feeling of eyes watching me.",
        "Pain rattled through my entire body as I crash through multiple leaves, branches, and finally a thick bush. Luckily I manged to cast a levitation spell in time to reduce the force of my fall.",
        "'What the heck. That hurt allot, now where am I?'",
        "As I looked around all I see was darkness and dense trees, and a creeping feeling of eyes watching me."
    };
    for(int i = 0; i < sizeof(prologueText2) / sizeof(prologueText2[0]); i++) {
        text(prologueText2[i]);
        
    }
    clear_console();
    // Game loop   here for now player->hp -= (player->weapon.dmg + (player->weapon.dmg * player->multi) - player->def); // prototype attack
    while (1) {
        render_view();
        input = _getch(); // Get player input for movement
        if (input == 'q') {
            break; // Exit the loop
        } else {
            check_tile(move_player(input), &*player, &*enemy, &*Nightmare, &*LostOne, &*Slime); // Move player based on input
        }
        clear_console();
    }
    text("Continuing execution after pressing 'q1'.\n");
    printf("Continuing execution after pressing 'q1'.\n");
    printf("Continuing execution after pressing 'q11'.\n");
}


int main(void){
    // Declaring variables
    student DM_Evandle, BM_Evandle, K_Evandle, ME_Evandle, player;
    weapon Enfield, MG42, shotgun, supernova;
    npc enemy, Nightmare, LostOne, Slime, Overlord, Terror, Mystic;
    stat DM_stat, BM_stat, K_stat, ME_stat;
    level Standard_level;
    spell basic_attack;
    image EF1, Althea_big, Althea_smol, Nightmare_icon, LostOne_icon, Slime_icon;

    init_all_images(&EF1, &Althea_big, &Althea_smol, &Nightmare_icon, &LostOne_icon, &Slime_icon);
    init_all_weapons(&Enfield, &MG42, &shotgun, &supernova);
    init_all_students(&DM_Evandle, &BM_Evandle, &K_Evandle, &ME_Evandle, &Enfield, &MG42, &shotgun, &supernova, &Standard_level, &Althea_smol);
    init_all_npcs(&enemy, &Nightmare, &LostOne, &Slime, &Overlord, &Terror, &Mystic, &Standard_level, &Enfield, &Nightmare_icon, &LostOne_icon, &Slime_icon);
    init_all_stats(&DM_stat, &BM_stat, &K_stat, &ME_stat);
    init_all_levels(&Standard_level);
    init_all_spells(&basic_attack);


    // Choose your character.
    char List_Choice[] = {'a', 'b', 'c', 'd', '\0'};
    character_select("Who do you want to play as?\n\na: Evandle(Doll Maker)    c: Evandle(Knight)\nb: Evandle(Battle Dress)    d: Evandle(Mana Engineer)", List_Choice,
    &DM_Evandle, &BM_Evandle, &K_Evandle, &ME_Evandle, "You have choosen ", &player
    );
    
    display_student(&player);
    text("");
    // Prologue
    prologue(&player, &enemy, &Nightmare, &LostOne, &Slime, &EF1);
    printf("Returned from prologue, continuing main...\n"); // Debug print
    printf("Continuing execution after pressing 'q2'.\n");
    printf("Continuing execution after pressing 'q2'.\n");
    return 0;
}


