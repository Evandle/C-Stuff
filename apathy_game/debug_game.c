#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_NAME_LENGTH 100
#define MAX_DESC_LENGTH 256
#define MAX_IMAGES 5
#define TARGET_FPS 4
#define FRAME_TIME 250 


#ifndef DATA_H
#define DATA_H


// Define the student struct

typedef enum {
    NONE = 0,
    STUN,
    CRIT
} statuseffect;
typedef struct {
    char name[100];
    char* img1;
    char* img2;
    char* img3;
    char* img4;
    char* img5;
} image;

typedef struct {
    int vit;
    int end;
    int mana;
    int intelligence;
    int agility;
    int luck;
    int insight;
    int corruption;
    int sanity;
} stat;

typedef struct {
    int level;
    int xpcap;
    float xpcapmultiplier;
    float hpmultiplier;
    float defenseMultiplier;
    float intelligenceMultiplier;
    float manamultiplier;
} level;

typedef struct {
    char name[100];
    char desc[256];
    int spell_power;
    int accuracy;
    int cooldown;
    int cost;
    int critchance;
    int critdamage;
    int stunchance;
    int stunduration;
    int corruption;
    int sanity;
} spell;

typedef struct {
    spell spell1;
    spell spell2;
    spell spell3;
    spell spell4;
    spell spell5;
    spell spell6;
    spell spell7;
    spell spell8;
    spell ult;
} skills;

typedef struct {
    char name[100];
    char desc[256];
    char rarity[100];
    int dmg;
    int dropchance;
} weapon;

typedef struct {
    char name[100];
    char course[100];
    int hp;
    int def;
    float multi;
    weapon weapon;
    level level;
    int xp;
    stat stats;
    skills skills;
    image img;
    // Add other fields as needed
} student;

typedef struct {
    char name[100];
    char desc[256];
    int hp;
    int def;
    weapon weapon;
    level level;
    int xp_drop;
    float lvl_multi;
    skills skills;
    image img;
} npc;



void free_image(image* imgStruct);

void draw_gui();

void ichika_image();

void hina_image();

void hoshino_image();

void arisu_image();


// Init for objects and characters
void init_stat(stat* s, int vit, int end, int mana, int intelligence, int agility, int luck, int insight, int corruption, int sanity);

void display_stat(stat* s);

void init_all_stats(stat* DM_stat, stat* BM_stat, stat* K_stat, stat* ME_stat);

void init_level(level* l, int level, int xpcap, float xpcapmultiplier, float hpmultiplier, float defenseMultiplier, float intelligenceMultiplier, float manamultiplier);

void display_level(level* l);

void init_all_levels(level* Standard_level);

void init_spell(spell* s, const char* name, const char* desc, int spell_power, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration);

void init_npc_spell(spell* s, const char* name, const char* desc, int spell_power, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration, int corruption, int sanity);

void display_spell(spell* s);

void init_all_spells(spell* basic_attack, spell* doll_slash, spell* doll_artillery, spell* doll_blast, spell* doll_dance, spell* precise_strike, spell* energy_burst, spell* cryo_phenix_blast, spell* blades_of_finality, spell* sisterhood_style, spell* common_sense, spell* mana_burst, spell* domain_of_stagnation, spell* optimized_ice, spell* energy_snipe, spell* heart_of_ice, spell* cube_of_wonder, spell* tenticle_grab, spell* seed_of_doubt, spell* black_lightning, spell* corrupting_touch, spell* vore, spell* devour);

void init_skills(skills* s, spell* spell1, spell* spell2, spell* spell3, spell* ult);

void init_npc_skills(skills* s, spell* spell1, spell* spell2, spell* spell3);

void display_skills(student* s);

void init_standard_skills(skills* DM_skills, skills* BM_skills, skills* K_skills, skills* ME_skills, skills* NIGH_npc_skills, skills* LOST_npc_skills, skills* SLIM_npc_skills, spell* basic_attack, spell* doll_slash, spell* doll_artillery, spell* doll_blast, spell* doll_dance, spell* precise_strike, spell* energy_burst, spell* cryo_phenix_blast, spell* blades_of_finality, spell* sisterhood_style, spell* common_sense, spell* mana_burst, spell* domain_of_stagnation, spell* optimized_ice, spell* energy_snipe, spell* heart_of_ice, spell* cube_of_wonder, spell* tenticle_grab, spell* seed_of_doubt, spell* black_lightning, spell* corrupting_touch, spell* vore, spell* devour);

// Init images
void init_image(image* img, char* name, char* img1, char* img2, char* img3, char* img4, char* img5);

void init_all_images(image* EF1, image* Althea_big, image* Althea_smol, image* Nightmare_icon, image* LostOne_icon, image* Slime_icon);

void init_weapon(weapon* w, const char* name, const char* desc, int dmg, int dropchance);

void display_weapon(weapon* w);

void init_student(student* s, const char* name, const char* course, int hp, int def, float multi, weapon* weapon, level* level, int xp, stat* stats, skills* skills, image* img);

void display_student(student* s);

void init_npc(npc* n, char* name, char* desc, int hp, int def, weapon* weapon, level* level, int xp_drop, skills* skills, image* img);

void display_npc(npc* n);

void init_all_weapons(weapon* Vandella_Doll, weapon* Blue_Regalia, weapon* Logic, weapon* Wisdom_Cube, weapon* natural_weapon);

void init_all_students(student* DM_Evandle, student* BM_Evandle, student* K_Evandle, student* ME_Evandle, stat* DM_stat, stat* BM_stat, stat* K_stat, stat* ME_stat, skills* DM_skills, skills* BM_skills, skills* K_skills, skills* ME_skills, weapon* Vandella_Doll, weapon* Blue_Regalia, weapon* Logic, weapon* Wisdom_Cube, level* Standard_level, image* Althea_smol);

