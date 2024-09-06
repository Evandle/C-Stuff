#ifndef STUDENT_H
#define STUDENT_H


// Define the student struct

typedef struct {
    char name[100];
    char desc[200];
    char rarity[100];
    int dmg;
    int dropchance;
} weapon;

typedef struct {
    char name[100];
    char school[100];
    int hp;
    int def;
    float multi;
    weapon weapon;
    int level;
    int xp;
    // Add other fields as needed
} student;

typedef struct {
    char name[100];
    char desc[250];
    int hp;
    int def;
    int level;
    int xp;
} npc;


void init_weapon(weapon* w, const char* name, const char* desc, int dmg, int dropchance);

void display_weapon(weapon* w);

void init_student(student* s, const char* name, const char* school, int hp, int def, float multi, weapon* weapon, int level, int xp);

void display_student(student* s);

void init_all_weapons(weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova);

void init_all_students(student* Ichika, student* Hina, student* Hoshino, student* Arisu, weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova);

#endif