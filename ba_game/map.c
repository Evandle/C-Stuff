#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include "student.h"
#define WIDTH 100
#define HEIGHT 30
#define TREE_COUNT 100
#define EMPTY_SPACE ' '
#define BOUNDARY '#'
#define PLAYER '@'

char map[HEIGHT][WIDTH];
int playerX = 1;
int playerY = 1;

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

    // Set the player's initial position
    map[playerY][playerX] = PLAYER;
}

// Function to render the map
void render_map() {
    for (int i = 0; i < HEIGHT; i++) {
        printf("%.*s\n", WIDTH, map[i]);
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