void init_all_npcs(npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, npc* Overlord, npc* Terror, npc* Mystic, skills* NIGH_npc_skills, skills* LOST_npc_skills, skills* SLIM_npc_skills, level* Standard_level, weapon* Enfield, image* Nightmare_icon, image* LostOne_icon, image* Slime_icon);



#endif

#ifndef MAP_H
#define MAP_H



// Function declarations
void init_forest(int TREE_COUNT, int ENEMY_COUNT);
void render_map();
void render_view();
char move_player(char direction);

#endif // MAP_H

#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>

#define WIDTH 100
#define HEIGHT 30

#define EMPTY_SPACE ' '
#define BOUNDARY '#'
#define TREE 'T'  // New character for trees
#define PLAYER '@'
#define NPC 'X'

#define VIEW_WIDTH 10
#define VIEW_HEIGHT 5
#define MIN_BOUNDARY 0
#define MIN_BOUNDARY_VIEW 1
#define MAX_WIDTH (WIDTH - 1)
#define MAX_HEIGHT (HEIGHT - 1)

char map[HEIGHT][WIDTH];
int playerX = 50;
int playerY = 15;

// Function to initialize the map with trees
void init_forest(int TREE_COUNT, int ENEMY_COUNT) {
    // Fill the map with boundaries and empty spaces in a single loop
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                map[i][j] = BOUNDARY;  // Set boundaries
            } else {
                map[i][j] = EMPTY_SPACE;  // Set empty spaces
            }
        }
    }
    // Randomly place trees in the map
    int placedTrees = 0;
    while (placedTrees < TREE_COUNT) {
        int treeX = rand() % (WIDTH - 2) + 1;  // Random X (avoid boundaries)
        int treeY = rand() % (HEIGHT - 2) + 1;  // Random Y (avoid boundaries)
        if (map[treeY][treeX] == EMPTY_SPACE) {  // Only place a tree in an empty space
            map[treeY][treeX] = TREE;  // Use TREE to represent a tree
            placedTrees++;
        }
    }
    // Randomly place enemies
    int placednpcs = 0;
    while (placednpcs < ENEMY_COUNT) {
        int npcX = rand() % (WIDTH - 2) + 1;  // Random X (avoid boundaries)
        int npcY = rand() % (HEIGHT - 2) + 1;  // Random Y (avoid boundaries)
        if (map[npcY][npcX] == EMPTY_SPACE) {  // Only place an enemy in an empty space
            map[npcY][npcX] = NPC;  // Use NPC to represent an enemy
            placednpcs++;
        }
    }
    // Set the player's initial position
    map[playerY][playerX] = PLAYER;
}

// Function to render the map
void render_map() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] != EMPTY_SPACE) {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to render the map with visible area around the player, make it load faster
void render_view() {
    // Calculate the visible area boundaries once
    int startX = playerX - VIEW_WIDTH / 2;
    int startY = playerY - VIEW_HEIGHT / 2;
    int endX = playerX + VIEW_WIDTH / 2;
    int endY = playerY + VIEW_HEIGHT / 2;

    // Clamp the view to the map boundaries
    if (startX < MIN_BOUNDARY + 1) startX = MIN_BOUNDARY_VIEW;
    if (startY < MIN_BOUNDARY + 1) startY = MIN_BOUNDARY_VIEW;
    if (endX > MAX_WIDTH) endX = MAX_WIDTH;
    if (endY > MAX_HEIGHT) endY = MAX_HEIGHT;

    // Prepare a buffer for the output
    char output[HEIGHT * (WIDTH + 1)]; // +1 for newline characters
    int index = 0;

    // Render the map
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // If the current map position is within the player's visible area, show it
            if (i >= startY && i < endY && j >= startX && j < endX) {
                output[index++] = map[i][j];
            } else {
                // Otherwise, show an empty space (or a fog symbol)
                output[index++] = ' ';
            }
        }
        output[index++] = '\n'; // Newline after each row
    }
    
    // Null-terminate the output string
    output[index] = '\0';

    // Print the entire output at once
    printf("%s", output);
}


// Function to move the player
char move_player(char direction) {
    // Calculate the new position based on direction
    int newX = playerX;
    int newY = playerY;
    switch (direction) {
        case 'w': newY--; break; // Move up
        case 's': newY++; break; // Move down
        case 'a': newX--; break; // Move left
        case 'd': newX++; break; // Move right
    }
    // Check if the new position is within bounds and not a tree
    if (newX > MIN_BOUNDARY && newX < MAX_WIDTH && newY > MIN_BOUNDARY && newY < MAX_HEIGHT) {
        if (map[newY][newX] != BOUNDARY && map[newY][newX] != TREE && map[newY][newX] != NPC) { // Check for trees
            // Move the player to the new position
            map[playerY][playerX] = EMPTY_SPACE;  // Clear the old position
            playerX = newX;
            playerY = newY;
            map[playerY][playerX] = PLAYER;  // Set the new position
            return 'O';
        }
        if (map[newY][newX] != BOUNDARY && map[newY][newX] != TREE && map[newY][newX] == NPC) {
            // Move the player to the new position
            map[playerY][playerX] = EMPTY_SPACE;  // Clear the old position
            playerX = newX;
            playerY = newY;
            map[playerY][playerX] = PLAYER;  // Set the new position
            return 'X';
        }
    }
    return ' ';
}

