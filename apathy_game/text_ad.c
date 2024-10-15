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

#define MAX_IMAGES 5
#define TARGET_FPS 4
#define FRAME_TIME 250 // in milliseconds


int character_select(char* prompt, char* valid_inputs, student* DM_Evandle, student* BM_Evandle, student* K_Evandle, student* ME_Evandle, char* output, student* place_holder);
void prologue(student* player, npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, image* EF1);
int init_player(student* place_holder, student* student);

// clear the console
void clear_console() {
    // Use ANSI escape codes for clearing the console
    system("cls"); 
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

void move1(image* img, int count) {
    const char* images[MAX_IMAGES] = { img->img1, img->img2, img->img3, img->img4, img->img5};
    printf("%s\n", images[count]);
}

// Function to check for critical hit and stun
void check_combat_effects(float crit_chance, float stun_chance) {
    // Initialize random number generator
    srand(time(0));

    // Generate a random number between 0 and 1 for crit and stun chances
    float crit_roll = rand() % 100;
    float stun_roll = rand() % 100;

    // Check for critical hit
    if (crit_roll < crit_chance) {
        if (stun_roll < stun_chance) {
            
        } else {

        }
    } else {
        if (stun_roll < stun_chance) {

        } else {

        }
    }
}



int battle_dice(int dice_power) {
    srand(time(0));
    int dice = rand() % dice_power;

    return dice;
}

void spell_select_shift(student* temp, spell* spell){
    temp->skills.spell1 = *spell;
}

void player_spell_select(student* player, student* temp) {
    
    char input;
    while (1) {
        scanf(" %c", &input);
        switch (tolower(input)) {  // Switch on the first character of input gcc -Wall text_ad.c data.c map.c -o game
            case 'a':
                spell_select_shift(temp, &player->skills.spell1);
                break;
            case 'b':
                spell_select_shift(temp, &player->skills.spell2);
                break;
            case 'c':
                spell_select_shift(temp, &player->skills.spell3);
                break;
            case 'd':
                spell_select_shift(temp, &player->skills.spell4);
                break;
            case 'e':
                spell_select_shift(temp, &player->skills.spell5);
                break;
            case 'f':
                spell_select_shift(temp, &player->skills.spell6);
                break;
            case 'g':
                spell_select_shift(temp, &player->skills.spell7);
                break;
            case 'h':
                spell_select_shift(temp, &player->skills.spell8);
                break;
            case 'u':
                spell_select_shift(temp, &player->skills.ult);
                break;
            default:
                printf("Invalid choice. Please select a valid spell.\n");
                continue;
        }
        break;  // Break the loop once a valid spell is selected
    }
}

void dice_clash(student* player, npc* enemy, student* temp, npc* npctemp, int* is_stun, int* npc_is_stun) {

    int chooser = rand() % 3;
    if (chooser == 0) npctemp->skills.spell1 = enemy->skills.spell1;
    else if (chooser == 1) npctemp->skills.spell1 = enemy->skills.spell2;
    else if (chooser == 2) npctemp->skills.spell1 = enemy->skills.spell3;
    // make the dice power roller for spells
    // dont forget, its can get buggy, change the ifs value to rolls value
    int player_dice = (rand() % temp->skills.spell1.spell_power) + player->weapon.dmg;
    int npc_dice = (rand() % npctemp->skills.spell1.spell_power) + enemy->weapon.dmg;

    // check for hit
    int hit_chance = rand() % 100;
    int is_hit = (hit_chance < temp->skills.spell1.accuracy);
    int npc_is_hit = (hit_chance < npctemp->skills.spell1.accuracy);

    // Check for critical hit (e.g., 10% chance)
    int crit_chance = rand() % 100;
    int is_crit = (crit_chance < temp->skills.spell1.critchance);  // 10% chance for crit
    int npc_is_crit = (crit_chance < npctemp->skills.spell1.critchance);

    // Check for stun (e.g., 15% chance)
    int stun_chance = rand() % 100;
    if (temp->skills.spell1.stunchance != 0){
        
        if ((stun_chance < temp->skills.spell1.stunchance)) *is_stun = temp->skills.spell1.stunduration;
    } 
    if (npctemp->skills.spell1.stunchance != 0){
        
        if ((stun_chance < npctemp->skills.spell1.stunchance)) *npc_is_stun = npctemp->skills.spell1.stunduration;
    }

    clear_console();
    printf("        <%s>        |        <%s>        \n\n", temp->skills.spell1.name, npctemp->skills.spell1.name);
    draw_dice_animation(player_dice, npc_dice);
    Sleep(1000);

    if (player_dice >= npc_dice && is_hit && *npc_is_stun <= 0) {
    // Apply critical hit multiplier (e.g., 2x damage)
        if (is_crit) {
            player_dice *= temp->skills.spell1.critdamage;  // Critical hit for player
            printf("| Critical dmg by the %s!\n", player->name);
            Sleep(1000);
        }
        if (((player_dice + (player_dice * player->multi)) - enemy->def) >= 0) {
            enemy->hp -= ((player_dice + (player_dice * player->multi)) - enemy->def);
        }
    }

    if (player_dice <= npc_dice && npc_is_hit && *is_stun <= 0) {
        // Apply critical hit multiplier (e.g., 2x damage)
        if (npc_is_crit) {
            npc_dice *= npctemp->skills.spell1.critdamage; 
            printf("| Critical dmg by the %s!\n", enemy->name);
            Sleep(1000);
        }
        if ((npc_dice - player->def) >= 0) {    
            player->hp -= ((npc_dice) - player->def);
        }
    }

    if (is_hit == 0) {
        printf("| %s missed\n", player->name);
        Sleep(1000);
    } 
    if (npc_is_hit == 0) {
        printf("| %s missed\n", enemy->name);
        Sleep(1000);
    }  

    if (*npc_is_stun > 0) {
        printf("| Evandle is stunned for %d turns\n", *npc_is_stun);
        Sleep(1000);
        (*npc_is_stun)--;
    }
    if (*is_stun > 0) {
        printf("| Enemy is stunned for %d turns\n", *is_stun);
        Sleep(1000);
        (*is_stun)--;
    }

}

void input_control( int input,student* player, npc* enemy, student* temp, npc* npctemp, int* is_stun, int* npc_is_stun) {
    switch (tolower(input)) {
        case 'a' : {
            display_skills(player);
            player_spell_select(player, temp);
            dice_clash(player, enemy, temp, npctemp, is_stun, npc_is_stun);
            input = 'X';
            break;
            }
        case 't' : input = 'X'; break;
        case 'r' : input = 'X'; break;
        case 'i' : input = 'X'; break;
        default: break;
    }
}

// battle loop, is in another loop
void init_battle(student* player, npc* enemy, npc* Enemy1, npc* Enemy2, npc* Enemy3) {
    clear_console();
    
    int count = 0, is_stun = 0, npc_is_stun = 0;
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
            student temp;
            npc npctemp;
            last_time = current_time; // Reset the timer

            // Clear the screen and redraw everything
            clear_console();
            //int pdice = battle_dice(player->skills.spell1.spell_power);
            //int edice = battle_dice(enemy->skills.spell1.spell_power);
            //dice_clash(pdice, edice);
            draw_ui(player, enemy);
            printf("%s", enemy->img.img1);
            printf("%s", player->img.img1);
            draw_gui();
            input = _getch();
            input_control(input, player, enemy, &temp, &npctemp, &is_stun, &npc_is_stun);
            


            printf("%ld", current_time);
            // Here you can add input handling and other game logic
            // For example:
            // scanf(" %c", &input);
            // handle_input(input, player, enemy);
            count = (count + 1) % MAX_IMAGES;
            if (player->hp <= 0 || enemy->hp <= 0) {
                clear_console();
                break;
            }
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
    printf("%s", place_holder->img.img1);
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

    imgtext("I jolted awake as I experienced the nauseating feeling of free falling.", EF1->img1);
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
        printf("\033[H\033[J"); // clears screen with less lag but looks ass
        if (player->hp <= 0){
            break;
        }
    }
    text("Continuing execution after pressing 'q1'.\n");
    printf("Continuing execution after pressing 'q1'.\n");
    printf("Continuing execution after pressing 'q11'.\n");
}


