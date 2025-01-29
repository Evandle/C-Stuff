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



#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>

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