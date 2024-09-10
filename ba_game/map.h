#ifndef MAP_H
#define MAP_H

#define WIDTH 100
#define HEIGHT 30
#define TREE_COUNT 400
#define EMPTY_SPACE ' '
#define BOUNDARY '#'
#define PLAYER '@'
#define NPC 'X'
#define ENEMY_COUNT 20
#define VIEW_WIDTH 10
#define VIEW_HEIGHT 5

// Function declarations
void init_forest();
void render_map();
void render_view();
void move_player(char direction);

#endif // MAP_H