int main(void){
    clear_console();
    // Declaring variables  gcc -Wall text_ad.c data.c map.c -o Apathy.exe -lwinmm
    student DM_Evandle, BM_Evandle, K_Evandle, ME_Evandle, player;
    weapon Vandella_Doll, Blue_Regalia, Logic, Wisdom_Cube, natural_weapon;
    npc enemy, Nightmare, LostOne, Slime, Overlord, Terror, Mystic;
    stat DM_stat, BM_stat, K_stat, ME_stat;
    level Standard_level;
    spell basic_attack, tenticle_grab, seed_of_doubt, black_lightning, corrupting_touch, vore, devour;
    spell doll_slash, doll_artillery, doll_blast, doll_dance;
    spell precise_strike, energy_burst, cryo_phenix_blast, blades_of_finality;
    spell sisterhood_style, common_sense, mana_burst, domain_of_stagnation;
    spell optimized_ice, energy_snipe, heart_of_ice, cube_of_wonder;
    skills DM_skills, BM_skills, K_skills, ME_skills, NIGH_npc_skills, LOST_npc_skills, SLIM_npc_skills;
    image EF1, Althea_big, Althea_smol, Nightmare_icon, LostOne_icon, Slime_icon;

    init_all_images(&EF1, &Althea_big, &Althea_smol, &Nightmare_icon, &LostOne_icon, &Slime_icon);
    init_all_weapons(&Vandella_Doll, &Blue_Regalia, &Logic, &Wisdom_Cube, &natural_weapon);
    init_all_stats(&DM_stat, &BM_stat, &K_stat, &ME_stat);
    init_all_levels(&Standard_level);
    init_all_spells(&basic_attack, &doll_slash, &doll_artillery, &doll_blast, &doll_dance, &precise_strike, &energy_burst, &cryo_phenix_blast, &blades_of_finality, &sisterhood_style, &common_sense, &mana_burst, &domain_of_stagnation, &optimized_ice, &energy_snipe, &heart_of_ice, &cube_of_wonder
        , &tenticle_grab, &seed_of_doubt, &black_lightning, &corrupting_touch, &vore, &devour);
    init_standard_skills(&DM_skills, &BM_skills, &K_skills, &ME_skills, &NIGH_npc_skills, &LOST_npc_skills, &SLIM_npc_skills, &basic_attack, &doll_slash, &doll_artillery, &doll_blast, &doll_dance, &precise_strike, &energy_burst, &cryo_phenix_blast, &blades_of_finality, &sisterhood_style, &common_sense, &mana_burst, &domain_of_stagnation, &optimized_ice, &energy_snipe, &heart_of_ice, &cube_of_wonder
        , &tenticle_grab, &seed_of_doubt, &black_lightning, &corrupting_touch, &vore, &devour);
    init_all_npcs(&enemy, &Nightmare, &LostOne, &Slime, &Overlord, &Terror, &Mystic, &NIGH_npc_skills, &LOST_npc_skills, &SLIM_npc_skills, &Standard_level, &natural_weapon, &Nightmare_icon, &LostOne_icon, &Slime_icon);
    init_all_students(&DM_Evandle, &BM_Evandle, &K_Evandle, &ME_Evandle, &DM_stat, &BM_stat, &K_stat, &ME_stat, &DM_skills, &BM_skills, &K_skills, &ME_skills, &Vandella_Doll, &Blue_Regalia, &Logic, &Wisdom_Cube, &Standard_level, &Althea_smol);

    // Choose your character.
    play_music();
    char List_Choice[] = {'a', 'b', 'c', 'd', '\0'};
    character_select("Who do you want to play as?\n\na: Evandle(Doll Maker)    c: Evandle(Knight)\nb: Evandle(Battle Dress)    d: Evandle(Mana Engineer)", List_Choice,
    &DM_Evandle, &BM_Evandle, &K_Evandle, &ME_Evandle, "You have choosen ", &player
    );
    srand(time(0));
    display_student(&player);
    text("");
    // Prologue
    prologue(&player, &enemy, &Nightmare, &LostOne, &Slime, &EF1);
    printf("Returned from prologue, continuing main...\n"); // Debug print
    printf("Continuing execution after pressing 'q2'.\n");
    printf("Continuing execution after pressing 'q2'.\n");
    return 0;
}


