
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Temporary functions.
int Morning1(const char* Player, const char* Maingirl);
char choice1(char* prompt, char* valid_inputs, char* outputA, char* outputB, char* outputC, char* outputD, int Affection_A, int Affection_B, int Affection_C, int Affection_D);
void calculate_affection(int choice_affection);

// Global Variables.
int Affection_Level = 20;

// Choice maker.
char choice1(char* prompt, char* valid_inputs, char* outputA, char* outputB, char* outputC, char* outputD, int Affection_A, int Affection_B, int Affection_C, int Affection_D){
    char user_input[3];
    do {
        printf("%s\n\n: ", prompt);
        if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
            user_input[strcspn(user_input, "\n")] = '\0';
            // Convert user input to lowercase for case-insensitive matching.
            for (int i = 0; user_input[i] != '\0'; i++) {
                user_input[i] = tolower(user_input[i]);
            }
            if (user_input[0] == '\0' || strchr(valid_inputs, user_input[0]) == NULL) {
                printf("Invalid input. Please try again.\n");
            }
            if (strchr(valid_inputs, user_input[0]) == NULL) {
                printf("Invalid input. Please try again.\n");
            }
        } 
        else {
            printf("Invalid input. Please try again.\n");
        }
    } while (strchr(valid_inputs, user_input[0]) == NULL);
    switch (user_input[0]) {
        case 'a':
            printf("%s\n", outputA);
            calculate_affection(Affection_A);
            return 'a';
        case 'b':
            printf("%s\n", outputB);
            calculate_affection(Affection_B);
            return 'b';
        case 'c':
            printf("%s\n", outputC);
            calculate_affection(Affection_C);
            return 'c';
        case 'd':
            printf("%s\n", outputD);
            calculate_affection(Affection_D);
            return 'd';
        default:
            // Handle unexpected input (shouldn't happen)
            return '?';
    }
}

// Affection updater function.
void calculate_affection(int choice_affection) {
    Affection_Level += choice_affection;
}


// The main function that calls the events and sets the timeline accordingly.
int main(void){
    char Player[100];
    char Maingirl[100];
    
    printf("What is your name?\n: ");
    fgets(Player, sizeof(Player) - 1, stdin);
    Player[strcspn(Player, "\n")] = '\0';

    printf("Who's the girl you want to settle down with?\n: ");
    fgets(Maingirl, sizeof(Maingirl) - 1, stdin);
    Maingirl[strcspn(Maingirl, "\n")] = '\0';

    Morning1(Player, Maingirl);

    printf("%d\n", Affection_Level);
    return 0;
}


// Morning, the start of the game's story line.
int Morning1(const char* Player, const char* Maingirl){
    char User_Choice = '_';
    char List_Choice[] = {'a', 'b', 'c', 'd', '\0'};
    int Affection_NegTwo = -2;
    int Affection_NegOne = -1;
    int Affection_One = 1;
    int Affection_Two = 2;
    int Affection_Three = 3;
    printf("%s let out an exasperated groan while stretching his arms. %s had been hard at work sorting through documents on his computer.\n\n", Player, Player);
    usleep(9000000);
    printf("\"Hey %s! Whatcha up to?\" A voice overflowing with energy and was quite loud was heard from behind %s. He looked behind to see the bright smile of %s.\n\n", Player, Player, Maingirl);
    usleep(9000000);
    printf("\"Just sorting some documents. You don't have anything to do, %s?\" %s was curios on her sudden visit.\n\n", Maingirl, Player);
    usleep(9000000);
    printf("\"Nope, I was kinda just wandering around thinking about what to do, and before I knew it, I'm right outside of your front door so I decided to invite myself in. I'm not bothering you, am I, %s?\" %s was as casual as ever as she explained that she just seemed to find her way here.\n\n", Player, Maingirl);
    usleep(9000000);
    printf("%c", choice1("a : Tell her its alright. b : Tease her abit.\nc : Tell her she's fun. d : Say nothing.", List_Choice,
                    "No you are not a bother at all.\n", "A little.\n", "It's fun having you around\n", "...\n",
                    Affection_Three, Affection_NegOne, Affection_Two, Affection_NegOne));
    usleep(9000000);
    return 0;
}


