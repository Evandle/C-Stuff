
#include <string.h>
#include <stdio.h>
#include "map.h"
#include "data.h"


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

void desplay_stat(stat* s) {
    printf("Vitality: %d\nEndurance: %d\nMana: %d\nIntelligence: %d\nAgility: %d\nLuck: %d\nInsight: %d\nCorruption: %d\nSanity: %d", s->vit, s->end, s->mana, s->intelligence, s->agility, s->luck, s->insight, s->corruption, s->sanity);
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

void desplay_level(level *l) {
    printf("Level: %d\nXp Cap: %d", l->level, l->xpcap);
}

void init_spell(spell* s, const char* name, const char* desc, int damage, float accuracy, int cooldown, int cost, float critchance, float critdamage, float stunchance, int stunduration) {
    strcpy(s->name, name);
    strcpy(s->desc, desc);
    s->damage = damage;
    s->accuracy = accuracy;
    s->cooldown = cooldown;
    s->cost = cost;
    s->critchance = critchance;
    s->critdamage = critdamage;
    s->stunchance = stunchance;
    s->stunduration = stunduration;
}

void desplay_spell(spell* s) {
    printf("Name: %s\nDescription: %s\nDamage: %d\nAccuracy: %.2f\nCooldown: %d\nCost: %d\nCrit Chance: %.2f\nCrit Damage: %.2f\nStun Chance: %.2f\nStun Duration: %d", s->name, s->desc, s->damage, s->accuracy, s->cooldown, s->cost, s->critchance, s->critdamage, s->stunchance, s->stunduration);
}

void init_weapon(weapon* w, const char* name, const char* desc, const int dmg, const int dropchance){
    strcpy(w->name, name);
    strcpy(w->desc, desc);
    w->dmg = dmg;
    w->dropchance = dropchance;
}

void display_weapon(weapon* w){
    printf("Name: %s\nDescription: %s\nDamage: %d\nDrop Chance: %d\n", w->name, w->desc, w->dmg, w->dropchance);
}

void init_student(student* s, const char* name, const char* course, int hp, const int def, const float multi, weapon* weapon, level* level, int xp) {
    strcpy(s->name, name);
    strcpy(s->course, course);
    s->hp = hp;
    s->def = def;
    s->multi = multi;
    s->weapon = *weapon;
    s->level = *level;
    s->xp = xp;
}

void init_npc(npc* n, char* name, char* desc, int hp, int def, weapon* weapon, level* level, int xp_drop) {
    strcpy(n->name, name);
    strcpy(n->desc, desc);
    n->hp = hp;
    n->def = def;
    n->weapon = *weapon;
    n->level = *level;
    n->xp_drop = xp_drop;
}

void init_image(image* i, char* name, char* img) {
    strcpy(i->name, name);
    strcpy(i->img, img);
}


void display_student(student* s){
    printf("Name: %s\nCourse: %s\nHP: %d\nDef: %d\nAtk Multi: %.2f\n\n", s->name, s->course, s-> hp, s->def, s->multi);
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

void init_all_images(image* EF1) {
    init_image(EF1, "The Beginning of Evandle's Wondering", 
    "..~^::~^!!?^~!^.:::~5~^77^~!::~7?JY?^:~:...................!7~^:::5B7:~P?::^:...!Y~:!55Y7^.:::~:::.\n"
    "..77~:~!~^^:~?Y7:::^!J!7^~:!^:~?YY?~^::^:....~...........:!?!^:^~?G5~~PP!:::.::~!!^~PG57::^!:^~^^::.\n"
    "..J5~~^~^:::7!7J?^::.!?!~~:^^~~?YY!7~^^:^^:.:Y7~~......:~??~^::!GPJ~!!?~:::.:^~^7?:!GPY~.~?.~?~^^:..\n"
    "..JPP5!^::^:|??|7?^.::~7!~::^^7YJJYJ!:^::^^^!5&B^.:::^~!~^^^:^!JY!^!!^^:::::~7?J5^~55J~:~7:~PJ.:^::.\n"
    "..7PP5~^.::^?Y?!!!~::::^~~^:::!J?!?5?~~77^:^^^Y&GY!^^^~^::^^!!!^::~~~^~^:::^JGPY~!P5~^^:!7JPG5::^::.\n"
    "..~PG5~~^^^:77Y??|^:^^:.::^:.:^7?!^JY??JYY?~^^:5BJYJ7::^^^::^:~~!777!~^.::^?G5!^7JY!:.:!PBGGG5^::::.\n"
    "..~Y5Y?J~~::YJ7JYY~^^^~:::.::::~!?^:??^:^!?J???7Y5J75?!!~~~~!7JYJ?!~^:::!?J5Y!~!^^!^::7?5GGG57.::.:.\n"
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
    ".^7^..!~!5^~!!JJYJPBB#B~:Y7??||5?:::.7J::~:.:....::.....^~:.:::.::~::~?7^!7!5#BG5Y7~^!!~:.:~^:^^:..:\n"
    "..:7!?~^~5P!^.:~7?7JP##P77Y~!?~!?::~~!7^:?:.:^...::.:..^J!:.:^:.::::..!Y?GPP#BGY?7!^~^::~~77^::.:::.\n"
    "..:^!!JY7?BG!!^^^!??7?5##PG57Y57Y~::~YPY~7.^::...::.~^^YJ~:.^~^:::::^~JYPGPP57?JJ7^:~^^~7J?~^..^7^::\n"
    "..:.^!~|??5GPG5^~!~7!^!?PBG#5YJYGJ^^~7P?.!^!:^:..^::::5J:...!7!^~^!~?75###GPJ??|^?^:^7?7?^^^~^!?!^:.\n"
    ":..:~^77~!!??7YP!J!!~~!!~!JP#B55B5!!!!5?.??~:~^^.:^!::7?::^:7YY!~!??G##GBGYYJ!^::^:!Y5?^^!YJ?!~^....\n"
    "::.:^!^77!7^~~^~7J??PJ~!!~!~?G#B#GYJY!~GY?7?^!~:^~:7:^!G7!~~YBJ^7B#BBBYJ5YJ!!7~7YPPY7~:757!~^^^^::.\n"
    ".:^^~7?~:..::7!7~:^~!!7!~~^~~~JGGGBBBPP#B5?5!7:7~77?755#PJ?PB#PY5GY?5P5?!~^:?Y?5Y7!^~^!J~..:!~^::...\n"
    "....:^~~7:.^::~~!^:^::.^~^::^^~7JPGBBP5PGPBGPPJ5PGGGGPYP5PP5?YJJ5Y7777~^^:^^~~~!~^J77!~::^:^~...:...\n"

    
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

