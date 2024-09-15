#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_NAME_LENGTH 100
#define MAX_DESC_LENGTH 256

#define MAX_IMAGES 5
#define FRAME_TIME 250 // Define a frame time in milliseconds

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
    int damage;
    float accuracy;
    int cooldown;
    int cost;
    float critchance;
    float critdamage;
    float stunchance;
    int stunduration;
} spell;

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
    spell spells;
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
} npc;





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

void init_spell(spell* s, const char* name, const char* desc, int damage, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration) {
    strncpy(s->name, name, MAX_NAME_LENGTH - 1);
    s->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(s->desc, desc, MAX_DESC_LENGTH - 1);
    s->desc[MAX_DESC_LENGTH - 1] = '\0'; // Ensure null termination
    s->damage = damage;
    s->accuracy = accuracy;
    s->cooldown = cooldown;
    s->cost = cost;
    s->critchance = critchance;
    s->critdamage = critdamage;
    s->stunchance = stunchance;
    s->stunduration = stunduration;
}

void display_spell(spell* s) {
    printf("Name: %s\nDescription: %s\nDamage: %d\nAccuracy: %.2f\nCooldown: %d\nCost: %d\nCrit Chance: %.2f\nCrit Damage: %.2f\nStun Chance: %.2f\nStun Duration: %d\n",
            s->name, s->desc, s->damage, s->accuracy, s->cooldown, s->cost, s->critchance, s->critdamage, s->stunchance, s->stunduration);
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

void init_student(student* s, const char* name, const char* course, int hp, int def, float multi, weapon* weapon, level* level, int xp) {
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
}

void init_npc(npc* n, char* name, char* desc, int hp, int def, weapon* weapon, level* level, int xp_drop) {
    strncpy(n->name, name, MAX_NAME_LENGTH - 1);
    n->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(n->desc, desc, MAX_NAME_LENGTH - 1);
    n->desc[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    n->hp = hp;
    n->def = def;
    n->weapon = *weapon; // Directly assign the weapon struct
    n->level = *level;   // Directly assign the level struct
    n->xp_drop = xp_drop;
}

void display_student(student* s) {
    printf("Name: %s\nCourse: %s\nHP: %d\nDef: %d\nAtk Multi: %.2f\n\n", s->name, s->course, s->hp, s->def, s->multi);
}

void init_all_stats(stat* DM_stat, stat* BM_stat, stat* K_stat, stat* ME_stat) {
    // Initializing stats (stat* s, int vit, int end, int mana, int intelligence, int agility, int luck, int insight, int corruption, int sanity) 
    init_stat(DM_stat, 7, 6, 120, 9, 7, 8, 0, 0, 10);
    init_stat(BM_stat, 8, 7, 130, 9, 8, 7, 0, 0, 8);
    init_stat(K_stat, 10, 10, 100, 7, 8, 6, 0, 0, 8);
    init_stat(ME_stat, 7, 5, 150, 10, 6, 8, 0, 0, 9);
}

void init_all_levels(level* Standard_level) {
    // level* l, int level, int xpcap, float xpcapmultiplier, float hpmultiplier, float defenseMultiplier, float intelligenceMultiplier, float manamultiplier) {
    init_level(Standard_level, 1, 100, 0.25, 0.1, 0.1, 0.1, 0.1);
}

void init_all_spells(spell* basic_attack) {
    init_spell(basic_attack, "Basic Attack", "A basic attack, cost nothing.", 6, 0.75, 0, 0, 0.25, 2, 0, 0);
}

void init_all_weapons(weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova) {
    // Initializing weapons
    init_weapon(Enfield, "Enfield EM-2", "The JTF standard gun", 10, 2);
    init_weapon(MG42, "MG42", "The BM_Evandle gun", 11, 2);
    init_weapon(shotgun, "shotgun", "The oji-san gun", 8, 2);
    init_weapon(supernova, "Sword of Light: Super Nova", "The JTF standard gun", 15, 2);
}


void init_all_students(student* DM_Evandle, student* BM_Evandle, student* K_Evandle, student* ME_Evandle, weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova, level* Standard_level) {
    // Initializing students
    init_student(DM_Evandle, "Evandle(Doll Maker)", "Mana Constructs", 50, 4, 0.30, Enfield, Standard_level, 0);
    init_student(BM_Evandle, "Evandle(Battle Dress)", "Magic Application", 40, 5, 0.50, MG42, Standard_level, 0);
    init_student(K_Evandle, "Evandle(Knight)", "Knight", 70, 7, 0.20, shotgun, Standard_level, 0);
    init_student(ME_Evandle, "Evandle(Mana Engineer)", "Spell Structures", 40, 3, 0.60, supernova, Standard_level, 0);
}

void init_all_npcs(npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, npc* Overlord,npc* Terror, npc* Mystic, level* Standard_level, weapon* Enfield) {
    init_npc(Nightmare, "Nightmare", "An abomination born from corruption.", 25, 2, Enfield, Standard_level, 10);
    init_npc(LostOne, "Lost One", "A shadow from a fallen mystic.", 30, 4, Enfield, Standard_level, 20);
    init_npc(Slime, "Slime", "A sentient sluge born from the rotting flesh of a dead outer god.", 20, 1, Enfield, Standard_level, 20);
    init_npc(Overlord, "OverLord", "A boss wip", 50, 5, Enfield, Standard_level, 100);
    init_npc(Terror, "Unknown", "A mystic who has fallen to terror.", 100, 5, Enfield, Standard_level, 200);
    init_npc(Mystic, "A lost Mob-chan", "Another student from KIvotos who was spirited away.", 50, 4, Enfield, Standard_level, 100);
    
}
void draw_gui() {
      // Clear the console screen
    printf("%d", strlen(
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
    ":..:!!J?:!YP5Y??P#GBBP^!7~:!~~YY..^:?5..:^......^:...:^....::..:...:7!:::..!#BBGP?7^^?77~:::^~^^:..\n"));

}




void move1(image* img, int count) {
    const char* images[MAX_IMAGES] = { img->img1, img->img2, img->img3, img->img4, img->img5};
    printf("%s\n", images[count]);
}

void clear_console() {
    // Use ANSI escape codes for clearing the console
    printf("\033[H\033[J");
}

int main() {
    image test1;
    srand(time(0));
    printf("Random chooser: %d\n", rand() % MAX_IMAGES);
    printf("\033[1;31mThis is red text\033[0m\n");
    printf("\033[1;32mThis is green text\033[0m\n");
    printf("\033[1;34;43mThis is blue text on yellow background\033[0m\n");
    printf("This is default text\n");

    init_image(&test1,
        "test image",
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
    "   ?@&!~~~~~5@@\n",
    "      .:~7!!~^:.\n"
    "        ~5P5Y^ \n"
    "..    :!P55PG5.\n"
    "YBG~  .5PB#GP5^\n"
    "~Y#^ .JBBP5#BY \n"
    ":!BP~P&&B7B@@@?\n"
    "  .G@&&BY?@&#@P\n"
    "   .JYBBJ7&@B&&\n"
    "     :#GPJBB&@&\n"
    "     5#!~~?@@@P\n"
    "    5@?^~~~5@@#\n"
    "   ?@&!~~~~~5@@\n",
    "      .:~7!!~^:.\n"
    "        ~5P5Y^ \n"
    "..    :!P55PGY.\n"
    "YBG~  .5PB#GP5^\n"
    "~Y#^ .JBBP5#BY \n"
    ":!BP~P&&B7B@@@?\n"
    "  .G@&&BY?@&#@P\n"
    "   .JYBBJ7&@B&&\n"
    "     :#GPJBB&&@\n"
    "     5#!~~?@@@P\n"
    "    5@?^~~~5@@#\n"
    "   ?@&!~~~~~5@@\n",
    "      .:~7!!~^:.\n"
    "        ~5P5Y^ \n"
    "..    :!P55PGY.\n"
    "YBG~  .5PB#GP5^\n"
    "~Y#^ .JBBP5#BY \n"
    ":!BP~P&&B7B@@@?\n"
    "  .G@&&BY?@&#@P\n"
    "   .JYBBJ7&@B&&\n"
    "     :#GPJBB&&@\n"
    "     5#!~~?@@@P\n"
    "    5@?^~~~5@@#\n"
    "   ?@&!~~~~~5@@\n",
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
    );

    int count = 0;
    clock_t last_time = clock();

    while (1) {
        clock_t current_time = clock();
        double elapsed_time = (double)(current_time - last_time) * 1000.0 / CLOCKS_PER_SEC;

        if (elapsed_time >= FRAME_TIME) {
            last_time = current_time; // Reset the timer
            clear_console();
            move1(&test1, count);
            count = (count + 1) % MAX_IMAGES; // Cycle through images

        }
    }

    return 0; // Return from main
}

