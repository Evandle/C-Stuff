#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include "data.h"
#include "map.h"
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

char map[HEIGHT][WIDTH];
int playerX = 50;
int playerY = 15;

// Function to initialize the map with trees
void init_forest() {
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
    srand(time(0));  // Seed the random number generator
    int placedTrees = 0;
    while (placedTrees < TREE_COUNT) {
        int treeX = rand() % (WIDTH - 2) + 1;  // Random X (avoid boundaries)
        int treeY = rand() % (HEIGHT - 2) + 1;  // Random Y (avoid boundaries)
        if (map[treeY][treeX] == EMPTY_SPACE) {  // Only place a tree in an empty space
            map[treeY][treeX] = BOUNDARY;  // Use BOUNDARY to represent a tree
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
        printf("%.*s\n", WIDTH, map[i]);
    }
}

// Function to render only the visible part of the map
void render_view() {
    int startX = playerX - VIEW_WIDTH / 2;
    int startY = playerY - VIEW_HEIGHT / 2;
    int endX = playerX + VIEW_WIDTH / 2;
    int endY = playerY + VIEW_HEIGHT / 2;

    // Clamp the view to the map boundaries
    if (startX < 0) startX = 0;
    if (startY < 0) startY = 0;
    if (endX > WIDTH) endX = WIDTH;
    if (endY > HEIGHT) endY = HEIGHT;

    for (int i = startY; i < endY; i++) {
        for (int j = startX; j < endX; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player
void move_player(char direction) {
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
    if (newX > 0 && newX < WIDTH - 1 && newY > 0 && newY < HEIGHT - 1) {
        if (map[newY][newX] != BOUNDARY) {
            // Move the player to the new position
            map[playerY][playerX] = EMPTY_SPACE;  // Clear the old position
            playerX = newX;
            playerY = newY;
            map[playerY][playerX] = PLAYER;  // Set the new position
        }
    }
}