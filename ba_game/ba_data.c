#include "student.h"
#include <string.h>
#include <stdio.h>
#include "map.h"


void init_weapon(weapon* w, const char* name, const char* desc, const int dmg, const int dropchance){
    strcpy(w->name, name);
    strcpy(w->desc, desc);
    w->dmg = dmg;
    w->dropchance = dropchance;
}

void display_weapon(weapon* w){
    printf("Name: %s\nDescription: %s\nDamage: %d\nDrop Chance: %d\n", w->name, w->desc, w->dmg, w->dropchance);
}

void init_student(student* s, const char* name, const char* school, int hp, const int def, const float multi, weapon* weapon, int level, int xp) {
    strcpy(s->name, name);
    strcpy(s->school, school);
    s->hp = hp;
    s->def = def;
    s->multi = multi;
    s->weapon = *weapon;
    s->level = level;
    s->xp = xp;
}

void display_student(student* s) {
    printf("Name: %s\nSchool: %s\nHP: %d\nDef: %d\nMulti: %.2f\n\n", s->name, s->school, s-> hp, s->def, s->multi);
}

void init_all_weapons(weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova) {
    // Initializing weapons
    init_weapon(Enfield, "Enfield EM-2", "The JTF standard gun", 10, 2);
    init_weapon(MG42, "MG42", "The Hina gun", 11, 2);
    init_weapon(shotgun, "shotgun", "The oji-san gun", 8, 2);
    init_weapon(supernova, "Sword of Light: Super Nova", "The JTF standard gun", 15, 2);
}


void init_all_students(student* Ichika, student* Hina, student* Hoshino, student* Arisu, weapon* Enfield, weapon* MG42, weapon* shotgun, weapon* supernova) {
    // Initializing students
    init_student(Ichika, "Ichika", "Trinity", 50, 5, 0.30, Enfield, 1, 0);
    init_student(Hina, "Hina", "Gehenna", 40, 3, 0.60, MG42, 1, 0);
    init_student(Hoshino, "Hoshino", "Abidos", 70, 7, 0.20, shotgun, 1, 0);
    init_student(Arisu, "Arisu", "Millennium", 40, 5, 0.50, supernova, 1, 0);
}