void play_music() {
    // Open the mp3 file
    mciSendString("open \"Ouroboros.mp3\" type mpegvideo alias bgm", NULL, 0, NULL);
    
    // Play the mp3 in the background (repeat indefinitely)
    mciSendString("play bgm repeat", NULL, 0, NULL);
}

void init_image(image* img, char* name, char* img1, char* img2, char* img3, char* img4, char* img5) {
        strcpy(img->name, name);
    img->img1 = img1;
    img->img2 = img2;
    img->img3 = img3;
    img->img4 = img4;
    img->img5 = img5;
}

void init_stat(stat* s, int vit, int end, int mana, int intelligence, int agility, int luck, int insight, int corruption, int sanity) {
    s->vit = vit;
    s->end = end;
    s->mana = mana;
    s->intelligence = intelligence;
    s->agility = agility;
    s->luck = luck;
    s->insight = insight;
    s->corruption = corruption;
    s->sanity = sanity;
}

void display_stat(stat* s) {
    printf("Vitality: %d\nEndurance: %d\nMana: %d\nIntelligence: %d\nAgility: %d\nLuck: %d\nInsight: %d\nCorruption: %d\nSanity: %d\n",
            s->vit, s->end, s->mana, s->intelligence, s->agility, s->luck, s->insight, s->corruption, s->sanity);
}

void init_level(level* l, int level, int xpcap, float xpcapmultiplier, float hpmultiplier, float defenseMultiplier, float intelligenceMultiplier, float manamultiplier) {
    l->level = level;
    l->xpcap = xpcap;
    l->xpcapmultiplier = xpcapmultiplier;
    l->hpmultiplier = hpmultiplier;
    l->defenseMultiplier = defenseMultiplier;
    l->intelligenceMultiplier = intelligenceMultiplier;
    l->manamultiplier = manamultiplier;
}

void display_level(level* l) {
    printf("Level: %d\nXp Cap: %d\n", l->level, l->xpcap);
}

void init_spell(spell* s, const char* name, const char* desc, int spell_power, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration) {
    strncpy(s->name, name, MAX_NAME_LENGTH - 1);
    s->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(s->desc, desc, MAX_DESC_LENGTH - 1);
    s->desc[MAX_DESC_LENGTH - 1] = '\0'; // Ensure null termination
    s->spell_power = spell_power;
    s->accuracy = accuracy;
    s->cooldown = cooldown;
    s->cost = cost;
    s->critchance = critchance;
    s->critdamage = critdamage;
    s->stunchance = stunchance;
    s->stunduration = stunduration;
}

void init_npc_spell(spell* s, const char* name, const char* desc, int spell_power, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration, int corruption, int sanity) {
    strncpy(s->name, name, MAX_NAME_LENGTH - 1);
    s->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(s->desc, desc, MAX_DESC_LENGTH - 1);
    s->desc[MAX_DESC_LENGTH - 1] = '\0'; // Ensure null termination
    s->spell_power = spell_power;
    s->accuracy = accuracy;
    s->cooldown = cooldown;
    s->cost = cost;
    s->critchance = critchance;
    s->critdamage = critdamage;
    s->stunchance = stunchance;
    s->stunduration = stunduration;
    s->corruption = corruption;
    s->sanity = sanity;
}

void display_spell(spell* s) {
    printf("Name: %s\nDescription: %s\nDamage: %d\nAccuracy: %.2f\nCooldown: %d\nCost: %d\nCrit Chance: %.2f\nCrit Damage: %.2f\nStun Chance: %.2f\nStun Duration: %d\n",
            s->name, s->desc, s->spell_power, s->accuracy, s->cooldown, s->cost, s->critchance, s->critdamage, s->stunchance, s->stunduration);
}

void init_skills(skills* s, spell* spell1, spell* spell2, spell* spell3, spell* ult) {
    s->spell1 = *spell1;
    s->spell2 = *spell2;
    s->spell3 = *spell3;
    s->ult = *ult;
}

void display_skills(student* s){
    printf("|a: %s |b: %s |c: %s |d: %s |\n"
            "|e: %s |f: %s |g: %s |h: %s |\n"
            "<|u: %s |>\n<|",
            s->skills.spell1.name, s->skills.spell2.name, s->skills.spell3.name, s->skills.spell4.name, s->skills.spell5.name, s->skills.spell6.name, s->skills.spell7.name, s->skills.spell8.name, s->skills.ult.name);
}

void init_npc_skills(skills* s, spell* spell1, spell* spell2, spell* spell3) {
    s->spell1 = *spell1;
    s->spell2 = *spell2;
    s->spell3 = *spell3;
}

void init_weapon(weapon* w, const char* name, const char* desc, int dmg, int dropchance) {
    strncpy(w->name, name, MAX_NAME_LENGTH - 1);
    w->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(w->desc, desc, MAX_DESC_LENGTH - 1);
    w->desc[MAX_DESC_LENGTH - 1] = '\0'; // Ensure null termination
    w->dmg = dmg;
    w->dropchance = dropchance;
}

void display_weapon(weapon* w) {
    printf("Name: %s\nDescription: %s\nDamage: %d\nDrop Chance: %d\n", w->name, w->desc, w->dmg, w->dropchance);
}

