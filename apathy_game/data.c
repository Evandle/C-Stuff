#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "data.h"

#define MAX_NAME_LENGTH 100
#define MAX_DESC_LENGTH 256

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
    init_student(DM_Evandle, "Evandle(Doll Maker)", "Mana Constructs", 50, 3, 0.30, Vandella_Doll, Standard_level, 0, DM_stat, DM_skills, Althea_smol);
    init_student(BM_Evandle, "Evandle(Battle Dress)", "Magic Application", 40, 4, 0.50, Blue_Regalia, Standard_level, 0, BM_stat, BM_skills, Althea_smol);
    init_student(K_Evandle, "Evandle(Knight)", "Knight", 70, 5, 0.20, Logic, Standard_level, 0, K_stat, K_skills, Althea_smol);
    init_student(ME_Evandle, "Evandle(Mana Engineer)", "Spell Structures", 40, 3, 0.60, Wisdom_Cube, Standard_level, 0, ME_stat, ME_skills, Althea_smol);
}

void init_all_npcs(npc* enemy, npc* Nightmare, npc* LostOne, npc* Slime, npc* Overlord,npc* Terror, npc* Mystic, skills* NIGH_npc_skills, skills* LOST_npc_skills, skills* SLIM_npc_skills, level* Standard_level, weapon* natural_weapon, image* Nightmare_icon, image* LostOne_icon, image* Slime_icon) {
    init_npc(Nightmare, "Nightmare", "An abomination born from corruption.", 25, 2, natural_weapon, Standard_level, 10, NIGH_npc_skills, Nightmare_icon);
    init_npc(LostOne, "Lost One", "A shadow from a fallen mystic.", 30, 4, natural_weapon, Standard_level, 20, LOST_npc_skills, LostOne_icon);
    init_npc(Slime, "Slime", "A sentient sluge born from the rotting flesh of a dead outer god.", 20, 2, natural_weapon, Standard_level, 20, SLIM_npc_skills, Slime_icon);
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

void draw_ui(student* player, npc* enemy) {
printf("|[%s]                  |                   [%s]|\n", player->name, enemy->name);
printf("/--------------------------------------------------------------------------------\\\n");
printf("|                  [%d]                  |                   [%d]                |\n", player->hp, enemy->hp);
printf("\\--------------------------------------------------------------------------------/\n");
}

void draw_gui() {
    // Glitchy ahh GUi, needs changing, its kinda ass.
    printf("|  A> ATTACK        |         T> TALK    |\n"
        "|  R> RUN           |         I> ITEMS   |\n");
    
}

void draw_dice_animation(int pdice, int npcdice) {
    printf(
        "                .:^YP!^:.                      .:^YP!^:.        \n"
        "             .~7?J5GGPYJJ?~:                .~7?J5GGPYJJ?~:     \n"
        "          :^!JYYPP7777!PYJPY?!~.         :^!JYYPP7777!PYJPY?!~. \n"
        "        ^?YYJ?5GGJ755??PGPJ?555J!      ^?YYJ?5GGJ755??PGPJ?555J!\n"
        "        YGP!~Y5555555555555!~YPPY      YGP!~Y5555555555555!~YPPY\n"
        "        !?JYP?5GG5YPPJ5GGGJYG??77      !?JYP?5GG5YPPJ5GGGJYG??77\n"
        "        5J?GGGJYG?^[%d]^YGP?5GGP!5P    5J?GGGJYG?^[%d]^YGP?5GGP!5P\n"
        "        P7PG?YGYJPPGGPP5?PP5GG5?G      P7PG?YGYJPPGGPP5?PP5GG5?G\n"
        "        75GY~~YG5?PGGGJJG5!~JGGY?      75GY~~YG5?PGGGJJG5!~JGGY?\n"
        "        ?PPPPPGGGGJYG?YGGGG5YGPP?      ?PPPPPGGGGJYG?YGGGG5YGPP?\n"
        "         .~?Y555YYY7~J5YYY55Y?~.        .~?Y555YYY7~J5YYY55Y?~. \n"
        "            .^7YJ7PG7G5J?!7~.              .^7YJ7PG7G5J?!7~.    \n"
        "                .~?57P?:.                      .~?57P?:.        \n"
        , pdice, npcdice
        );
}




void ichika_image() {
    printf("                  ..::                  \n");
    printf("                ~~..~:.                 \n");
    printf("               ^777~:~^                 \n");
    printf("              ~77?GY7^.                 \n");
    printf("              !JGB#BJ~                  \n");
    printf("             .~!JGG7!!.                 \n");
    printf("             ^~~~?!!!!!^                \n");
    printf("            ^~!7!7!!!~7J7:.             \n");
    printf("           ^!^^~!~~^~!!~~!!:            \n");
    printf("          ^!~^^^^^^^!77!!!:             \n");
    printf("         .^!^^~~~~~~!7?!:~~:            \n");
    printf("      .~!. ~!:~!!!!!!!~. .!7!^.         \n");
    printf("    .^7!^.^~~^~~~~~!~~^^::^~!77!:       \n");
    printf("   ^!!~^^~!~~~~~~~~~~~~~~^^^^!777~.     \n");
    printf("  ^77!^^^!!^:7555^~YY5!.:^^^^^7!!!~^    \n");
    printf(" :~!!7^^:^!: J&&P :PPP:    ...~!!~~::.  \n");
    printf(".::~!!^   ~! ?&#~ :PGJ        .~!:^^    \n");
    printf("  .~~!~   ^!^Y&P  :PG!         .~^ :.   \n");
    printf("   ::^!.  .!7B#7  .5G!          .^      \n");
    printf("    . ::  .~YG5:.. ?P?           .      \n");
    printf("         :~^77~:^: ^!!                  \n");
    printf("          :^!~^ .:::!^                  \n");
    printf("           .~!!!!!!:~.                  \n");
    printf("           :~~?^.  .~                   \n");
    printf("           ^~.J~.  .~.                  \n");
    printf("          ^!^ ^^:. :!:                  \n");
    printf("         .~^       :~^                  \n");
}

void hina_image() {
    printf("                  ....:::::. .                    \n");
    printf("                  .. ..::... .                    \n");
    printf("           .         :J5Y7^:.                     \n");
    printf("            ..      .5###BPYP?:                   \n");
    printf("             ~!.   :~JPG#G~JGGPJY!^ ::            \n");
    printf("              .:^!PY!Y7!J5Y5GGPPJ!!~~.            \n");
    printf("              .!?!775Y~~~PB7JJ7!!  ..             \n");
    printf("            .^7?7?J!?7~!!5G7~: .^^^~~::.          \n");
    printf("        .:^~^.   ?BP?JY?PGGP7^~^^::.:!!~~^.       \n");
    printf("     .:~!!!~.   ~GBPJ!~7Y75GGJ!^   .~!!!7!!^.     \n");
    printf("   .~~7?!^^!^  .!!~.~^.:~^^^!??7^ .!: .:!?^:^.    \n");
    printf("  .~^.!.   ^~. :    :^ :~::~::.^~:^~     ^: ::.   \n");
    printf("  :: ..      ~:.    .~.^^:::^~~~~~ .      :   ..  \n");
    printf(" ..          ....   ::^^  .^~^.~ .                \n");
    printf("               .:..^^.~^  .^^...                  \n");
    printf("                      :.                          \n");
}

void hoshino_image() {
    printf("         .:~7!!~~!?!:.        \n");
    printf("         ..^!7J7?J75!.        \n");
    printf("            ~5BBBP??:         \n");
    printf("          .J##B###&J          \n");
    printf("         .!G#PG##BBB~         \n");
    printf("          :PPGBBBGP!:         \n");
    printf("         !PP5PBBY!Y:          \n");
    printf("       !5GPGP&#GGYGBP:        \n");
    printf("     ~JPGPP#BBG5GGG#&Y        \n");
    printf("   :~?5GPPG#5JJYJJPGB5^       \n");
    printf("   :JGGGG5GY^^~!^^!?JYPY?~.   \n");
    printf("^.~GBGPGPG5^^~~~~~^^^!???GG?. \n");
    printf("!!#BGJPGGY^^~~~~~~~~^^~~!7P#P^\n");
    printf(".G#B7 GBY~~~~~~!?JY7~^~^^~^~?5\n");
    printf(" Y#P  ?J7^7Y5P?7#&&J~^^^~!7: ^\n");
    printf(" .?Y. ^~77:7#&?~#&G!~^^^~~7!  \n");
    printf("   .. ^J.  .B&!!&#!   ....:~  \n");
    printf("      !?   .PB^7&B.           \n");
    printf("     .!J   ~BG:J&B.           \n");
    printf("     .!7   .PG.5&G            \n");
    printf("     :^.    75.G&!            \n");
    printf("     :~.    !7^&P             \n");
    printf("     ^7     ~7!5^             \n");
    printf("            .~7J~             \n");
    printf("             .7JJ^            \n");
}

void arisu_image() {
    printf("               !:!J^~                   \n");
    printf("               !~!7^~^:                 \n");
    printf("                ~!?5J?!~^     .:~YJ^    \n");
    printf("                :?PBPPJ7!    :~7GYYY7:  \n");
    printf("                ~J?GGYJJ7^!!77!PY!~YBY!: \n");
    printf("               :7J5P5?!!7JJYY7?P7YGG55?~ \n");
    printf("               ~!JB5JP7!!JJ?!^~5GG5?^.  \n");
    printf("              ^BBYGGJ5GB5JJ7Y5Y?!~.     \n");
    printf("             .?B5?YJ~JBB5YY7!7~:        \n");
    printf("         .:~J5Y?~^~~~^!?5!^:.           \n");
    printf("    :~7J5P5PG5J!^~~~~~7?J?.             \n");
    printf("   !G##BBBBB5JP7^~~~~^~PPG!             \n");
    printf(" :Y#BBGPGBGG5Y#7~??~!7!5BG?:            \n");
    printf("!G#BGBBGGBG5?!7~!BB!?#5!7!!7.           \n");
    printf("!PGP5PGGPP5J!~~~~GB!7#Y:!!!!7           \n");
    printf(":~7YY5555YJ!~~~~~GP~~PG^!~~~!7.         \n");
    printf("  :7YYJ??7~~~^~:~BP~^YB~!::~^~7:        \n");
    printf("    :~~7?~^^:~::~5Y^:^G:^^ ^^^~J~.      \n");
    printf("    .:!!!~~^^~:^:~~..:7^:~:^~~!7Y~:     \n");
    printf("      ....::...  7?: ~J~  .....::..     \n");
    printf("                 75~ 7J:                \n");
}

