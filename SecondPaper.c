#include <stdio.h>
#include <string.h>

int main(void){
    char user_input[1];
    
    printf("Enter your grade: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0';
    
    switch (user_input[0]){
        case 'A':
        case 'B':
            printf("Good Job");
            break;
        case 'C':
            printf("You're doing okay");
            break;
        case 'D':
        case 'F':
            printf("You need to study harder");
            break;
        default:
            printf("Stop lying and tell me your actual grade");
            break;
        
    }
    return 0;
    
    
}