#include <stdio.h>

void draw_dice_animation(int pdice, int npcdice) {
    printf(
        "               ____________                  ____________      \n"
        "              /            \\                /            \\       \n"
        "              |     [%d]    |                |    [%d]     |     \n"
        "              \\____________/                \\____________/      \n"
        "                                                                \n"
        , pdice, npcdice
        );
}

int main(void){
    draw_dice_animation(6, 1);





    return 0;
}