void init_student(student* s, const char* name, const char* course, int hp, int def, float multi, weapon* weapon, level* level, int xp, stat* stats, skills* skills, image* img) {
    strncpy(s->name, name, MAX_NAME_LENGTH - 1);
    s->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(s->course, course, MAX_NAME_LENGTH - 1);
    s->course[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    s->hp = hp;
    s->def = def;
    s->multi = multi;
    s->weapon = *weapon; // Directly assign the weapon struct
    s->level = *level;   // Directly assign the level struct
    s->xp = xp;
    s->stats = *stats;
    s->skills = *skills;
    s->img = *img;
}

void init_npc(npc* n, char* name, char* desc, int hp, int def, weapon* weapon, level* level, int xp_drop, skills* skills, image* img) {
    strncpy(n->name, name, MAX_NAME_LENGTH - 1);
    n->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(n->desc, desc, MAX_NAME_LENGTH - 1);
    n->desc[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    n->hp = hp;
    n->def = def;
    n->weapon = *weapon; // Directly assign the weapon struct
    n->level = *level;   // Directly assign the level struct
    n->xp_drop = xp_drop;
    n->skills = *skills;
    n->img = *img;
}


void display_student(student* s) {
    printf("Name: %s\nCourse: %s\nHP: %d\nDef: %d\nAtk Multi: %.2f\n\n", s->name, s->course, s->hp, s->def, s->multi);
}

void init_all_stats(stat* DM_stat, stat* BM_stat, stat* K_stat, stat* ME_stat) {
    // Initializing stats (stat* s, int vit, int end, int mana, int intelligence, int agility, int luck, int insight, int corruption, int sanity) 
    init_stat(DM_stat, 7, 6, 120, 9, 7, 8, 0, 0, 10);
    init_stat(BM_stat, 8, 7, 130, 9, 8, 7, 0, 0, 8);
    init_stat(K_stat, 10, 10, 100, 7, 8, 6, 0, 0, 8);
    init_stat(ME_stat, 7, 5, 170, 10, 6, 8, 0, 0, 9);
}

void init_all_levels(level* Standard_level) {
    // level* l, int level, int xpcap, float xpcapmultiplier, float hpmultiplier, float defenseMultiplier, float intelligenceMultiplier, float manamultiplier) {
    init_level(Standard_level, 1, 100, 0.25, 0.1, 0.1, 0.1, 0.1);
}

// Spell initializations, pain in the ass btw
void init_all_spells(spell* basic_attack, spell* doll_slash, spell* doll_artillery, spell* doll_blast, spell* doll_dance, spell* precise_strike, spell* energy_burst, spell* cryo_phenix_blast, spell* blades_of_finality, spell* sisterhood_style, spell* common_sense, spell* mana_burst, spell* domain_of_stagnation, spell* optimized_ice, spell* energy_snipe, spell* heart_of_ice, spell* cube_of_wonder, spell* tentacle_grab, spell* seed_of_doubt, spell* black_lightning, spell* corrupting_touch, spell* vore, spell* devour) {
    //init_spell(spell* s, const char* name, const char* desc, int spell_power, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration)
    init_spell(basic_attack, "Basic Attack", "A basic attack, cost nothing.", 
        6, 75, 0, 0, 15, 2, 0, 0);

    init_spell(doll_slash, "Doll Slash", "The doll perform a close combat attack.", 
        6, 90, 0, 0, 25, 2, 0, 0);
    init_spell(doll_artillery, "Doll Artillery", "The doll fires multiple high powered magic barrages.", 
        10, 90, 1, 30, 30, 2, 25, 1);
    init_spell(doll_blast, "Doll's Trick", "The doll fires multiple magic spells.", 
        8, 90, 0, 10, 25, 2, 0, 0);
    init_spell(doll_dance, "Everlasting Performance", "Makes multiple physical illusions of the doll, then along side with the copies the doll attack with barrages and lazers.", 
        18, 99, 3, 60, 30, 2, 25, 2);

    init_spell(precise_strike, "Precise Strike", "A quick and powerful strike on an enemy's weakness.", 
        6, 95, 0, 0, 30, 2, 0, 0);
    init_spell(energy_burst, "Energy Burst", "A huge beam of cryo alined energy blast.", 
        12, 95, 1, 35, 25, 2, 30, 1);
    init_spell(cryo_phenix_blast, "Cryo Phenix Blast", "A blast of freezing fire ball.", 
        8, 90, 0, 15, 25, 2, 25, 1);
    init_spell(blades_of_finality, "Blades Of Finality", "Multiple flying blades that freezes their target to absolute zero.",
        19, 95, 3, 75, 25, 3, 75, 2);

    init_spell(sisterhood_style, "Sisterhood Style", "The fighting style of the sisterhood, mainly focuses on strong defenses and evasion while delivering powerful strikes when the opportunity shows.",
        6, 90, 0, 0, 25, 2, 0, 0);
    init_spell(common_sense, "Common sense", "An overwhelming physical force is usually the best defense.",
        8, 90, 1, 0, 25, 2, 25, 1);
    init_spell(mana_burst, "Mana burst", "Uses mana to reinforce and coat her, and using burst of mana to increase the speed and force of attacks.",
        12, 90, 1, 30, 30, 3, 0, 0);
    init_spell(domain_of_stagnation, "Domain Of Stagnation", "Creates a domain over the curent environment that sucks the heat of everything trapped in it as time passes. Evandle then uses all those gathered heat and launch it as a giant beam of heat.",
        20, 99, 3, 100, 25, 2, 0, 0);

    init_spell(optimized_ice, "Optimized Ice", "A very optimized ice spell, with very high mana use efficiency. Coupled with Evandle's high ice affinity further boosts it's power.", 
        7, 95, 0, 3, 30, 2, 25, 1);
    init_spell(energy_snipe, "Energy Snipe", "High precision concentrated lazer attack, allows the caster to snipe enemies from far away with little deviation on its target location.", 
        12, 99, 1, 40, 50, 2, 0, 0);
    init_spell(heart_of_ice, "Heart Of Ice", "A powerful burst of nano edge ice from all directions of the caster, creating a deadly flower of death.",
        15, 95, 2, 50, 40, 3, 50, 2);
    init_spell(cube_of_wonder, "Cube Of Wonder", "A giant purple cube that rejects and erases everything it touches. Evandle impowers her Wisdom Cube with her own mana turning it purple and activating the complex and massive spell structure it contains. It was her own little personal project however, it became too complex and powerful for her to cast it herself.",
        22, 95, 4, 100, 25, 3, 0, 0);

    // npc spells tentacle_grab, seed_of_doubt, black_lightning, corrupting_touch, vore, devour
    init_npc_spell(tentacle_grab, "Tentacle Grab", "The abomination grabs it's garget using it's many black slimy tentacles.",
        6, 80, 1, 0, 25, 2, 50, 1, 0, 0);
    init_npc_spell(seed_of_doubt, "Seed Of Doubt", "The nightmare mind rapes and plants a seek of doubt in it's target's mind, lowering their sanity.", 
        8, 90, 1, 0, 25, 2, 0, 0, 0, 1);
    
    init_npc_spell(black_lightning, "Black Lightning", "Casts a lightning tainted and impowered by corruption.",
        8, 95, 1, 15, 30, 2, 25, 1, 0, 0);
    init_npc_spell(corrupting_touch, "Corrupting Touch", "Spreads the dead outer gods' corruption through touch.",
        7, 75, 1, 0, 25, 2, 0, 0, 1, 0);
    
    init_npc_spell(vore, "Vore", "Vores the target and dissolves them into nutrition.",
        7, 75, 1, 0, 25, 2, 50, 1, 0, 0);
    init_npc_spell(devour, "Devour", "Devours the target and their essence and existence. Once it dovours a human, it can shapeshift into them.", 
        10, 90, 2, 30, 30, 3, 0, 0, 0, 0);

}

// Standard skills
void init_standard_skills(skills* DM_skills, skills* BM_skills, skills* K_skills, skills* ME_skills, skills* NIGH_npc_skills, skills* LOST_npc_skills, skills* SLIM_npc_skills, spell* basic_attack, spell* doll_slash, spell* doll_artillery, spell* doll_blast, spell* doll_dance, spell* precise_strike, spell* energy_burst, spell* cryo_phenix_blast, spell* blades_of_finality, spell* sisterhood_style, spell* common_sense, spell* mana_burst, spell* domain_of_stagnation, spell* optimized_ice, spell* energy_snipe, spell* heart_of_ice, spell* cube_of_wonder, spell* tenticle_grab, spell* seed_of_doubt, spell* black_lightning, spell* corrupting_touch, spell* vore, spell* devour) {
    init_skills(DM_skills, doll_slash, doll_artillery, doll_blast, doll_dance);
    init_skills(BM_skills, precise_strike, energy_burst, cryo_phenix_blast, blades_of_finality);
    init_skills(K_skills, sisterhood_style, common_sense, mana_burst, domain_of_stagnation);
    init_skills(ME_skills, optimized_ice, energy_snipe, heart_of_ice, cube_of_wonder);
    
    init_npc_skills(NIGH_npc_skills, basic_attack, tenticle_grab, seed_of_doubt);
    init_npc_skills(LOST_npc_skills, basic_attack, black_lightning, corrupting_touch);
    init_npc_skills(SLIM_npc_skills, basic_attack, vore, devour);
}

void init_all_weapons(weapon* Vandella_Doll, weapon* Blue_Regalia, weapon* Logic, weapon* Wisdom_Cube, weapon* natural_weapon) {
    // Initializing weapons
    init_weapon(Vandella_Doll, "Vandella Doll", "Evandle's favorite doll. A cute 30cm tall doll of a girl with brown hair, she has an ojo-sama esthetic but has a close familiarity to Evandle's features. A multifunctional mainly built for companionship but her battle capabilities is considerable."
    , 2, 0);
    init_weapon(Blue_Regalia, "Blue_Regalia", "Evandle's battle regalia provided by the University, further modified by her to fit her fighting style."
    , 2, 0);
    init_weapon(Logic, "Logic", "A large polearm made with magicaly reactive metal modified to fit Evandle's esthetic and preference."
    , 1, 0);
    init_weapon(Wisdom_Cube, "Wisdom Cube", "A cube built by Evandle with the help of the University's specialized equipment. Used for easier spell building, storage, and casting, it simulates the spell structure for virtual testing. It amplifies the power of spells within it, identifies problems and warnings within a spell structure stored in it."
    , 3, 0);
    init_weapon(natural_weapon, "natural weapon", "A creature's natural weapon, be it claws, fangs, spikes, or limbs"
    , 1, 0);
}


void init_all_students(student* DM_Evandle, student* BM_Evandle, student* K_Evandle, student* ME_Evandle, stat* DM_stat, stat* BM_stat, stat* K_stat, stat* ME_stat, skills* DM_skills, skills* BM_skills, skills* K_skills, skills* ME_skills, weapon* Vandella_Doll, weapon* Blue_Regalia, weapon* Logic, weapon* Wisdom_Cube, level* Standard_level, image* Althea_smol) {
    // Initializing students
    init_student(DM_Evandle, "Evandle(Doll Maker)", "Mana Constructs", 50, 2, 0.30, Vandella_Doll, Standard_level, 0, DM_stat, DM_skills, Althea_smol);
    init_student(BM_Evandle, "Evandle(Battle Dress)", "Magic Application", 40, 3, 0.50, Blue_Regalia, Standard_level, 0, BM_stat, BM_skills, Althea_smol);
    init_student(K_Evandle, "Evandle(Knight)", "Knight", 70, 3, 0.20, Logic, Standard_level, 0, K_stat, K_skills, Althea_smol);
    init_student(ME_Evandle, "Evandle(Mana Engineer)", "Spell Structures", 40, 2, 0.60, Wisdom_Cube, Standard_level, 0, ME_stat, ME_skills, Althea_smol);
}

void init_all_npcs(npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, npc* Overlord,npc* Terror, npc* Mystic, skills* NIGH_npc_skills, skills* LOST_npc_skills, skills* SLIM_npc_skills, level* Standard_level, weapon* natural_weapon, image* Nightmare_icon, image* LostOne_icon, image* Slime_icon) {
    init_npc(Nightmare, "Nightmare", "An abomination born from corruption.", 25, 2, natural_weapon, Standard_level, 10, NIGH_npc_skills, Nightmare_icon);
    init_npc(LostOne, "Lost One", "A shadow from a fallen mystic.", 30, 4, natural_weapon, Standard_level, 20, LOST_npc_skills, LostOne_icon);
    init_npc(Slime, "Slime", "A sentient sluge born from the rotting flesh of a dead outer god.", 20, 1, natural_weapon, Standard_level, 20, SLIM_npc_skills, Slime_icon);
    init_npc(Overlord, "OverLord", "A boss wip", 50, 5, natural_weapon, Standard_level, 100, SLIM_npc_skills, Slime_icon);
    init_npc(Terror, "Unknown", "A mystic who has fallen to terror.", 100, 5, natural_weapon, Standard_level, 200, SLIM_npc_skills, Slime_icon);
    init_npc(Mystic, "A lost Mob-chan", "Another student from KIvotos who was spirited away.", 50, 4, natural_weapon, Standard_level, 100, SLIM_npc_skills, Slime_icon);
    
}


void init_all_images(image* EF1, image* Althea_big, image* Althea_smol, image* Nightmare_icon, image* LostOne_icon, image* Slime_icon) {
    init_image(EF1, "The Beginning of Evandle's Wondering", 
    "..~5PJ?Y!^:^JP5JYY7^!^^^::.:::::!!^:^~?!:^!!~~~!~7YYYPPGGPP555J?7~^^:^~!!JPJ~::.^~^:^7~JBGG5!^:::::.\n"
    ".::7G7^:.::~?^?5555!!7~^:::::.:::::^::^~!::^~~~:::^^^^^^!!~^^^:::::^?YYJJ57:.:~!~:^!~7PBPPPY~^:::::.\n"
    ".:^Y7JY~^~^?^!^7YBPY?~:::^:::::::::::::::~!~:!!!^^^^::::..:::^~7?7J555?~:.^7!!^::^^^P#J7Y??~^::^::.\n"
    "..::^!??77!^JYYY!!?JPG5?7J5?^:::::::.:...^JGY:.:^~~^^^:^^:~~!?JY?!7?!^:::^J57::^^!?YBB5Y?7!?~^^~?::.\n"
    "...:~^?~::::?!J5?~~.~J5GGB##G?~^^...::::..!#?....::::^^^~~^^~~:.:^::.::~~!!^:^^:!YP#BG5?^^~7^^~!Y^:.\n"
    "....:::!Y7~~?~!~7J7~::~?JJ5YY?7!?!^:..:...~B:..:.::::::.:::::::^::^^~~^^^~~^:^!!5GBG5Y!:.~~7^^!!J^^.\n"
    ".:::::^:~~?^J7JYY?!^7?~::^^!!~~~^~~^:.....J#:........:....:.:::^~~~^^:^!~!?J?G##BGPP?^~^:~^!::!J?~~.\n"
    "::::~::~::~?BJ~7J?P5Y55PY!^::^^^^^^^^:....P#:............:::::^^:::::^~7JPG5GB#PJP???:~^.~^~.:~5J~^.\n"
    ".^^^^:.:^^:!YPYJ!~??YPGB#GJ^:::::::::..:!!BB~....^~:......::.:....:^!7J???75G57:~Y~77.^:^::^:^!P5!^.\n"
    ".~~^^::::::~7775GYY?~~!?J5PY7???7~:.....~G#&5.!J?P#GJ:.::..:..:^!!!7~~^:~777~^^~!?:7!::::!:^:~^P57:.\n"
    ".^7^~^::.::~77~7?PYJJ?7~^:^~7?Y5JJ7~^::.:7P#7!#&##&&#5??77!^.::::^:^^~7?!^:^~~^^~7.77.^:.!~~^~7557:.\n"
    ".^7!^~^.:..^?~^!!Y!^?JJ?7!~^^^:^::::^^^:. !PY~BGGB#&&#BGYY!::.:::^~!!!7!^^!~^^:.^7.7?.~^.:JJY!P5Y~:.\n"
    ".:77~:!.:..^7^^!~?~:~~Y?!?J?7~^::::......~JB##&PJPBGBGYJ7^:..:::^^::::::^^^^::..:!.7~.::::^75^YPJ~:.\n"
    "..!777~:.^:^7^^~:?^::~?^:::~~~~~^^:.....~PGB&&#?:~!!!?~!!..:::::^:::::::.::.::..:~.7^...:::!P75G!!::\n"
    "..^?!7~!::^:J~.^:7:.:~!:.:......::^:..:~?PG#BY!......:..........:^:::::.........:^.~:..^~:^.JPB5~~::\n"
    ":::!??7?!.^.7~.^:!..::!:.............:?PG#5Y5G?^~~~~^^^:......:..:..........::...:.~:.::::^:P#G?!^~.\n"
    ":~:^7Y57J^.:!~.::!:.:^7^.......:^~!?JYY?!7~Y#&BP?^:~!^^^......::............~^.....:..77:~!^GBP?7^~.\n"
    ".~7~~7JYJ?.^!~.::~..::~:^^....:JP5?~:....^!YG##&&P!^:::^^:!JY5?~!:........!^......:^:YYJ.!:JPP5J~!:.\n"
    ".:!!7?!555^:~^.:.^:.:.~:::.....^^:.......:7?YG#BB#&#BBB#BB&&@5.^7:........~:......:^:7???5JGPP7!~!:.\n"
    ".!?7J5?PB7:^^^:::::.:^:..................^?Y5GGGB#&&&&#&&#GY^.~J:...........:.....:.:^:YYBBG57??~:.\n"
    ":::57~7?JBY~~:^::^:^^...:..................!Y5GGPGB#&&###P!!7???7?:...........~:.:..~^^~~~!BBY7J77~..\n"
    ".^~~P7^^JPGJ!^:..7!~:.^::...:..............:7?5GJ?5PGB&B~.~G####BBPY?!!J7.......!^:J~.!7?5#G777!~^..\n"
    "..!~~Y?!^!YBJ7^.:?~.:.^:......::::..........75PGBBPGGB&5..:~!::^~~!?J5G#&Y^..:..^7!^:~JBYG#J:?J!^.:.\n"
    "...~^:?J7~~5#G!:7!::.:::..::..:::?^..::.....:JYB##&G7JY^^^7^:..........:7PG^.:.:!!7!JPB#GGB!!?7^:::.\n"
    ":::^!!YJJ?7^PPY^!Y^::^:..:::....:::..::......JPG#BY:...^!~:...............^^.:.::..^^7GBB5?J?7~^^:^:\n"
    ".^:~~?JG77?JJJB?7J^^^~:^^...::::::...77......~G5Y^:~~~!G#G!............::.::.:!?J7:~^5PGY!?J?!^:::^:\n"
    ":^^:!~!JP?5G5^JGPJ^~^^~:7::.^::~.....~!.......:!:^::..:!5#&Y:..........::.:^!?~^!75J7GB5~?7?!^..^~^.\n"
    ".^:7:7!~?5?JGJ7J#G~!7.:.!??.:::?::...::.....:..:.~:......^?BB?~~:....::..::::...:^B#B#5!!7~7^:!~~^..\n"
    ".:^??~~^^?57?GP?P#YY5^^::~7^..:!:^..:7^........:.~:.........7G&#^....::..7~^~7J!:!BBB5?JJ~?!!7!~~::.\n"
    "..:^^^^.!!!J?75GPBB5BJ~:^:~7:~:?7.::.!^:....:....?~..........:5&~...:.:.^:7!!7G#5BP5J?J!!J~JY~^~.::.\n"
    "...^!7~!:!!7???JPGGP#J7:J^.~!:^P?..::~?:...:^....7^...::.......JJ...^7~.^:^.^?G#G5YJ!!~!?!??^:^:.^:.\n"
    ":..:!!J?:!YP5Y??P#GBBP^!7~:!~~YY..^:?5..:^......^:...:^....::..:...:7!:::..!#BBGP?7^^?77~:::^~^^:..\n"
    , "N/A", "N/A", "N/A", "N/A");
    init_image(Althea_big, "Evandle on full shut in nerd mode",
        "                        .~?JYYJ?!:      \n"
        "                      .?PBBBBGGGGPJ^    \n"
        "                     :PGPPPPGPGGGGGG!   \n"
        "                     PGPPPPPPPPPPPPPG.  \n"
        "                 ^~^!BP5JJ5GBP5PGGPPP.  \n"
        " :?!^.           !B##BYJP5GYPGJJJPPGP:. \n"
        " P&&&#G5?~         7BPPGBBB#PBGGYPGG#BP:\n"
        "J&&&&&&&&7         YG55G#&&&&##BGPPB?^. \n"
        "!P#&&&&&J         7BPP5PPB####G5YPGB:   \n"
        "  :^~7B#.       .JBGPPPGPGBBBBGBGPGG.   \n"
        " :~!?5&#!      ^PBB&&&##BG!YBB#@&&&#J^  \n"
        "?YB#&&#&G.    ?GG#@@&&&B#?^BB#@@&@@&@&~ \n"
        "  :^~G&&@P.  YBPG@&&&&##5.?#&&&&&@@&@@J \n"
        "     .5@@@B!JBG#&&&&&##P^:G&@@@&@@&@@@P \n"
        "       5@@@&BP&@&&&&B##7.7#@@@&&#&&@@@B \n"
        "        Y@@@&&@@&&&###B~.5#@@&&&G#&@@@&^\n"
        "         5@@@@&@##&###P::P#@@&@@&GB@@&@?\n"
        "         .Y&@@#5GG#B#BJ::5#@&&@@&BG&&&@B\n"
        "           :Y5:JGP#GGGP:.7B@&@@@&GG&@@@@\n"
        "              .B#G&BPGG7:.J@&@@@BPB#&@@@\n"
        "               ?###BGGGGP?Y&&@@BGG##@@@@\n"
        "               :#&BB#BB##BGB&@&&#GB&@@@@\n"
        "               ?@##57?77!!!7#@@@@##&@@@G\n"
        "              7&&#B!^^~^~~~^Y@@@@@&&@@#:\n"
        "             ?@@&#J^~~~~~~~~!#@@@@@@&&B \n"
        "            !&@@#5^~~~~~~~~~~J@@@@@@@@B:\n"
        "           ~&@@&B!~~~~~~~~~~~~G@@@@@@@@#\n"
        "          ^#@@@&5^~~~~~~~~~~~~!B@@@@@@@@\n"
        "         .B@@@@&?^~~~~~~~~~~~~~!#@@@@@@@\n"
        "         Y@@@@@#7^~~~~~~~~~~~~~~!G@@@@@@\n"
        "        :&@@@@&B!~~~~~~~~~~~~~~~~~P@@@@@\n"
        , "N/A", "N/A", "N/A", "N/A");
    init_image(Althea_smol, "Evandle on full shut in nerd mode, smol version",
        "      .:~7!!~^:.\n"
        "        ~5PPY^ \n"
        "..    :!P5PPG5.\n"
        "YBG~  .5PB#GP5^\n"
        "~Y#^ .JBBPG#BY \n"
        ":!BP~P&&#7B@@@?\n"
        "  .G@&&#Y?@&#@P\n"
        "   .JYBBJ7&@B&&\n"
        "     :#GPJB&B&@\n"
        "     5#!~~?@@@P\n"
        "    5@?^~~~5@@#\n"
        "   ?@&!~~~~~5@@\n"
        , "N/A", "N/A", "N/A", "N/A");
    init_image(Nightmare_icon, "An abomination", 
        "                                            .^. :~.  ^  ::      \n"
        "                                             ^^.:!^  ~: ::      \n"
        "                                           . :!~~~~. ^~:~.   .  \n"
        "                                       ..   ..:!7~7!~!!~: ..:.. \n"
        "                                        .::^^^^~?!~~~!!~^~^. .. \n"
        "                                          .^~~!7J~^~^~7~~!~^^:  \n"
        "                                         .::^^^!7!~~^~~^::... . \n"
        "                                           .^~~~^~!!!~~~!~~~:.. \n"
        "                                          .:::^^^~^ ~!~~^:::.   \n"
        "                                              :::~.  ~~^:       \n"
        "                                              . .:   .: ..      \n"
        "                                                ..               \n"
        , "N/A", "N/A", "N/A", "N/A");
    init_image(LostOne_icon, "A corrupted human, under the will of an higher entity",
        "                                                  .^:.          \n"
        "                                                ^!7PJ?~         \n"
        "                                                ~^~7~^^         \n"
        "                                               .~^~^~^~.        \n"
        "                                               ^^::^::^~        \n"
        "                                             .^^:^:::^:^^.      \n"
        "                                            ^~^:^~^^^!^:^~^     \n"
        "                                           ^~^::^!~~!!^::^~^.   \n"
        "                                         .~~^^::^~?J?!~^::^~~:  \n"
        "                                        ^~~^^::~~~?7?!~~^::^~~~.\n"
        , "N/A", "N/A", "N/A", "N/A");
    init_image(Slime_icon, "Freaky slime", 
        "                                           ^^^~~!!~!^^~.   \n"
        "                                          .^!!~~7?~^!!!:   \n"
        "                                         :~~~~~~!!!^~~!~^  \n"
        "                                        ^!7?!!!7777?77!!~. \n"
        "                                       .~~7JYJ??JJY??JYJ!~.\n"
        "                                       .~~!?Y5??JJ?7JYJ7~~.\n"
        "                                        .:^~!JJ??????7!^:. \n"
        "                                          .::^~7~:!!~^:::. \n"
        "                                       ::^~~^^^^~~~^^^^^:  \n"
        , "N/A", "N/A", "N/A", "N/A");

}

void draw_dice_animation(int pdice, int npcdice) {
    printf(
        "               ____________                  ____________      \n"
        "              /            \\                /            \\       \n"
        "              |     [%d]    |                |    [%d]     |     \n"
        "              \\____________/                \\____________/      \n"
        "                                                                \n"
        , pdice, npcdice
        );
}


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

void draw_ui(student* player, npc* enemy) {
printf("|[%s]                  |                   [%s]|\n", player->name, enemy->name);
printf("/--------------------------------------------------------------------------------\\\n");
printf("|                  [%d]                  |                   [%d]                 |\n", player->hp, enemy->hp);
printf("\\--------------------------------------------------------------------------------/\n");
}

void draw_gui() {
    // Glitchy ahh GUi, needs changing, its kinda ass.
    printf("|  A> ATTACK        |         T> TALK    |\n"
        "|  R> RUN           |         I> ITEMS   |\n");
    


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

void dice_clash(student* player, npc* enemy, student* temp, npc* npctemp, int* is_stun, int* npc_is_stun ) {

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

    if (is_hit == 0) printf("| %s missed\n", player->name); Sleep(2000);
    if (npc_is_hit == 0) printf("| %s missed\n", enemy->name); Sleep(2000);

    if (*npc_is_stun > 0) {
        printf("| Evandle is stunned for %d\n", *npc_is_stun);
        Sleep(1000);
        (*npc_is_stun)--;
    }
    if (*is_stun > 0) {
        printf("| Enemy is stunned for %d\n", *is_stun);
        Sleep(1000);
        (*is_stun)--;
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
            switch (tolower(input)) {
                case 'a' : {
                    display_skills(player);
                    player_spell_select(player, &temp);
                    dice_clash(player, enemy, &temp, &npctemp, &is_stun, &npc_is_stun);
                    break;
                    }
                case 't' : break;
                case 'r' : break;
                case 'i' : break;
                default: break;
            }
            
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
        clear_console();
        if (player->hp <= 0){
            break;
        }
    }
    text("Continuing execution after pressing 'q1'.\n");
    printf("Continuing execution after pressing 'q1'.\n");
    printf("Continuing execution after pressing 'q11'.\n");
}


int main(void){
    // Declaring variables
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

