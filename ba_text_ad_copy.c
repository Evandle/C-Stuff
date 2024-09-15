#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "student.h"
#include "map.h"

int character_select(char* prompt, char* valid_inputs, student* Ichika, student* Hina, student* Hoshino, student* Arisu, char* output, student* place_holder);
int prologue(student* player);
int init_player(student* place_holder, student* student);


int text(char* text){
    printf("%s\n", text);
    while (getchar() != '\n');
    return 0;
}
int imgtext(char* text, char* img){
    printf("%s\n", img);
    while (getchar() != '\n');
    printf("%s\n", text);
    while (getchar() != '\n');
    return 0;
}

// Character select function
int character_select(char* prompt, char* valid_inputs, student* Ichika, student* Hina, student* Hoshino, student* Arisu, char* output, student* place_holder){
    char user_input[3];
    do {
        printf("%s\n\n: ", prompt);
        if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
            user_input[strcspn(user_input, "\n")] = '\0';

            // Convert user input to lowercase for case-insensitive matching.
            for (int i = 0; user_input[i] != '\0'; i++) {
                user_input[i] = tolower(user_input[i]);
            }

            // Check if the user input is valid
            if (user_input[0] == '\0' || strchr(valid_inputs, user_input[0]) == NULL) {
                printf("Invalid input. Please try again.\n");
            }
        } 
        else {
            printf("Invalid input. Please try again.\n");
        }
    } while (strchr(valid_inputs, user_input[0]) == NULL);
    switch (user_input[0]) {
        case 'a':
            printf("%s%s\n", output, Ichika->name);
            init_player(&*place_holder, &*Ichika);
            ichika_image();
            return 0;
        case 'b':
            printf("%s%s\n", output, Hina->name);
            init_player(&*place_holder, &*Hina);
            hina_image();
            return 0;
        case 'c':
            printf("%s%s\n", output, Hoshino->name);
            init_player(&*place_holder, &*Hoshino);
            hoshino_image();
            return 0;
        case 'd':
            printf("%s%s\n", output, Arisu->name);
            init_player(&*place_holder, &*Arisu);
            arisu_image();
            return 0;
        default:
            // Handle unexpected input (shouldn't happen)
            return 1;
    }
}

int init_player(student* place_holder, student* student) {
    strcpy(place_holder->name, student->name);
    strcpy(place_holder->school, student->name);
    place_holder->hp = student->hp;
    place_holder->def = student->def;
    place_holder->multi = student->multi;
    place_holder->weapon = student->weapon;
    place_holder->level = student->level;
    return 0;
}

// Start of the game
int prologue(student* player){
    clear_console("cls");
    // Game loop condition
    bool isRunning = true;
    int battle_count;
    image EF1;

    init_all_images(&EF1);
    init_forest();
    char input;

    // Game start
    text("\"Apathy\"");
    text("A game by Benedict\n");
    clear_console("cls");

    imgtext("I jolted awake as I experienced the nauseating feeling of free falling.", EF1.img);
    text("I blankly stared at the starless night sky, it was pretty in an unnerving sort of way. I wonder how I got here, the last thing I remembered was...");
    text("Going on a ship with my classmates to participate in a tournament... A pirate attack and the eventual ship reck on an unknown island... There was somehow human made stuctures there...");
    text("A fight with a strange cult... And then an explosion...");
    text("'Huh, who would have thought that the portal looking structure was actually a portal how silly of me.'");
    text("'It's not like I where aiming for the dam thing, but that hooded asshole was just in front of it.'");
    text("Now that I'm fully awake gravity of the situation finally kicked in my nausea addled head.");
    text("'Oh fuck!'");
    clear_console("cls");

    text("Pain rattled through my entire body as I crash through multiple leaves, branches, and finally a thick bush. Luckily I manged to cast a levitation spell in time to reduce the force of my fall.");
    text("'What the heck. That hurt allot, now where am I?'");
    text("As I looked around all I see was darkness and dense trees, and a creeping feeling of eyes watching me.");
    clear_console("cls");
    // Game loop
    while (isRunning) {
        // Render the map (from map.c)
        render_map();
        // Get player input for movement
        input = _getch();  // Use _getch() to get single keypress without enter
        // Process input and move player (from map.c)
        if (input == 'q') {
            clear_console("cls");
            isRunning = 0;  // Quit the map
        }
        move_player(input);
        // Clear screen for the next frame
        clear_console("cls");
    }
    player->hp -= (player->weapon.dmg + (player->weapon.dmg * player->multi) - player->def); // prototype attack
    display_student(&*player);
    text("A game by Benedict\n");
    return 0;
}


int main(void){
    // Game loop
    bool isRunning = true;

    // Declaring variables
    student Ichika, Hina, Hoshino, Arisu, player;
    weapon Enfield, MG42, shotgun, supernova;
    npc enemy, Nightmare, LostOne, Slime, Overlord, Terror, Mystic;
    

    // Initializing weapons
    init_all_weapons(&Enfield, &MG42, &shotgun, &supernova);
    // Initializing students
    init_all_students(&Ichika, &Hina, &Hoshino, &Arisu, &Enfield, &MG42, &shotgun, &supernova);
    // Initializing
    init_all_npcs(&enemy, &Nightmare, &LostOne, &Slime, &Overlord, &Terror, &Mystic, &Enfield);

    

    // Choose your character.
    char List_Choice[] = {'a', 'b', 'c', 'd', '\0'};
    character_select("Who do you want to play as?\n\na: Ichika    c: Hoshino\nb: Hina    d: Arisu", List_Choice,
    &Ichika, &Hina, &Hoshino, &Arisu, "You have choosen ", &player
    );
    display_student(&player);
    text("");

    // Prologue
    prologue(&player);


    return 0;
}


