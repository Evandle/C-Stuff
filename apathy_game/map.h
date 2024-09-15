#ifndef MAP_H
#define MAP_H

#define WIDTH 100
#define HEIGHT 30

#define EMPTY_SPACE ' '
#define BOUNDARY '#'
#define TREE 'T'  
#define PLAYER '@'
#define NPC 'X'

#define VIEW_WIDTH 10
#define VIEW_HEIGHT 5
#define MIN_BOUNDARY 0
#define MIN_BOUNDARY_VIEW 1
#define MAX_WIDTH (WIDTH - 1)
#define MAX_HEIGHT (HEIGHT - 1)

// Function declarations
void init_forest(int TREE_COUNT, int ENEMY_COUNT);
void render_map();
void render_view();
char move_player(char direction);

#endif // MAP_H
