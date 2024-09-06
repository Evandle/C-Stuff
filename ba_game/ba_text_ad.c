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
            return 0;
        case 'b':
            printf("%s%s\n", output, Hina->name);
            init_player(&*place_holder, &*Hina);
            return 0;
        case 'c':
            printf("%s%s\n", output, Hoshino->name);
            init_player(&*place_holder, &*Hoshino);
            return 0;
        case 'd':
            printf("%s%s\n", output, Arisu->name);
            init_player(&*place_holder, &*Arisu);
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
    system("cls");
    // Game loop condition
    bool isRunning = true;
    init_forest();
    char input;

    // Game start
    text("\"Purple Catalog\"");
    text("A game by Benedict\n");
    text("Kivotos has fallen, due to the GSC president going missing, the S.C.H.A.L.E's sensei getting comatose, and the actions of bad actors, Kivotos has been plunged in to anarchy.");
    text("During the attack of CROMA a huge spacial rift opened puling you in.");
    text("You have awoken in the middle of nowhere with only trees your eyes can see.");

    // Game loop
    while (1) {
        // Render the map (from map.c)
        render_map();
        // Get player input for movement
        input = _getch();  // Use _getch() to get single keypress without enter
        // Process input and move player (from map.c)
        if (input == 'q') {
            break;  // Quit the game
        }
        move_player(input);
        // Clear screen for the next frame
        system("cls");
    }

    player->hp -= (player->weapon.dmg + (player->weapon.dmg * player->multi) - player->def); // prototype attack
    display_student(&*player);

}


int main(void){
    // Game loop
    bool isRunning = true;

    // Declaring variables
    student Ichika, Hina, Hoshino, Arisu, player;
    weapon Enfield, MG42, shotgun, supernova;

    // Initializing weapons
    init_all_weapons(&Enfield, &MG42, &shotgun, &supernova);
    // Initializing students
    init_all_students(&Ichika, &Hina, &Hoshino, &Arisu, &Enfield, &MG42, &shotgun, &supernova);

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


