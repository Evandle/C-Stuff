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


void play_music();


void draw_ui(student* player, npc* enemy);

void draw_gui();

void draw_dice_animation(int pdice, int npcdice);

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