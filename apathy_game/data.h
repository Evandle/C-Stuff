#ifndef DATA_H
#define DATA_H


// Define the student struct

typedef struct {
    char name[100];
    char img[3500];
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

void init_spell(spell* s, const char* name, const char* desc, int damage, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration);

void display_spell(spell* s);

void init_all_spells(spell* basic_attack);

// Init images
void init_image(image* i, const char* name, const char* img);
void init_all_images(image* EF1, image* Althea_big, image* Althea_smol, image* Nightmare_icon, image* LostOne_icon, image* Slime_icon);

void init_weapon(weapon* w, const char* name, const char* desc, int dmg, int dropchance);

void display_weapon(weapon* w);

void init_student(student* s, const char* name, const char* school, int hp, int def, float multi, weapon* weapon, level* level, int xp, image* img);

void display_student(student* s);

void init_npc(npc* n, char* name, char* desc, int hp, int def, weapon* weapon, level* level, int xp_drop, image* img);

void display_npc(npc* n);

void init_all_weapons(weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova);

void init_all_students(student* DM_Evandle, student* BM_Evandle, student* K_Evandle, student* ME_Evandle, weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova, level* Standard_level, image* Althea_smol);

void init_all_npcs(npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, npc* Overlord, npc* Terror, npc* Mystic, level* Standard_level, weapon* Enfield, image* Nightmare_icon, image* LostOne_icon, image* Slime_icon);



#endif